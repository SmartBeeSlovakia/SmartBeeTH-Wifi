#ifndef PAGE_MAIN_H
#define PAGE_MAIN_H
//
//   The MAIN PAGE
//
const char PAGE_main[] PROGMEM = R"=====(
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" href="style.css" type="text/css" />    
  <script src="microajax.js"></script>  
  <table border="0"  cellspacing="0" cellpadding="3" style="width:350px" > 
  <tr><td align="center"><H5>Temperature & Humidity Wifi node sensor</H5><br><hr></td></tr>
  <tr><td align="center"><a href="admin.html" style="width:290px" class="btn btn--m btn--bee" >Configuration</a><br></td></tr>
  <tr><td align="center"><br></td></tr>
  <tr><tr><td align="center"><h5><a href="http://www.i-control.sk" >&copy;2015  I-Control Slovakia</a></h5.<br></td></tr>
</table>
  
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
#endif


void filldynamicdata()
{        
    String values ="";
    values += "mydynamicdata|" + (String) + "This is filled by AJAX. Millis since start: " + (String) millis() + "|div\n";   // Build a string, like this:  ID|VALUE|TYPE
    server.send ( 200, "text/plain", values);   
}

void processMain()
{        
    if (server.args() > 0 )  // Are there any POST/GET Fields ? 
    {
       for ( uint8_t i = 0; i < server.args(); i++ ) {  // Iterate through the fields
            if (server.argName(i) == "firstname") 
            {
                 // Your processing for the transmitted form-variable 
                 String fName = server.arg(i);
            }
        }
    }
    server.send ( 200, "text/html", PAGE_main  ); 
}