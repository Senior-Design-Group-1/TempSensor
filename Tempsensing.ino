
#include <DHT.h>
#include <math.h>

// DHT22 sensor configuration
#define DHTPIN 4
#define DHTTYPE DHT22

// Create DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize DHT22 sensor
  dht.begin();

  // Allow sensor to stabilize
  delay(2000);

  Serial.println("DHT22 Temperature Sensor");
  Serial.println("------------------------");
}

void loop() {
  // Read temperature in Celsius
  float temperatureC = dht.readTemperature();

  // Read temperature in Fahrenheit
  float temperatureF = dht.readTemperature(true);

  // Read relative humidity
  float humidity = dht.readHumidity();

  // Check for invalid measurements
  if (isnan(temperatureC) ||
      isnan(temperatureF) ||
      isnan(humidity)) {
    Serial.println("Error: Failed to read DHT22!");
  }
  else {
    // Print measured values
    Serial.print("Temperature: ");
    Serial.print(temperatureF, 1);
    Serial.print(" °F | ");

    Serial.print(temperatureC, 1);
    Serial.print(" °C | ");

    Serial.print("Humidity: ");
    Serial.print(humidity, 1);
    Serial.println(" %");
  }

  // Wait 3 seconds before next reading
  delay(3000);
}
