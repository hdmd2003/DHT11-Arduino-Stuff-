
#include "DHT.h"

#define DHTPIN 7
     
#define DHTTYPE DHT11


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("Date & Time, Humidity %, Temperature *C, Temperature *F"));

  dht.begin();
}

void loop() {

  delay(1000);


  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float f = dht.readTemperature(true);


  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.print(t);
  Serial.print(",");
  Serial.println(f);

}
  
