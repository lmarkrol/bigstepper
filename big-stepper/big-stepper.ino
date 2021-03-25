/*
  Stepper Motor Test
  stepper-test01.ino
  Uses MA860H or similar Stepper Driver Unit
  Has speed control & reverse switch

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Defin pins

int reverseSwitch = 2;  // Push button for reverse
int driverPUL = 7;    // PUL- pin
int driverDIR = 6;    // DIR- pin
//int driverENA = 8;    // ENA- pin
int spd = A0;     // Potentiometer

// Variables

int pd = 500;       // Pulse Delay period
boolean setdir = LOW; // Set Direction
//boolean setena = LOW; // Set ENAble

// Interrupt Handler

void revmotor (){

  setdir = !setdir;
 // setena = !setena;

}


void setup() {

  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
//  pinMode (driverENA, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(reverseSwitch), revmotor, FALLING);

}

void loop() {

    pd = map((analogRead(spd)),0,1023,2000,10);
//    pd = map((analogRead(spd)),0,1024,0,100);
    digitalWrite(driverDIR,setdir);
//    digitalWrite(driverENA,setena);
    digitalWrite(driverPUL,HIGH);
    delayMicroseconds(pd);
    digitalWrite(driverPUL,LOW);
    delayMicroseconds(pd);

}




//int reverseSwitch = 2;  // Push button for reverse
//int driverPUL = 7;    // PUL- pin
//int driverDIR = 6;    // DIR- pin
//int range = 10,
//    s = 50,
//    pd = 100;       // Pulse Delay period
//boolean setdir = LOW; // Set Direction
//
//void revmotor () {
//  setdir = !setdir;
//}
//
//void setup() {
//  Serial.begin(9600);
//  pinMode (driverPUL, OUTPUT);
//  pinMode (driverDIR, OUTPUT);
//  attachInterrupt(digitalPinToInterrupt(reverseSwitch), revmotor, FALLING);
//}
//
//void loop() {
//  if (Serial.available())
//  {
//    char spd = Serial.read();
//    if (spd == '+' || spd == 'a') pd += range;
//    else if (spd == '-' || spd == 'z') pd -= range;
//    Serial.println(pd);
//    if (pd > 100) pd = 100;
//    else if (pd < 0) pd = 0;
//    s = map(pd, 0, 100, 2000, 50);
//  }
//  digitalWrite(driverDIR, setdir);
//  digitalWrite(driverPUL, HIGH);
//  delayMicroseconds(s);
//  digitalWrite(driverPUL, LOW);
//  delayMicroseconds(s);
//}
