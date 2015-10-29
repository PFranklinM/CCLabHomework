const int RedPin1 = 4;
const int RedPin2 = 7;
const int RedPin3 = 11;

int counter = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(RedPin1, OUTPUT);
  pinMode(RedPin2, OUTPUT);
  pinMode(RedPin3, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  counter++;
  Serial.println(counter);

  if(counter < 10){
  digitalWrite(RedPin1, HIGH);
  digitalWrite(RedPin2, LOW);
  digitalWrite(RedPin3, LOW);

  delay(2000);

  digitalWrite(RedPin1, LOW);
  digitalWrite(RedPin2, HIGH);
  digitalWrite(RedPin3, LOW);

  delay(2000);

  digitalWrite(RedPin1, LOW);
  digitalWrite(RedPin2, LOW);
  digitalWrite(RedPin3, HIGH);

  delay(2000);
  }

  if(counter > 10){
  digitalWrite(RedPin1, HIGH);
  digitalWrite(RedPin2, HIGH);
  digitalWrite(RedPin3, LOW);

  delay(2000);

  digitalWrite(RedPin1, LOW);
  digitalWrite(RedPin2, HIGH);
  digitalWrite(RedPin3, HIGH);

  delay(2000);
  }
}

  
