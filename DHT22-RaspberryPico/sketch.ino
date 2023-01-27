#include <DHT.h> // Include the DHT library

#define DHTPIN 22 // DHT22 sensor pin connected to digital pin 22
#define DHTTYPE DHT22 // Specify the type of DHT sensor

DHT dht(DHTPIN, DHTTYPE); // Create an instance of the DHT sensor

void setup() {
  Serial1.begin(9600); // Initialize serial communication
  dht.begin(); // Initialize the DHT sensor
}

void loop() {
  float humidity = dht.readHumidity(); // Read the humidity
  float temperature = dht.readTemperature(); // Read the temperature

  if (isnan(humidity) || isnan(temperature)) { // Check for errors
    Serial1.println("Error reading from DHT sensor!");
    return;
  }

  Serial1.print("Humidity: ");
  Serial1.print(humidity);
  Serial1.print("%  ");
  Serial1.print("Temperature: ");
  Serial1.print(temperature);
  Serial1.println("*C");

  delay(2000); // Wait 2 seconds before taking another reading
}