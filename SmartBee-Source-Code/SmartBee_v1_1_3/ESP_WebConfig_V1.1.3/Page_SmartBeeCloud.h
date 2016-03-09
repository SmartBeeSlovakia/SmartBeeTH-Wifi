

//
//  HTML PAGE
//

const char PAGE_SmartBeeCloudPage[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>SmartBee Cloud</strong>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td align="center"><a href="/sbcregister" style="width:290px" class="btn btn--m btn--bee" >Register device</a><br></td></tr>
<tr><td align="center"><a href="/sbcsetings" style="width:290px" class="btn btn--m btn--bee" >Configuration</a><br></td></tr>
<tr><td align="center"><a href="/sbcinfo"   style="width:290px"  class="btn btn--m btn--bee" >Information</a><br></td></tr>
</table>
<hr>

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


