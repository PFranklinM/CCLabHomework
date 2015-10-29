int xPin = A1;
int yPin = A0;
int buttonPin = 13;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

bool start = true;

bool Pin1;
bool Pin2;
bool Pin3;

const int BluePin1 = 2;
const int BluePin2 = 5;
const int BluePin3 = 9;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(BluePin1, OUTPUT);
  pinMode(BluePin2, OUTPUT);
  pinMode(BluePin3, OUTPUT);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Pin1 = false;
  Pin2 = false;
  Pin3 = true;

}

void loop() {
  // put your main code here, to run repeatedly:

  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);


  if(start == true){
    digitalWrite(BluePin1, LOW);
    digitalWrite(BluePin2, LOW);
    digitalWrite(BluePin3, HIGH);
    start = false;
  }


  if(Pin3 == true){
   if(yPosition > 501){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, HIGH);
      digitalWrite(BluePin3, LOW);

      Pin1 = false;
      Pin2 = true;
      Pin3 = false; 
   }

   if(xPosition > 517){
      digitalWrite(BluePin1, HIGH);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);

      Pin1 = true;
      Pin2 = false;
      Pin3 = false; 
   }
  }

  if(Pin2 == true){
    if(yPosition < 499){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, HIGH);

      Pin1 = false;
      Pin2 = false;
      Pin3 = true; 
    }

    if(xPosition > 517){
      digitalWrite(BluePin1, HIGH);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);

      Pin1 = true;
      Pin2 = false;
      Pin3 = false; 
    }
  }

  if(Pin1 == true){
    if(xPosition < 515){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, HIGH);
      digitalWrite(BluePin3, LOW);

      Pin1 = false;
      Pin2 = true;
      Pin3 = false; 
    }

    if(yPosition < 499){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, HIGH);

      Pin1 = false;
      Pin2 = false;
      Pin3 = true; 
    }
  }
}
