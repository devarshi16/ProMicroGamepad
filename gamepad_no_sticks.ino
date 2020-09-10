#include <Joystick.h>
#define UP_PIN 5
#define DOWN_PIN 6
#define LEFT_PIN 4
#define RIGHT_PIN 7
#define X_KEY_PIN 10
#define Y_KEY_PIN 16
#define A_KEY_PIN 14
#define B_KEY_PIN 15
#define START_PIN 8
#define SELECT_PIN 9
#define L_KEY_PIN 3
#define R_KEY_PIN 2

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 1,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, Z Axis
  false, false, false,   //  Rx, Ry, Rz
  false, false,          //  rudder, throttle
  false, false, false);  // accelerator, brake, steering

void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  //Analog pins don't need setup
  
  // Initialize Joystick Library
  Joystick.setXAxisRange(-127,127);
  Joystick.setYAxisRange(-127,127);
  Joystick.setRxAxisRange(-127,127);
  Joystick.setRyAxisRange(-127,127);
  Joystick.setThrottleRange(-1,1);
  Joystick.setRudderRange(-1,1);
  Joystick.begin();
}

//Joy1
int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;
//Joy2
int xPosition1 = 0;
int yPosition1 = 0;
int mapX1 = 0;
int mapY1 = 0;

void loop() {
  // JOY1
  xPosition = analogRead(A0);
  delay(2);
 //Delay between reading analog inputs
  yPosition = analogRead(A1);
  delay(2);
  xPosition1 = analogRead(A2);
  delay(2);
  yPosition1 = analogRead(A3);
  delay(2);
  
  mapX = map(xPosition, 0, 1023, -127, 127);
  mapY = map(yPosition, 0, 1023, -127, 127);
  mapX1 = map(xPosition1, 0, 1023, -127, 127);
  mapY1 = map(yPosition1, 0, 1023, -127, 127);
  if (mapX>10)
  {Joystick.setXAxis(mapX);}
  else if (mapX<-10)
  {Joystick.setXAxis(mapX);}
  else
  {Joystick.setXAxis(0);}

  if (mapY >10)
  {Joystick.setYAxis(mapY);}
  else if (mapY < -10)
  {Joystick.setYAxis(mapY);}
  else
  {Joystick.setYAxis(0);}
  

  if (mapX1>10)
  {Joystick.setRxAxis(mapX1);}
  else if (mapX<-10)
  {Joystick.setRxAxis(mapX1);}
  else
  {Joystick.setRxAxis(0);}

  if (mapY1 >10)
  {Joystick.setRyAxis(mapY1);}
  else if (mapY < -10)
  {Joystick.setRyAxis(mapY1);}
  else
  {Joystick.setRyAxis(0);}

  //UP
  if (digitalRead(UP_PIN) == LOW)
  {Joystick.setHatSwitch(0,0);}
  //DOWN
  else if (digitalRead(DOWN_PIN) == LOW)
  {Joystick.setHatSwitch(0,180);}
  //LEFT
  else if (digitalRead(LEFT_PIN) == LOW)
  {Joystick.setHatSwitch(0,270);}
  //RIGHT
  else if (digitalRead(RIGHT_PIN) == LOW)
  {Joystick.setHatSwitch(0,90);}
  else
  {Joystick.setHatSwitch(0,-1);}

  // A_KEY
  if (digitalRead(A_KEY_PIN) == HIGH)
  {Joystick.setButton(0, LOW);}
  else
  {Joystick.setButton(0, HIGH);}

  // B_KEY
  if (digitalRead(B_KEY_PIN) == HIGH)
  {Joystick.setButton(1, LOW);}
  else
  {Joystick.setButton(1, HIGH);}

  // X_KEY
  if (digitalRead(X_KEY_PIN) == HIGH)
  {Joystick.setButton(2, LOW);}
  else
  {Joystick.setButton(2, HIGH);}

  // Y_KEY
  if (digitalRead(Y_KEY_PIN) == HIGH)
  {Joystick.setButton(3, LOW);}
  else
  {Joystick.setButton(3, HIGH);}
  
  // L_KEY_PIN
  if (digitalRead(L_KEY_PIN) == HIGH)
  {Joystick.setButton(4, LOW);}
  else
  {Joystick.setButton(4, HIGH);}

  // R_KEY_PIN
  if (digitalRead(R_KEY_PIN) == HIGH)
  {Joystick.setButton(5, LOW);}
  else
  {Joystick.setButton(5, HIGH);}

  // START
  if (digitalRead(START_PIN) == HIGH)
  {Joystick.setButton(7, LOW);}
  else
  {Joystick.setButton(7, HIGH);}

  // SELECT
  if (digitalRead(SELECT_PIN) == HIGH)
  {Joystick.setButton(6, LOW);}
  else
  {Joystick.setButton(6, HIGH);}

  delay(10);
   
}
