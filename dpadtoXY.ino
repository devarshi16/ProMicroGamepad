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
  8, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, Z Axis
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
  Joystick.setXAxisRange(-1,1);
  Joystick.setYAxisRange(-1,1);
  Joystick.begin();
}

void loop() {
  //UP  
  if (digitalRead(UP_PIN) == LOW)
  {Joystick.setYAxis(-1);}
  if (digitalRead(DOWN_PIN) == LOW)//DOWN
  {Joystick.setYAxis(1);}
  if ((digitalRead(UP_PIN) == HIGH)&&(digitalRead(DOWN_PIN) == HIGH))
  {Joystick.setYAxis(0);}

  if (digitalRead(RIGHT_PIN) == LOW)//RIGHT
  {Joystick.setXAxis(1);}
  if (digitalRead(LEFT_PIN) == LOW)//LEFT
  {Joystick.setXAxis(-1);}
  if ((digitalRead(RIGHT_PIN) == HIGH)&&(digitalRead(LEFT_PIN) == HIGH))
  {Joystick.setXAxis(0);}

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
