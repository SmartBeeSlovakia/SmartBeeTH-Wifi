
/* 
  SmartBee-TH  Temperature and humidity sensor 


  Version  1.1.3 - 2016-01-01

  */

 
#include <Adafruit_HTU21DF.h> 
#include <Wire.h>
//#include <stdint.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Ticker.h>
#include <EEPROM.h>
//#include <WiFiUdp.h>
#include "helpers.h"
#include "global.h"

//Include the HTML, STYLE and Script "Pages"
#include "Page_Main.h"
#include "Page_Root.h"
#include "Page_Admin.h"
#include "Page_Script.js.h"
#include "Page_Style.css.h"
#include "Page_NTPsettings.h"
#include "Page_Information.h"
#include "Page_General.h"
#include "PAGE_NetworkConfiguration.h"
#include "Page_Thingspeak.h"
#include "Page_EmonCms.h"
#include "Page_SmartBeeCloud.h"
#include "Page_Firmware.h"
#include "Page_Language.h"

//External Function
extern "C" {
#include "user_interface.h"
#include "Esp.h"
//uint16 readvdd33(void);
}




//ADC_MODE(ADC_VCC);
char FirmwareID[8] = "1.1.3";
char gDeviceName[18] = "SmartBeeTH-000000";
char gNodeID[7] = "000000";
int Red_Pin = 2;
int Green_Pin = 5;
int Blue_Pin = 4; 
int CfgBtn_Pin = 12;
int BtnVal = 1;
int PowerType=1; // 0-2xAA Alkaline in series = 3V, 1-2xLi-ion 14500 in pararel 3,7V, 2-External power via input 5V - 12V
int uCounter = 0; //define update counter
boolean UpTsFlg = false; //upload flag for ThingSpeak upload
boolean UpEmFlg = false; //upload flag for EmonCms upload
boolean UpSbFlg = false; //upload flag for SmartBee cloud upload
boolean UpCsFlg = false; //upload flag for custom script upload



const char PAGE_UpdateOk[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="refresh" content="6; URL=/">
Updating firmware finished. Restarting devices. Please wait...
)=====";
   
//Definitions
#define ACCESS_POINT_PASSWORD  "SmartBee" 
#define AdminTimeOut 300  // Defines the Time in Seconds, when the Admin-Mode will be diabled
#define ResetTimeOut 1 // define reset counter 




//start of program
Adafruit_HTU21DF htu = Adafruit_HTU21DF();


void setup ( void ) {
  //Set RGB led pin
  pinMode(Red_Pin, OUTPUT);// red led
  pinMode(Green_Pin, OUTPUT);// green led
  pinMode(Blue_Pin, OUTPUT);//blue led
  SetLed(0,true);
  
  //Set Config Button
  pinMode(CfgBtn_Pin, INPUT); //configuration button



  // Create a "gDeviceName" from chip_id
  sprintf(gDeviceName+11, "%X", ESP.getChipId());              // Append Hex ID Number at position 3
  sprintf(gNodeID, "%X", ESP.getChipId());
  config.NodeID = gDeviceName;
  config.Sensor = true;
	config.DevType = "SmartBeeTH";
  config.Firmware = FirmwareID;
	
	Wire.begin(13, 14); // (sda,scl) choose your pins here
	EEPROM.begin(2048);
	Serial.begin(115200);

  
	delay(500);
  config.ResetEnabled = 0;
	config.Temperature = "";
	config.Humidity = "";
  Serial.println();
	Serial.println("Booting ...");
  //Serial.setDebugOutput(true);




  if (digitalRead(CfgBtn_Pin) == LOW){
    AdminEnabled = true;
    Serial.println("Input to ADMIN Configuration!");  
  }

  
  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    config.Sensor = false;
  }


     
	if (!ReadConfig()){
    //default configuration
    DefaultConfig();
    config.BatteryType = PowerType;
		WriteConfig();
		Serial.println("General config applied");
	}

  if (config.BatteryType != PowerType){
    config.BatteryType = PowerType;
    WriteConfig();
    Serial.println("General power seting config was applied");
  }
    config.BatteryType = PowerType;
    
	
	if (AdminEnabled)
	{
		WiFi.mode(WIFI_AP_STA);
		//WiFi.softAP( ACCESS_POINT_NAME  , ACCESS_POINT_PASSWORD);
    WiFi.softAP( gDeviceName  , ACCESS_POINT_PASSWORD);
    //Blue led 2 seccond  for input to configuration mode
    ConfigureWifi();
    SetLed(3,true);
    delay (2000);
    SetLed(0,true);
    
	}
	else
	{
    SetLed(1,config.StatusLed);
    delay (100);
    SetLed(0,config.StatusLed);
		WiFi.mode(WIFI_STA);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(config.ssid);
    Serial.println(analogRead(A0));
    ConfigureWifi();

    byte ConCounter;
    ConCounter = 0;
    while (WiFi.status() != WL_CONNECTED) {
    ConCounter ++;
    delay(500);
    Serial.print(".");
    if (ConCounter >20){
      SetLed(1,config.StatusLed);
      delay (1000);
      SetLed(0,config.StatusLed);
      Sleep();  
    }
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  SetLed(3,config.StatusLed);
  delay (200);
  SetLed(0,config.StatusLed);      
	}

	
	
  if (AdminEnabled)
  {
    MDNS.begin(gDeviceName);
    
  	server.on ( "/", processLanguage  );
  	server.on ( "/admin/filldynamicdata", filldynamicdata );
  	server.on ( "/favicon.ico",   []() { Serial.println("favicon.ico"); server.send ( 200, "text/html", "" );   }  );
    server.on ( "/main", processMain  );
  	server.on ( "/admin", processAdmin  );
    server.on ( "/svk", processSvk  );
    server.on ( "/eng", processEng  );
  	server.on ( "/config", send_network_configuration_html );
  	server.on ( "/info", ProcessInfo );
  	server.on ( "/ntp.html", send_NTP_configuration_html  );
  	server.on ( "/general", send_general_html  );
    server.on ( "/thingspeak.html", send_thingspeak_html  );
    server.on ( "/emoncms.html", send_emoncms_html  );
  	server.on ( "/smartbeecloud", []() { Serial.println("smartbeecloud.html"); server.send ( 200, "text/html", PAGE_SmartBeeCloudPage );   }  );
  	server.on ( "/style.css", []() { Serial.println("style.css"); server.send ( 200, "text/plain", PAGE_Style_css );  } );
  	server.on ( "/microajax.js", []() { Serial.println("microajax.js"); server.send ( 200, "text/plain", PAGE_microajax_js );  } );
  	server.on ( "/admin/values", send_network_configuration_values_html );
  	server.on ( "/admin/connectionstate", send_connection_state_values_html );
  	server.on ( "/admin/infovalues", send_information_values_html );
  	server.on ( "/admin/ntpvalues", send_NTP_configuration_values_html );
  	server.on ( "/admin/generalvalues", send_general_configuration_values_html);
  	server.on ( "/admin/devicename",     send_devicename_value_html);
    server.on ( "/admin/thingspeakvalues", send_thingspeak_configuration_values_html);
    server.on ( "/admin/emoncmsvalues", send_emoncms_configuration_values_html);
  
  	server.on("/firmware", HTTP_GET, []()
  	{ server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      if (config.Language=="SK") {
        server.send ( 200, "text/html", SK_PAGE_Firmware  );
      }
      if (config.Language=="EN") {
        server.send ( 200, "text/html", EN_PAGE_Firmware  );
      }
      else{
        server.send ( 200, "text/html", EN_PAGE_Firmware  );
      }
    });
    server.onFileUpload([](){
      if(server.uri() != "/update") return;
      HTTPUpload& upload = server.upload();
      if(upload.status == UPLOAD_FILE_START){
        Serial.setDebugOutput(true);
        WiFiUDP::stopAll();
        Serial.printf("Update: %s\n", upload.filename.c_str());
        uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
        if(!Update.begin(maxSketchSpace)){//start with max available size
          Update.printError(Serial);
        }
      } else if(upload.status == UPLOAD_FILE_WRITE){
        if(Update.write(upload.buf, upload.currentSize) != upload.currentSize){
          Update.printError(Serial);
        }
      } else if(upload.status == UPLOAD_FILE_END){
        if(Update.end(true)){ //true to set the size to the current progress
          Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
        } else {
          Update.printError(Serial);
        }
        Serial.setDebugOutput(false);
      }
      yield();
    });
    server.on("/update", HTTP_POST, [](){
      server.sendHeader("Connection", "close");
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, "text/html", (Update.hasError())?"FAIL":PAGE_UpdateOk);
      ESP.restart();
    });
  	
  	
  	
  	server.onNotFound ( []() { Serial.println("Page Not Found"); server.send ( 400, "text/html", "Page not Found" );   }  );
  	server.begin();
   
     MDNS.addService("http", "tcp", 80);
  
    Serial.printf("Ready! Open http://%s.local in your browser\n", gDeviceName);
    
  	Serial.println( "HTTP server started" );
  }
}




 
void loop ( void ) {
	if (AdminEnabled)
	{
		if (AdminTimeOutCounter > AdminTimeOut)
		{
			 AdminEnabled = false;
			 Serial.println("Admin Mode disabled!");
			 WiFi.mode(WIFI_STA);
       AdminTimeOutCounter = 0;
		}
  server.handleClient();


  /*
  *    Your Code here
  */
  
  
  yield();
  //delay(1);

  //yield();
  if (config.ResetEnabled){
    ResetTimeOutCounter++;
    if (ResetTimeOutCounter > ResetTimeOut)
    {
    ResetTimeOutCounter = 0;
    FactoryReset();  
    }

  }
  yield();


  
	}
  else
  {
  // *** code for upload mode 

  //*******ThingSpeak upload***********
  if (config.tsenabled){
    if (UpTsFlg == false){
      ThingSpeakUpload();
    } 
  }
  
  //*******EmonCMS upload***********
  if (config.emonenabled){
    if (UpEmFlg == false){
      EmonCmsUpload();
    } 
  }
  
  
  
  Sleep();
	}

	
}






///////////////////////////////////////////////////////////////////////
//////////////////       FUNCTIONS          ///////////////////////////
///////////////////////////////////////////////////////////////////////






void SetLed(int color, boolean enable) {
// Set status colour LED

  if (!enable){
  color = 0;  
  }
  switch (color) {
      case 0: //0 - leds is off
        digitalWrite(Red_Pin, HIGH);
        digitalWrite(Green_Pin, HIGH);
        digitalWrite(Blue_Pin, HIGH);
        break;
      case 1: //1 - red color
        digitalWrite(Red_Pin, LOW);
        digitalWrite(Green_Pin, HIGH);
        digitalWrite(Blue_Pin, HIGH);
        break;
      case 2: //2 - green color
        digitalWrite(Red_Pin, HIGH);
        digitalWrite(Green_Pin, LOW);
        digitalWrite(Blue_Pin, HIGH);
        break;
      case 3: //3 - blue color
        digitalWrite(Red_Pin, HIGH);
        digitalWrite(Green_Pin, HIGH);
        digitalWrite(Blue_Pin, LOW);
        break;
      case 4: //4 - white color
        digitalWrite(Red_Pin, LOW);
        digitalWrite(Green_Pin, LOW);
        digitalWrite(Blue_Pin, LOW);
        break;
      case 5: //5 - purple color
        digitalWrite(Red_Pin, LOW);
        digitalWrite(Green_Pin, HIGH);
        digitalWrite(Blue_Pin, LOW);
        break;
      case 6: //6 - yelow color
        digitalWrite(Red_Pin, LOW);
        digitalWrite(Green_Pin, LOW);
        digitalWrite(Blue_Pin, HIGH);
        break;
      case 7: //7 - Azure color
        digitalWrite(Red_Pin, HIGH);
        digitalWrite(Green_Pin, LOW);
        digitalWrite(Blue_Pin, LOW);
        break;
      default: // turn all the LEDs off:
        digitalWrite(Red_Pin, HIGH);
        digitalWrite(Green_Pin, HIGH);
        digitalWrite(Blue_Pin, HIGH);
  }

}

void FactoryReset()
{
  config.ResetEnabled=0;
  //Blink RGB leds for factory reset
  SetLed(0,true);
  delay (100);
  SetLed(1,true);
  delay (200);
  SetLed(0,true);
  delay (200);
  SetLed(1,true);
  delay (200);
  SetLed(0,true);
  delay (200);
  SetLed(4,true);
  delay (500);
  SetLed(0,true);  
  //Erase full eeprom
  ClearEEPROM(2048);
  DefaultConfig();
  WriteConfig();
  Serial.println("Factory reset applied ");
  AdminTimeOutCounter=0;
}





///////////////////////////////////////////////////////////////////////
//////////////////   THINGSPEAK UPLOAD      ///////////////////////////
///////////////////////////////////////////////////////////////////////


void ThingSpeakUpload(){
  TsStart:
  
  ++uCounter;
  delay(2000);
  if (uCounter >= 4){
    UpTsFlg = true;
    uCounter = 0;
  }
  
  yield();
  Serial.print("Connecting to ");
  Serial.println(config.tssite);
  Serial.print("Update Counter: ");
  Serial.println(uCounter);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = config.tsport.toInt();
  yield();
  if (!client.connect(config.tssite.c_str(), httpPort)) {
    Serial.println("connection failed");
    SetLed(5,config.StatusLed);
    delay (200);
    SetLed(0,config.StatusLed);
    yield();
    //return;
    goto TsStart;
  }
  yield();
  if (!config.Sensor)
  {
  config.Temperature="Err";
  config.Humidity = "Err";
  }
  else{
  config.Temperature = Adafruit_HTU21DF().readTemperature();
  config.Humidity = Adafruit_HTU21DF().readHumidity();
  }
  
  
 
  
  String HeapSize = String(system_get_free_heap_size());
  String Voltage = String(readADC());
  String BatPercent = String(BatteryPercent(readADC(),PowerType));
  //"/update?api_key=TAPIKEY&field1=TEMPERATURE&field1=HUMIDITY&field3=BATMVOLT&field4=BATPERCENT&field5=HEAPSIZE&field6=UCOUNTER"
  //String url = "/update?api_key=";
  //url += config.tsapi;
  //url += "&field1=";
  //url += config.Temperature;
  //url += "&field2=";
  //url += config.Humidity;
  //url += "&field3=";
  //url += HeapSize;
  yield();
  String url = config.tsstring;
  url.replace("TAPIKEY",config.tsapi);
  url.replace("TEMPERATURE",config.Temperature);
  url.replace("HUMIDITY",config.Humidity);
  url.replace("BATMVOLT",Voltage);
  url.replace("BATPERCENT",BatPercent);
  url.replace("HEAPSIZE",HeapSize);
  url.replace("UCOUNTER",String(uCounter));

  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  yield();
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + config.tssite.c_str() + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);
  yield();
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  yield();
  SetLed(2,config.StatusLed);
  delay (300);
  SetLed(0,config.StatusLed);
  Serial.println();
  yield();
  uCounter = 0;
  Serial.print("closing connection from: ");
  Serial.println(config.tssite);
}

///////////////////////////////////////////////////////////////////////
//////////////////      EMONCMS UPLOAD      ///////////////////////////
///////////////////////////////////////////////////////////////////////


void EmonCmsUpload(){
  EmStart:
  
  ++uCounter;
  delay(2000);
  if (uCounter >= 4){
    UpEmFlg = true;
    uCounter = 0;
  }
  
  yield();
  Serial.print("Connecting to ");
  Serial.println(config.emonsite);
  Serial.print("Update Counter: ");
  Serial.println(uCounter);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = config.emonport.toInt();
  yield();
  if (!client.connect(config.emonsite.c_str(), httpPort)) {
    Serial.println("connection failed");
    SetLed(5,config.StatusLed);
    delay (200);
    SetLed(0,config.StatusLed);
    yield();
    //return;
    goto EmStart;
  }
  yield();
  if (!config.Sensor)
  {
  config.Temperature="Err";
  config.Humidity = "Err";
  }
  else{
  config.Temperature = Adafruit_HTU21DF().readTemperature();
  config.Humidity = Adafruit_HTU21DF().readHumidity();
  }
  
  
 
  
  String HeapSize = String(system_get_free_heap_size());
  String Voltage = String(readADC());
  String BatPercent = String(BatteryPercent(readADC(),PowerType));
  yield();
  String url = config.emonstring;
  url.replace("ENODEID",String(config.emonnodeID));
  url.replace("EAPIKEY",config.emonapi);
  url.replace("TEMPERATURE",config.Temperature);
  url.replace("HUMIDITY",config.Humidity);
  url.replace("BATMVOLT",Voltage);
  url.replace("BATPERCENT",BatPercent);
  url.replace("HEAPSIZE",HeapSize);
  url.replace("UCOUNTER",String(uCounter));

  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  yield();
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + config.emonsite.c_str() + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);
  yield();
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  yield();
  SetLed(2,config.StatusLed);
  delay (300);
  SetLed(0,config.StatusLed);
  Serial.println();
  yield();
  uCounter = 0;
  Serial.print("closing connection from: ");
  Serial.println(config.emonsite);
}


void Sleep(){
  system_deep_sleep_set_option(0);
  int SleepTime = config.UpdateTime;
  system_deep_sleep(SleepTime * 60 * 1000000);
}




