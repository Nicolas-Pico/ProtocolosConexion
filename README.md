# Protocolos de conexión usando el módulo ESP8266
Este proyecto es un ejemplo simple de cómo enviar datos de temperatura y humedad a Thingsboard utilizando un dispositivo IoT (ESP8266) con conectividad a WiFi. Se utiliza un microcontrolador compatible con Arduino IDE y una conexión WiFi para enviar datos aleatorios de temperatura y humedad a través de HTTP POST y MQTT a un servidor Thingsboard.

## Configuración
Antes de cargar el código en tu dispositivo, asegúrate de agregar la siguiente URL adicional en el administrador de Arduino IDE para el módulo ESP8266 http://arduino.esp8266.com/stable/package_esp8266com_index.json

![Imagen URL](https://github.com/Nicolas-Pico/ProtocolosConexion/blob/main/Arduino_URL.png)

## Uso
1. Conecta tu dispositivo IoT (ESP8266) a una red WiFi.
2. Carga el código en tu dispositivo.
3. Abre el monitor serial en la velocidad de baudios 115200.
4. Observa cómo se envían datos aleatorios de temperatura y humedad a Thingsboard cada 5 segundos.
   
## Dependencias
- [ArduinoHttpClient](https://github.com/arduino-libraries/ArduinoHttpClient) - Cliente HTTP para Arduino y ESP8266.
- [ESP8266WiFi](https://github.com/esp8266/Arduino) - Biblioteca para la conexión WiFi en el ESP8266.
- [PubSubClient](https://github.com/knolleary/pubsubclient) - Cliente MQTT para Arduino y ESP8266.
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson) - Biblioteca para manipulación y generación de documentos JSON.
- [ArduinoOTA](https://github.com/esp8266/Arduino/tree/master/libraries/ArduinoOTA) - Soporte para actualizaciones OTA (Over-The-Air).


## Notas adicionales

- Asegúrate de que la plataforma Thingsboard esté configurada para manejar tanto los datos JSON como los mensajes adicionales.
- Asegúrate de que los datos lleguen al topic de Telemetría.
- Monitoriza el uso de memoria para evitar problemas de memoria insuficiente.

## Contribuciones
Las contribuciones son bienvenidas. Si encuentras algún problema o tienes sugerencias para mejorar el código, siéntete libre de abrir un problema o enviar una solicitud de extracción.
