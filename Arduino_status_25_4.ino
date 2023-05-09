unsigned long previousmillis = 0;  // variable to store the previous time
const unsigned long intervalSetup = 500;  // interval for the delay in setup in millis()econds
const unsigned long intervalHandshake = 100;  // interval for the delay in the handshake in millis()econds
unsigned long dbTimeArray [13][120] = {0};
signed int workingLine = 1;
bool dataAtSensor1, dataAtSensor2, dataAtSensor3, dataAtSensor4, dataAtSensor5 = false;
bool dataAtSensor6, dataAtSensor7, dataAtSensor8, dataAtSensor9, dataAtSensor10 = false;
bool isSensorBlocked = false;
unsigned long blockStartMillis = 0;
const unsigned long blockDurationMillis = 2500;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  handshake();
  unsigned long currentmillis = millis();  // get the current time
  while(currentmillis - previousmillis >= intervalSetup) {
    previousmillis = currentmillis;  // update the previous time
  }
  setPinModes();
  Serial.println("Finnished Setup, entering Loop!");

}


void loop() {
  // put your main code here, to run repeatedly:
  getTimeOfWagon();
  sendDataViaUSB();
}



bool isPinRecifingHIGH(int pin){
  pinMode(pin, INPUT);
  while(isSensorBlocked){
    unsigned long currentMillis = millis();
    if (currentMillis - blockStartMillis >= blockDurationMillis) {
      // block period has elapsed, unblock the pin
      isSensorBlocked = false;
    }
  }
    if (digitalRead(pin) == HIGH) { //Has to be changed to LOW as soon as all sensores are connected
      // do something with the pin value, then block it for 2 seconds
      isSensorBlocked = true;
      blockStartMillis = millis();
      return true;
    }
    else {
    return false;
    }
}

void sendDataViaUSB(){
  if(dataAtSensor1){
    String dataToSend = "1 : " + String(workingLine) + " : " + String(dbTimeArray[1][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor1 = false;
  }
  if(dataAtSensor2){
    String dataToSend = "2 : " + String(workingLine) + " : " + String(dbTimeArray[2][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor2 = false;
  }
  if(dataAtSensor3){
    String dataToSend = "3 : " + String(workingLine) + " : " + String(dbTimeArray[3][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor3 = false;
  }
  if(dataAtSensor4){
    String dataToSend = "4 : " + String(workingLine) + " : " + String(dbTimeArray[4][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor4 = false;
  }
  if(dataAtSensor5){
    String dataToSend = "5 : " + String(workingLine) + " : " + String(dbTimeArray[5][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor5 = false;
  }
  if(dataAtSensor6){
    String dataToSend = "6 : " + String(workingLine) + " : " + String(dbTimeArray[6][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor6 = false;
  }
  if(dataAtSensor7){
    String dataToSend = "7 : " + String(workingLine) + " : " + String(dbTimeArray[7][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor7 = false;
  }
  if(dataAtSensor8){
    String dataToSend = "8 : " + String(workingLine) + " : " + String(dbTimeArray[8][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor8 = false;
  }
  if(dataAtSensor9){
    String dataToSend = "9 : " + String(workingLine) + " : " + String(dbTimeArray[9][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor9 = false;
  }
  if(dataAtSensor10){
    String dataToSend = "10 : " + String(workingLine) + " : " + String(dbTimeArray[10][workingLine]);
    Serial.println(dataToSend);
    dataAtSensor10 = false;
  }

}

bool handshake(){
  bool hasfinished1 = false;
  bool hasfinished2 = false;
  String recive1;
  String recive2;
  String recive0;

  while (!hasfinished1) {
    if (Serial.available()) {
      recive1 = Serial.readString();
      if (recive1.indexOf("C") >= 0) {
        Serial.println("C");
        hasfinished1 = true;
        delay(500);  // wait for the receiver to process the message
        }
    }
  }

  while (!hasfinished2) {
    if (Serial.available()) {
      recive2 = Serial.readString();
      if (recive2.indexOf("R") >= 0) {
        hasfinished2 = true;
        return true;
      }
    }
  }

  return false;
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
