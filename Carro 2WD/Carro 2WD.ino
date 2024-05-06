#include <HCSR04.h>

// Initialize sensor that uses digital pins 13 and 12.
const byte triggerPin = 4;
const byte echoPin = 5;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

int motorA_PWM = 10; //Controle de velocidade do motor A (Esquerdo)
int motorB_PWM = 11; //Controle de velocidade do motor B (Direito)
int motorA_EN = 12; //Controle de direção do motor A (Esquerdo))
int motorB_EN = 13; //Controle de direção do motor B (Direito)
 //variável para controle de velocidade de rotação dos motores,sendo 0 o valor de velocidade mínimo e 255 o valor de velocidade máxima. 
void setup(){ 

  Serial.begin(9600); //Inicializa a comunicação serial
  

  pinMode (motorA_PWM, OUTPUT);
  pinMode (motorA_EN, OUTPUT);
  pinMode (motorB_PWM, OUTPUT);
  pinMode (motorB_EN, OUTPUT);
}
void loop(){ 
  

  float distance = distanceSensor.measureDistanceCm();
  Serial.println(distance);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(distance);
 
  if (distance >= 0 && distance <= 25){
    parar();
    
  }else{
    frente();
  }
  

  
  
}


void frente(){
  digitalWrite(motorA_EN, HIGH); //Motor A. HIGH = HORARIO
  digitalWrite(motorB_EN, HIGH); //Motor B. HIGH = HORARIO
  
  analogWrite(motorA_PWM, 0); //PWM do motor esquerdo 
  analogWrite(motorB_PWM, 0); //PWM do motor direito 
}

void parar(){
  digitalWrite(motorA_EN, LOW); //Motor A. HIGH = HORARIO
  digitalWrite(motorB_EN, LOW); //Motor B. HIGH = HORARIO
  analogWrite(motorA_PWM, 255); //PWM do motor esquerdo 
  analogWrite(motorB_PWM, 255); //PWM do motor direito 
  delay(2000);
  digitalWrite(motorA_EN, HIGH); //Motor A. HIGH = HORARIO
  digitalWrite(motorB_EN, LOW); //Motor B. HIGH = HORARIO
  analogWrite(motorA_PWM, 0); //PWM do motor esquerdo 
  analogWrite(motorB_PWM, 255); //PWM do motor direito 
  delay(1000);
}
