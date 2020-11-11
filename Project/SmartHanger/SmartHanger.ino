
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiManager.h>

#define connection "Network Connection Setup"
//const char* ssid = "ABCkkkkk";
//const char* password = "Amit123@";
const char *macAdd = "f0:08:d1:db:53:4c";

const char *serverName = "http://testqaweb.com/smartHanger/api/Auth/updateHangerDetails";

const int ledGreen = 18;
const int ledRed = 19;
const int batteryPin = 33;
int TRIGGER_PIN = 2;

int occupied = 0;
int ADC = 0;
int voltage = 0;
int state;
float percentage = 0;
String deviceId = "SH-f0:08:d1:db:53:4c";

WiFiManager wifiManager;

void setup()
{
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(TRIGGER_PIN, INPUT);
  Serial.begin(115200);

  wifiManager.autoConnect(connection);
  Serial.println("Connected to Network");
}
void sendData()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    http.begin(serverName);

    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String httpRequestData = "hangerId=1 &deviseStatus=1 &battery=" + String(percentage) + "&status=" + String(occupied) + "&macAdd=" + String(macAdd) + "&deviceId=" + String(deviceId) + "";

    int httpResponseCode = http.POST(httpRequestData);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    // Free resources
    http.end();
  }
  else
  {
    Serial.println("WiFi Disconnected");
  }
}
void ldrSetup()
{

  int a = analogRead(39), b = analogRead(34), c = analogRead(32), d = digitalRead(TRIGGER_PIN);
  if (a == 0 || b == 0 || c == 0)
  {
    occupied = 1;
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    sendData();
  }

  else
  {
    occupied = 0;
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    sendData();
  }
}
void batterySetup()
{

  ADC = analogRead(batteryPin);

  //Serial.print("ADC VALUE = ");
  //
  //Serial.println(ADC);
  delay(1000);

  voltage = (ADC * 3.3) / (4095);
  Serial.print("Voltage = ");
  Serial.print(voltage);
  Serial.print("volts");
  Serial.println(" ");

  percentage = (voltage * 100) / 3.3;
  Serial.print("percent=");
  Serial.print(percentage);
  Serial.println(" ");
  
  delay(1000);
}
void loop()
{

  state = digitalRead(TRIGGER_PIN);
  Serial.println(state);
  if (digitalRead(TRIGGER_PIN) == 1)
  {
    if (!wifiManager.startConfigPortal(connection))
      Serial.println("failed to connect and hit timeout");
    delay(3000);
    if (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
      Serial.println("Failed to connect to the network");
      ESP.restart();
    }
  }
  else
  {
    ldrSetup();
    batterySetup();
  }
}
