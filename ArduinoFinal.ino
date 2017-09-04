#include <LowPower.h>

#include <SoftwareSerial.h>

#define Fila1 5
#define Fila2 6
#define Fila3 7
#define Fila4 8
#define Fila5 9
#define Fila6 12
#define Fila7 13



int Lecturas;
int Filas=8;
int Columnas=3;
int Medicion=0;
int n=0;
int FilaAlerta=0;
int Valor3=0;
int Valor2=0;
int Valor1=0;
float Resultado=0;
int m=0;
//char Sleep='AT+SLEEP';


SoftwareSerial Blue (4,3);



void setup() {
  Serial.begin(9600);
  Blue.begin (9600);
  pinMode(Fila1,OUTPUT);
  pinMode(Fila2,OUTPUT);
  pinMode(Fila3,OUTPUT);
  pinMode(Fila4,OUTPUT);
  pinMode(Fila5,OUTPUT);
  pinMode(Fila6,OUTPUT);
  pinMode(Fila7,OUTPUT);
  
  digitalWrite(Fila1,LOW);
  digitalWrite(Fila2,LOW);
  digitalWrite(Fila3,LOW);
  digitalWrite(Fila4,LOW);
  digitalWrite(Fila5,LOW);
  digitalWrite(Fila6,LOW);
  digitalWrite(Fila7,LOW);
  
  
  
  
}

void loop() {
  
 
 //Blue.write(Sleep);
 //delay(1000);
 
LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
   
  
 String Leer=" ";

    for (int i=1; i<8; i++)
    {  
      m=i+4;
      if (m==10)
      {
        m=12;
      }
      else if (m==11)
      {
        m=13;
        }
 
      for(int j=1; j<4; j++)
      {
        
    digitalWrite(m,HIGH);
    
    Lecturas = analogRead(j);
    delay(1);
    Leer =String(Lecturas);
    
    if (Lecturas>400)
    {
      FilaAlerta=i;
      Valor3=Valor2;
      Valor2=Valor1;
      Valor1=FilaAlerta;
      Resultado=(Valor1+Valor2+Valor3)/3;
      
      if(abs(Resultado-FilaAlerta)<0.0000001)
      {      
      if (FilaAlerta<3)
      {
        Blue.print('A');
        Blue.print(" ");
        
        }
      else if (2<FilaAlerta && FilaAlerta<6)
      {
        Blue.print('B');
        Blue.print(" ");
        
        }
      else
      {
        Blue.print('C');
        Blue.print(" ");
        }
      Valor3=0;
      Valor2=0;
      Valor1=0;
      
      }
    }
//// 
      
//      Blue.write("HHHHHHHHHHHHHHH");
//      Blue.print(" ");
      
      Blue.print(Leer);
      Blue.print(" ");
      Blue.flush();
//     if (Lecturas>600)
//    {
//      FilaAlerta=i;
//      Valor3=Valor2;
//      Valor2=Valor1;
//      Valor1=FilaAlerta;
//      Resultado=(Valor1+Valor2+Valor3)/3;
//      if(Resultado-FilaAlerta<1.e-7)
//      {      
//      if (FilaAlerta<5)
//      {
//        Blue.print('A');
//        Blue.print(" ");
//        
//        }
//      else if (5<FilaAlerta && FilaAlerta<7)
//      {
//        Blue.print('B');
//        Blue.print(" ");
//        
//        }
//      else
//      {
//        Blue.print('C');
//        Blue.print(" ");
//        }
//      }
//    }    
//     
      }
    digitalWrite(m,LOW);  
    }




  

}
