#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define _SSID "emobility"                  // Your WiFi SSID
#define _PASSWORD "srkr@1980"        // Your WiFi Password
#define FIREBASE_HOST "e-bms-80fc0-default-rtdb.asia-southeast1.firebasedatabase.app"  // Firebase URL without "https://"
#define FIREBASE_AUTH "" // Your Firebase Database Secret (can be empty if not required)

// Initialize Firebase
FirebaseData firebaseData;
FirebaseConfig firebaseConfig;
FirebaseAuth firebaseAuth;

void setup() 
{
  Serial.begin(9600);
  WiFi.begin(_SSID, _PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  // Setup Firebase
  firebaseConfig.api_key = FIREBASE_AUTH; // Add your Firebase Auth Key here if needed
  firebaseConfig.database_url = FIREBASE_HOST;

  Firebase.begin(&firebaseConfig, &firebaseAuth);
  Firebase.reconnectWiFi(true);
}

void loop() 
{
  
  if (Firebase.getInt(firebaseData, "/BinaryValue1")) {
    int value1 = firebaseData.intData();
    Serial.print("Binary Value 1: ");
    Serial.println(value1);
  } else {
    Serial.print("Failed to get Binary Value 1: ");
    Serial.println(firebaseData.errorReason());
  }

  if (Firebase.getInt(firebaseData, "/BinaryValue2")) {
    int value2 = firebaseData.intData();
    Serial.print("Binary Value 2: ");
    Serial.println(value2);
  } else {
    Serial.print("Failed to get Binary Value 2: ");
    Serial.println(firebaseData.errorReason());
  }


  delay(2000); // Adjust delay as needed
}
