const byte ledPin = 13; //led

const byte buoyOnePin = 3; //hall sensor
const byte buoyTwoPin = 4; //hall sensor
const byte buoyThreePin = 5; //hall sensor
const byte buoyFourPin = 6; //hall sensor


const int signalPin = 7;

volatile byte buoyOneState = LOW;
volatile byte buoyTwoState = LOW;
volatile byte buoyThreeState = LOW;
volatile byte buoyFourState = LOW;

void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(signalPin, OUTPUT);

  pinMode(buoyOnePin, INPUT_PULLUP);
  pinMode(buoyTwoPin, INPUT_PULLUP);
  pinMode(buoyThreePin, INPUT_PULLUP);
  pinMode(buoyFourPin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(buoyOnePin), BuoyOneCheck, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buoyTwoPin), BuoyTwoCheck, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buoyThreePin), BuoyThreeCheck, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buoyFourPin), BuoyFourCheck, CHANGE);

  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, buoyOneState);
  //Serial.println(state);

  if (buoyOneState == HIGH) {
    digitalWrite(signalPin, buoyOneState);
    //Serial.println("Sent!");
  }
}


//called when Hall sensor detects change 
void BuoyOneCheck() {
  buoyOneState = !buoyOneState;
  Serial.println("buoy/1/" + buoyOneState);  
}

void BuoyTwoCheck() {
  buoyTwoState = !buoyTwoState;
  Serial.println("buoy/2/" + buoyTwoState);  
}

void BuoyThreeCheck() {
  buoyThreeState = !buoyThreeState;
  Serial.println("buoy/3/" + buoyThreeState);  
}

void BuoyFourCheck() {
  buoyFourState = !buoyFourState;
  Serial.println("buoy/4/" + buoyFourState);  
}




