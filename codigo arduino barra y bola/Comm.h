/*************************************************************
 * 
 * tarea de comunicacion
 * 
 * No debe llamarse puesto que se usa serial event, en el String s queda 
 * los datos de las comunicaciones
 * 
 **********************************************************/
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin


#pragma once

//String val = "0" ;
String Temporal = "0" ;
String s = ""; 
// Configuracion de la comunicacion para el desarrollo

void SetupComm() {
  // put your setup code here, to run once:
Serial.begin(BAUD_RATE);     //Configura velocidad de comunicacion, inicializa puerto
}


void serialEvent() 
{ s="";   //incia la variable en vacio
  while (Serial.available())          //Mientras haya datos disponibles en el puerto serial
  {   char c = Serial.read();         //guarda en c lo que tiene el puerto serial
      while ( c != '\n' )            //Hasta que el caracter sea intro
        {     s = s + c ;             //concatenamos c con lo que tenia s
              delay(1);               //espera 1 ms
              c = Serial.read();      //guarda en c lo que tiene el puerto serial
        }
  }
    if ( s.startsWith("sp="))          //Si la cadena s inicia con "sp="
     {
        String Temp = s.substring(3);
      //  Serial.println(Temp);
//        Setpoint=Temp.toInt(); 

     }
    if ( s.startsWith("rc="))         //Si la cadena s inicia con "rc="
    {
      String Temp = s.substring(3);
    //Setpoint=Temp.toInt(); 
   //  digitalWrite(ledPin,LOW);       //pin apaga
    }

    if ( s.startsWith("d?"))           //Si la cadena s inicia con "d?"
    {
    Serial.println(dist());           // el pin invierte su estado
    }
    
 if ( s.startsWith("grad="))                                    //Si la cadena s inicia con "Distancia"
    {
  Temporal =  s.substring(5);
  val= Temporal.toInt();
   myservo.write(val);
}
}
