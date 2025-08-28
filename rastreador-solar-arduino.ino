#include <Servo.h>

// Definindo as portas de leitura analógica
Servo servo;

int analogInPin1 = A0;
int analogInPin2 = A1;
int analogInPin3 = A2;
int analogInPin4 = A3;
int digitalInPin9 = 9;

int sensorValue;
int pos = 0;

void setup() {
  servo.attach(digitalInPin9);
  Serial.begin(9600);
}

void loop() {
  // Realiza a leitura e escita a cada intervalo de tempo
  const int sensorValue1 = analogRead(analogInPin1);
  const int sensorValue2 = analogRead(analogInPin2);
  const int sensorValue3 = analogRead(analogInPin3);
  const int sensorValue4 = analogRead(analogInPin4);

  // Envia os dados para a porta serial
  /*
  Serial.println("v1: " + String(sensorValue1));
  Serial.println("v2: " + String(sensorValue2));
  Serial.println("v3: " + String(sensorValue3));
  Serial.println("v4: " + String(sensorValue4));
*/

  float x1 = sensorValue1 + sensorValue4;
  float x2 = sensorValue1 + sensorValue2;

  float fx = (x2 - x1) / (x2 + x1);

  float y1 = sensorValue1 + sensorValue4;
  float y2 = sensorValue2 + sensorValue3;

  float fy = (y2 - y1) / (y2 + y1);

  const float c = 1.889;
  float angfx, angfy;
  
  if (fx != 0 || fy != 0) {
    angfx = atan(c * fx) * 180 / PI;
    angfy = atan(c * fy) * 180 / PI;
  }

  servo.write(angfx + 90);

}