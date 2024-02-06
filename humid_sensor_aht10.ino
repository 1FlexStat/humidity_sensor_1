#добавмили в девбранч ноывй код
#include <Adafruit_AHT10.h>

Adafruit_AHT10 aht;

// byte (0..255)
int temp = 0;
int hum = 0;

#define RELE_HUMIDITY 2
#define ON 1
#define OFF 0



void setup() {
  Serial.begin(115200);
  Serial.println("Adafruit AHT10 demo!");

  int b = aht.begin();

  if (!aht.begin()) {
    Serial.println("Could not find AHT10? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 found");
  pinMode(RELE_HUMIDITY, OUTPUT);
  digitalWrite(RELE_HUMIDITY, OFF);
}  //setup

void loop() {
  sensors_event_t h, t;
  aht.getEvent(&h, &t);  // populate temp and humidity objects with fresh data

  temp = t.temperature;
  hum = h.relative_humidity;

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" degrees C");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("% rH");
  if (hum >= 60) {
    digitalWrite(RELE_HUMIDITY, ON);
    Serial.println("включили реле");
  }
  if(hum < 58){
    digitalWrite(RELE_HUMIDITY, OFF);
    Serial.println("откл реле");
  }



  delay(500);
}  //loop
