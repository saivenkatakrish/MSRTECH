#include <ESP8266WiFi.h>
#include <ESP8266Firebase.h> // Correct library

// Replace with your Wi-Fi credentials
#define WIFI_SSID "G Pavani"
#define WIFI_PASSWORD "pavani@18"

// Firebase settings
#define REFERENCE_URL "https://esp2serial-default-rtdb.firebaseio.com/" // Firebase Database URL

Firebase firebase(REFERENCE_URL);  // Initialize Firebase with the URL

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");
}

void loop() {
  // Retrieve the string value from Firebase
  String valueStr = firebase.getString("/Input");  // Replace "/test" with your path

  if (valueStr.length() > 0) {
    int value = valueStr.toInt();  // Convert the string to an integer if needed
    Serial.print("Value from Firebase: ");
    Serial.println(value);
  } else {
    Serial.println("Failed to get data from Firebase or empty data.");
  }

  // Delay for 2 seconds before the next read
  delay(2000);
}
