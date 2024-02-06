
#include <Adafruit_AHT10.h>

#define ATH10 ;
#define RELE_FOR_COMPRESSOR 2
#define RELE_FOR_BLOWERFEN 3

Adafruit_AHT10 aht;

Adafruit_Sensor *aht_humidity, *aht_temp;

void setup(void) {

  Serial.begin(115200);
  while (!Serial)
    delay(10);

  Serial.println("Adafruit AHT10 test!");

  if (!aht.begin()) {
    Serial.println("Failed to find AHT10 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("AHT10 Found!");
  aht_temp = aht.getTemperatureSensor();
  aht_temp->printSensorDetails();


  aht_humidity = aht.getHumiditySensor();
  aht_humidity->printSensorDetails();

  pinMode(RELE_FOR_COMPRESSOR, OUTPUT);
  pinMode(RELE_FOR_BLOWERFEN, OUTPUT);
}


void loop() {


  sensors_event_t humidity;
  sensors_event_t temp;
  aht_humidity->getEvent(&humidity);
  aht_temp->getEvent(&temp);

  Serial.print("\t\tTemperature ");
  Serial.print(temp.temperature);
  Serial.println(" deg C");

  Serial.print("\t\tHumidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" % rH");
  Serial.print("\t\tTemperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degrees C");

  if ( sensors_event_t humidity > 60) {
    digitalWrite(RELE_FOR_COMPRESSOR, 1);
    Serial.print("COMPRESSOR_ON.");
  }


  delay(100);
}
