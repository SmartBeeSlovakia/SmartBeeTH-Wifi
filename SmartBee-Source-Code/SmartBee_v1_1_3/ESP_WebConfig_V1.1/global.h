#ifndef GLOBAL_H
#define GLOBAL_H

ESP8266WebServer server(80);									// The Webserver
boolean firstStart = true;										// On firststart = true, NTP will try to get a valid time
int AdminTimeOutCounter = 0;									// Counter for Disabling the AdminMode
int ResetTimeOutCounter = 0;									// Counter for factory reset
//strDateTime DateTime;											// Global DateTime structure, will be refreshed every Second
//WiFiUDP UDPNTPClient;											// NTP Client
//unsigned long UnixTimestamp = 0;								// GLOBALTIME  ( Will be set by NTP)
boolean Refresh = false; // For Main Loop, to refresh things like GPIO / WS2812
//int cNTP_Update = 0;											// Counter for Updating the time via NTP
Ticker tkSecond;												// Second - Timer for Updating Datetime Structure
boolean AdminEnabled = false;		// Enable Admin Mode for a given Time
//byte Minute_Old = 100;				// Helpvariable for checking, when a new Minute comes up (for Auto Turn On / Off)




struct strConfig {
	String ssid;
	String password;
	byte  IP[4];
	byte  Netmask[4];
	byte  Gateway[4];
	boolean dhcp;
	String ntpServerName;
	long Update_Time_Via_NTP_Every;
	long timezone;
	boolean daylight;
	String DeviceName;
	boolean AutoTurnOff;
	boolean AutoTurnOn;
	byte TurnOffHour;
	byte TurnOffMinute;
	byte TurnOnHour;
	byte TurnOnMinute;
	byte LED_R;
	byte LED_G;
	byte LED_B;
  String Temperature;
  String Humidity;
  String Voltage;
  boolean StatusLed;
  byte UpdateTime;
  String NodeID;
  String NodeLocation;
  boolean Sensor;
  int ResetEnabled;
  byte BatteryType;
  String Firmware;
  String DevType;
  String Language;
  //thingspeak configuration
  boolean tsenabled;
  String tssite;
  String tsport;
  String tsapi;
  String tsstring;
  //end thingspeak configuration
  
  //emoncms configuration
  byte emonnodeID;
  boolean emonenabled;
  String emonsite;
  String emonport;
  String emonapi;
  String emonstring;
  //end emon configuration
  
  
}   config;


/*
**
** CONFIGURATION HANDLING
**
*/
void ConfigureWifi()
{
	Serial.println("Configuring Wifi");
	WiFi.begin (config.ssid.c_str(), config.password.c_str());
	if (!config.dhcp)
	{
		WiFi.config(IPAddress(config.IP[0],config.IP[1],config.IP[2],config.IP[3] ),  IPAddress(config.Gateway[0],config.Gateway[1],config.Gateway[2],config.Gateway[3] ) , IPAddress(config.Netmask[0],config.Netmask[1],config.Netmask[2],config.Netmask[3] ));
	}
}

void WriteConfig()
{

	Serial.println("Writing Config");
	EEPROM.write(0,'C');
	EEPROM.write(1,'F');
	EEPROM.write(2,'G');

  WriteStringToEEPROM(10,config.Language);

	EEPROM.write(16,config.dhcp);
	EEPROM.write(17,config.daylight);
	
	EEPROMWritelong(18,config.Update_Time_Via_NTP_Every); // 4 Byte

	EEPROMWritelong(22,config.timezone);  // 4 Byte


	EEPROM.write(26,config.LED_R);
	EEPROM.write(27,config.LED_G);
	EEPROM.write(28,config.LED_B);

	EEPROM.write(32,config.IP[0]);
	EEPROM.write(33,config.IP[1]);
	EEPROM.write(34,config.IP[2]);
	EEPROM.write(35,config.IP[3]);

	EEPROM.write(36,config.Netmask[0]);
	EEPROM.write(37,config.Netmask[1]);
	EEPROM.write(38,config.Netmask[2]);
	EEPROM.write(39,config.Netmask[3]);

	EEPROM.write(40,config.Gateway[0]);
	EEPROM.write(41,config.Gateway[1]);
	EEPROM.write(42,config.Gateway[2]);
	EEPROM.write(43,config.Gateway[3]);


	WriteStringToEEPROM(64,config.ssid);
	WriteStringToEEPROM(96,config.password);
	WriteStringToEEPROM(128,config.ntpServerName);
  //WriteStringToEEPROM(250,config.NodeID);
  WriteStringToEEPROM(250,config.NodeLocation);
  EEPROM.write(280,config.StatusLed);
  EEPROM.write(281,config.UpdateTime);
  EEPROM.write(282,config.BatteryType);
  
	EEPROM.write(300,config.AutoTurnOn);
	EEPROM.write(301,config.AutoTurnOff);
	EEPROM.write(302,config.TurnOnHour);
	EEPROM.write(303,config.TurnOnMinute);
	EEPROM.write(304,config.TurnOffHour);
	EEPROM.write(305,config.TurnOffMinute);
	WriteStringToEEPROM(306,config.DeviceName);
  
  //thingspeak configuration
  EEPROM.write(340,config.tsenabled);
  WriteStringToEEPROM(341,config.tssite);
  WriteStringToEEPROM(372,config.tsport);
  WriteStringToEEPROM(377,config.tsapi);
  WriteStringToEEPROM(400,config.tsstring);
	//end thingspeak configuration
  
  //emoncms configuration
  EEPROM.write(639,config.emonnodeID);
  EEPROM.write(640,config.emonenabled);
  WriteStringToEEPROM(641,config.emonsite);
  WriteStringToEEPROM(672,config.emonport);
  WriteStringToEEPROM(677,config.emonapi);
  WriteStringToEEPROM(720,config.emonstring);
	//end of emoncms configuration


	EEPROM.commit();
}
boolean ReadConfig()
{

	Serial.println("Reading Configuration");
	if (EEPROM.read(0) == 'C' && EEPROM.read(1) == 'F'  && EEPROM.read(2) == 'G' )
	{
		Serial.println("Configurarion Found!");
		
    config.Language = ReadStringFromEEPROM(10);
    
    config.dhcp = 	EEPROM.read(16);

		config.daylight = EEPROM.read(17);

		config.Update_Time_Via_NTP_Every = EEPROMReadlong(18); // 4 Byte

		config.timezone = EEPROMReadlong(22); // 4 Byte

		config.LED_R = EEPROM.read(26);
		config.LED_G = EEPROM.read(27);
		config.LED_B = EEPROM.read(28);

		config.IP[0] = EEPROM.read(32);
		config.IP[1] = EEPROM.read(33);
		config.IP[2] = EEPROM.read(34);
		config.IP[3] = EEPROM.read(35);
		config.Netmask[0] = EEPROM.read(36);
		config.Netmask[1] = EEPROM.read(37);
		config.Netmask[2] = EEPROM.read(38);
		config.Netmask[3] = EEPROM.read(39);
		config.Gateway[0] = EEPROM.read(40);
		config.Gateway[1] = EEPROM.read(41);
		config.Gateway[2] = EEPROM.read(42);
		config.Gateway[3] = EEPROM.read(43);
		config.ssid = ReadStringFromEEPROM(64);
		config.password = ReadStringFromEEPROM(96);
		config.ntpServerName = ReadStringFromEEPROM(128);
		//config.NodeID = ReadStringFromEEPROM(250);
    config.NodeLocation = ReadStringFromEEPROM(250);
		config.StatusLed = EEPROM.read(280);
    config.UpdateTime = EEPROM.read(281);
    config.BatteryType = EEPROM.read(282);
		config.AutoTurnOn = EEPROM.read(300);
		config.AutoTurnOff = EEPROM.read(301);
		config.TurnOnHour = EEPROM.read(302);
		config.TurnOnMinute = EEPROM.read(303);
		config.TurnOffHour = EEPROM.read(304);
		config.TurnOffMinute = EEPROM.read(305);
		config.DeviceName= ReadStringFromEEPROM(306);
    
    //thingspeak configuration
    config.tsenabled = EEPROM.read(340);
    config.tssite = ReadStringFromEEPROM(341);
    config.tsport = ReadStringFromEEPROM(372);
    config.tsapi = ReadStringFromEEPROM(377);
    config.tsstring = ReadStringFromEEPROM(400);
    //end thingspeak configuration
    
    //emoncms configuration
    config.emonnodeID = EEPROM.read(639);
    config.emonenabled = EEPROM.read(640);
    config.emonsite = ReadStringFromEEPROM(641);
    config.emonport = ReadStringFromEEPROM(672);
    config.emonapi = ReadStringFromEEPROM(677);
    config.emonstring = ReadStringFromEEPROM(720);
    //end of emoncms configuration
    
		return true;
		
	}
	else
	{
		Serial.println("Configurarion NOT FOUND!!!!");
		return false;
	}
}

/*
**
**  NTP 
**
*/

//const int NTP_PACKET_SIZE = 48; 
//byte packetBuffer[ NTP_PACKET_SIZE]; 
//void NTPRefresh()
//{
//
//	
//
//
	//if (WiFi.status() == WL_CONNECTED)
	//{
		//IPAddress timeServerIP; 
		//WiFi.hostByName(config.ntpServerName.c_str(), timeServerIP); 
		////sendNTPpacket(timeServerIP); // send an NTP packet to a time server
//
//
		//Serial.println("sending NTP packet...");
		//memset(packetBuffer, 0, NTP_PACKET_SIZE);
		//packetBuffer[0] = 0b11100011;   // LI, Version, Mode
		//packetBuffer[1] = 0;     // Stratum, or type of clock
		//packetBuffer[2] = 6;     // Polling Interval
		//packetBuffer[3] = 0xEC;  // Peer Clock Precision
		//packetBuffer[12]  = 49;
		//packetBuffer[13]  = 0x4E;
		//packetBuffer[14]  = 49;
		//packetBuffer[15]  = 52;
		//UDPNTPClient.beginPacket(timeServerIP, 123); 
		//UDPNTPClient.write(packetBuffer, NTP_PACKET_SIZE);
		//UDPNTPClient.endPacket();
//
//
		//delay(1000);
//  
		//int cb = UDPNTPClient.parsePacket();
		//if (!cb) {
			//Serial.println("NTP no packet yet");
		//}
		//else 
		//{
			//Serial.print("NTP packet received, length=");
			//Serial.println(cb);
			//UDPNTPClient.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer
			//unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
			//unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
			//unsigned long secsSince1900 = highWord << 16 | lowWord;
			//const unsigned long seventyYears = 2208988800UL;
			//unsigned long epoch = secsSince1900 - seventyYears;
			//UnixTimestamp = epoch;
		//}
	//}
//}

void Second_Tick()
{
	AdminTimeOutCounter++;
	Refresh = true;
}
 

#endif

void DefaultConfig(){
    
    
    // DEFAULT CONFIG
		config.Language = "EN";
    config.ssid = "MyAP";
		config.password = "";
		config.dhcp = true;
		config.IP[0] = 192;config.IP[1] = 168;config.IP[2] = 1;config.IP[3] = 100;
		config.Netmask[0] = 255;config.Netmask[1] = 255;config.Netmask[2] = 255;config.Netmask[3] = 0;
		config.Gateway[0] = 192;config.Gateway[1] = 168;config.Gateway[2] = 1;config.Gateway[3] = 1;
		config.ntpServerName = "0.de.pool.ntp.org";
		config.Update_Time_Via_NTP_Every =  0;
		config.timezone = -10;
		config.daylight = true;
		config.DeviceName = "SmartBee Node Sensor";
		config.AutoTurnOff = false;
		config.AutoTurnOn = false;
		config.TurnOffHour = 0;
		config.TurnOffMinute = 0;
		config.TurnOnHour = 0;
		config.TurnOnMinute = 0;
    config.StatusLed = true;
    config.UpdateTime = 1;
    config.BatteryType = 0;
  
    config.NodeLocation = "Default location";
    //thingspeak configuration
    config.tsenabled = false;
    config.tssite="api.thingspeak.com";
    config.tsport = "80";
    config.tsapi="QUYFXZ0ORJ0OQ7LK";
    config.tsstring = "/update?api_key=TAPIKEY&field1=TEMPERATURE&field2=HUMIDITY&field3=BATMVOLT&field4=BATPERCENT&field5=HEAPSIZE&field6=UCOUNTER";
    //end of thingspeak configuration
    
    //emoncms configuration
    config.emonnodeID = 1;
    config.emonenabled = false;
    config.emonsite="www.emoncms.org";
    config.emonport = "80";
    config.emonapi="ff2f2329b15781545a8e973784c3e85b";
    config.emonstring = "/input/post.json?node=ENODEID&apikey=EAPIKEY&json={Temperature:TEMPERATURE,Humidity:HUMIDITY,Battery_mV:BATMVOLT,Battery_Percent:BATPERCENT,FreeRAM:HEAPSIZE,RetryCount:UCOUNTER";
    //end of emoncms configuration

}

void ClearEEPROM(int EepromSize){
  Serial.println("Erasing EEPROM!!!!");
	for ( int i = 0; i < EepromSize; i++ ) {
			EEPROM.write(i,0xFF); 
  }
}


static int BatteryPercent(int mV, int PowerType){
  float Percent; 
  float temp1;
  float temp2;
  switch (PowerType) {
    case 0:
        temp1 = mV - 2000;
        temp2 = 3000-2000;
        temp2 = temp2 * 10; 
        Percent = temp1 / temp2;
        Percent = Percent * 1000; 
        Serial.println ("AAA");
        Serial.println (Percent);
        Serial.println (mV);
        if (Percent >100){
          Percent = 100;
          }
        if (Percent < 0){
          Percent = 0;
          }
        break;
      case 1:
        temp1 = mV - 3000;
        temp2 = 3700-3000;
        temp2 = temp2 * 10;        
        Percent = temp1 / temp2;
        Percent = Percent * 1000;
        Serial.println ("Li-Ion");
        Serial.println (Percent);
        Serial.println (mV);
        if (Percent >100){
          Percent = 100;
          }
        if (Percent < 0){
          Percent = 0;
          }
        break;
      case 2:
        temp1 = mV - 3000;
        temp2 = 4000-3000;
        temp2 = temp2 * 10;        
        Percent = temp1 / temp2;
        Percent = Percent * 1000;
        Serial.println ("Ext Power");
        Serial.println (Percent);
        Serial.println (mV);
        if (Percent >100){
          Percent = 100;
          }
        if (Percent < 0){
          Percent = 0;
          }
        break;
        
  }
  return Percent;
}


int readADC(){
  float ad = 0;
  ad=analogRead(A0);
  ad = ad*4;
   ad = ad/920;  //for 3M33 Resistor input V max 4.33V 
  //ad = ad/1241;  //for 330kohm Resistor input V max 4.3V 
  //ad = ad/1135;    //for 270kohm Resistor input V max 3.7V 
  ad = ad *1000;
  return ad;
}