// Simple gamepad example that demonstraits how to read five Arduino
// digital pins and map them to the Arduino Joystick library.
//
// The digital pins 2 - 6 are grounded when they are pressed.
// Pin 2 = UP
// Pin 3 = RIGHT
// Pin 4 = DOWN
// Pin 5 = LEFT
// Pin 6 = FIRE
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus
// 2016-11-24
//--------------------------------------------------------------------

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
  true, true, false,     // X and Y, Z Axis
  true, true, false,   //  Rx, Ry, Rz
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
  //pinMode(A0,INPUT);
  //pinMode(A1,INPUT);
  //pinMode(A2,INPUT_PULLUP);
  //pinMode(A3,INPUT_PULLUP);
  
  // Initialize Joystick Library
  Joystick.setXAxisRange(-127,127);
  Joystick.setYAxisRange(-127,127);
  Joystick.setRxAxisRange(-127,127);
  Joystick.setRyAxisRange(-127,127);
  Joystick.setThrottleRange(-1,1);
  Joystick.setRudderRange(-1,1);
  Joystick.begin();

  //Joystick.setZAxisRange(-1, 1);
//  Joystick.setRZAxisRange(-1, 1);

}

// Last state of the buttons
int lastButtonState[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
int usedPins[12] = {2,3,4,5,6,7,8,9,10,14,15,16};
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

/*
  //UP
  if (digitalRead(UP_PIN)==LOW)
  {Joystick.setRudder(1);}
  //DOWN
  if (digitalRead(DOWN_PIN)==LOW)
  {Joystick.setRudder(-1);}
  if ((digitalRead(UP_PIN)==HIGH) && (digitalRead(DOWN_PIN)==HIGH))
  {Joystick.setRudder(0);}
  //RIGHT
  if (digitalRead(RIGHT_PIN)==LOW)
  {Joystick.setThrottle(1);}
  //LEFT
  if (digitalRead(LEFT_PIN)==LOW)
  {Joystick.setThrottle(-1);}
  if ((digitalRead(RIGHT_PIN)==HIGH) && (digitalRead(LEFT_PIN)==HIGH))
  {Joystick.setThrottle(0);}
  */
  

  // JOY1
  xPosition = analogRead(A0);
  delay(2);
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

  /*
  //DOWN
  if (digitalRead(DOWN_PIN) == HIGH)
  {Joystick.setButton(1, LOW);}
  else
  {Joystick.setButton(1, HIGH);}

  //LEFT
  if (digitalRead(LEFT_PIN) == HIGH)
  {Joystick.setButton(2, LOW);}
  else
  {Joystick.setButton(2, HIGH);}

  //RIGHT
  if (digitalRead(RIGHT_PIN) == HIGH)
  {Joystick.setButton(3, LOW);}
  else
  {Joystick.setButton(3, HIGH);}
*/

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
  /*
  // Read pin values for other buttons
  for (int index = 0; index < 12; index++)
  {
    currentButton = usedPins[index]
    int currentButtonState = !digitalRead(currentButton);
    if (currentButtonState != lastButtonState[index])
    {
      switch (currentButton) {
        case UP_PIN: // UP
          if (currentButtonState == 1) {
            Joystick.setYAxis(1);
          } else {
            Joystick.setYAxis(0);
          }
          break;r
        case RIGHT_PIN: // RIGHT
          if (currentButtonState == 1) {
            Joystick.setXAxis(1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case DOWN_PIN: // DOWN
          if (currentButtonState == 1) {
            Joystick.setYAxis(-1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case LEFT_PIN: // LEFT
          if (currentButtonState == 1) {
            Joystick.setXAxis(-1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case X_KEY_PIN: //FIRE
          Joystick.setButton(0, currentButtonState);
          break;
        case Y_KEY_PIN:
          Joystick.setButton(1, currentButtonState);
          break;
        case A_KEY_PIN:
          Joystick.setButton(2, currentButtonState);
          break;
        case B_KEY_PIN:
          Joystick.setButton(3, currentButtonState);
          break;
        case START_PIN:
          Joystick.setButton(4, currentButtonState);
          break;
        case SELECT_PIN:
          Joystick.setButton(5, currentButtonState);
          break;
        case L_KEY_PIN:
          Joystick.setButton(6, currentButtonState);
          break;
        case R_KEY_PIN:
          Joystick.setButton(7, currentButtonState);
          break;
      }
      lastButtonState[index] = currentButtonState;
    }
  */

 
}
/*
 *
 * #include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  13, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

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
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);



  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-512, 512);
  Joystick.setYAxisRange(-512, 512);
}


void loop() {
  if (analogRead(A0) < 500)
  {Joystick.setXAxis(analogRead(A0)-512);}
  else if (analogRead(A0) > 524)
  {Joystick.setXAxis(analogRead(A0)-511);}
  else
  {Joystick.setXAxis(0);}

  if (analogRead(A1) < 500)
  {Joystick.setYAxis(analogRead(A1)-512);}
  else if (analogRead(A1) > 524)
  {Joystick.setYAxis(analogRead(A1)-511);}
  else
  {Joystick.setYAxis(0);}

  if (digitalRead(2) == HIGH)
  {Joystick.setButton(0, LOW);}
  else
  {Joystick.setButton(0, HIGH);}
 
  if (digitalRead(3) == HIGH)
  {Joystick.setButton(1, LOW);}
  else
  {Joystick.setButton(1, HIGH);}

  if (digitalRead(4) == HIGH)
  {Joystick.setButton(2, LOW);}
  else
  {Joystick.setButton(2, HIGH);}

  if (digitalRead(5) == HIGH)
  {Joystick.setButton(3, LOW);}
  else
  {Joystick.setButton(3, HIGH);}

  if (digitalRead(6) == HIGH)
  {Joystick.setButton(4, LOW);}
  else
  {Joystick.setButton(4, HIGH);}

  if (digitalRead(7) == HIGH)
  {Joystick.setButton(5, LOW);}
  else
  {Joystick.setButton(5, HIGH);}

  if (digitalRead(8) == HIGH)
  {Joystick.setButton(6, LOW);}
  else
  {Joystick.setButton(6, HIGH);}

  if (digitalRead(9) == HIGH)
  {Joystick.setButton(7, LOW);}
  else
  {Joystick.setButton(7, HIGH);}

  if (digitalRead(10) == HIGH)
  {Joystick.setButton(8, LOW);}
  else
  {Joystick.setButton(8, HIGH);}

   if (digitalRead(11) == HIGH)
  {Joystick.setButton(9, LOW);}
  else
  {Joystick.setButton(9, HIGH);}

  if (digitalRead(12) == HIGH)
  {Joystick.setButton(10, LOW);}
  else
  {Joystick.setButton(10, HIGH);}

  if (digitalRead(13) == HIGH)
  {Joystick.setButton(11, LOW);}
  else
  {Joystick.setButton(11, HIGH);}
 
  if (digitalRead(A4) == HIGH)
  {Joystick.setButton(12, LOW);}
  else
  {Joystick.setButton(12, HIGH);}

 
 
  delay(10);
}*/
