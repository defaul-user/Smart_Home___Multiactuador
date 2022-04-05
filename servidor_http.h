  
  #ifndef SERVIDOR_HTTP_H
  #define SERVIDOR_HTTP_H
  
    /* Librerias necesarias para el funcionamiento */
    
    #include <ESP8266WiFi.h>
    #include <ESP8266WebServer.h> //Servidor Web
    #include <ESP8266HTTPClient.h> // Cliente http
    #include "mensajes.h"
    
    
    /* IP del SERVIDOR WEB que recibira los datos del sensor de tª y humedad */
    
    #define SERVER_IP "192.168.1.225:8080" // IP OpenHab
    #define SERVER_IP_HTTP "192.168.1.225:9000" // IP ServidorWeb.jar

    
    /* Las siguientes variables se definen para no usar DHCP */
    
    IPAddress wifiIP(192,168,1,87); // IP que se asignara al esp8266
    IPAddress wifiNet(255,255,255,0); // Mascara de subred
    IPAddress wifiGW(192,168,1,1); // Router

    
    /* Servidor WEB */
    
    ESP8266WebServer servidorWeb(80); // Instanciar objeto servidor web
    
    
    /* Variable de estado de la conexion del servidor */
    
    typedef enum {CONECTADO, NCONECTADO} tEstadoConexion;
    tEstadoConexion estadoConexion;



    /* Cabeceras de las funciones */
    
    void arrancar_servidor_web(); // Funcion para incializar el servidor WEB  
    void manejadorServidor(); // GESTION CONEXION CON EL SERVIDOR 

    
    /*   HTTP   */
    
    void manejadorRaiz(); // Pagina inicial con el menu de opciones   
    void paginaNoEncontrada(); // Manejador para una pagina no encontrada o para una peticion no valida

    
    /* Funciones asociadas a cada peticion */
    
    /*  ACTUADOR ENCHUFE  */
    
    void manejadorEncendidoEnchufe();    
    void manejadorApagadoEnchufe();  
    void manejadorEstadoEnchufe();

    
    /*  INTERRUPTOR  */
    
    void manejadorEncendidoInterruptor();
    void manejadorApagadoInterruptor();   
    void manejadorEstadoInterruptor();
    
    
    /*  PERSIANA  */
    
    void manejadorPersianaSubir();    
    void manejadorPersianaBajar();    
    void manejadorPersianaParar();
  
  
  #endif
