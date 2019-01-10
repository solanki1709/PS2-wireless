#include <PS2X_lib.h>  //for v1.6
#include <megaPinDefs.h>

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you conect the controller, 
//or call config_gamepad(pins) again after connecting the controller.
int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup(){
 Serial.begin(115200);

 //CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************
  
 error = ps2x.config_gamepad(16,27,36,26, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
}
void loop() {
 //DualShock Controller
  
    //ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
    
    if(ps2x.Button(PSB_START))                   //will be TRUE as long as button is pressed
         Serial.println("Start is being held");
    else if(ps2x.Button(PSB_SELECT))
         Serial.println("Select is being held");
         
         
     else if(ps2x.Button(PSB_PAD_UP)) {         //will be TRUE as long as button is pressed
       Serial.print("Up held this hard: ");
      // Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
      }
     else if(ps2x.Button(PSB_PAD_RIGHT)){
       Serial.print("Right held this hard: ");
        //Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
      }
      else if(ps2x.Button(PSB_PAD_LEFT)){
       Serial.print("LEFT held this hard: ");
        //Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
      }
      else if(ps2x.Button(PSB_PAD_DOWN)){
       Serial.print("DOWN held this hard: ");
     //Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
      }   
  
    
   //   vibrate = ps2x.Analog(PSAB_BLUE);        //this will set the large motor vibrate speed based on 
                                              //how hard you press the blue (X) button    
    
    else if (ps2x.NewButtonState())               //will be TRUE if any button changes state (on to off, or off to on)
    {
     
       
         
        if(ps2x.Button(PSB_L3))
         Serial.println("L3 pressed");
        else if(ps2x.Button(PSB_R3))
         Serial.println("R3 pressed");
        else if(ps2x.Button(PSB_L2))
         Serial.println("L2 pressed");
        else if(ps2x.Button(PSB_R2))
         Serial.println("R2 pressed");
        else if(ps2x.Button(PSB_GREEN))
         Serial.println("Triangle pressed");
         
    }   
         
    
    if(ps2x.ButtonPressed(PSB_RED))             //will be TRUE if button was JUST pressed
         Serial.println("Circle just pressed");
         
   else if(ps2x.ButtonReleased(PSB_PINK))             //will be TRUE if button was JUST released
         Serial.println("Square just released");     
    
    else if(ps2x.NewButtonState(PSB_BLUE))            //will be TRUE if button was JUST pressed OR released
         Serial.println("X just changed");    
    
    
    else if(ps2x.Button(PSB_L1))
    Serial.println("L1 pressed");
    else if(ps2x.Button(PSB_R1))
    Serial.println("R1 pressed");
    
    // print stick values if either is TRUE
  /*  {
        Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_LX), DEC); 
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_RY), DEC); 
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_RX), DEC); 
    } */
    delay(50);
 }
 
