/* 
 * THIS IS A CODE FOR INTERFACING WIRELESS PS2 CONTROLLER WITH SRA128 BOARD.
 * REFERENCE: http://www.techmonkeybusiness.com/using-a-playstation-2-controller-with-your-arduino-project.html
 *            http://www.billporter.info/2010/06/05/playstation-2-controller-arduino-library-v1-0/
 * DATA PIN IS CONNECTED TO GO -- PIN 26  
 * COMMAND PIN IS CONNECTED TO G1 -- PIN 27
 * ATTENTION PIN IS CONNECTED TO G2 -- PIN 36
 * CLOCK PIN IS CONNECTED TO G3 -- PIN 16
 * THE CONTROLLER IS OPERATED AT 5V.
 */

#include <megaPinDefs.h>
#include <PS2X_lib.h>

#define data_pin 26
#define clock_pin 16
#define command_pin 27
#define attention_pin 36

boolean press_sens = false;  //disabled pressure sensitivity
boolean rumble_motor = false;  //disabled rumble motor

PS2X jstick;

void setup() 
{
  jstick.config_gamepad(clock_pin,command_pin,attention_pin,data_pin,press_sens,rumble_motor);
  Serial.begin(57600);
}

void loop() 
{
  jstick.read_gamepad();
  
  delay(10);
  
  if(jstick.ButtonPressed(PSB_START))
    Serial.println("Start pressed");

  else if(jstick.ButtonPressed(PSB_SELECT))
    Serial.println("Select pressed");
  
  else if(jstick.Button(PSB_L2))
    Serial.println("L2 pressed");
    
  else if (jstick.Button(PSB_L1))
    Serial.println("L1 pressed");
  
  else if (jstick.Button(PSB_L3))
    Serial.println("L3 pressed");
  
  else if (jstick.Button(PSB_R3))
    Serial.println("R3 pressed");
  
  else if (jstick.Button(PSB_R1))
    Serial.println("R1 pressed");
  
  else if (jstick.Button(PSB_R2))
    Serial.println("R2 pressed");
  
  else if (jstick.Button(PSB_PAD_UP))
    Serial.println("Up pressed");
  
  else if (jstick.Button(PSB_PAD_DOWN))
    Serial.println("Down pressed");
  
  else if (jstick.Button(PSB_PAD_RIGHT))
    Serial.println("Right pressed");
  
  else if (jstick.Button(PSB_PAD_LEFT))
    Serial.println("Left pressed");
  
  else if (jstick.ButtonPressed(PSB_TRIANGLE))
    Serial.println("Triangle pressed");
  
  else if (jstick.ButtonPressed(PSB_SQUARE))
    Serial.println("Square pressed");
  
  else if (jstick.ButtonPressed(PSB_CROSS))
    Serial.println("Cross pressed");
  
  else if (jstick.ButtonPressed(PSB_CIRCLE))
    Serial.println("Circle pressed");
}
