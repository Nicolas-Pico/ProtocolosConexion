#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ArduinoOTA.h>

const char* ssid         = "TU_SSID"; // Nombre de la red Wifi
const char* password     = "TU_PASSWORD"; // Contrasena de la red Wifi
const char* mqttServer   = "demo.thingsboard.io"; // URL o IP de la plaforma o servidor de Thingsboard
const int   mqttPort     = 1883; // Puerto de conexion
const char* mqttUser     = "USER_MQTT";       // Nombre de usuario
const char* mqttPassword = "PASSWORD";    // Contrasena de usuario
const char* mqttClient   = "CLIENT_MQTT";    // Client ID

WiFiClient espClient; // Se crea un objeto de cliente WiFi
PubSubClient client(espClient); // Se crea un objeto de cliente MQTT usando el cliente WiFi
const int capacity = JSON_OBJECT_SIZE(21); // Capacidad del objeto JSON
StaticJsonDocument<capacity> doc; // Se crea un documento JSON estático

int contador = 1; // Contador para el número de mensajes
char message[30]; // Almacena el mensaje a enviar

void setup() {
  Serial.begin(115200); // Inicialización de la comunicación serial
  WiFi.begin(ssid, password); // Conexión a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqttServer, mqttPort); // Configuración del servidor MQTT
}

void loop() {
  if (!client.connected()) {
    reconnect(); // Reconectar si no está conectado al servidor MQTT
  }

  // Generación de valores aleatorios para los datos del documento JSON
  doc["Dado0"] = random(100);
  doc["Dado1"] = random(100);
  doc["Dado2"] = random(100);
  doc["Dado3"] = random(100);
  doc["Dado4"] = random(100);
  doc["Dado5"] = random(100);
  doc["Dado6"] = random(100);
  doc["Dado7"] = random(100);
  doc["Dado8"] = random(100);
  doc["Dado9"] = random(100);

  // Construcción de la conexion MQTT
  String topic = "v1/devices/me/telemetry";
  char topicBuf[256];
  topic.toCharArray(topicBuf, 256);

  // Serialización del documento JSON a una cadena
  char docBuffer[256];
  size_t n = serializeJson(doc, docBuffer);

  // Publicación del documento JSON en el tema MQTT
  client.publish(topicBuf, docBuffer, n);

  // Construcción del mensaje y publicación en el tema MQTT
  sprintf(message, "MQTT ESP32 - Message no. %d", contador);
  Serial.print("Message sent: ");
  Serial.println(message);

  client.publish(topicBuf, message);
  Serial.println("Message sent successfully...");
  delay(1000);
  contador++;
}

void reconnect() {
  Serial.println("Connecting to the MQTT broker...");

  // Intentar la conexión hasta que sea exitosa
  while (!client.connected()) {
    if (client.connect(mqttClient, mqttUser, mqttPassword)) {
      Serial.println("Connected to the broker!");
    } else {
      Serial.print("Failed to connect to the broker - Status: ");
      Serial.println(client.state());
      delay(2000);
    }
  }
}