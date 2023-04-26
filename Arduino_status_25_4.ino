unsigned long previousMillis = 0;  // variable to store the previous time
const unsigned long intervalSetup = 500;  // interval for the delay in setup in milliseconds
const unsigned long intervalHandshake = 100;  // interval for the delay in the handshake in milliseconds
unsigned long dbTimeArray [13][30] = {0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  handshake();
  unsigned long currentMillis = millis();  // get the current time
  if (currentMillis - previousMillis >= intervalSetup) {
    previousMillis = currentMillis;  // update the previous time
  setPinModes();

  }

}


void loop() {
  // put your main code here, to run repeatedly:

  }
}

bool checkpin(int pin){
  pinMode(pin, INPUT);
  int pinState = digitalRead(pin);
  if(pinState == HIGH){
    return true;
  }
  else{
    return false;
  }
}

void getTimeOfWagon(){
  bool hasBeenWritten = false;
  if(checkpin(24)){
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = 1;
      if(dbTimeArray[1][i] != 0){
        dbTimeArray[1][i] = passTime;
        hasBeenWritten;
      }
      else{
        i++;
      }
    }
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

setPinModes(){
  pinMode(24, INPUT); //first input pin
  pinMode(26, INPUT);
  pinMode(28, INPUT);
  pinMode(30, INPUT);
  pinMode(32, INPUT);
  pinMode(34, INPUT);
  pinMode(36, INPUT);
  pinMode(38, INPUT);
  pinMode(40, INPUT);
  pinMode(42, INPUT); //last input pin
  pinMode(25, OUTPUT); // power pins for the sensors
  pinMode(27, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(43, OUTPUT); // till here
  // and set them all to HIGH
  digitalWrite(25, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(31, HIGH);
  digitalWrite(33, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(37, HIGH);
  digitalWrite(39, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(42, HIGH);
}
