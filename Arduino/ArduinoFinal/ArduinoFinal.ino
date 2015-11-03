const int RedPin1 = 2;
const int RedPin2 = 4;
const int RedPin3 = 6;
const int RedPin4 = 8;
const int RedPin5 = 10;
const int RedPin6 = 12;

const int BluePin1 = 3;
const int BluePin2 = 5;
const int BluePin3 = 7;
const int BluePin4 = 9;
const int BluePin5 = 11;
const int BluePin6 = 13;

int long moveCounter = 0;

int long counter = 0;

int xPin = A1;
int yPin = A0;

int xPosition = 0;
int yPosition = 0;

bool BlueStart = true;
bool RedStart = true;

bool BPin1;
bool BPin2;
bool BPin3;
bool BPin4;
bool BPin5;
bool BPin6;

bool RPin1;
bool RPin2;
bool RPin3;
bool RPin4;
bool RPin5;
bool RPin6;

void setup() {
  // put your setup code here, to run once:

  pinMode(RedPin1, OUTPUT);
  pinMode(RedPin2, OUTPUT);
  pinMode(RedPin3, OUTPUT);
  pinMode(RedPin4, OUTPUT);
  pinMode(RedPin5, OUTPUT);
  pinMode(RedPin6, OUTPUT);

  pinMode(BluePin1, OUTPUT);
  pinMode(BluePin2, OUTPUT);
  pinMode(BluePin3, OUTPUT);
  pinMode(BluePin4, OUTPUT);
  pinMode(BluePin5, OUTPUT);
  pinMode(BluePin6, OUTPUT);
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  BPin1 = false;
  BPin2 = false;
  BPin3 = false;
  BPin4 = false;
  BPin5 = false;
  BPin6 = true;

  RPin1 = true;
  RPin2 = false;
  RPin3 = false;
  RPin4 = false;
  RPin5 = false;
  RPin6 = false;

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  enemyMove();

}

void playerMove(){
    
    //Player Movement
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);

  
//  Serial.print("X: ");
//  Serial.print(xPosition);
//  Serial.print(" | Y: ");
//  Serial.println(yPosition);


  if(BlueStart == true){
    digitalWrite(BluePin1, LOW);
    digitalWrite(BluePin2, LOW);
    digitalWrite(BluePin3, LOW);
    digitalWrite(BluePin4, LOW);
    digitalWrite(BluePin5, LOW);
    digitalWrite(BluePin6, HIGH);
    
    BlueStart = false;
    
  }



  if(BPin6 == true){
    moveCounter++;
   if(xPosition < 504 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, HIGH);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = false;
      BPin4 = true;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
   }

   if(yPosition > 493 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, HIGH);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = false;
      BPin4 = false;
      BPin5 = true;
      BPin6 = false;

      moveCounter = 0;
      }
  }

  if(BPin5 == true){
    moveCounter++;
    if(xPosition < 504 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, HIGH);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = true;
      BPin4 = false;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
    }

   if(yPosition < 489 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, HIGH);

      BPin1 = false;
      BPin2 = false;
      BPin3 = false;
      BPin4 = false;
      BPin5 = false;
      BPin6 = true;

      moveCounter = 0;
      }
  }

  if(BPin4 == true){
    moveCounter++;
    if(xPosition < 504 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, HIGH);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = true;
      BPin3 = false;
      BPin4 = false;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
    }

    if(xPosition > 508 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, HIGH);

      BPin1 = false;
      BPin2 = false;
      BPin3 = false;
      BPin4 = false;
      BPin5 = false;
      BPin6 = true;

      moveCounter = 0;
   }

   if(yPosition > 493 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, HIGH);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = true;
      BPin4 = false;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
      }
  }

  if(BPin3 == true){
    moveCounter++;
    if(xPosition < 504 && moveCounter > 1500){
      digitalWrite(BluePin1, HIGH);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = true;
      BPin2 = false;
      BPin3 = false;
      BPin4 = false;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
    }

    if(xPosition > 508 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, HIGH);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = false;
      BPin4 = false;
      BPin5 = true;
      BPin6 = false;

      moveCounter = 0;
   }

   if(yPosition < 489 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, HIGH);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = false;
      BPin4 = true;
      BPin5 = false;
      BPin6 = false; 

      moveCounter = 0;
   }
  }

  if(BPin2 == true){
    moveCounter++;
    if(xPosition > 508 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, HIGH);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = false;
      BPin4 = true;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
   }

   if(yPosition > 493 && moveCounter > 1500){
      digitalWrite(BluePin1, HIGH);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = true;
      BPin2 = false;
      BPin3 = false;
      BPin4 = false;
      BPin5 = false;
      BPin6 = false; 

      moveCounter = 0;
      }
  }

  if(BPin1 == true){
    moveCounter++;
    if(xPosition > 508 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, LOW);
      digitalWrite(BluePin3, HIGH);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = false;
      BPin3 = true;
      BPin4 = false;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
      }
   }
   if(yPosition < 489 && moveCounter > 1500){
      digitalWrite(BluePin1, LOW);
      digitalWrite(BluePin2, HIGH);
      digitalWrite(BluePin3, LOW);
      digitalWrite(BluePin4, LOW);
      digitalWrite(BluePin5, LOW);
      digitalWrite(BluePin6, LOW);

      BPin1 = false;
      BPin2 = true;
      BPin3 = false;
      BPin4 = false;
      BPin5 = false;
      BPin6 = false;

      moveCounter = 0;
      }
   }

  void enemyMove(){
    
  for(int long lightWait = 0; lightWait < 15000; lightWait++){

    counter++;
       
     if(counter < 300000){
      if(lightWait < 2500){
        digitalWrite(RedPin1, HIGH);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = true;
        RPin2 = false;
        RPin3 = false;
        RPin4 = false;
        RPin5 = false;
        RPin6 = false;

        playerMove();

        if(RPin1 == true && BPin1 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 2500 && lightWait < 5000){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, HIGH);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = false;
        RPin2 = true;
        RPin3 = false;
        RPin4 = false;
        RPin5 = false;
        RPin6 = false;

        playerMove();

        if(RPin2 == true && BPin2 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 5000 && lightWait < 7500){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, HIGH);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = true;
        RPin4 = false;
        RPin5 = false;
        RPin6 = false;

        playerMove();

        if(RPin3 == true && BPin3 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 7500 && lightWait < 10000){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, HIGH);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = false;
        RPin4 = true;
        RPin5 = false;
        RPin6 = false;

        playerMove();

       if(RPin4 == true && BPin4 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 10000 && lightWait < 12500){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, HIGH);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = false;
        RPin4 = false;
        RPin5 = true;
        RPin6 = false;

        playerMove();

        if(RPin5 == true && BPin5 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 12500){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, HIGH);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = false;
        RPin4 = false;
        RPin5 = false;
        RPin6 = true;

        playerMove();

        if(RPin6 == true && BPin6 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
        }
      }

      if(counter >= 300000){
        if(lightWait < 2500){
        digitalWrite(RedPin1, HIGH);
        digitalWrite(RedPin2, HIGH);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = true;
        RPin2 = true;
        RPin3 = false;
        RPin4 = false;
        RPin5 = false;
        RPin6 = false;

        playerMove();

        if(RPin1 == true && BPin1 == true || RPin2 == true && BPin2 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 2500 && lightWait < 5000){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, HIGH);
        digitalWrite(RedPin3, HIGH);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = false;
        RPin2 = true;
        RPin3 = true;
        RPin4 = false;
        RPin5 = false;
        RPin6 = false;

        playerMove();

        if(RPin2 == true && BPin2 == true || RPin3 == true && BPin3 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 5000 && lightWait < 7500){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, HIGH);
        digitalWrite(RedPin4, HIGH);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = true;
        RPin4 = true;
        RPin5 = false;
        RPin6 = false;

        playerMove();

        if(RPin3 == true && BPin3 == true || RPin4 == true && BPin4 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 7500 && lightWait < 10000){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, HIGH);
        digitalWrite(RedPin5, HIGH);
        digitalWrite(RedPin6, LOW);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = false;
        RPin4 = true;
        RPin5 = true;
        RPin6 = false;

        playerMove();

       if(RPin4 == true && BPin4 == true || RPin5 == true && BPin5 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 10000 && lightWait < 12500){
        digitalWrite(RedPin1, LOW);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, HIGH);
        digitalWrite(RedPin6, HIGH);
         
        RPin1 = false;
        RPin2 = false;
        RPin3 = false;
        RPin4 = false;
        RPin5 = true;
        RPin6 = true;

        playerMove();

        if(RPin5 == true && BPin5 == true || RPin6 == true && BPin6 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
      }

      if(lightWait >= 12500){
        digitalWrite(RedPin1, HIGH);
        digitalWrite(RedPin2, LOW);
        digitalWrite(RedPin3, LOW);
        digitalWrite(RedPin4, LOW);
        digitalWrite(RedPin5, LOW);
        digitalWrite(RedPin6, HIGH);
         
        RPin1 = true;
        RPin2 = false;
        RPin3 = false;
        RPin4 = false;
        RPin5 = false;
        RPin6 = true;

        playerMove();

        if(RPin6 == true && BPin6 == true || RPin1 == true && BPin1 == true){

          digitalWrite(BluePin1, LOW);
          digitalWrite(BluePin2, LOW);
          digitalWrite(BluePin3, LOW);
          digitalWrite(BluePin4, LOW);
          digitalWrite(BluePin5, LOW);
          digitalWrite(BluePin6, LOW);
          
          digitalWrite(RedPin1, HIGH);
          digitalWrite(RedPin2, HIGH);
          digitalWrite(RedPin3, HIGH);
          digitalWrite(RedPin4, HIGH);
          digitalWrite(RedPin5, HIGH);
          digitalWrite(RedPin6, HIGH);

          delay(1000);
    
          digitalWrite(RedPin1, LOW);
          digitalWrite(RedPin2, LOW);
          digitalWrite(RedPin3, LOW);
          digitalWrite(RedPin4, LOW);
          digitalWrite(RedPin5, LOW);
          digitalWrite(RedPin6, LOW);

          delay(1000);
        }
        }
      }
    }
}

  

