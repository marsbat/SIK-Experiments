  #include<SoftwareSerial.h>

//pin assignment

int rxPin = 10; // from arduino  pin 10 to roomba pin 3
int txPin = 11; // from srduino pin 11 to roomba pin 4
int ddPin = 5; // from srduino pin 5 to roomba pin 5

SoftwareSerial cereal(rxPin, txPin);

void setup() {
  Serial.begin(9600);
  delay(3000);
  Serial.println("Your uncle is a monkey");

  pinMode (ddPin, OUTPUT);
  //pinMode (rxPin, );
  //pinMode (txPin, );
  
  cereal.begin(19200);
  
  delay(100);
  
  if (cereal.available()){
    Serial.println(cereal.read());
  } else {
    Serial.println("Cereal failed");
  }
  
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(2000);

  // Safe mode
  
  cereal.write(128);

  delay(10);

  cereal.write(130);

  delay(10);
  
  // full mode
  /*
  cereal.write(130);

  delay(10);

  cereal.write(132);

  delay(10);
  */
  
  cereal.write(128);
  cereal.write(173);
  cereal.write(128);
  delay(10);
  cereal.write(131);

  //cereal.write(143); return to dock

  cereal.write(141);
  cereal.write(1);
}



void loop() {
  // put your main code here, to run repeatedly:

}
