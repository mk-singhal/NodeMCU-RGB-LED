const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title>RGB LED Color Control</title>
<script src="https://kit.fontawesome.com/342a6423c4.js" crossorigin="anonymous"></script>
<style>
body {
    padding: 30px;
    background-color: #68686842;
}

h1 {
    text-align: center;
    font-family: "Arial Black", Gadget, sans-serif;
}

div.colorDisp {
    position: relative;
    margin-bottom: 70px;
    margin-right: 10%;
    display: inline-block;
}

div.colorDisp i {
    font-size: 600px;
    width: 40%;
}

#bulb {
    text-shadow:10px 10px 30px grey; 
}
.mainBox {
    width: 40%;
    min-width: 250px;
    border: 1px black solid;
    border-bottom-width: 0px;
    box-shadow:10px 10px 8px grey;
    display: inline-block;
}

table, tr, th {
    width: 100%;
    padding: 20px;
    border-collapse: collapse;
}

th {
    width: auto;
    border-bottom: 1px black solid;
}

.slider {
    width: 100%;
    min-width: 60px;
    position: relative;
}

.slider:hover {
    cursor: pointer;
}
</style>
</head>
<body>
<h1>ESP8266 RGB LED Project</h1>
<div class="colorDisp"><i id="bulb" class="fas fa-lightbulb"></i></div>
<div class="mainBox">
    <table>
        <tr>
            <th>RED</th>
            <th><input type="range" min="0" max="255" value="0" class="slider" id="rRange"></th>
            <th><span id="rVal">0</span></th>
        </tr>
        <tr>
            <th>GREEN</th>
            <th><input type="range" min="0" max="255" value="0" class="slider" id="gRange"></th>
            <th><span id="gVal">0</span></th>
        </tr>
        <tr>
            <th>BLUE</th>
            <th><input type="range" min="0" max="255" value="0" class="slider" id="bRange"></th>
            <th><span id="bVal">0</span></th>
        </tr>
    </table>
</div>

<script>
  var rSlider = document.getElementById("rRange");
  var gSlider = document.getElementById("gRange");
  var bSlider = document.getElementById("bRange");
  var red = 0;
  var green = 0;
  var blue = 0;
  //=======================================================================
  //        Sends the Updated RED value whenever slider is slided
  //=======================================================================
  rSlider.oninput = function() {
    document.getElementById("rVal").innerHTML = this.value;
    document.getElementById("bulb").style.color = "rgb(" + rSlider.value + ", " + gSlider.value + ", " + bSlider.value + ")";
    red = rSlider.value;
    console.log(red,green,blue);
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        var txt = this.responseText;
      }  
    };
    xhttp.open("GET", "setRGB?r="+red+"&g="+green+"&b="+blue, true); //Handle readADC server on ESP8266
    xhttp.send();
  }
  //=======================================================================
  //       Sends the Updated GREEN value whenever slider is slided
  //=======================================================================
  gSlider.oninput = function() {
    document.getElementById("gVal").innerHTML = this.value;
    document.getElementById("bulb").style.color = "rgb(" + rSlider.value + ", " + gSlider.value + ", " + bSlider.value + ")";
    green = gSlider.value;
    console.log(red,green,blue);
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        var txt = this.responseText;
      }  
    };
    xhttp.open("GET", "setRGB?r="+red+"&g="+green+"&b="+blue, true); //Handle readADC server on ESP8266
    xhttp.send();
  }
  //=======================================================================
  //        Sends the Updated BLUE value whenever slider is slided
  //=======================================================================
  bSlider.oninput = function() {
    document.getElementById("bVal").innerHTML = this.value;
    document.getElementById("bulb").style.color = "rgb(" + rSlider.value + ", " + gSlider.value + ", " + bSlider.value + ")";
    blue = bSlider.value;
    console.log(red,green,blue);
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        var txt = this.responseText;
      }  
    };
    xhttp.open("GET", "setRGB?r="+red+"&g="+green+"&b="+blue, true); //Handle readADC server on ESP8266
    xhttp.send();
  } 
</script>
</body>
</html>
)=====";
