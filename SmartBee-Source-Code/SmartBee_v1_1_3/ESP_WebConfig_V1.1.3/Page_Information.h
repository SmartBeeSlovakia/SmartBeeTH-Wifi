#ifndef PAGE_INFOMATION_H
#define PAGE_INFOMATION_H


//
//   The EN HTML PAGE
//
const char EN_PAGE_Information[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="style.css" type="text/css" />
<script src="microajax.js"></script> 
<a href="/main"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Device information</strong>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td align="right"><b>Device</b></td></tr>
<tr><td align="right">Node ID: </td><td><span id="nodeid"></span></td></tr>
<tr><td align="right">Type:</td><td><span id="devicetype"></span></td></tr>
<tr><td align="right">Name:</td><td><span id="devicename"></span></td></tr>
<tr><td align="right">Location: </td><td><span id="deviceloc"></span></td></tr>
<tr><td align="right">Firmware:</td><td><span id="devicefw"></span></td></tr>
<tr><td align="right">Free RAM:</td><td><span id="deviceheap"></span></td></tr>
<tr><td align="right">Update time:</td><td><span id="deviceuptime"> min.</span></td></tr>
<tr><td align="right">Battery:</td><td><span id="devicebat"> min.</span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAAK/INwWK6QAAAAlwSFlzAAASdAAAEnQB3mYfeAAAABl0RVh0U29mdHdhcmUAQWRvYmUgSW1hZ2VSZWFkeXHJZTwAAALMSURBVFhH7ZZRSBNxHMf/dze8c7PhNkhC5dpWMVkDH8wWk7KNyS4r6b0etB566SFkm9jDDKu1yIFCPUQQgmhlFhS0wB6CEBKxQCKXcw+CVxqEDEImbvv1O9Po8e4v7F46+HHc7vf9/L//3//3v/0J2f21d/cIOoLF7/efs1qtXpQfwWDpMJQqURRb5+bm7mzLT+B9HyWKTubxeM5mMpnb2+rjeD9AR6JUud3u0+l0+tY/BpyUKDoZGjiDBvp1M4A9EMpmsw9KpVKzzWYLoBE73VQoVS6Xq31hYeEuGjAbDAalB8q7BDsGAMDC8/xJNOCgnAudzIlLkFldHcQK2InFcqzsFRAbG6WloaE3RUL6LhFypezfgVqHQ/qWSAC0tECysvIVGqiiqyWlqrahQZJjsXWoroY4w4wjxkyJopP9NWC1Qtxg0MGAsgTJ5Dr4fJAQBB0MYBPK3d3rQAjECdHBwE4FsAkTRqMOBv43oe5N6PFIcji81YQ3CXmGm3kP3YamV3lXIpGcYuAGIQ8RU74zYU1d3eHPy8vDhfn5jWIkAj+mphafp1JhNGGln49Kpa2qyvV1dvY9/g3DpizDxtoaQC6HD5swMTIygBiTShRVmjDY1RWH6WnIT0xAYWwMihibo6NQmJyEpfHxfBCPalRklSLn41Bo6ntnJxRjMYBo9E/09EC+txcWOzqgX5LuIUtQydOc1vzI7Z5J8zwUmpoAgkGAtjaAQAB+2e3wyWSCa17vGFJrNJNVCnzXRfHJDMtCDrsfOA6gogKUnbCCkUIDwfr6PmTtV8nTnNZ0yGS6+tRolL/ggD8xFCPK4B8ZBpJm81vCsl1ItWgmqxQoHX65VRB6hznuw2uGKbzDgV+ybG6A51/g8TiK70MqWdRpIiq7caZhL8fFT3Hc/YMc14fPPfj7eYwKarIGYTXmtmMo5b6IcQHjKAajgbGV+hvcUCB/ku7JswAAAABJRU5ErkJggg==" width="32" height="32"></td><td><span id="tempvalue"> &deg;C</span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAACB1BMVEUAc+8Ac/AAdO8AdPAAde8AdfAAdu8AdvAAd/AAePABdPABde8BdfABdu8BdvABePACde8Cdu8Cd+8CePADd/ADevAGePAHefAHevAIevAKevAKe/ALfPALfPEMfPEMffANffEQf/ERgPESgPETgPATgPEUgPEUgvEZhfEahPEbhfEchPEchvEdhfIehvIeh/EiiPIiifIjifIjivImi/IojPIpjfIqjfIrjvMukfMvj/MwkfIykfMzkvM0kvM0k/M1lPM2k/M2lPM5lfM8lvM9mPM/mfNAmfNCm/NFnPRGnfRInfROofRSovVSpPVTovRUpPVap/VaqPVcqPRdqPVfqfVgqfVgq/Viq/VlrfVnrvZorvZssfZws/ZztfZ3t/d6uPd+uveCvfiEv/iGv/eHwPiKwfiMwviOw/iVx/mZyfmayfidy/mezPmfzPmizvmo0fqq0fqs0/qt1Pqv1fux1vq12Pq12Pu32fq62vu62/u83Pu+3fvA3vvA3vzB3vvG4PzL4/zL5PzO5vzT6PzU6PzW6f3W6v3X6v3Y6v3Z6/3a6v3b7f3d7f3e7v3f7v3g7/3h7/3k8f3l8f3p9P7q9P7r9P3s9f7v9v7w+P7x+P7y+P7z+P/z+f70+P70+f70+v72+v73+/74+/74+//4/P/5/P/6/P/6/f77/f/9/v/+//////+oDCohAAABcElEQVR4AWNYQwAMgIJV0xbjVbC6PrRwOT4FLZ5cNjWrcSuYGiXGyufTi1PBskwVdk4Oyfg5uBQ0WLFwcnKyaRetwq5gSogIBycQ8Hl0YlWwKkeRnRME2KUTF2JT0ObCygkBrKZ1WBQsS5ZmhyrgEImegamg2Y4VKs3JwapXiaFgWaoEB9QAJSV2wagF6Ar63FhgFhhGqDMbNaIpWF2iDHeBUlYQu3jaalQFSxKEOGEKpHJy5ZgDZqMqmOvPAlcgW1Stz+QwAVXBbG+4Anaj1joDBsseVAULgrlhBojHLi1WY3SdjKpgeYowBwc/BwcHq7hvx/w4YYHwhWjerNZiFzWz1VC3TuhaVWHCKpuzGk3B9DA+duOkqqZJK2aVOfOyuPdjBHWtDTO7TmReaX6MES+zbsEqzMgqMGdhZZdRVRBhZdbMmIcluheVe8nzMDMycks65s/FmqJWTcwOdLKw90tvX4kz2c+d2N0/cxV18yYA0WsVGCmzwMQAAAAASUVORK5CYII=" width="32" height="32"></td><td><span id="humvalue"> %</span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAADpklEQVRYhe2W229UVRSHv73PPnNrZ9rpQFsdKC2VjkKIVJsGE/Ea9MkYg/bJ/8s3nnz3DzB4iTGIEpASSpi2Q2grdUrndoY597OPD3Wa1hRG0pB56Xo5Zye/tdaXtfZeWSKOY/ppsq/ZjwAA9aIO8xffuQS8BpjACSAA/gZCYOn3367feKkAQRCcnymVzillGhOTkxeklNn1R49uOo5dv3f3rgBeCED0egUXZt8qAV8Al4Ehy7Ky1375dabVatFqtbAsC9d1KRaLfL3wZTmXy7WBFvA98N2ft289OBTA+x9+FL9x9hzT02dIpZIsL5eRUpLPj+zTNRp1tNacOTOD63qsri5zf+keP//4g3he/J4tGB09Hk1NTRnKNIi0Zur0NADJZHKfbiA7CDEEYYihDE5MTLC2vtYrfG+ATCZjzF+cp7yySqdjE4QhnuuxsrpCGIZEUUSkNcPDeZSpyOVyFAoFpkslbt+6dXiA6ubmXd/zuPzJpzMxQniep/0gwEwkU67r4vs+QRDQtlodQ8r42LFj5LJZo7Ky/KRRe9I6NECn02ktLS7ecdrtnG3bru/7rud5frPZVOVyeaWrK5VKw0opDMNQxWKxqJSqBJ43eGgA0zSjubm57dnZ2U4QBFYQBE+DIHAAKpXKUlc3Pj4+KaWUhmGY+Xx+qNlstk3TTPeK3/dJ2HeAni2wtZP+5ubVdy8df+/Ug/oqVWtL1zt1au16dmtx87OubvL1qWbCTGjDNMSps5Nqsl40be04hwZYzW/M10TAyeg06/oxm3EVizap/7huifqwjAUiljRimz+8xfMb+Y1e4XsDCCVJvpomkxsimyjg5DSGnyFNEjcT7OoGRodACKQyyObzPPWaCNW7w32/A0cARwB9B+j5DP2qg7du483YEGmUJ0lGisxgap8u6oTEMUil8RMudsXCr/acQwcDCLG7xIgrC1f0528vWNt/NQZ1J2QoSMUdvyMeNh4qa2N712ei+IqXUAnMRJKTzoS8cPIr/9vc1ZTYCRYDHLR9PasCgp32ZJRQsnW/Njw3N4+ZSOL7PlGkGR0fZ+8+8HhjPUkMI4URTNPk5o3r5sDO1jQI2IDuguxLdBCVEEICKWBsbGzsg0Kh8HE6nX5TSpnpgiulJvb6hGG4xs5qjtbadhznTq1Wu1atVn8CqoAbx7H+vwC7FQDyQPbf8245n2NdjQbaQKNbgfiAZM8C2BtM7Pl/EYv3fJ95B3qu5S/b+j4H/gFxeZ6MjPHPtQAAAABJRU5ErkJggg==" width="32" height="32"></td><td><span id="batvalue"> mV</span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAADpklEQVRYhe2W229UVRSHv73PPnNrZ9rpQFsdKC2VjkKIVJsGE/Ea9MkYg/bJ/8s3nnz3DzB4iTGIEpASSpi2Q2grdUrndoY597OPD3Wa1hRG0pB56Xo5Zye/tdaXtfZeWSKOY/ppsq/ZjwAA9aIO8xffuQS8BpjACSAA/gZCYOn3367feKkAQRCcnymVzillGhOTkxeklNn1R49uOo5dv3f3rgBeCED0egUXZt8qAV8Al4Ehy7Ky1375dabVatFqtbAsC9d1KRaLfL3wZTmXy7WBFvA98N2ft289OBTA+x9+FL9x9hzT02dIpZIsL5eRUpLPj+zTNRp1tNacOTOD63qsri5zf+keP//4g3he/J4tGB09Hk1NTRnKNIi0Zur0NADJZHKfbiA7CDEEYYihDE5MTLC2vtYrfG+ATCZjzF+cp7yySqdjE4QhnuuxsrpCGIZEUUSkNcPDeZSpyOVyFAoFpkslbt+6dXiA6ubmXd/zuPzJpzMxQniep/0gwEwkU67r4vs+QRDQtlodQ8r42LFj5LJZo7Ky/KRRe9I6NECn02ktLS7ecdrtnG3bru/7rud5frPZVOVyeaWrK5VKw0opDMNQxWKxqJSqBJ43eGgA0zSjubm57dnZ2U4QBFYQBE+DIHAAKpXKUlc3Pj4+KaWUhmGY+Xx+qNlstk3TTPeK3/dJ2HeAni2wtZP+5ubVdy8df+/Ug/oqVWtL1zt1au16dmtx87OubvL1qWbCTGjDNMSps5Nqsl40be04hwZYzW/M10TAyeg06/oxm3EVizap/7huifqwjAUiljRimz+8xfMb+Y1e4XsDCCVJvpomkxsimyjg5DSGnyFNEjcT7OoGRodACKQyyObzPPWaCNW7w32/A0cARwB9B+j5DP2qg7du483YEGmUJ0lGisxgap8u6oTEMUil8RMudsXCr/acQwcDCLG7xIgrC1f0528vWNt/NQZ1J2QoSMUdvyMeNh4qa2N712ei+IqXUAnMRJKTzoS8cPIr/9vc1ZTYCRYDHLR9PasCgp32ZJRQsnW/Njw3N4+ZSOL7PlGkGR0fZ+8+8HhjPUkMI4URTNPk5o3r5sDO1jQI2IDuguxLdBCVEEICKWBsbGzsg0Kh8HE6nX5TSpnpgiulJvb6hGG4xs5qjtbadhznTq1Wu1atVn8CqoAbx7H+vwC7FQDyQPbf8245n2NdjQbaQKNbgfiAZM8C2BtM7Pl/EYv3fJ95B3qu5S/b+j4H/gFxeZ6MjPHPtQAAAABJRU5ErkJggg==" width="32" height="32"></td><td><span id="batpercent"> %</span></td></tr>

</table>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td align="right"><b>Network</b></td></tr>
<tr><td align="right">SSID:</td><td><span id="x_ssid"></span></td></tr>
<tr><td align="right">IP:</td><td><span id="x_ip"></span></td></tr>
<tr><td align="right">Netmask:</td><td><span id="x_netmask"></span></td></tr>
<tr><td align="right">Gateway:</td><td><span id="x_gateway"></span></td></tr>
<tr><td align="right">Mac:</td><td><span id="x_mac"></span></td></tr>
</table>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td colspan="2" align="center"><a href="javascript:GetState()" class="btn btn--m btn--bee">Refresh</a></td></tr>
</table>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px">
<tr><td align="center"><h5><a href="http://www.smartbee.eu" >&copy;2016  SmartBee Slovakia</a></h5.<br></td></tr>
</table>
<script>

function GetState()
{
	setValues("/admin/infovalues");
}

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				GetState();
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====" ;


//
//   The SK HTML PAGE
//
const char SK_PAGE_Information[] PROGMEM = R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="style.css" type="text/css" />
<script src="microajax.js"></script> 
<a href="/main"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Informácie o zariadení</strong>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td align="right"><b>Zariadenie</b></td></tr>
<tr><td align="right">ID nódu: </td><td><span id="nodeid"></span></td></tr>
<tr><td align="right">Typ:</td><td><span id="devicetype"></span></td></tr>
<tr><td align="right">Meno:</td><td><span id="devicename"></span></td></tr>
<tr><td align="right">Umiestnenie: </td><td><span id="deviceloc"></span></td></tr>
<tr><td align="right">Firmware:</td><td><span id="devicefw"></span></td></tr>
<tr><td align="right">Pamäť:</td><td><span id="deviceheap"></span></td></tr>
<tr><td align="right">Odosielanie:</td><td><span id="deviceuptime"> min.</span></td></tr>
<tr><td align="right">Batéria:</td><td><span id="devicebat"></span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAABGdBTUEAAK/INwWK6QAAAAlwSFlzAAASdAAAEnQB3mYfeAAAABl0RVh0U29mdHdhcmUAQWRvYmUgSW1hZ2VSZWFkeXHJZTwAAALMSURBVFhH7ZZRSBNxHMf/dze8c7PhNkhC5dpWMVkDH8wWk7KNyS4r6b0etB566SFkm9jDDKu1yIFCPUQQgmhlFhS0wB6CEBKxQCKXcw+CVxqEDEImbvv1O9Po8e4v7F46+HHc7vf9/L//3//3v/0J2f21d/cIOoLF7/efs1qtXpQfwWDpMJQqURRb5+bm7mzLT+B9HyWKTubxeM5mMpnb2+rjeD9AR6JUud3u0+l0+tY/BpyUKDoZGjiDBvp1M4A9EMpmsw9KpVKzzWYLoBE73VQoVS6Xq31hYeEuGjAbDAalB8q7BDsGAMDC8/xJNOCgnAudzIlLkFldHcQK2InFcqzsFRAbG6WloaE3RUL6LhFypezfgVqHQ/qWSAC0tECysvIVGqiiqyWlqrahQZJjsXWoroY4w4wjxkyJopP9NWC1Qtxg0MGAsgTJ5Dr4fJAQBB0MYBPK3d3rQAjECdHBwE4FsAkTRqMOBv43oe5N6PFIcji81YQ3CXmGm3kP3YamV3lXIpGcYuAGIQ8RU74zYU1d3eHPy8vDhfn5jWIkAj+mphafp1JhNGGln49Kpa2qyvV1dvY9/g3DpizDxtoaQC6HD5swMTIygBiTShRVmjDY1RWH6WnIT0xAYWwMihibo6NQmJyEpfHxfBCPalRklSLn41Bo6ntnJxRjMYBo9E/09EC+txcWOzqgX5LuIUtQydOc1vzI7Z5J8zwUmpoAgkGAtjaAQAB+2e3wyWSCa17vGFJrNJNVCnzXRfHJDMtCDrsfOA6gogKUnbCCkUIDwfr6PmTtV8nTnNZ0yGS6+tRolL/ggD8xFCPK4B8ZBpJm81vCsl1ItWgmqxQoHX65VRB6hznuw2uGKbzDgV+ybG6A51/g8TiK70MqWdRpIiq7caZhL8fFT3Hc/YMc14fPPfj7eYwKarIGYTXmtmMo5b6IcQHjKAajgbGV+hvcUCB/ku7JswAAAABJRU5ErkJggg==" width="32" height="32"></td><td><span id="tempvalue"> &deg;C</span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAACB1BMVEUAc+8Ac/AAdO8AdPAAde8AdfAAdu8AdvAAd/AAePABdPABde8BdfABdu8BdvABePACde8Cdu8Cd+8CePADd/ADevAGePAHefAHevAIevAKevAKe/ALfPALfPEMfPEMffANffEQf/ERgPESgPETgPATgPEUgPEUgvEZhfEahPEbhfEchPEchvEdhfIehvIeh/EiiPIiifIjifIjivImi/IojPIpjfIqjfIrjvMukfMvj/MwkfIykfMzkvM0kvM0k/M1lPM2k/M2lPM5lfM8lvM9mPM/mfNAmfNCm/NFnPRGnfRInfROofRSovVSpPVTovRUpPVap/VaqPVcqPRdqPVfqfVgqfVgq/Viq/VlrfVnrvZorvZssfZws/ZztfZ3t/d6uPd+uveCvfiEv/iGv/eHwPiKwfiMwviOw/iVx/mZyfmayfidy/mezPmfzPmizvmo0fqq0fqs0/qt1Pqv1fux1vq12Pq12Pu32fq62vu62/u83Pu+3fvA3vvA3vzB3vvG4PzL4/zL5PzO5vzT6PzU6PzW6f3W6v3X6v3Y6v3Z6/3a6v3b7f3d7f3e7v3f7v3g7/3h7/3k8f3l8f3p9P7q9P7r9P3s9f7v9v7w+P7x+P7y+P7z+P/z+f70+P70+f70+v72+v73+/74+/74+//4/P/5/P/6/P/6/f77/f/9/v/+//////+oDCohAAABcElEQVR4AWNYQwAMgIJV0xbjVbC6PrRwOT4FLZ5cNjWrcSuYGiXGyufTi1PBskwVdk4Oyfg5uBQ0WLFwcnKyaRetwq5gSogIBycQ8Hl0YlWwKkeRnRME2KUTF2JT0ObCygkBrKZ1WBQsS5ZmhyrgEImegamg2Y4VKs3JwapXiaFgWaoEB9QAJSV2wagF6Ar63FhgFhhGqDMbNaIpWF2iDHeBUlYQu3jaalQFSxKEOGEKpHJy5ZgDZqMqmOvPAlcgW1Stz+QwAVXBbG+4Anaj1joDBsseVAULgrlhBojHLi1WY3SdjKpgeYowBwc/BwcHq7hvx/w4YYHwhWjerNZiFzWz1VC3TuhaVWHCKpuzGk3B9DA+duOkqqZJK2aVOfOyuPdjBHWtDTO7TmReaX6MES+zbsEqzMgqMGdhZZdRVRBhZdbMmIcluheVe8nzMDMycks65s/FmqJWTcwOdLKw90tvX4kz2c+d2N0/cxV18yYA0WsVGCmzwMQAAAAASUVORK5CYII=" width="32" height="32"></td><td><span id="humvalue"> %</span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAADpklEQVRYhe2W229UVRSHv73PPnNrZ9rpQFsdKC2VjkKIVJsGE/Ea9MkYg/bJ/8s3nnz3DzB4iTGIEpASSpi2Q2grdUrndoY597OPD3Wa1hRG0pB56Xo5Zye/tdaXtfZeWSKOY/ppsq/ZjwAA9aIO8xffuQS8BpjACSAA/gZCYOn3367feKkAQRCcnymVzillGhOTkxeklNn1R49uOo5dv3f3rgBeCED0egUXZt8qAV8Al4Ehy7Ky1375dabVatFqtbAsC9d1KRaLfL3wZTmXy7WBFvA98N2ft289OBTA+x9+FL9x9hzT02dIpZIsL5eRUpLPj+zTNRp1tNacOTOD63qsri5zf+keP//4g3he/J4tGB09Hk1NTRnKNIi0Zur0NADJZHKfbiA7CDEEYYihDE5MTLC2vtYrfG+ATCZjzF+cp7yySqdjE4QhnuuxsrpCGIZEUUSkNcPDeZSpyOVyFAoFpkslbt+6dXiA6ubmXd/zuPzJpzMxQniep/0gwEwkU67r4vs+QRDQtlodQ8r42LFj5LJZo7Ky/KRRe9I6NECn02ktLS7ecdrtnG3bru/7rud5frPZVOVyeaWrK5VKw0opDMNQxWKxqJSqBJ43eGgA0zSjubm57dnZ2U4QBFYQBE+DIHAAKpXKUlc3Pj4+KaWUhmGY+Xx+qNlstk3TTPeK3/dJ2HeAni2wtZP+5ubVdy8df+/Ug/oqVWtL1zt1au16dmtx87OubvL1qWbCTGjDNMSps5Nqsl40be04hwZYzW/M10TAyeg06/oxm3EVizap/7huifqwjAUiljRimz+8xfMb+Y1e4XsDCCVJvpomkxsimyjg5DSGnyFNEjcT7OoGRodACKQyyObzPPWaCNW7w32/A0cARwB9B+j5DP2qg7du483YEGmUJ0lGisxgap8u6oTEMUil8RMudsXCr/acQwcDCLG7xIgrC1f0528vWNt/NQZ1J2QoSMUdvyMeNh4qa2N712ei+IqXUAnMRJKTzoS8cPIr/9vc1ZTYCRYDHLR9PasCgp32ZJRQsnW/Njw3N4+ZSOL7PlGkGR0fZ+8+8HhjPUkMI4URTNPk5o3r5sDO1jQI2IDuguxLdBCVEEICKWBsbGzsg0Kh8HE6nX5TSpnpgiulJvb6hGG4xs5qjtbadhznTq1Wu1atVn8CqoAbx7H+vwC7FQDyQPbf8245n2NdjQbaQKNbgfiAZM8C2BtM7Pl/EYv3fJ95B3qu5S/b+j4H/gFxeZ6MjPHPtQAAAABJRU5ErkJggg==" width="32" height="32"></td><td><span id="batvalue"> mV</span></td></tr>
<tr><td align="right"><img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAADpklEQVRYhe2W229UVRSHv73PPnNrZ9rpQFsdKC2VjkKIVJsGE/Ea9MkYg/bJ/8s3nnz3DzB4iTGIEpASSpi2Q2grdUrndoY597OPD3Wa1hRG0pB56Xo5Zye/tdaXtfZeWSKOY/ppsq/ZjwAA9aIO8xffuQS8BpjACSAA/gZCYOn3367feKkAQRCcnymVzillGhOTkxeklNn1R49uOo5dv3f3rgBeCED0egUXZt8qAV8Al4Ehy7Ky1375dabVatFqtbAsC9d1KRaLfL3wZTmXy7WBFvA98N2ft289OBTA+x9+FL9x9hzT02dIpZIsL5eRUpLPj+zTNRp1tNacOTOD63qsri5zf+keP//4g3he/J4tGB09Hk1NTRnKNIi0Zur0NADJZHKfbiA7CDEEYYihDE5MTLC2vtYrfG+ATCZjzF+cp7yySqdjE4QhnuuxsrpCGIZEUUSkNcPDeZSpyOVyFAoFpkslbt+6dXiA6ubmXd/zuPzJpzMxQniep/0gwEwkU67r4vs+QRDQtlodQ8r42LFj5LJZo7Ky/KRRe9I6NECn02ktLS7ecdrtnG3bru/7rud5frPZVOVyeaWrK5VKw0opDMNQxWKxqJSqBJ43eGgA0zSjubm57dnZ2U4QBFYQBE+DIHAAKpXKUlc3Pj4+KaWUhmGY+Xx+qNlstk3TTPeK3/dJ2HeAni2wtZP+5ubVdy8df+/Ug/oqVWtL1zt1au16dmtx87OubvL1qWbCTGjDNMSps5Nqsl40be04hwZYzW/M10TAyeg06/oxm3EVizap/7huifqwjAUiljRimz+8xfMb+Y1e4XsDCCVJvpomkxsimyjg5DSGnyFNEjcT7OoGRodACKQyyObzPPWaCNW7w32/A0cARwB9B+j5DP2qg7du483YEGmUJ0lGisxgap8u6oTEMUil8RMudsXCr/acQwcDCLG7xIgrC1f0528vWNt/NQZ1J2QoSMUdvyMeNh4qa2N712ei+IqXUAnMRJKTzoS8cPIr/9vc1ZTYCRYDHLR9PasCgp32ZJRQsnW/Njw3N4+ZSOL7PlGkGR0fZ+8+8HhjPUkMI4URTNPk5o3r5sDO1jQI2IDuguxLdBCVEEICKWBsbGzsg0Kh8HE6nX5TSpnpgiulJvb6hGG4xs5qjtbadhznTq1Wu1atVn8CqoAbx7H+vwC7FQDyQPbf8245n2NdjQbaQKNbgfiAZM8C2BtM7Pl/EYv3fJ95B3qu5S/b+j4H/gFxeZ6MjPHPtQAAAABJRU5ErkJggg==" width="32" height="32"></td><td><span id="batpercent"> %</span></td></tr>

</table>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td align="right"><b>Sieť</b></td></tr>
<tr><td align="right">SSID:</td><td><span id="x_ssid"></span></td></tr>
<tr><td align="right">IP:</td><td><span id="x_ip"></span></td></tr>
<tr><td align="right">Maska:</td><td><span id="x_netmask"></span></td></tr>
<tr><td align="right">Brána:</td><td><span id="x_gateway"></span></td></tr>
<tr><td align="right">Mac:</td><td><span id="x_mac"></span></td></tr>
</table>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px" >
<tr><td colspan="2" align="center"><a href="javascript:GetState()" class="btn btn--m btn--bee">Obnoviť</a></td></tr>
</table>
<hr>
<table border="0"  cellspacing="0" cellpadding="3" style="width:350px">
<tr><td align="center"><h5><a href="http://www.smartbee.eu" >&copy;2016  SmartBee Slovakia</a></h5.<br></td></tr>
</table>
<script>

function GetState()
{
	setValues("/admin/infovalues");
}

window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{
				GetState();
		});
	});
}
function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}



</script>
)=====" ;

// odlozene
//<tr><td align="right">Temperature :</td><td><span id="tempvalue"> &deg;C</span></td></tr>
//<tr><td align="right">Humidity :</td><td><span id="humvalue"> %</span></td></tr>





//
// FILL WITH INFOMATION
// 

void send_information_values_html ()
{

	String values ="";
  String Battery = "";
  
  switch(config.BatteryType){
    case 0:
      Battery = "AA - Alkaline";
      break;
    case 1:
      Battery = "14500 Li-Ion";
      break;
    case 2:
      Battery = "Ext. Power";
      break;
    default:
      Battery = "14500 Li-Ion";
  }

  
  if (!config.Sensor)
	{
  config.Temperature="Err";
  config.Humidity = "Err";
  }
  else{
  config.Temperature = Adafruit_HTU21DF().readTemperature();
  config.Humidity = Adafruit_HTU21DF().readHumidity();
  }
  
  
	values += "x_ssid|" + (String)WiFi.SSID() +  "|div\n";
	values += "x_ip|" +  (String) WiFi.localIP()[0] + "." +  (String) WiFi.localIP()[1] + "." +  (String) WiFi.localIP()[2] + "." + (String) WiFi.localIP()[3] +  "|div\n";
	values += "x_gateway|" +  (String) WiFi.gatewayIP()[0] + "." +  (String) WiFi.gatewayIP()[1] + "." +  (String) WiFi.gatewayIP()[2] + "." + (String) WiFi.gatewayIP()[3] +  "|div\n";
	values += "x_netmask|" +  (String) WiFi.subnetMask()[0] + "." +  (String) WiFi.subnetMask()[1] + "." +  (String) WiFi.subnetMask()[2] + "." + (String) WiFi.subnetMask()[3] +  "|div\n";
	values += "x_mac|" + GetMacAddress() +  "|div\n";
	values += "devicename|" +  (String)  config.DeviceName +  "|div\n";
  values += "devicetype|" +  (String)  config.DevType +  "|div\n";
  values += "devicefw|" +  (String)  config.Firmware +  "|div\n";
  values += "deviceheap|" +  (String)  ESP.getFreeHeap() + " Bytes" +  "|div\n";
  values += "batvalue|" +  (String)  readADC() + " mV" +  "|div\n";
  values += "batpercent|" +  (String)  BatteryPercent(readADC(),config.BatteryType) + " %" +  "|div\n";
  values += "deviceuptime|" +  (String)  config.UpdateTime + " min." +  "|div\n";
  values += "devicebat|" +  (String)  Battery +  "|div\n";
  values += "tempvalue|" +  (String) config.Temperature +" &deg;C" +  "|div\n";
  values += "humvalue|" +  (String)  config.Humidity + " %" +  "|div\n";
  values += "nodeid|" + (String)  config.NodeID +  "|div\n";
  values += "deviceloc|" +  (String)  config.NodeLocation +  "|div\n";
	server.send ( 200, "text/plain", values);
	Serial.println(__FUNCTION__); 

}

void ProcessInfo()
{
if (config.Language=="SK") {
    server.send ( 200, "text/html", SK_PAGE_Information  );
    }
    if (config.Language=="EN") {
    server.send ( 200, "text/html", EN_PAGE_Information  );
    }
    else{
    server.send ( 200, "text/html", EN_PAGE_Information  );
    }

}

#endif
