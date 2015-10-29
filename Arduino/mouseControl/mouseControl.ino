int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

int ledbot = 13;
int ledright = 12;
int ledtop = 11;
int ledleft = 10;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  pinMode(ledbot, OUTPUT);
  pinMode(ledright, OUTPUT);
  pinMode(ledtop, OUTPUT);
  pinMode(ledleft, OUTPUT);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); 
  
  // For versions prior to Arduino 1.0.1
  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);
  
}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  if(xPosition > 501){
    digitalWrite(ledleft, HIGH);
    digitalWrite(ledbot, LOW);
    digitalWrite(ledright, LOW);
    digitalWrite(ledtop, LOW);
//    delay(0);
  } 
  
  if(xPosition < 499){
    digitalWrite(ledright, HIGH);
    digitalWrite(ledbot, LOW);
    digitalWrite(ledleft, LOW);
    digitalWrite(ledtop, LOW);
//    delay(0);
  }
  
  if(yPosition < 514){
    digitalWrite(ledright, LOW);
    digitalWrite(ledbot, LOW);
    digitalWrite(ledleft, LOW);
    digitalWrite(ledtop, HIGH);
//    delay(0);
  }
  
  if(yPosition > 516){
    digitalWrite(ledright, LOW);
    digitalWrite(ledbot, HIGH);
    digitalWrite(ledleft, LOW);
    digitalWrite(ledtop, LOW);
//    delay(0);
  }

  if(xPosition > 501 && yPosition < 514){
    digitalWrite(ledright, LOW);
    digitalWrite(ledbot, LOW);
    digitalWrite(ledleft, HIGH);
    digitalWrite(ledtop, HIGH);
//    delay(0);
  }
  
  if(xPosition > 501 && yPosition > 516){
    digitalWrite(ledright, LOW);
    digitalWrite(ledbot, HIGH);
    digitalWrite(ledleft, HIGH);
    digitalWrite(ledtop, LOW);
//    delay(0);
  }

  if(xPosition < 499 && yPosition < 514){
    digitalWrite(ledright, HIGH);
    digitalWrite(ledbot, LOW);
    digitalWrite(ledleft, LOW);
    digitalWrite(ledtop, HIGH);
//    delay(0);
  }
  
  if(xPosition < 499 && yPosition > 516){
    digitalWrite(ledright, HIGH);
    digitalWrite(ledbot, HIGH);
    digitalWrite(ledleft, LOW);
    digitalWrite(ledtop, LOW);
//    delay(0);
  }

  if(xPosition == 500 && yPosition == 515) {
    digitalWrite(ledright, LOW);
    digitalWrite(ledbot, LOW);
    digitalWrite(ledleft, LOW);
    digitalWrite(ledtop, LOW);
//    delay(0);
  }

  if(buttonState == 0){
    digitalWrite(ledright, HIGH);
    digitalWrite(ledbot, HIGH);
    digitalWrite(ledleft, HIGH);
    digitalWrite(ledtop, HIGH);
//    delay(0);
  }
  
  if(xPosition == 500 && yPosition == 515) {
    digitalWrite(ledright, LOW);
    digitalWrite(ledbot, LOW);
    digitalWrite(ledleft, LOW);
    digitalWrite(ledtop, LOW);
//    delay(0);
  }

    delay(0.5);
  
}
