

//
//  HTML PAGE
//

const char EN_PAGE_AdminMainPage[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<a href="/main"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Configuration</strong>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td align="center"><a href="/general" style="width:290px" class="btn btn--m btn--bee" >General Setings</a><br></td></tr>
<tr><td align="center"><a href="/config" style="width:290px" class="btn btn--m btn--bee" >Network Setings</a><br></td></tr>
<tr><td align="center"><a href="/smartbeecloud"   style="width:290px"  class="btn btn--m btn--bee" >SmartBee services</a><br></td></tr>
<tr><td align="center"><a href="thingspeak.html"   style="width:290px"  class="btn btn--m btn--bee" >ThingSpeak services</a><br></td></tr>
<tr><td align="center"><a href="emoncms.html"   style="width:290px"  class="btn btn--m btn--bee" >EmonCms services</a><br></td></tr>
<tr><td align="center"><a href="custom.html"   style="width:290px"  class="btn btn--m btn--bee" >Custom script</a><br></td></tr>
<tr><td align="center"><a href="/firmware"   style="width:290px"  class="btn btn--m btn--bee" >Firmware update</a><br></td></tr>
</table>
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
				// Do something after load...
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

</script>

)=====";


const char SK_PAGE_AdminMainPage[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="style.css" type="text/css" />    
<script src="microajax.js"></script> 
<a href="/main"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Konfigurácia</strong>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td align="center"><a href="/general" style="width:290px" class="btn btn--m btn--bee" >Hlavné nastavenia</a><br></td></tr>
<tr><td align="center"><a href="/config" style="width:290px" class="btn btn--m btn--bee" >Sieťové nastavenia</a><br></td></tr>
<tr><td align="center"><a href="/smartbeecloud"   style="width:290px"  class="btn btn--m btn--bee" >Služby SmartBee</a><br></td></tr>
<tr><td align="center"><a href="thingspeak.html"   style="width:290px"  class="btn btn--m btn--bee" >Služby ThingSpeak</a><br></td></tr>
<tr><td align="center"><a href="emoncms.html"   style="width:290px"  class="btn btn--m btn--bee" >Služby EmonCMS</a><br></td></tr>
<tr><td align="center"><a href="custom.html"   style="width:290px"  class="btn btn--m btn--bee" >Uživ. Skript</a><br></td></tr>
<tr><td align="center"><a href="/firmware"   style="width:290px"  class="btn btn--m btn--bee" >Aktualizácia firmware</a><br></td></tr>
</table>
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
				// Do something after load...
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

</script>

)=====";


void processAdmin()
{
if (config.Language=="SK") {
    server.send ( 200, "text/html", SK_PAGE_AdminMainPage  );
    }
    if (config.Language=="EN") {
    server.send ( 200, "text/html", EN_PAGE_AdminMainPage  );
    }
    else{
    server.send ( 200, "text/html", EN_PAGE_AdminMainPage  );
    }

}