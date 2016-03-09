
//
//   EN - The Firmware update page
//
const char EN_PAGE_Firmware[] PROGMEM = R"=====(
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Firmware update</strong>
  <hr>  
  <form method="POST" action="/update" enctype="multipart/form-data">
  <table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
  <tr><td align="center"><input type="file" name="update"></td></tr>
  <tr><td align="center"><input type="submit" style="width:150px" class="btn btn--m btn--bee" value="Update"></td></tr>
  <tr><td align="center"><br></td></tr>
</table>
</form>  
  
   <script>                

		window.onload = function ()
		{
			load("style.css","css", function() 
			{
				load("microajax.js","js", function() 
				{
						//setValues("/admin/filldynamicdata");  //-- this function calls the function on the ESP      
				});
			});
		}
		function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



   </script>

)=====";

//
//   SK - The Firmware update page
//
const char SK_PAGE_Firmware[] PROGMEM = R"=====(
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <a href="/admin"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Aktualizácia firmware</strong>
  <hr>  
  <form method="POST" action="/update" enctype="multipart/form-data">
  <table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
  <tr><td align="center"><input type="file" name="update"></td></tr>
  <tr><td align="center"><input type="submit" style="width:150px" class="btn btn--m btn--bee" value="Aktualizovať"></td></tr>
  <tr><td align="center"><br></td></tr>
</table>
</form>  
  
   <script>                

		window.onload = function ()
		{
			load("style.css","css", function() 
			{
				load("microajax.js","js", function() 
				{
						//setValues("/admin/filldynamicdata");  //-- this function calls the function on the ESP      
				});
			});
		}
		function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



   </script>

)=====";






