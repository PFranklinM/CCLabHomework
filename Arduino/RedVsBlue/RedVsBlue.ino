int ledBlue = 12;
int ledRed = 13;

int buttonPinBlue = 2;
int buttonPinRed = 3;

int buttonStateBlue = 0;
int buttonStateRed = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledBlue, OUTPUT);
  pinMode(buttonPinBlue, INPUT);

  pinMode(ledRed, OUTPUT);
  pinMode(buttonPinRed, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonStateBlue = digitalRead(buttonPinBlue);

  if(buttonStateBlue == HIGH){
    digitalWrite(ledBlue, HIGH);
    delay(0);
  }else{
    digitalWrite(ledBlue, LOW);
    delay(0);
  }

  buttonStateRed = digitalRead(buttonPinRed);

  if(buttonStateRed == HIGH){
    digitalWrite(ledRed, HIGH);
    delay(0);
  }else{
    digitalWrite(ledRed, LOW);
    delay(0);
  }
  
 }
