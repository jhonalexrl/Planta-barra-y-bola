// Planificador
 
// -- Librerias ------------------------------------------
//Espacio para agregar las librerias necesitadas en el proyecto 

float dist();

//---Llamada a las diferentes tareas realizadas en .h----
#include "Pines.h"                                           // Configuracion de pines y shields a utilizar
#include "Distancia.h"  
#include "Led.h"                                            // Tarea para medir distancia para el uso en el planeador de tareas
#include "Pid.h"
#include "Comm.h"               // Tarea de comunicacion y algunos comandos para utilizar desde el puerto serial
#include "servomotor.h"


 
// -- Variables de control de tiempo ---------------------
 
unsigned long int T;     // Tiempo total (microsegundos)
 
// -- Variables de temporizacion de tareas ---------------

 
// Tarea 1: LED

unsigned long int ts1;   // Tiempo parcial (tarea 1)
unsigned long int t01;   // Tiempo de la ultima ejecucion

// Tarea 2: Control de sensor ultrasonico
//#define Ts2 50      // Periodo de la tarea 1
unsigned long int ts2;   // Tiempo parcial (tarea 1)
unsigned long int t02;   // Tiempo de la ultima ejecucion

// Tarea 3: Control de servomotor
#define Ts3 100       // Periodo de la tarea 1
unsigned long int ts3;   // Tiempo parcial (tarea 1)
unsigned long int t03;   // Tiempo de la ultima ejecucion
  
// -- Inicializacion -------------------------------------
 
void setup() {
  ts1 = 0;
  t01 = 0;
  ts2 = 0;
  t02 = 0;
  ts3 = 0;
  t03 = 0;
  SetupLED();
  SetupComm();
  SetupDist();
  SetupPid();
  Setupservo();
} 
 
// -- Bucle principal ------------------------------------
 
void loop(){
   // Actualizar tiempo
  T = millis();               // Tiempo de planeador basado en milisegundos
  // Temporizacion tarea 1
  ts1 = T - t01;
  if (ts1 >= Ts1) {
    UpdateLED();              // en este espacio se hace la llamada a la tarea de acuerdo a
    t01 = T;                  // la configuración de tiempos Ts1
  } 

    
  // Temporizacion tarea 1
  ts2 = T - t02;
  if (ts2 >= Ts2) {
   TareaPID();
    t02 = T;
  }

  }
