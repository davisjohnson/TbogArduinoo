boolean countDown = false;
boolean normal = false;
boolean gameOver = false;
boolean threePoint = false;
int count = 0;
const int digitalInPin = 7;
const int redPin = 6;
const int greenPin = 9;
const int bluePin = 5;
long timeOn;
long currentTime;

void setup() {
  Serial.begin(9600);
  pinMode(digitalInPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  timeOn = millis();
  countDown = true;
}

void loop() {
  currentTime = (millis()-timeOn);
 // Serial.println(currentTime);
  
  if(countDown) {
      //soundEffect
      if(currentTime>=5000) {
        countDown = false;
        normal =  true;
        Serial.println("Starting now");
        ledSet(0,0,255);
      }
  }
  if(normal) {
    // music = ON;
    if(digitalRead(digitalInPin) == HIGH){
      count+=2;
      Serial.println(count);
    }
    if( currentTime>=50000 ){ 
      normal = false;
      threePoint = true;
      Serial.println("Three point mode");
      ledSet(0,255,0);
    }
  }
  if(threePoint) {
   if(digitalRead(digitalInPin) == HIGH) {
    count+=3;
    ledSet(255,0,0);
    Serial.println(count);
   }
   if(currentTime >= 65000) {
    threePoint = false;
    gameOver = true;
    count = 0;
    Serial.println("Game Over");
    ledSet(0,0,0);
   }
  }
  if(gameOver) {
    while(true){
    //music = ON;//
      if(digitalRead(digitalInPin)==HIGH){
        gameOver=false;
        countDown=true;
        timeOn = millis();
        Serial.println("Starting countdown");
        break;
      }
    }
  }
}

void ledSet(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
