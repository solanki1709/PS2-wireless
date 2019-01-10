#include <PS2X_lib.h>

#define data_pin 26
#define clock_pin 16
#define command_pin 27
#define attention_pin 36

boolean press_sens = false;  //disabled pressure sensitivity
boolean rumble_motor = false;  //disabled rumble motor

PS2X jstick;

int right_X = 0;
int left_X = 0;
int right_Y  = 0;
int left_Y = 0;

int mright_X = 0;
int mleft_X = 0;
int mright_Y  = 0;
int mleft_Y = 0;

void setup() 
{
  jstick.config_gamepad(clock_pin,command_pin,attention_pin,data_pin,press_sens,rumble_motor);
  Serial.begin(57600);
}

void loop() 
{
  jstick.read_gamepad();

  right_X = jstick.Analog(PSS_RX);
  right_Y = jstick.Analog(PSS_RY);
  left_X = jstick.Analog(PSS_LX);
  left_Y = jstick.Analog(PSS_LY);

  mright_X = map(right_X,0,255,-127,128);
  mright_Y = map(right_Y,0,255,128,-127);
  mleft_X = map(left_X,0,255,-127,128);
  mleft_Y = map(left_Y,0,255,128,-127);

  Serial.print("Right X:");
  Serial.print(mright_X);
  Serial.print("\t");

  Serial.print("Right Y:");
  Serial.print(mright_Y);
  Serial.print("\t");

  Serial.print("Left X:");
  Serial.print(mleft_X);
  Serial.print("\t");

  Serial.print("Left Y:");
  Serial.println(mleft_Y);

  delay(10);

}
