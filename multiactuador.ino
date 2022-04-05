#include "hardware.h"
#include "gestorWifi.h"
#include "mensajes.h"
#include "servidor_http.h"


void setup() {

  gestionPulsador();
  
  Serial.begin(115200); // Establecer la velocidad de consola serie
  
  Serial.println("");
  
  setup_wifi();

  inicializarPines();
  
  arrancar_servidor_web();

  arrancar_servidor_mqtt();
  
} //end SETUP

void loop() {

  manejadorServidorMQTT();
  
  mqtt_EnviarMensaje();
 
  gestionPulsador();

  manejadorServidor(); // Gestión del servidor HTTP

  estadoWifi(); 
  
} //end LOOP
