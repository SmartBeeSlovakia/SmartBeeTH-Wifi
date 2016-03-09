//
//  HTML Factory reset PAGE
//

const char Page_FactoryResetPage[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="admin.html"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Factory reset to default</strong>
<hr>
<form action="" method="get">
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr>
	<td align="right">Reset: </td>
	<td><input type="checkbox" id="resetenabled" name="resetenabled"></td>
</tr>
<hr>
<tr>
<td align="center"><input type="submit" style="width:120px" class="btn btn--m btn--bee" value="Yes"></td>
<td align="center"><a href="admin.html" style="width:120px" class="btn btn--m btn--bee" >No</a></td>
</tr>
</table>
</form>
<hr>



<script>


 

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
    setValues("/admin/factoryresetvalues");
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====";


const char PAGE_ReloadReset[] PROGMEM = R"=====(
<meta http-equiv="refresh" content="5; URL=main.html">
Please Wait....Configuring and Restarting.
)=====";





void send_factory_reset_html()
{

  if (server.args() > 0 )  // Save Settings
	{
		String temp = "";
    config.ResetEnabled = false;
		for ( uint8_t i = 0; i < server.args(); i++ ) {
			if (server.argName(i) == "resetenabled") config.ResetEnabled = true;
			
		}
		 server.send ( 200, "text/html", PAGE_ReloadReset );
  	//Erase full eeprom
    ClearEEPROM(2048);
    DefaultConfig();
    WriteConfig();
  	Serial.println("Factory reset applied ");
    AdminTimeOutCounter=0;;
		
	}
	else
	{
		server.send ( 200, "text/html", Page_FactoryResetPage ); 
	}
	Serial.println(__FUNCTION__);

}



//
//   FILL THE PAGE WITH VALUES
//

void send_factory_reset_values_html()
{
	String values ="";
  values += "resetenabled|" +  (String) (config.ResetEnabled ? "checked" : "") + "|chk\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 
}