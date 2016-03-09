//
//  EN HTML PAGE
//

const char EN_PAGE_AdminThingSpeakSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>ThingSpeak services</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr>
	<td align="right">Enable</td>
	<td><input type="checkbox" id="tsenabled" name="tsenabled"></td>
</tr>

<tr>
	<td align="left" <hr></td>
</tr>

<tr>
<td align="right" >Site/IP:</td>
	<td><input type="text" id="tssite" name="tssite" value="" maxlength="30"></td>
</tr>

<tr>
	<td align="left" ></td>
</tr>

<tr>
<td align="right">Port:</td>
 <td><input type="text" id="tsport" name="tsport" value="" maxlength="4"></td>
</tr>

<tr>
	<td align="left" </td>
</tr>

<tr>
<td align="right">API key:</td>
	<td><input type="text" id="tsapi" name="tsapi" value="" maxlength="16"></td>
</tr>

<tr>
	<td align="left" ></td>
</tr>

<tr>
<td align="right">String:</td>
	<td><textarea cols ="21" rows="8" id="tsstring" name="tsstring" value="" maxlength="200"></textarea></td>
</tr>


</table>
<hr>
<strong>Variables</strong>

<table border="0"  cellspacing="0" cellpadding="3" >


<tr>
<td align="right">API Key: </td>
<td align="left"><b>TAPIKEY</b></td>
</tr>

<tr>
<td align="right">Temperature: </td>
	<td align="left"><b>TEMPERATURE</b></td>
</tr>

<tr>
<td align="right">Humidity: </td>
	<td align="left"><b>HUMIDITY</b></td>
</tr>

<tr>
<td align="right">Battery(mV): </td>
	<td align="left"><b>BATMVOLT</b></td>
</tr>

<tr>
<td align="right">Battery(%): </td>
	<td align="left"><b>BATPERCENT</b></td>
</tr>
<tr>
<td align="right">Free Mem: </td>
	<td align="left"><b>HEAPSIZE</b></td>
</tr>
<tr>
<td align="right">Retry Count: </td>
	<td align="left"><b>UCOUNTER</b></td>
</tr>


<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--bee" value="Save"></td></tr>
</table>
<hr>
</form>
<script>

 

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				setValues("/admin/thingspeakvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";







//
//  SK HTML PAGE
//

const char SK_PAGE_AdminThingSpeakSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Služby ThingSpeak</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr>
	<td align="right">Zapnúť</td>
	<td><input type="checkbox" id="tsenabled" name="tsenabled"></td>
</tr>

<tr>
	<td align="left" <hr></td>
</tr>

<tr>
<td align="right" >Stránka/IP:</td>
	<td><input type="text" id="tssite" name="tssite" value="" maxlength="30"></td>
</tr>

<tr>
	<td align="left" ></td>
</tr>

<tr>
<td align="right">Port:</td>
 <td><input type="text" id="tsport" name="tsport" value="" maxlength="4"></td>
</tr>

<tr>
	<td align="left" </td>
</tr>

<tr>
<td align="right">API kľúč:</td>
	<td><input type="text" id="tsapi" name="tsapi" value="" maxlength="16"></td>
</tr>

<tr>
	<td align="left" ></td>
</tr>

<tr>
<td align="right">Retazec:</td>
	<td><textarea cols ="21" rows="8" id="tsstring" name="tsstring" value="" maxlength="200"></textarea></td>
</tr>


</table>
<hr>
<strong>Premenné</strong>

<table border="0"  cellspacing="0" cellpadding="3" >


<tr>
<td align="right">API Kľúč: </td>
<td align="left"><b>TAPIKEY</b></td>
</tr>

<tr>
<td align="right">Teplota: </td>
	<td align="left"><b>TEMPERATURE</b></td>
</tr>

<tr>
<td align="right">Vlhkosť: </td>
	<td align="left"><b>HUMIDITY</b></td>
</tr>

<tr>
<td align="right">Batéria(mV): </td>
	<td align="left"><b>BATMVOLT</b></td>
</tr>

<tr>
<td align="right">Batéria(%): </td>
	<td align="left"><b>BATPERCENT</b></td>
</tr>
<tr>
<td align="right">Pamäť: </td>
	<td align="left"><b>HEAPSIZE</b></td>
</tr>
<tr>
<td align="right">Počítadlo: </td>
	<td align="left"><b>UCOUNTER</b></td>
</tr>


<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--bee" value="Uložiť"></td></tr>
</table>
<hr>
</form>
<script>

 

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				setValues("/admin/thingspeakvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";




// Functions for this Page

//void send_thingspeak_value_html()
//{
		
//	String values ="";
//	values += "tssite|" + (String) config.tssite + "|div\n";
//  values += "tsport|" + (String) config.tsport + "|div\n";
//  values += "tsapi|" + (String) config.tsapi + "|div\n";
//  values += "tsstring|" + (String) config.tsstring + "|div\n";
//	server.send ( 200, "text/plain", values);
//	Serial.println(__FUNCTION__); 
	
//}

void send_thingspeak_html()
{
	
	if (server.args() > 0 )  // Save Settings
	{
		config.tsenabled = false;
    String temp = "";
		for ( uint8_t i = 0; i < server.args(); i++ ) {
			if (server.argName(i) == "tsenabled") config.tsenabled = true;
			if (server.argName(i) == "tssite") config.tssite = urldecode(server.arg(i)); 
			if (server.argName(i) == "tsport") config.tsport = urldecode(server.arg(i));
			if (server.argName(i) == "tsapi") config.tsapi = urldecode(server.arg(i));
			if (server.argName(i) == "tsstring") config.tsstring = urldecode(server.arg(i));
		}
		WriteConfig();
		AdminTimeOutCounter=0;
	}
  if (config.Language=="SK") {
    server.send ( 200, "text/html", SK_PAGE_AdminThingSpeakSettings  );
  }
  if (config.Language=="EN") {
    server.send ( 200, "text/html", EN_PAGE_AdminThingSpeakSettings  );
  }
  else{
    server.send ( 200, "text/html", EN_PAGE_AdminThingSpeakSettings  );
  }
	Serial.println(__FUNCTION__); 
	
	
}


//
//   FILL THE PAGE WITH VALUES
//

void send_thingspeak_configuration_values_html()
{
	String values ="";
  values += "tsenabled|" +  (String) (config.tsenabled ? "checked" : "") + "|chk\n";
	values += "tssite|" +  (String)  config.tssite +  "|input\n";
	values += "tsport|" +  (String)  config.tsport +  "|input\n";
	values += "tsapi|" +   (String) config.tsapi +  "|input\n";
	values += "tsstring|" +  (String)  config.tsstring +  "|input\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
}