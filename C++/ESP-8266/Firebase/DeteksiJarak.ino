#include "secrets.h"
#include <Firebase.h>
#include <ArduinoJson.h>
#define LED_PIN D5 
#define buzzerPin D6
#define TRIG_PIN D1
#define ECHO_PIN D2

Firebase fb(REFERENCE_URL);
void setup() 
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    digitalWrite(buzzerPin, LOW);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
// Connect to WiFi:
    Serial.println();
    Serial.println();
    Serial.print("Connecting to: ");
    Serial.println(WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        Serial.print("-");
        delay(500);
    }

    Serial.println();
    Serial.println("WiFi Connected");
    Serial.println();

    // Turn on built-in LED for UNO R4 WiFi
    #if defined(ARDUINO_UNOWIFIR4)
        digitalWrite(LED_BUILTIN, HIGH);
    #endif

    Serial.println("Creating JSON data...");
    
    StaticJsonDocument<255> docOutput;

    docOutput["LED1"] = 1;
    docOutput["BUZZER"] = 1;

    String output;

    serializeJson(docOutput, output);

    Serial.println("JSON data created:");
    Serial.println(output);
    Serial.println();

    Serial.println("Sending JSON to Firebase...");
    int responseCode = fb.setJson("dataArduino", output);
    Serial.print("Set JSON - Response Code: ");
    Serial.println(responseCode);

    if (responseCode == 200) {
        Serial.println("JSON data successfully sent to Firebase!");
    } else {
        Serial.println("Failed to send JSON data to Firebase!");
        Serial.print("Response code ");
        Serial.print(responseCode);
        Serial.println(" indicates an error occurred.");
        return; // Exit if we can't send data
    }

    Serial.println();

    Serial.println("Retrieving JSON from Firebase...");

}

float readDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    unsigned long duration =
        pulseIn(ECHO_PIN, HIGH, 30000);

    if (duration == 0) {
        return -1.0;
    }

    return duration * 0.0343 / 2.0;
}

void loop() {

String input;
    int responseCode = fb.getJson("dataArduino", input);
    Serial.print("Get JSON - Response Code: ");
    Serial.println(responseCode);
    //test ->
    
    if (responseCode != 200) {
        Serial.println("Could not retrieve data from Firebase");
        Serial.print("Response code ");
        Serial.print(responseCode);
        Serial.println(" indicates an error occurred.");
        Serial.println("This might be due to:");
        Serial.println("- Network connectivity issues");
        Serial.println("- Incorrect Firebase URL or path");
        Serial.println("- Authentication problems");
        return;
    }

    Serial.println("JSON data retrieved:");
    Serial.println(input);
    Serial.println();

    StaticJsonDocument<255> docInput;

    DeserializationError error = deserializeJson(docInput, input);

    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

    Serial.println("Parsing JSON data...");

    // child data 
    int led1 = docInput["LED1"] | 0;
    int buzzer = docInput["BUZZER"] | 0;

    digitalWrite(LED_PIN, led1);

    digitalWrite(buzzerPin, buzzer);

    Serial.println("--- Parsed Data ---");

    Serial.print("LED 1 : ");
    Serial.println(led1);

    Serial.print("BUZZER : ");
    Serial.println(buzzer);
    
float distance = readDistance();

    if (distance >= 0) {
        docInput["DISTANCE_CM"] = distance;

        String output;
        serializeJson(docInput, output);

        int writeCode = fb.setJson("dataArduino", output);

        Serial.print("Jarak: ");
        Serial.print(distance);
        Serial.println(" cm");

        Serial.print("Firebase write: ");
        Serial.println(writeCode);
    } else {
        Serial.println("Sensor: no echo detected");
        }   
        Serial.println("JSON example completed!");
}
