//MIRANDO DE ATRAS HACIA ADELANTE
//SENSOR QTR
//#include <QTRSensors.h>
//#define NUM_SENSORS   1     
//#define TIMEOUT       2500  
//#define EMITTER_PIN   3    


//QTRSensorsRC qtrrc((unsigned char[]) {5},NUM_SENSORS, TIMEOUT, EMITTER_PIN);  // El 5 es el pin de out debe estar en un PWM
//unsigned int sensorValues[NUM_SENSORS];

//SENSORES ULTRASONICOS
//SENSOR
    int trig=2;
    int echo=3;
    
//ESTADO DEL SENSOR
    boolean sensor=false;
    
//MOTORES
    int out1=5;
    int out2=6; 
    
    int out3=12;
    int out4=11;

//PARA CALIBRAR

    int velGiro=80;  //velocidad giro
    int velArran=255; //velocidad arranque
    int velMin=100;    // velocidad minima
    int distSensor=50; //rango en cm para detectar objetivos
    int qtrSensor=200; // rango para la deteccion de linea blanca
    int distance=0;
// TEMPORALES
   int temporal=0;
void setup(){
    Serial.begin(9600);
       pinMode(trig,OUTPUT);
       pinMode(echo,INPUT);    
       pinMode(out1,OUTPUT);
       pinMode(out2,OUTPUT);
       pinMode(out3,OUTPUT);
       pinMode(out4,OUTPUT);
       pinMode(7,OUTPUT);
       digitalWrite(7,HIGH);
       delay(3300);
}
   
void loop(){
  /*      
      //sensorQTR();
      ultrasonico();
      // sensorQTR();
      primeraLinea();
      delayMicroseconds(1000);  
        if(sensor==true){
           // cuando detecte  a menos de 16 cm  al oponente se le lanza con todo
          if(distance<16){velArran=255; atras(); delay(400); Serial.println("Adelante Rapido");}
          else{
           velArran=velMin; 
           Serial.println("Despacio");
           atras();
           delay(400);
          }
        }
        if(sensor==false){
           Serial.println("GIRAR DERECHA");
           derecha(); 
        }
      Serial.println("");
      */
     // atras();
     adelanteA();
}
   
  
 void primeraLinea(){
     if(temporal==0){
       sensor=false;
       temporal=1; 
     }
 } 
 // TODO EL CODIGO DE LOS SENSORES

 
    void ultrasonico(){ // Distancia Del Ultrasonico 
      int distancia=calculoUltrasonico(trig,echo);
           distance=distancia;   
        if(distancia>=0 && distancia <= distSensor){
             sensor=true;
             Serial.println(distancia);
        }
        else{
             sensor=false; 
        }  
    }
    
     
int calculoUltrasonico(int trig, int echo){
    digitalWrite(trig, LOW);  // Inicializamos el senor
    delayMicroseconds(20);
    digitalWrite(trig, HIGH);  // Flanco ascendente
    delayMicroseconds(100);    // Duracion del pulso
    digitalWrite(trig, LOW);  // Flanco descendente   
    int duracion = pulseIn(echo, HIGH);
    int distancia = (duracion/2)/29;  
    return distancia;    
}

 //atrasD adelante  llanta izq
 // adelante D 
 
  void adelanteA(){
      atrasD(velArran);
    //  adelanteD(velArran);
  }

// CODIGO MOTORES //
void adelante(){
   //  adelanteI(velArran);
     adelanteD(velArran);
}


void atras(){
      atrasI(velArran);  
      atrasD(velArran);
}


void izquierda(){
      adelanteD(velGiro);
      atrasI(velGiro);
}

void derecha(){
      adelanteI(velGiro);
      atrasD(velGiro); 
}


void detener(){
     digitalWrite(out1,LOW);
     digitalWrite(out2,LOW);
     digitalWrite(out3,LOW);  
     digitalWrite(out4,LOW);  
}


void adelanteI(int velocidad){
  digitalWrite(out2,LOW);
  analogWrite(out1,velocidad);  
}

void adelanteD(int velocidad){
  digitalWrite(out4,LOW);
  analogWrite(out3,velocidad);  
}


void atrasI(int velocidad){
  digitalWrite(out1,LOW);
  analogWrite(out2,velocidad);  
}

void atrasD(int velocidad){
  digitalWrite(out3,LOW);
  analogWrite(out4,velocidad);  
}


/*void sensorQTR(){
  qtrrc.read(sensorValues);
  if(sensorValues[0]<=qtrSensor){
      atras();
      delay(1500);
      sensor=false;
  }
}*/

  
