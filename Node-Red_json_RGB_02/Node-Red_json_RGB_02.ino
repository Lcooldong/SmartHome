#include <ArduinoJson.h>
#define LED_R 9
#define LED_G 11
#define LED_B 10

void setup() {
  Serial.begin(115200);
//  pinMode(LED_R, OUTPUT);
//  pinMode(LED_G, OUTPUT);
//  pinMode(LED_B, OUTPUT);
  ledcAttachPin(LED_R, 0);  //pin, channel
  ledcAttachPin(LED_G, 1);
  ledcAttachPin(LED_B, 2);

  ledcSetup(0, 5000, 8);  // channel, Hz(보통 5000), bit(해상도)
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  
}

void loop() {
  if(Serial.available()){
    String data = Serial.readStringUntil(0x0a);

  // 4c dc 28
    int color[3] = {0, 0, 0};

    for(int i= 0, i < sizeof(color); i++)
    {
      color[i] = 16*data[2i].toInt() + data[2i+1].toInt();   
    }
    

  }
}

void setColorCh(int redCh, int greenCh, int blueCh){
  ledcAttachPin(LED_R, redCh);  //pin, channel
  ledcAttachPin(LED_G, greenCh);
  ledcAttachPin(LED_B, blueCh);

  ledcSetup(redCh, 5000, 8);  // channel, Hz(보통 5000), bit(해상도)
  ledcSetup(greenCh, 5000, 8);
  ledcSetup(blueCh, 5000, 8);
}

void setColor(String red, String green, String blue){
  ledcWrite(0, red.toInt());
  ledcWrite(1, green.toInt());
  ledcWrite(2, blue.toInt());
}
