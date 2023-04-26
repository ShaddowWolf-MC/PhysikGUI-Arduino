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
    pinMode(24, INPUT);
    pinMode(26, INPUT);
    pinMode(28, INPUT);
    pinMode(30, INPUT);
    pinMode(32, INPUT);
    pinMode(34, INPUT);
    pinMode(36, INPUT);
    pinMode(38, INPUT);
    pinMode(40, INPUT);
    pinMode(42, INPUT);

  }

}


void loop() {
  // put your main code here, to run repeatedly:
  if(isPinHIGH(3)){
    Serial.println("Pin Ishigh");
  }
}

bool isPinHIGH(int pin){
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
  char data;
  while(hasfinished1 != true){
    if(Serial.available()){
      data = Serial.read();
      if(data != 'C'){
      }
      else{
        Serial.println("C");
        hasfinished1 = true;
        unsigned long currentMillis = millis();  // get the current time
        if (currentMillis - previousMillis >= intervalHandshake) {
          previousMillis = currentMillis;  // update the previous time
        }
      }
    }
  }
  while(hasfinished2 != true){
    if(Serial.available()){
      data = Serial.read();
      if(data != 'R'){
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
