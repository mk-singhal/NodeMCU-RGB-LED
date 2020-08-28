#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//includes our frontend part
#include "index.h"

//SSID and Password of your WiFi router
const char* ssid = "Here goes your ssid";
const char* password = "Here goes your password";

ESP8266WebServer server(80);

//LED Connections
const int BlueLED = 0; // D3
const int RedLED = 5;    // D1 
const int GreenLED = 4; // D2

//=======================================================================
//                    handles main page
//=======================================================================
void handleRoot() {
  Serial.println("Root Page Requested");
  server.send(200, "text/html", MAIN_page);
}

//=======================================================================
//                    Handle Set Color
//=======================================================================
void handleLED() {
  //Saperate Colors are sent through javascript
  String red = server.arg("r");
  String green = server.arg("g");
  String blue = server.arg("b");
  int r = red.toInt();
  int g = green.toInt();
  int b = blue.toInt();
  
  //PWM Correction 8-bit to 10-bit
  r = map(r, 0, 255, 1023, 0);
  g = map(g, 0, 255, 1023, 0);
  b = map(b, 0, 255, 1023, 0);

  Serial.print("Red:");
  Serial.println(r);
  Serial.println(red);
  
  Serial.print("Green:");
  Serial.println(g);
  Serial.println(green);
  
  Serial.print("Blue:");
  Serial.println(b);
  Serial.println(blue);
  
  //ESP supports analogWrite(All IOs are PWM)
  analogWrite(RedLED,r);
  analogWrite(GreenLED,g);
  analogWrite(BlueLED,b);

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated-- Press Back Button");
   
}

//=======================================================================
//                    SETUP
//=======================================================================
void setup(){
  Serial.begin(115200);   //Start serial connection  
  
  pinMode(RedLED,OUTPUT);
  pinMode(GreenLED,OUTPUT);
  pinMode(BlueLED,OUTPUT);
  
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");  
  Serial.println("WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  
  server.on("/", handleRoot);  //Associate handler function to path
  server.on("/setRGB",handleLED);
    
  server.begin();      //Start server
  Serial.println("HTTP server started");
}

//=======================================================================
//                    LOOP
//=======================================================================
void loop(){
  server.handleClient();
}
