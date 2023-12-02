# ProtocolosConexion
Este proyecto es un ejemplo simple de cómo enviar datos de temperatura y humedad a Thingsboard utilizando un dispositivo IoT (ESP8266) con conectividad a WiFi. Se utiliza un microcontrolador compatible con Arduino y una conexión WiFi para enviar datos aleatorios de temperatura y humedad a través de HTTP POST y MQTT a un servidor Thingsboard.

## Configuración
Antes de cargar el código en tu dispositivo, asegúrate de agregar la siguiente URL adicional en el administrador de Arduino IDE para el módulo ESP8266:
http://arduino.esp8266.com/stable/package_esp8266com_index.json

## Uso
1. Conecta tu dispositivo IoT a una red WiFi.
2. Carga el código en tu dispositivo.
3. Abre el monitor serial en la velocidad de baudios 115200.
4 .Observa cómo se envían datos aleatorios de temperatura y humedad a Thingsboard cada 5 segundos.
   
## Dependencias
ArduinoHttpClient
ESP8266WiFi

## Contribuciones
Las contribuciones son bienvenidas. Si encuentras algún problema o tienes sugerencias para mejorar el código, siéntete libre de abrir un problema o enviar una solicitud de extracción.
