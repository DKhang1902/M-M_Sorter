#include <L298N.h>
L298N myMotor(10,8,7);
#include <Servo.h>
Servo myServo;
int S0 = 2;
int S1 = 3;
int S2 = 4;
int S3 = 5;
int sensorOut = 6;
int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;
String founded_color;

int servo_controller = 9;

//servo postion of cup: red, yellow, orange, blue, green, brown, other
int redPos = 92;
int yellowPos = 104;
int orangePos = 116;
int bluePos = 127;
int greenPos = 138;
int brownPos = 148;
int otherPos = 159;

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

//Set up servo
myServo.attach(servo_controller);
myServo.write(0);
delay(100);

Serial.begin(9600);


}

String what_color (int minired,int maxired,int minigreen, int maxigreen, int miniblue, int maxiblue,String color){
  if (redfrequency > minired && redfrequency < maxired && greenfrequency < maxigreen && greenfrequency > minigreen && bluefrequency < maxiblue && bluefrequency > miniblue){
  Serial.println(color);
  return color;
}
}

//Turn the servo
void turning_servo(String color){
  if (color == "RED"){
    myServo.write(redPos);
  }
  else if (color == "YELLOW"){
    myServo.write(yellowPos);
  }
   else if (color == "ORANGE"){
    myServo.write(orangePos);
  }
   else if (color == "BLUE"){
    myServo.write(bluePos);
  }
   else if (color == "GREEN"){
    myServo.write(greenPos);
  }
   else if (color == "BROWN"){
    myServo.write(brownPos);
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
founded_color= what_color(0, 100, 0, 100, 0, 100, "RED");
founded_color=what_color(0, 100, 0, 100, 0, 100, "YELLOW");
founded_color=what_color(0, 100, 0, 100, 0, 100, "ORANGE");
founded_color=what_color(0, 100, 0, 100, 0, 100, "BLUE");
founded_color=what_color(0, 100, 0, 100, 0, 100, "GREEN");
founded_color=what_color(0, 100, 0, 100, 0, 100, "BROWN");

turning_servo(founded_color);

Serial.println();
delay(500);
}
