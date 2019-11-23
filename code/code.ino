boolean countDown = false;
boolean normal = false;
boolean gameOver = false;
boolean threePoint = false;
int count = 0;
const int digitalInPin = D7;

void setup() {
  Serial.begin(9600);
  pinMode(digitalInPin, INPUT);
  timeOn = millis();
}

void loop() {
  currentTime = 1000*(millis()-timeOn);
  if(countDown) {
      //soundEffect
      if(currentTime>=5) {
        count = 0;
        countDown = false;
        normal true;
      }
  }
  if(normal) {
    // music = ON;
    if(A0){
      count+=2;
      // play celebration sound
    }
    if( timeOn - endNormalTime ){ //endNormalTime needs to be created
      normal = false;
      threePoint = true;
    }
  }
  if(threePoint) {
   if(digitalRead(digitalInPin) == HIGH) {
    count+=3;
    //soundEffect
   }
   if(currentTime >= 65) {
    threePoint = false;
    gameOver = true;
    //soundEffect
   }
  }
  if(gameOver) {
    
  }
}
