#include "ArduinoJson.h"
#include "EspMQTTClient.h"

const int TRIG_PIN = 5;  // Pino de trigger do sensor ultrassônico
const int ECHO_PIN = 18;  // Pino de eco do sensor ultrassônico
long duration;
float distance;

EspMQTTClient client{
  "Wokwi-GUEST", // SSID do WiFi
  "",             // Senha do WiFi
  "mqtt.tago.io", // Endereço do servidor MQTT
  "Default",      // Usuário MQTT
  "0e40552c-fed9-4c40-a29b-05151b7e245f",   // Token do dispositivo
  "SafeTrace",    // Nome do dispositivo
  1883            // Porta de comunicação MQTT
};

void setup() {
  Serial.begin(9600);
  Serial.println("Conectando WiFi");

  while (!client.isWifiConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }

  Serial.println("WiFi Conectado");
  Serial.println("Conectando com Servidor MQTT");

  while (!client.isMqttConnected()) {
    Serial.print('.');
    client.loop();
    delay(1000);
  }

  Serial.println("MQTT Conectado");
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void onConnectionEstablished() {
  // Callback quando a conexão MQTT é estabelecida
}

char bufferJson[100];

int lerSensorUltrassonico() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  
  delay(1000);

  return distance;
}

void loop() {
  int distancia = lerSensorUltrassonico();

  Serial.print("Distancia: ");
  Serial.println(distancia);

  StaticJsonDocument<300> documentoJson;
  documentoJson["variable"] = "distancia";
  documentoJson["value"] = distancia;
  documentoJson["unit"] = "cm";

  serializeJson(documentoJson, bufferJson);
  Serial.println(bufferJson);
  client.publish("topicoTDSPI", bufferJson);

  delay(5000);
  client.loop();
}
