#include <L298N.h>
L298N myMotor(9,8,7);
int S0 = 2;
int S1 = 3;
int S2 = 4;
int S3 = 5;
int sensorOut = 6;
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;

void setup() {
  // put your setup code here, to run once:
myMotor.setSpeed(100);
pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

//Setting frequency scaling to 20%
digitalWrite(S0, HIGH);
digitalWrite(S1, LOW);

Serial.begin(9600);


}

void what_color (int minired,int maxired,int minigreen, int maxigreen, int miniblue, int maxiblue,String color){
  if (redfrequency > minired && redfrequency < maxired && greenfrequency < maxigreen && greenfrequency > minigreen && bluefrequency < maxiblue && bluefrequency > miniblue){
  Serial.println(color);
}
}


void loop() {
  // put your main code here, to run repeatedly:
  myMotor.forward();
    //Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  //Reading the output frequency
  redfrequency = pulseIn(sensorOut, LOW);

  //Print the value on serial monitor
  Serial.print("R= ");
  Serial.print(redfrequency);//printing red LED frequency
  Serial.print(" ");
  delay(100);

//Setting Green filtered photodiodes to be read
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);

//Reading the output frequency
greenfrequency = pulseIn(sensorOut, LOW);

//Printing the value on the serial monitor
Serial.print("G= ");
Serial.print(greenfrequency);
Serial.print(" ");
delay(100);

//Setting blue filtered photodiodes to read
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);

//Reading the output frequency
bluefrequency = pulseIn(sensorOut, LOW);

//Printing the value on the serial monitor
Serial.print("B= ");
Serial.print(bluefrequency);
Serial.println(" ");
delay(100);


//Find the color
what_color(0, 100, 0, 100, 0, 100, "BROWN");



Serial.println();
delay(500);
}
