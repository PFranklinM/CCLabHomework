const int RedPin1 = 4;
const int RedPin2 = 7;
const int RedPin3 = 11;

const int BluePin1 = 2;
const int BluePin2 = 5;
const int BluePin3 = 9;

int counter = 0;

int xPin = A1;
int yPin = A0;
int buttonPin = 13;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

bool BlueStart = true;
bool RedStart = true;

bool BPin1;
bool BPin2;
bool BPin3;

bool RPin1;
bool RPin2;
bool RPin3;

void setup() {
  // put your setup code here, to run once:

  pinMode(RedPin1, OUTPUT);
  pinMode(RedPin2, OUTPUT);
  pinMode(RedPin3, OUTPUT);

  pinMode(BluePin1, OUTPUT);
  pinMode(BluePin2, OUTPUT);
  pinMode(BluePin3, OUTPUT);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  BPin1 = false;
  BPin2 = false;
  BPin3 = true;

  RPin1 = true;
  RPin2 = false;
  RPin3 = false;

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  enemyMove();


//collision detection can two lights be on at the same time?
//if (255, 0, 255)
//call comparison everytime something happens in the loop()
}

void playerMove(){
    
    //Player Movement
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);


  if(BlueStart == true){
    digitalWrite(BluePin1, LOW);
    digitalWrite(BluePin2, LOW);
    digitalWrite(BluePin3, HIGH);
    
    BlueStart = false;
  }


  if(BPin3 == true){
   if(yPosition > 501){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, HIGH);
      digitalWrite(BluePin3, LOW);

      BPin1 = false;
      BPin2 = true;
      BPin3 = false; 
   }

   if(xPosition > 517){
      digitalWrite(BluePin1, HIGH);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);

      BPin1 = true;
      BPin2 = false;
      BPin3 = false; 
   }
  }

  if(BPin2 == true){
    if(yPosition < 499){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, HIGH);

      BPin1 = false;
      BPin2 = false;
      BPin3 = true; 
    }

    if(xPosition > 517){
      digitalWrite(BluePin1, HIGH);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);

      BPin1 = true;
      BPin2 = false;
      BPin3 = false; 
    }
  }

  if(BPin1 == true){
    if(xPosition < 515){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, HIGH);
      digitalWrite(BluePin3, LOW);

      BPin1 = false;
      BPin2 = true;
      BPin3 = false; 
    }

    if(yPosition < 499){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, HIGH);

      BPin1 = false;
      BPin2 = false;
      BPin3 = true; 
      }
    }
  }

  void enemyMove(){
    
    //Enemy Movement
//  counter++;
//  Serial.println(counter);

//  if(counter < 10){

    for(int lightWait = 0; lightWait < 300; lightWait++){
      Serial.println(lightWait);
      if(lightWait < 100){
        digitalWrite(RedPin1, HIGH);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
         
        RPin1 = true;
        RPin2 = false;
        RPin3 = false;

        playerMove();

        if(RPin1 == true && BPin1 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 100 && lightWait < 200){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, HIGH);
        digitalWrite(RedPin3, LOW);
         
        RPin1 = false;
        RPin2 = true;
        RPin3 = false;

        playerMove();

        if(RPin2 == true && BPin2 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 200){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, HIGH);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = true;

        playerMove();

        if(RPin3 == true && BPin3 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);

          delay(1000);
        }
      }
    }


//  if(counter > 10){
//  digitalWrite(RedPin1, HIGH);
//  digitalWrite(RedPin2, HIGH);
//  digitalWrite(RedPin3, LOW);
//
//  RPin1 = true;
//  RPin2 = true;
//  RPin3 = false;
//
//  digitalWrite(RedPin1, LOW);
//  digitalWrite(RedPin2, HIGH);
//  digitalWrite(RedPin3, HIGH);
//
//  RPin1 = false;
//  RPin2 = true;
//  RPin3 = true;
//  }
}

  
