
const int pin1 = 7;
const int pin2 = 4; // Pin connected to reed switch
const int pin3 = 5;
const int pin4 = 6;

const int LED_PIN = 13; // LED pin - active-high

boolean oneCheck, twoCheck, threeCheck, fourCheck = false;

void setup()
{
  Serial.begin(9600);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);

  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int onePin = !digitalRead(pin1);
  int twoPin = !digitalRead(pin2);
  int threePin = !digitalRead(pin3);
  int fourPin = !digitalRead(pin4);

  if (onePin && !oneCheck)
  {
    Serial.println("buoy1/1");
    oneCheck = true;
  } else if (!onePin && oneCheck)
  {
    Serial.println("buoy1/0");
    oneCheck = false;
  }

  if (twoPin && !twoCheck)
  {
    Serial.println("buoy2/1");
    twoCheck = true;
  } else if (!twoPin && twoCheck)
  {
    Serial.println("buoy2/0");
    twoCheck = false;
  }

  if (threePin && !threeCheck)
  {
    Serial.println("buoy3/1");
    threeCheck = true;
  } else if (!threePin && threeCheck)
  {
    Serial.println("buoy3/0");
    threeCheck = false;
  }


  if (fourPin && !fourCheck)
  {
    Serial.println("buoy4/1");
    fourCheck = true;
  } else if (!fourPin && fourCheck)
  {
    Serial.println("buoy4/0");
    fourCheck = false;
  }

}
