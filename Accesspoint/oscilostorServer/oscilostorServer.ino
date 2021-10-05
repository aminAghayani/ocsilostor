#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>

IPAddress receiverIP(192,168,4,1);
IPAddress receiverGateway(192,168,4,9);
IPAddress receiverSubnet(255,255,255,0);
char* receiverSSID = "oscilostor";
char* receiverPass = "amin1234";
WiFiUDP udp;
unsigned int receiverPort = 51919;
unsigned int distinationPort = 61388;
IPAddress distinationIP(192,168,4,100);
char packetBufferAp[255];
char receivedData[420];
int serialPacketIndex = 0;
int ledState = 0;
int usartReadAttempts = 0;

extern "C" {
  #include "user_interface.h"
}

//*******************************************************************************
void usual_init_wifi(void)
{  
  struct softap_config config; 
  WiFi.disconnect();
  WiFi.softAPdisconnect();
  WiFi.mode(WIFI_OFF);
   
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(receiverIP, receiverGateway, receiverSubnet);
  wifi_softap_dhcps_stop();
  WiFi.softAP(receiverSSID, receiverPass);
  //Serial.println(WiFi.getAutoConnect());
  
  IPAddress receiverIP = WiFi.softAPIP();
  //Serial.print("Main AP IP address: ");
  //Serial.println(myIP);
  udp.begin(receiverPort);
  //Serial.println(apSSID);
  //Serial.println(apPass);
 
  wifi_softap_get_config(&config);  
  config.max_connection = 8;       
  wifi_softap_set_config(&config); 
}

//*******************************************************************************
void clearSerialData(){
  
  for(int i=0 ; i<420 ; i++){
        receivedData[i] = 0;
      }
      serialPacketIndex = 0;
      
}
void serialReciever(void){
  
  if(Serial.available() > 0){

      receivedData[serialPacketIndex] = Serial.read();
      serialPacketIndex++;
      
      //Serial.println(receivedData);
      if(serialPacketIndex >= 5 && receivedData[0] == 's' && receivedData[serialPacketIndex-3] == 'e'
      && receivedData[serialPacketIndex-2] == 'n' && receivedData[serialPacketIndex-1] == 'd'){
        
        udp.beginPacket(distinationIP, distinationPort);
        udp.write(receivedData,serialPacketIndex);
        udp.endPacket();
        clearSerialData();
      }
      
      else if(serialPacketIndex > 415 || receivedData[0] != 's'){
        clearSerialData();
      }
      
      
  }
}

//*******************************************************************************
void wifiReciever(void)
{  
  int packetSize = udp.parsePacket();
  if (packetSize) 
  {
    int len = udp.read(packetBufferAp, 255);
    
    
      
    if(len > 0 && packetBufferAp[0] == 's'){           
    //Serial.print(len,DEC);
    Serial.write(packetBufferAp,len);
    if(ledState == 0){ 
        ledState = 1;
        digitalWrite(LED_BUILTIN, LOW); 
      }
      else{ 
        ledState = 0;
        digitalWrite(LED_BUILTIN, HIGH); 
      }
    }
    else if(packetBufferAp[0] == 'H' && packetBufferAp[1] == 'e' && packetBufferAp[2] == 'l' && packetBufferAp[3] == 'l' && packetBufferAp[4] == 'o'){
      distinationIP = udp.remoteIP();
      distinationPort = udp.remotePort();
      //Serial.println(udp.remoteIP());
      //Serial.println(udp.remotePort());
      udp.beginPacket(distinationIP, distinationPort);
      udp.write("Hello");
      udp.endPacket();
      while (Serial.read() >= 0);
      Serial.print(packetBufferAp);
      if(ledState == 0){ 
        ledState = 1;
        digitalWrite(LED_BUILTIN, LOW); 
      }
      else{ 
        ledState = 0;
        digitalWrite(LED_BUILTIN, HIGH); 
      }
    }
    else if(packetBufferAp[0] == 'B' && packetBufferAp[1] == 'y' && packetBufferAp[2] == 'e'){
      udp.beginPacket(distinationIP, distinationPort);
      udp.write("Bye");
      udp.endPacket();
      Serial.print(packetBufferAp);
      if(ledState == 0){ 
        ledState = 1;
        digitalWrite(LED_BUILTIN, LOW); 
      }
      else{ 
        ledState = 0;
        digitalWrite(LED_BUILTIN, HIGH);
      }
      while (Serial.read() >= 0);
    }
  }  
}

//*******************************************************************************
void sendPacket(char data[45]) 
{
  udp.beginPacket(distinationIP , distinationPort);
  udp.write(data);
  udp.endPacket();
}

void setup() {
  delay(200);
  Serial.begin(115200);
  delay(10);

  usual_init_wifi();
  while (Serial.read() >= 0);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  
  wifiReciever();
  serialReciever();
  
 
}
