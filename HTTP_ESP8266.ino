#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "TU_SSID"; // Nombre de la red Wifi
const char* password = "TU_PASSWORD"; // Contrasena de la red Wifi
const char* thingsboardServer = "demo.thingsboard.io"; // URL o IP de la plaforma o servidor de Thingsboard
const char* accessToken = "Z0eN2lx1y1F66vXVdkXY"; // Token del dispositivo

// Intervalo de actualización en milisegundos (5 segundos)
const int updateInterval = 5000;                        
unsigned long lastUpdate = 0;

// Creación de objetos WiFiClient y HttpClient
WiFiClient client;  
HTTPClient http;    

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting...");

  // Esperar a que se establezca la conexión WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  // Imprimir el estado de la conexión
  Serial.println("");
  Serial.println("Connected!!!");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
}

void loop() {
  // Obtener el tiempo actual en milisegundos
  unsigned long now = millis();

  // Verificar si ha pasado el tiempo de actualización
  if (now - lastUpdate >= updateInterval) {
    // Llamar a la función para enviar datos a Thingsboard
    sendTelemetry();
    lastUpdate = now;
  }
}

void sendTelemetry() {
  // Construir la URL de la API HTTP de Thingsboard
  String url = "http://";
  url += thingsboardServer;
  url += "/api/v1/";
  url += accessToken;
  url += "/telemetry";

  // Generar valores de temperatura y humedad aleatorios
  float temperature = random(0, 100); // Cambia el rango según sea necesario
  float humidity = random(0, 100); // Cambia el rango según sea necesario

  // Construir el cuerpo del mensaje (en formato JSON)
  String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";

  // Realizar la solicitud HTTP POST a Thingsboard
  http.begin(client, url);  // Usar begin con WiFiClient
  http.addHeader("Content-Type", "application/json");
  http.addHeader("X-Authorization", "Bearer " + String(accessToken));
  int httpCode = http.POST(payload);
  String response = http.getString();

  // Verificar la respuesta del servidor Thingsboard
  if (httpCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);
    Serial.print("Response message: ");
    Serial.println(response);
  } else {
    Serial.print("Error request HTTP");
    Serial.print("Response message: ");
    Serial.println(response);
  }
  
  // Finalizar la conexión HTTP
  http.end();
}