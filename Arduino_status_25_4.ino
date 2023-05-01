unsigned long previousMillis = 0;  // variable to store the previous time
const unsigned long intervalSetup = 500;  // interval for the delay in setup in milliseconds
const unsigned long intervalHandshake = 100;  // interval for the delay in the handshake in milliseconds
<<<<<<< HEAD

=======
unsigned long dbTimeArray [13][120] = {0};
signed int lastWrittenLine = 1;
>>>>>>> parent of 0cb1014 (Fixed array support)

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

<<<<<<< HEAD
=======
void sendDataViaUSB(){

  Serial.digitalWrite()
}

>>>>>>> parent of 0cb1014 (Fixed array support)
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
<<<<<<< HEAD
=======

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


void getTimeOfWagon(){
  if(checkpin(24)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[1][i] != 0){
        dbTimeArray[1][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(26)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[2][i] != 0){
        dbTimeArray[2][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(28)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[3][i] != 0){
        dbTimeArray[3][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(30)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[4][i] != 0){
        dbTimeArray[4][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(32)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[5][i] != 0){
        dbTimeArray[5][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(34)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[6][i] != 0){
        dbTimeArray[6][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(36)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[7][i] != 0){
        dbTimeArray[7][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(38)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[8][i] != 0){
        dbTimeArray[8][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(40)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[9][i] != 0){
        dbTimeArray[9][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;
      }
    }
  }

  if(checkpin(42)){
    bool hasBeenWritten = false;
    unsigned long passTime = millis();
    while(hasBeenWritten != true){
      int i = lastWrittenLine;
      if(dbTimeArray[10][i] != 0){
        dbTimeArray[10][i] = passTime;
        hasBeenWritten;
      }
      else{
        lastWrittenLine++;
        i = lastWrittenLine;        
      }
    }
  }


}
>>>>>>> parent of 0cb1014 (Fixed array support)
