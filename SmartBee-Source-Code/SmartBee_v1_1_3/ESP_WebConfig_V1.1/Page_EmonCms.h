//
//  EN HTML PAGE
//

const char EN_PAGE_AdminEmonCmsSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>EmonCMS services</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">Enable</td><td><input type="checkbox" id="emonenabled" name="emonenabled"></td></tr>
<tr><td align="left" <hr></td></tr>
<tr><td align="right">Node ID :</td><td>
<select  id="emonnodeid" name="emonnodeid">
    <option value="1">1</option>
		<option value="2">2</option>
		<option value="3">3</option>
		<option value="4">4</option>
		<option value="5">5</option>
		<option value="6">6</option>
		<option value="7">7</option>
		<option value="8">8</option>
		<option value="9">9</option>
    <option value="10">10</option>
    <option value="11">11</option>
    <option value="12">12</option>
    <option value="13">13</option>
    <option value="14">14</option>
    <option value="15">15</option>
    <option value="16">16</option>
    <option value="17">17</option>
    <option value="18">18</option>
    <option value="19">19</option>
    <option value="20">20</option>
    <option value="21">21</option>
    <option value="22">22</option>
    <option value="23">23</option>
    <option value="24">24</option>
    <option value="25">25</option>
    <option value="26">26</option>
    <option value="27">27</option>
    <option value="28">28</option>
    <option value="29">29</option>
    <option value="30">30</option>
    <option value="31">31</option>
    <option value="32">32</option>
    
	</select>
</td></tr>
<tr><td align="left" ></td></tr>
<tr><td align="right" >Site/IP:</td><td><input type="text" id="emonsite" name="emonsite" value="" maxlength="30"></td></tr>
<tr><td align="left" ></td></tr>
<tr><td align="right">Port:</td><td><input type="text" id="emonport" name="emonport" value="" maxlength="4"></td></tr>
<tr><td align="left" </td></tr>
<tr><td align="right">API key:</td><td><input type="text" id="emonapi" name="emonapi" value="" maxlength="32"></td></tr>
<tr><td align="left" ></td></tr>
<tr><td align="right">String:</td><td><input type="text" id="emonstring" name="emonstring" value="" maxlength="200"></td></tr>
</table>
<hr>
<strong>Variables</strong>
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">Node ID: </td><td align="left"><b>ENODEID</b></td></tr>
<tr><td align="right">API Key: </td><td align="left"><b>EAPIKEY</b></td></tr>
<tr><td align="right">Temperature: </td><td align="left"><b>TEMPERATURE</b></td></tr>
<tr><td align="right">Humidity: </td><td align="left"><b>HUMIDITY</b></td></tr><tr>
<td align="right">Battery(mV): </td><td align="left"><b>BATMVOLT</b></td></tr>
<tr><td align="right">Battery(%): </td><td align="left"><b>BATPERCENT</b></td></tr>
<tr><td align="right">Free RAM: </td><td align="left"><b>HEAPSIZE</b></td></tr>
<tr><td align="right">Retry Count: </td><td align="left"><b>UCOUNTER</b></td></tr>
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
				setValues("/admin/emoncmsvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";




//
//  SK HTML PAGE
//

const char SK_PAGE_AdminEmonCmsSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Služby EmonCMS</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">Zapnúť</td><td><input type="checkbox" id="emonenabled" name="emonenabled"></td></tr>
<tr><td align="left" <hr></td></tr>
<tr><td align="right">ID nódu :</td><td>
<select  id="emonnodeid" name="emonnodeid">
    <option value="1">1</option>
		<option value="2">2</option>
		<option value="3">3</option>
		<option value="4">4</option>
		<option value="5">5</option>
		<option value="6">6</option>
		<option value="7">7</option>
		<option value="8">8</option>
		<option value="9">9</option>
    <option value="10">10</option>
    <option value="11">11</option>
    <option value="12">12</option>
    <option value="13">13</option>
    <option value="14">14</option>
    <option value="15">15</option>
    <option value="16">16</option>
    <option value="17">17</option>
    <option value="18">18</option>
    <option value="19">19</option>
    <option value="20">20</option>
    <option value="21">21</option>
    <option value="22">22</option>
    <option value="23">23</option>
    <option value="24">24</option>
    <option value="25">25</option>
    <option value="26">26</option>
    <option value="27">27</option>
    <option value="28">28</option>
    <option value="29">29</option>
    <option value="30">30</option>
    <option value="31">31</option>
    <option value="32">32</option>
    
	</select>
</td></tr>
<tr><td align="left" ></td></tr>
<tr><td align="right" >Stránka/IP:</td><td><input type="text" id="emonsite" name="emonsite" value="" maxlength="30"></td></tr>
<tr><td align="left" ></td></tr>
<tr><td align="right">Port:</td><td><input type="text" id="emonport" name="emonport" value="" maxlength="4"></td></tr>
<tr><td align="left" </td></tr>
<tr><td align="right">API kľúč:</td><td><input type="text" id="emonapi" name="emonapi" value="" maxlength="32"></td></tr>
<tr><td align="left" ></td></tr>
<tr><<td><textarea cols ="21" rows="8" id="emonstring" name="emonstring" value="" maxlength="200"></textarea></td></tr>
</table>
<hr>
<strong>Premenné</strong>
<table border="0"  cellspacing="0" cellpadding="3" >
<tr><td align="right">ID nódu: </td><td align="left"><b>ENODEID</b></td></tr>
<tr><td align="right">API Kľúč: </td><td align="left"><b>EAPIKEY</b></td></tr>
<tr><td align="right">Teplota: </td><td align="left"><b>TEMPERATURE</b></td></tr>
<tr><td align="right">Vlhkosť: </td><td align="left"><b>HUMIDITY</b></td></tr><tr>
<td align="right">Batéria(mV): </td><td align="left"><b>BATMVOLT</b></td></tr>
<tr><td align="right">Batéria(%): </td><td align="left"><b>BATPERCENT</b></td></tr>
<tr><td align="right">Pamäť: </td><td align="left"><b>HEAPSIZE</b></td></tr>
<tr><td align="right">Počítadlo: </td><td align="left"><b>UCOUNTER</b></td></tr>
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
				setValues("/admin/emoncmsvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";


void send_emoncms_html()
{
	
	if (server.args() > 0 )  // Save Settings
	{
		config.emonenabled = false;
    String temp = "";
		for ( uint8_t i = 0; i < server.args(); i++ ) {
			if (server.argName(i) == "emonenabled") config.emonenabled = true;
      if (server.argName(i) == "emonnodeid") config.emonnodeID =  server.arg(i).toInt();
			if (server.argName(i) == "emonsite") config.emonsite = urldecode(server.arg(i)); 
			if (server.argName(i) == "emonport") config.emonport = urldecode(server.arg(i));
			if (server.argName(i) == "emonapi") config.emonapi = urldecode(server.arg(i));
			if (server.argName(i) == "emonstring") config.emonstring = urldecode(server.arg(i));
		}
		WriteConfig();
		AdminTimeOutCounter=0;
	}
  if (config.Language=="SK") {
    server.send ( 200, "text/html", SK_PAGE_AdminEmonCmsSettings  );
  }
  if (config.Language=="EN") {
    server.send ( 200, "text/html", EN_PAGE_AdminEmonCmsSettings  );
  }
  else{
    server.send ( 200, "text/html", EN_PAGE_AdminEmonCmsSettings  );
  }
	Serial.println(__FUNCTION__); 
	
	
}


//
//   FILL THE PAGE WITH VALUES
//

void send_emoncms_configuration_values_html()
{
	String values ="";
  values += "emonenabled|" +  (String) (config.emonenabled ? "checked" : "") + "|chk\n";
  values += "emonnodeid|" +  (String)  config.emonnodeID +  "|input\n";
	values += "emonsite|" +  (String)  config.emonsite +  "|input\n";
	values += "emonport|" +  (String)  config.emonport +  "|input\n";
	values += "emonapi|" +   (String) config.emonapi +  "|input\n";
	values += "emonstring|" +  (String)  config.emonstring +  "|input\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
}