//#ifndef PAGE_MAIN_H
//#define PAGE_MAIN_H
//
//   The MAIN PAGE
//


const char EN_PAGE_main[] PROGMEM = R"=====(
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" href="style.css" type="text/css" />    
  <script src="microajax.js"></script>  
  <table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
  <tr><td align="center"><img src="data:image/gif;base64,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" width="348" height="108" alt="SmartBee Logo"><br></td></tr>
  
  
  <tr><td align="center"><H5>Temperature & Humidity Wifi node sensor</H5><br><hr></td></tr>
  <tr><td align="center"><a href="/info"   style="width:290px"  class="btn btn--m btn--bee" >Device Information</a><br></td></tr>
  <tr><td align="center"><a href="/admin" style="width:290px" class="btn btn--m btn--bee" >Configuration</a><br></td></tr>
  <tr><td align="center"><br></td></tr>
  <tr><td align="center"><h5><a href="http://www.smartbee.eu" >&copy;2016  SmartBee Slovakia</a></h5.<br></td></tr>
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


const char SK_PAGE_main[] PROGMEM = R"=====(
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <link rel="stylesheet" href="style.css" type="text/css" />    
  <script src="microajax.js"></script>  
  <table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
  <tr><td align="center"><img src="data:image/gif;base64,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" width="348" height="108" alt="SmartBee Logo"><br></td></tr>
  
  
  <tr><td align="center"><H5>Wifi sensor teploty a vlhkosti</H5><br><hr></td></tr>
  <tr><td align="center"><a href="/info"   style="width:290px"  class="btn btn--m btn--bee" >Informácie o zariadení</a><br></td></tr>
  <tr><td align="center"><a href="/admin" style="width:290px" class="btn btn--m btn--bee" >Konfigurácia</a><br></td></tr>
  <tr><td align="center"><br></td></tr>
  <tr><tr><td align="center"><h5><a href="http://www.smartbee.eu" >&copy;2016  SmartBee Slovakia</a></h5.<br></td></tr>
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
//#endif


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
    
    if (config.Language=="SK") {
    server.send ( 200, "text/html", SK_PAGE_main  );
    }
    if (config.Language=="EN") {
    server.send ( 200, "text/html", EN_PAGE_main  );
    }
    else{
    server.send ( 200, "text/html", EN_PAGE_main  );
    }
    
   
}