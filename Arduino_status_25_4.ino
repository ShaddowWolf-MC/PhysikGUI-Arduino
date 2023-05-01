unsigned long previousMillis = 0;  // variable to store the previous time
const unsigned long intervalSetup = 500;  // interval for the delay in setup in milliseconds
const unsigned long intervalHandshake = 100;  // interval for the delay in the handshake in milliseconds


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  handshake();
  unsigned long currentMillis = millis();  // get the current time
  if (currentMillis - previousMillis >= intervalSetup) {
    previousMillis = currentMillis;  // update the previous time
  pinMode(24, OUTPUT);
  pinMode(26, INPUT);

  }

}


void loop() {
  // put your main code here, to run repeatedly:
  if(isPinRecifingHIGH(3)){
    Serial.println("Pin Ishigh");
  }
}

bool isPinRecifingHIGH(int pin){
  pinMode(pin, INPUT);
  int pinState = digitalRead(pin);
  if(pinState == HIGH){
    return true;
  }
  else{
    return false;
  }
}

bool handshake(){
  bool hasfinished1, hasfinished2 = false;
  string recive1, recive2;
  while(hasfinished1 != true){
    if(Serial.available() != 0){
      recive1 = Serial.readStringUntil('\r');
      if(recive1 != "C"){
      }
      else{
        Serial.println('C');
        hasfinished1 = true;
        unsigned long currentMillis = millis();  // get the current time
        if (currentMillis - previousMillis >= intervalHandshake) {
          previousMillis = currentMillis;  // update the previous time
        }
      }
    }
  }
  while(hasfinished2 != true){
    if(Serial.available() != 0){
      recive2 = Serial.readStringUntil('\r');
      if(recive2 != "R"){
      }
      else{
        hasfinished2 = true;
        unsigned long currentMillis = millis();  // get the current time
        if (currentMillis - previousMillis >= intervalHandshake) {
          previousMillis = currentMillis;  // update the previous time
        }
        return true;
      }
    }
  }
}
