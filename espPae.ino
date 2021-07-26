// EspDebug - Test sketch for ESP8266 module

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/* Datos de conección a wifi */
const char* ssid = "SPEED_LONDONO";
const char* password = "011100FL";

// dirección del servidor
String url = "http://35.226.204.189/api/device/3205901539/state";
int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  Serial.println("running");


  /* // Conectar WiFi */
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Conectando...");
    delay(500);
  }
  Serial.println("Conectado!");
}
HTTPClient http;
WiFiClient client;

bool turnLightOn() {
  String payload;
  if (http.begin(client, url))  //Iniciar conexión
  {
    int httpCode = http.GET();  // Realizar petición

    if (httpCode > 0) {

      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        payload = http.getString();  // Obtener respuesta
      }
    }

    http.end();
  }
  /* La respuesta del servidor puede ser: */
  /* {LightState:true} o {LightState:false}*/
  /* notemos que suficiente saber si el caracter despues de : es "t" o "f"*/

  /* variable sera el valor numerico que representa a "t" o "f"*/
  int variable = int(payload.charAt(14));
  /* 116 es el valor ascii de "t" */
  if (variable == 116) {
    return true;
  }
  /* 116 es el valor ascii de "f" */
  if (variable == 102) {
    return false;
  }
  return false;
}

void loop() {

  if (turnLightOn()) {
    Serial.println("encender luz");
    digitalWrite(ledPin,LOW);
  } else {
    Serial.println("apagar luz");
    digitalWrite(ledPin,HIGH);
  }


  delay(2000);
}
