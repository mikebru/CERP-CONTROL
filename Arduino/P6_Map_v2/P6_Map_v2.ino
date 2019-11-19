const byte ledPin = 13; //led
//const byte interruptPin = 3; //hall sensor
const int pin1 = 2;
const int pin2 = 3;
const int pin3 = 4;
const int pin4 = 5;

const int signalPin = 7;

volatile byte state = LOW;

boolean onePin, twoPin, threePin, fourPin = false;
boolean oneCheck, twoCheck, threeCheck, fourCheck = false;


void setup() {
  pinMode(ledPin, OUTPUT);
  //pinMode(interruptPin, INPUT_PULLUP);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);

  pinMode(signalPin, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), test, CHANGE);
  Serial.begin(9600);
  Serial.println("active");
}

void loop() {
  /*
  digitalWrite(ledPin, state);
  Serial.println(state);

  if (state == HIGH) {
    digitalWrite(signalPin, state);
    Serial.println("Sent!");
  }
  */

  
 //Serial.println(digitalRead(pin1));

  onePin = !digitalRead(pin1);
  twoPin = !digitalRead(pin2);
  threePin = !digitalRead(pin3);
  fourPin = !digitalRead(pin4);

  if (onePin)
  {
    Serial.println("buoy1/1");
    oneCheck = true;  
  }else if(!onePin)
  {
    Serial.println("buoy1/0");
    oneCheck = false;  
  }
  
  if (twoPin)
  {
    Serial.println("buoy2/1");
    twoCheck = true;
  }else if(!twoPin)
  {
    Serial.println("buoy2/0");
    twoCheck = false;  
  }
  
  if (threePin)
  {
    Serial.println("buoy3/1");
    threeCheck = true;
  }else if(!threePin)
  {
    Serial.println("buoy3/0");
    threeCheck = false;  
  }
  
  
  if(fourPin && !fourCheck)
  {
    Serial.println("buoy4/1");
    fourCheck = true;
  }else if(!fourPin && fourCheck)
  {
    Serial.println("buoy4/0");
    fourCheck = false;  
  }

}

void test() {
  state = !state;
}
