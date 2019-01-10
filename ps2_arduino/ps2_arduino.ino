#include <PS2X_lib.h>                         /* PS2 Controller Library */
//#include <LiquidCrystal.h>                    /* LiquidCrystal Library */
PS2X ps2x;                                    /* create PS2 Controller Class*/
byte Type = 0;
byte vibrate = 0;
int RX=0,RY=0,LX=0,LY=0;
//LiquidCrystal Serial(2,3,7, 6, 5, 4);            /* initialize the library with the numbers of the interface pins*/
void setup(){
  Serial.begin(115200);
  // Serial.begin(16, 2);                             /* 16X2 Serial display */
   ps2x.config_gamepad(13,11,10,12, true, true); /* setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error*/
  //Type = ps2x.readType();                       /* Reading type of the PS2 Ccontroller */
   //if(Type==1){                                  /* Type 1 is Duel shock controller */ 
     // Serial.setCursor(0, 0);                       /* Setting display position*/
     // Serial.println("   DualShock    ");             /* display if the controller is duel shock*/
     // Serial.setCursor(0, 1) ;
     // Serial.println("Controller Found");
     // delay(1000);
   //   Serial.clear(); 
 //  }
}
void loop(){
 
   ps2x.read_gamepad(false, vibrate);   /* read controller and set large motor to spin at 'vibrate' speed */
  // Serial.setCursor(0, 0);                 /* Position the Serial cursor */
  // Serial.println("Stick values:   ");       /* Display analog stick values */
  // Serial.setCursor(0, 1);
   LY = ps2x.Analog(PSS_LY);          /* Reading Left stick Y axis */
   LX = ps2x.Analog(PSS_LX);          /* Reading Left stick X axis */
   RY = ps2x.Analog(PSS_RY);          /* Reading Right stick Y axis */
   RX = ps2x.Analog(PSS_RX);          /* Reading Right stick X axis */
   if((LY <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.println("00");                /* eg: if LY= 5 then it display as "005" in Serial */
   if((LY >= 9 &&LY <= 99))           /* standardize to 3 digit by checking between 10-99 */
      Serial.println("0");                 /* eg: if LY= 55 then it display as "055" in Serial */     
   Serial.println(LY,DEC);                 /* display left analog stick Y axis */
   Serial.println(",");                    /* separate values using comma */
   if((LX <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.println("00");                /* eg: if LX= 5 then it display as "005" in Serial */
   if((LX >= 9 && LX<=99))            /* standardize to 3 digit by checking between 10-99 */
      Serial.println("0");                 /* eg: if LX= 55 then it display as "055" in Serial */  
   Serial.println(LX,DEC);                 /* display left analog stick X axis */
   Serial.println(",");                    /* separate values using comma */
   if((RY <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.println("00");                /* eg: if RY= 5 then it display as "005" in Serial */
   if((RY >= 9 &&RY<=99))             /* standardize to 3 digit by checking between 10-99 */
      Serial.println("0");                 /* eg: if RY= 55 then it display as "055" in Serial */  
   Serial.println(RY,DEC);                 /* display Right analog stick Y axis               */
   Serial.println(",");                    /* separate values using comma */
   if((RX <= 9))                      /* standardize to 3 digit by checking less than 10 */
      Serial.println("00");                /* eg: if RX= 5 then it display as "005" in Serial */
   if((RX >= 9 &&RX <= 99))           /* standardize to 3 digit by checking between 10-99 */
      Serial.println("0");                 /* eg: if RX= 55 then it display as "055" in Serial */  
   Serial.println(RX,DEC);                 /* display Right analog stick X axis          */
   Serial.println(" ");
   if(ps2x.NewButtonState()) {        /* will be TRUE if any button changes state  */
//      Serial.setCursor(0, 0);
      if(ps2x.Button(PSB_START))      /* will be TRUE as long START button is pressed */
         Serial.println("START PRESSED   ");
      if(ps2x.Button(PSB_SELECT))             /* will be TRUE as long SELECT button is pressed */
         Serial.println("SELECT PRESSED  ");
      if(ps2x.Button(PSB_PAD_UP))             /* will be TRUE as long as UP button is pressed */
         Serial.println("UP PRESSED      "); 
      if(ps2x.Button(PSB_PAD_RIGHT))          /* will be TRUE as long as UP button is pressed */
         Serial.println("RIGHT PRESSED   ");
      if(ps2x.Button(PSB_PAD_LEFT))           /* will be TRUE as long as LEFT button is pressed */
         Serial.println("LEFT PRESSED    "); 
      if(ps2x.Button(PSB_PAD_DOWN))           /* will be TRUE as long as DOWN button is pressed */
         Serial.println("DOWN PRESSED    "); 
      if(ps2x.Button(PSB_L1))                 /* will be TRUE as long as L1 button is pressed */
         Serial.println("L1 pressed      ");
      if(ps2x.Button(PSB_R1))                 /* will be TRUE as long as R1 button is pressed */
         Serial.println("R1 pressed      "); 
      if(ps2x.Button(PSB_L2))                 /* will be TRUE as long as L2 button is pressed */
         Serial.println("L2 pressed      ");
      if(ps2x.Button(PSB_R2))                 /* will be TRUE as long as R2 button is pressed */
         Serial.println("R2 pressed      ");
      if(ps2x.Button(PSB_L3))                 /* will be TRUE as long as L3 button is pressed */
         Serial.println("L3 pressed      ");
      if(ps2x.Button(PSB_R3))                 /* will be TRUE as long as R3 button is pressed */
         Serial.println("R3 pressed      ");
      if(ps2x.Button(PSB_GREEN))              /* will be TRUE as long as GREEN/Triangle button is pressed */
         Serial.println("Triangle pressed");
      if(ps2x.Button(PSB_BLUE))                /* will be TRUE as long as BLUE/CROSS/X button is pressed */
         Serial.println("X pressed       "); 
       if(ps2x.Button(PSB_RED))               /* will be TRUE as long as RED/Circle button is pressed */
         Serial.println("Circle pressed  "); 
      if(ps2x.Button(PSB_PINK))               /* will be TRUE as long as PINK/Squre button is pressed */
         Serial.println("Square pressed  "); 
      delay(700);
   }
   else;
}
