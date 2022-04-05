 
  #ifndef SERVIDOR_MQTT_H
  #define SERVIDOR_MQTT_H
  
    #include <PubSubClient.h>
    #include "hardware.h"
    
    /* IP del BROKER MQTT (Raspberry en nuestro caso) */
    
    const char* mqtt_server = "192.168.1.225";
    
       
    /* IP del SERVIDOR WEB que recibira los datos del sensor de tª y humedad */
    
    #define SERVER_IP "192.168.1.225:8080" // IP OpenHab  
    
    
    /* Cliente ESP8266 (MQTT) */
    
    WiFiClient espClient;
    PubSubClient client(mqtt_server,1883,espClient); // 1883 es el puerto listener para el Broker
    //const char* clientID = "ESP8266_1";
    uint8_t intentos_conexion = 0; // Contador q usaremos para limitar el nº de intentos de conexion a la red wifi
    
    
    /* Variables correspondientes a los TOPIC SUB y PUB ( MQTT ) */
    
    const char* topic_pub = "casa/dormitorio/luztecho/estado";
    const char* topic_subs_enchufe = "casa/dormitorio/enchufe/orden"; // Variable Correspondiente al ACTUADOR ENCHUFE
    const char* topic_subs_interruptor = "casa/dormitorio/luztecho/orden";
    
    
    /* Variables para trabajar con los MENSAJES que se envían ( MQTT ) */
    
    char mensajeMQTT[50];
    long tiempoUltimoMnesaje = 0;
    
    
    /* Cabeceras de las funciones */
    
    void callback(char* topic, byte* payload, unsigned int length); // Funcion callback para los mensajes entrantes (llamadas) mqtt
    void reconnect(); // Funcion para reconectar en caso de perderse la conexion con el broker mqtt
    void mqtt_EnviarMensaje(); // Funcion para enciar mensajes cada 2 segundos
    void arrancar_servidor_mqtt();
    void manejadorServidorMQTT();
  
  #endif
