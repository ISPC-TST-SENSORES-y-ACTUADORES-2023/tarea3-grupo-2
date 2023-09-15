#include "DHT.h" //Librería DHT11_22

DHT dht(2, DHT22); 
// DEclaracion de VARIABLES
  float xhumedad = 0;
  float xtemperatura =0;

  float xhumedadAux = 101;
  float xtemperaturaAux =81;


//SE utiliza potenciometro para simular el Sensor BMP280

  int XpresionAtmosferica = analogRead(A0);
  int XpresionAtmosfericaAux = 1001;  


void setup() {
  //Defino Los Pines Como Entrada
  pinMode(A0, INPUT);
  pinMode(2, INPUT);

  Serial.begin(9600); 
  dht.begin(); 

}

void loop() {

  xhumedad = dht.readHumidity(); //Leer humedad
  xtemperatura = dht.readTemperature(); //Leer temperatura    
  XpresionAtmosferica = analogRead(A0); // lEER seÑAL DE potenciometro

         if ((xhumedad != xhumedadAux) || (xtemperatura != xtemperaturaAux) ||(XpresionAtmosferica!=XpresionAtmosfericaAux))
          {
                xhumedadAux = xhumedad;   
                xtemperaturaAux =xtemperatura;
                XpresionAtmosfericaAux=XpresionAtmosferica;

                Serial.print("Humedad:"); 
                Serial.print(xhumedadAux);
                Serial.println("%"); 
                Serial.print("Temperatura:");
                Serial.print(xtemperaturaAux);
                Serial.print("°C");

                Serial.print(" Presion Atmosferica:");
                Serial.print(XpresionAtmosferica);  
                Serial.println("Pa"); 
          }
 }