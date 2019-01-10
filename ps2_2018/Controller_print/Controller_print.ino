#include <pinDefsAutoNew.h>
#include <io128.h>
#include <sra128.h>
#include "avr/io.h"
#include <psx.h>
#include <psx2.h>

#define joystickBuffer 35

int LX = 0, LY = 0, RX = 0, RY = 0;

void setup() 
{
  psx_init(&PORTG, 0, &PORTG, 3, &PORTG, 1, &PORTG, 2);
  Serial.begin(57600);
  Serial.println("Setup Done!");
}

void loop()
{
  psx_read_gamepad();
  if (LX == 128 && LY == (-128) && RX == 128 && RY == (-128)) 
  {
      LX = (psx_stick(PSS_LX)) - 127;
      LY = 127 - (psx_stick(PSS_LY));
      RX = (psx_stick(PSS_RX)) - 127;
      RY =  127 - (psx_stick(PSS_RY)) ;
      Serial.println("Controller Disconnected");
      psx_init(&PORTG, 0, &PORTG, 3, &PORTG, 1, &PORTG, 2);
  }
  else
  {
     if(psx_button_press(PSB_L1)){
      Serial.println("L1");
    }
    else if(psx_button_press(PSB_L2)){
      Serial.println("L2");
    }
    else if(psx_button_press(PSB_R1)){
      Serial.println("R1");
    }
    else if(psx_button_press(PSB_R2)){
      Serial.println("R2");
    }
    else if(psx_button_press(PSB_SELECT)){
      Serial.println("select");
    }
    else if(psx_button_press(PSB_START)){
      Serial.println("start");
    }
    else if(psx_button_press(PSB_L3)){
      Serial.println("L3");
    }
    else if(psx_button_press(PSB_R3)){
      Serial.println("R3");
    }
   /* else
    {
      Serial.println("No button pressed");
    }
    
    }   */
  }
}

