
/************************************************************/
//Author - Creative KHOPDI
//https://www.youtube.com/c/CreativeKHOPDI
//https://youtu.be/FRuLvmUC410
/************************************************************/

// please connect the foolowing pins with vegetables through jumper wire

//T2 -->> GPIO2
//T3 -->> GPIO15
//T4 -->> GPIO13
//T5 -->> GPIO12
//T6 -->> GPIO14
//T7 -->> GPIO27
//T8 -->> GPIO33
//T9 -->> GPIO32

#define BUZZER_PIN          13                       //connect your speaker using pin no 13 and gnd
#define SOUND_PWM_CHANNEL   0
#define SOUND_RESOLUTION    8 // 8 bit resolution
#define SOUND_ON            (1<<(SOUND_RESOLUTION-1)) // 50% duty cycle
#define SOUND_OFF           0                         // 0% duty cycle
#define DELAY               220

int threshold = 38;                                   // CHANGE THE THRESHOLD AS PER YOUR HARDWARE REQUIREMENT
int threshold_banana = 27;                            // CHANGE THE THRESHOLD AS PER YOUR HARDWARE REQUIREMENT
bool touch1detected = false;
bool touch2detected = false;
bool touch3detected = false;
bool touch4detected = false;
bool touch5detected = false;
bool touch6detected = false;
bool touch7detected = false;
bool touch8detected = false;

void gotTouch1(){
 touch1detected = true;
}

void gotTouch2(){
 touch2detected = true;
}

void gotTouch3(){
 touch3detected = true;
}

void gotTouch4(){
 touch4detected = true;
}
void gotTouch5(){
 touch5detected = true;
}

void gotTouch6(){
 touch6detected = true;
}
void gotTouch7(){
 touch7detected = true;
}

void gotTouch8(){
 touch8detected = true;
}

void setup()
{
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");
  touchAttachInterrupt(T2, gotTouch1, threshold);
  touchAttachInterrupt(T3, gotTouch2, threshold_banana);
  touchAttachInterrupt(T4, gotTouch3, threshold);
  touchAttachInterrupt(T5, gotTouch4, threshold);
  touchAttachInterrupt(T6, gotTouch5, threshold);
  touchAttachInterrupt(T7, gotTouch6, threshold); 
  touchAttachInterrupt(T8, gotTouch7, threshold);
  touchAttachInterrupt(T9, gotTouch8, threshold);
}

void loop()
{

  if(touch2detected){
    touch2detected = false;
    tone (13, 40, DELAY);
    Serial.print("T2 ");
    Serial.println(touchRead(T3));
  }
    if(touch4detected){
    touch4detected = false;
    tone (13, 150, DELAY);
    Serial.print("T4 ");
    Serial.println(touchRead(T5));

  }
  if(touch5detected){
    touch5detected = false;
    tone (13, 240, DELAY);
    Serial.print("T5 ");
    Serial.println(touchRead(T6));

  }
    if(touch6detected){
    touch6detected = false;
    tone (13, 350, DELAY);
    Serial.print("T6 ");
    Serial.println(touchRead(T7));

  }
  if(touch7detected){
    touch7detected = false;
    tone (13, 470, DELAY);
    Serial.print("T7 ");
    Serial.println(touchRead(T8));
  }
    if(touch8detected){
    touch8detected = false;
    tone (13, 620, DELAY);
    Serial.print("T8 ");
    Serial.println(touchRead(T9));
  }

}

void tone(int pin, int frequency, int duration)
{
  ledcSetup(SOUND_PWM_CHANNEL, frequency, SOUND_RESOLUTION);  // Set up PWM channel
  ledcAttachPin(pin, SOUND_PWM_CHANNEL);                      // Attach channel to pin
  ledcWrite(SOUND_PWM_CHANNEL, SOUND_ON);
  delay(duration);
  ledcWrite(SOUND_PWM_CHANNEL, SOUND_OFF);
}
