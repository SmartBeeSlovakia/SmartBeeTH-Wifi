//
//  EN HTML PAGE
//
const char EN_PAGE_AdminGeneralSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>General Settings</strong>
<hr>
<form action="" method="post">
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr>
<td align="right">Node ID: </td>
 <td><h6><span id="nodeid"></h6></span></td>
</tr>
<tr>
	<td align="right">Device name: </td>
	<td><input type="text" id="devicename" name="devicename" value="" maxlength="20"></td>
</tr>
<tr>
	<td align="right">Location: </td>
	<td><input type="text" id="deviceloc" name="deviceloc" value="" maxlength="20"></td>
</tr>
 <tr>
	<td align="right">Update time: </td>
	<td>
	<select  id="updatetime" name="updatetime">
    <option value="0">Off</option>
		<option value="1">1 min.</option>
		<option value="2">2 min.</option>
		<option value="5">5 min.</option>
		<option value="10">10 min.</option>
		<option value="15">15 min.</option>
		<option value="20">20 min.</option>
		<option value="30">30 min.</option>
		<option value="45">45 min.</option>
    <option value="60">1 hour</option>
	</select>
	</td>
</tr>
 <tr>
	<td align="right">Battery type: </td>
	<td>
	<select  id="battype" name="battype">
    <option value="0" disabled>AA - Alkaline</option>
		<option value="1" disabled>14500 Li-Ion</option>
    <option value="2" disabled>Ext. Power</option>
	</select>
	</td>
</tr>
<tr>
	<td align="right"> Status LED:</td>
	<td><input type="checkbox" id="ledenabled" name="ledenabled"></td>
</tr>
<br>
<br>
<tr>
	<td align="right">Factory reset: </td>
	<td>
	<select  id="factoryreset" name="factoryreset">
    <option value="0">No</option>
		<option value="1">Yes</option>
	</select>
	</td>
</tr>
</table>
<hr>
<br>

<table border="0"  cellspacing="0" cellpadding="3" style="width:350px">
<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--bee" value="Save"></td></tr>
</table>
</form>
<br>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px">
<tr><td align="center"><h5><a href="http://www.smartbee.eu" >&copy;2016  SmartBee Slovakia</a></h5.<br></td></tr>
</table>
<script>

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				setValues("/admin/generalvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";

//
//  SK HTML PAGE
//
const char SK_PAGE_AdminGeneralSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Hlavné nastavenia</strong>
<hr>
<form action="" method="post">
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr>
<td align="right">ID nódu: </td>
 <td><span id="nodeid"></span></td>
</tr>
<tr>
	<td align="right">Meno nódu: </td>
	<td><input type="text" id="devicename" name="devicename" value="" maxlength="20"></td>
</tr>
<tr>
	<td align="right">Umiestnenie: </td>
	<td><input type="text" id="deviceloc" name="deviceloc" value="" maxlength="20"></td>
</tr>
 <tr>
	<td align="right">Odosielanie: </td>
	<td>
	<select  id="updatetime" name="updatetime">
    <option value="0">Off</option>
		<option value="1">1 min.</option>
		<option value="2">2 min.</option>
		<option value="5">5 min.</option>
		<option value="10">10 min.</option>
		<option value="15">15 min.</option>
		<option value="20">20 min.</option>
		<option value="30">30 min.</option>
		<option value="45">45 min.</option>
    <option value="60">1 hour</option>
	</select>
	</td>
</tr>
 <tr>
	<td align="right">Napájanie: </td>
	<td>
	<select  id="battype" name="battype">
    <option value="0" disabled>AA - Alkalické</option>
		<option value="1" disabled>14500 Li-Ion</option>
    <option value="2" disabled>Ext. Napájanie</option>
	</select>
	</td>
</tr>
<tr>
	<td align="right"> Stavová LED:</td>
	<td><input type="checkbox" id="ledenabled" name="ledenabled"></td>
</tr>
<br>
<br>
<tr>
	<td align="right">Z výroby: </td>
	<td>
	<select  id="factoryreset" name="factoryreset">
    <option value="0">Nie</option>
		<option value="1">Áno</option>
	</select>
	</td>
</tr>
</table>
<hr>
<br>

<table border="0"  cellspacing="0" cellpadding="3" style="width:350px">
<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--bee" value="Uložiť"></td></tr>
</table>
</form>
<br>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px">
<tr><td align="center"><h5><a href="http://www.smartbee.eu" >&copy;2016  SmartBee Slovakia</a></h5.<br></td></tr>
</table>
<script>

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				setValues("/admin/generalvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";


const char PAGE_WaitAndDefault[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="refresh" content="6; URL=/">
Please Wait....    Saving factory setting and Restarting.
)=====";


// Functions for this Page
void send_devicename_value_html()
{
		
	String values ="";
	values += "devicename|" + (String) config.DeviceName + "|div\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
	
}

void send_general_html()
{
	
	if (server.args() > 0 )  // Save Settings
	{
		config.StatusLed = false;
    config.ResetEnabled = false;
		String temp = "";
		for ( uint8_t i = 0; i < server.args(); i++ ) 
    {
			if (server.argName(i) == "devicename") config.DeviceName = urldecode(server.arg(i)); 
      if (server.argName(i) == "deviceloc") config.NodeLocation = urldecode(server.arg(i)); 
			if (server.argName(i) == "ledenabled") config.StatusLed = true; 
			if (server.argName(i) == "updatetime") config.UpdateTime =  server.arg(i).toInt(); 
      if (server.argName(i) == "battype") config.BatteryType =  server.arg(i).toInt();
      if (server.argName(i) == "language") config.Language = urldecode(server.arg(i)); 
      if (server.argName(i) == "factoryreset") 
      {
        config.ResetEnabled = server.arg(i).toInt();  
		    if (config.ResetEnabled == 1)
        {
          server.send ( 200, "text/html", PAGE_WaitAndDefault );
        }
        else
        {
          WriteConfig();
        }
      }
    }
		
		firstStart = true;
	}
  
  if (config.Language=="SK") {
    server.send ( 200, "text/html", SK_PAGE_AdminGeneralSettings  );
    }
    if (config.Language=="EN") {
    server.send ( 200, "text/html", EN_PAGE_AdminGeneralSettings  );
    }
    else{
    server.send ( 200, "text/html", EN_PAGE_AdminGeneralSettings  );
  }
  
	Serial.println(__FUNCTION__); 	
}

void send_general_configuration_values_html()
{
	String values ="";
	values += "devicename|" +  (String)  config.DeviceName +  "|input\n";
  values += "deviceloc|" +  (String)  config.NodeLocation +  "|input\n";
	values += "updatetime|" +  (String)  config.UpdateTime +  "|input\n";
  values += "nodeid|" + (String)  config.NodeID +  "|div\n";
	values += "ledenabled|" +  (String) (config.StatusLed ? "checked" : "") + "|chk\n";
  values += "factoryreset|" +  (String) config.ResetEnabled + "|input\n";
  values += "battype|" +  (String) config.BatteryType + "|input\n";
  values += "language|" +  (String)  config.Language +  "|input\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
}