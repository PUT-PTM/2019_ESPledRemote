// Neopixel
#include <Adafruit_NeoPixel.h>

// ESP8266
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
// Webserver Config
const char *ssid = "ky";
const char *password = "12345678";
IPAddress ip(192, 168, 43, 233);
IPAddress gateway(192, 168, 43, 1);
IPAddress subnet(255, 255, 255, 0);
WiFiServer server ( 80 );

// Neopixel Config
#define NeoPIN D3
#define NUM_LEDS 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NeoPIN, NEO_RGB + NEO_KHZ400);


void setup ( void ) {
 delay(5);
  Serial.begin ( 115200 );
 server.begin();
  WiFi.begin ( ssid, password );
  WiFi.config(ip,gateway,subnet);
  strip.begin();
  for(int i=0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color( 0, 0, 0 ) );
  }
  strip.show();

}

void loop ( void ) {
    // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // waiting fo a client
   Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  String req = request.substring(10);
int ln = req.length()-1;
int c1 = req.indexOf('/'); //first place to cut string
int c2 = req.indexOf('/',c1+1); //second place
int red = req.substring(0,c1).toInt();
int green = req.substring(c1+1,c2).toInt();
int blue = req.substring(c2+1,c2+4).toInt();
Serial.println(request.substring(10,13));
Serial.println(request.substring(5,9));
if(request.substring(5,9)=="true" && request.substring(10,13)=="an1"){
  while(1){
      WiFiClient client = server.available();
      String request2 = client.readStringUntil('\r');
  if(request2.substring(10,13)=="an1" || request2.substring(0)==""){
  for(int j = 0; j < 3; j++ ) { 
    // Fade IN
    for(int k = 0; k < 255; k++) {
      for(int i=0; i < NUM_LEDS; i++) {
      switch(j) { 
     case 0: strip.setPixelColor(i, strip.Color( k, 0, 0 ) ); break;
        case 1: strip.setPixelColor(i, strip.Color( 0, k, 0 ) ); break;
        case 2: strip.setPixelColor(i, strip.Color( 0, 0, k ) ); break;
      }
      }
      strip.show();
     delay(5);
    }
    // Fade OUT
    for(int k = 255; k >= 0; k--) { 
      for(int i=0; i < NUM_LEDS; i++) {
      switch(j) { 
        case 0: strip.setPixelColor(i, strip.Color( k, 0, 0 ) ); break;
        case 1: strip.setPixelColor(i, strip.Color( 0, k, 0 ) ); break;
        case 2: strip.setPixelColor(i, strip.Color( 0, 0, k ) ); break;
      }
      }
      strip.show();
       delay(5);
    }
    strip.clear();
  }
  }
  else{
  break;
  }
}
}
  else if(request.substring(5,9)=="true" && request.substring(10,13)=="an2"){
String req = request.substring(14);
int ln = req.length()-1;
int c1 = req.indexOf('/'); //first place to cut string
int c2 = req.indexOf('/',c1+1); //second place
int red = req.substring(0,c1).toInt();
int green = req.substring(c1+1,c2).toInt();
int blue = req.substring(c2+1,c2+4).toInt();
while(1){
   WiFiClient client = server.available();
      String request2 = client.readStringUntil('\r');
  if(request2.substring(10,13)=="an2" || request2.substring(0)==""){
 for(int i=0; i < NUM_LEDS; i++) {
    
    strip.setPixelColor(i, strip.Color( green, red, blue ) );
    strip.setPixelColor(i-1, strip.Color( 0, 0, 0 ) );
    delay(100);
    strip.show();
 }
 strip.clear();
}
else{
  break;
}
}
  }
  else if(request.substring(5,9)=="true"){
  for(int i=0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color( green, red, blue ) );
    delay(10);
  }
}

else{
  strip.clear();
  }

strip.show();
}
