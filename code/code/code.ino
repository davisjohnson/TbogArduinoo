boolean countDown = false;
boolean normal = false;
boolean gameOver = false;
boolean threePoint = false;
int count = 0;
const int digitalInPin = 7;
long timeOn;
long currentTime;

void setup() {
  Serial.begin(9600);
  pinMode(digitalInPin, INPUT);
  timeOn = millis();
  countDown = true;
}

void loop() {
  currentTime = 1000*(millis()-timeOn);
  Serial.println(currentTime);
  
  if(countDown) {
      //soundEffect
      if(currentTime>=5) {
        countDown = false;
        normal =  true;
        Serial.println("Starting now");
      }
  }
  if(normal) {
    // music = ON;
    if(digitalRead(digitalInPin) == HIGH){
      count+=2;
      Serial.println(count);
    }
    if( currentTime>=50 ){ 
      normal = false;
      threePoint = true;
      Serial.println("Starting normal");
    }
  }
  if(threePoint) {
   if(digitalRead(digitalInPin) == HIGH) {
    count+=3;
    Serial.println(count);
   }
   if(currentTime >= 65) {
    threePoint = false;
    gameOver = true;
    count = 0;
    Serial.println("Game Over");
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
