unsigned long previousmillis = 0;  // variable to store the previous time
const unsigned long intervalSetup = 500;  // interval for the delay in setup in millis()econds
const unsigned long intervalHandshake = 100;  // interval for the delay in the handshake in millis()econds
unsigned long dbTimeArray [13][120] = {0};
signed int workingLine = 1;
bool dataAtSensor1, dataAtSensor2, dataAtSensor3, dataAtSensor4, dataAtSensor5 = false;
bool dataAtSensor6, dataAtSensor7, dataAtSensor8, dataAtSensor9, dataAtSensor10 = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  handshake();
  unsigned long currentmillis = millis();  // get the current time
  if (currentmillis - previousmillis >= intervalSetup) {
    previousmillis = currentmillis;  // update the previous time
  Serial.println("TestSerialDebug");
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

//void sendDataViaUSB(){

//Serial.digitalWrite("")


//}


bool handshake(){
  bool hasfinished1, hasfinished2 = false;
  String recive1, recive2;
  while(hasfinished1 != true){
    if(Serial.available() != 0){
      recive1 = Serial.readStringUntil('\r');
      if(recive1 != "C"){
        delay(1);
      }
      else{
        Serial.println("C");
        hasfinished1 = true;
        unsigned long currentmillis = millis();  // get the current time
        if (currentmillis - previousmillis >= intervalHandshake) {
          previousmillis = currentmillis;  // update the previous time
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
        unsigned long currentmillis = millis();  // get the current time
        if (currentmillis - previousmillis >= intervalHandshake) {
          previousmillis = currentmillis;  // update the previous time
        }
        return true;
      }
    }
  }
}


void setPinModes(){
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
  if(isPinRecifingHIGH(24)){ //First Sensor
    double timeAtPin = millis();
    dbTimeArray[1][workingLine] = timeAtPin;
    dataAtSensor1 = true;
  }

  if(isPinRecifingHIGH(26)){ //Second Sensor
    double timeAtPin = millis();
    dbTimeArray[2][workingLine] = timeAtPin;
    dataAtSensor2 = true;
  }

  if(isPinRecifingHIGH(28)){ //Third Sensor
    double timeAtPin = millis();
    dbTimeArray[3][workingLine] = timeAtPin;
    dataAtSensor3 = true;
  }

  if(isPinRecifingHIGH(30)){ //Forth Sensor
    double timeAtPin = millis();
    dbTimeArray[4][workingLine] = timeAtPin;
    dataAtSensor4 = true;
  }

  if(isPinRecifingHIGH(32)){ //Fith Sensor
    double timeAtPin = millis();
    dbTimeArray[5][workingLine] = timeAtPin;
    dataAtSensor5 = true;
  }

  if(isPinRecifingHIGH(34)){ //Sixth Sensor
    double timeAtPin = millis();
    dbTimeArray[6][workingLine] = timeAtPin;
    dataAtSensor6 = true;
  }

  if(isPinRecifingHIGH(36)){ //Seventh Sensor
    double timeAtPin = millis();
    dbTimeArray[7][workingLine] = timeAtPin;
    dataAtSensor7 = true;
  }

  if(isPinRecifingHIGH(38)){ //Eigth Sensor
    double timeAtPin = millis();
    dbTimeArray[8][workingLine] = timeAtPin;
    dataAtSensor8 = true;
  }

  if(isPinRecifingHIGH(40)){ //Nineth Sensor
    double timeAtPin = millis();
    dbTimeArray[9][workingLine] = timeAtPin;
    dataAtSensor9 = true;
  }

  if(isPinRecifingHIGH(42)){ //Tenth Sensor
    double timeAtPin = millis();
    dbTimeArray[10][workingLine] = timeAtPin;
    dataAtSensor10 = true;
    workingLine = workingLine + 1;
  }
}
