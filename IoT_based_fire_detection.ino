/*************************************************************

  You’ll need:
   - Blynk IoT app (download from App Store or Google Play)
   - ESP32 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL39otB3sqk"
#define BLYNK_TEMPLATE_NAME "IoT based fire detection"
#define BLYNK_AUTH_TOKEN "v9M2G2m0cL7mszz0CL1xpGNTqkrJhAki"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
int flame_sensor=34;
int gas_sensor=33;
char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "impulsetech";  // type your wifi name
char pass[] = "impulse567";  // type your wifi password
BlynkTimer timer;
void sendSensor()
{
  // Request temperature to all devices on the data line
  int gas_sensordata=analogRead(gas_sensor);
  int flame_sensordata=analogRead(flame_sensor);
  Serial.println("Gas sensor data: ");
  Serial.println(gas_sensordata);
  Serial.println("Flame sensor data: ");
  Serial.println(flame_sensordata);
  delay(1000);
  
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, flame_sensordata);
    Blynk.virtualWrite(V1, gas_sensordata);
    delay(500);
}
void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(100L, sendSensor);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
