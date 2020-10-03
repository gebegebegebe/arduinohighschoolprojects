#include <SoftwareSerial.h> //This library has to be downloaded (most likely)

SoftwareSerial BT(4, 5); 
void setup()  
{
  Serial.begin(115200); //To communicate with computer
  // set digital pin to control as an output
  pinMode(13, OUTPUT);

  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  BT.println("Hello from Arduino");
  // Send message to computer to make sure Arduino has sent the message
  Serial.println("Sent hello to device");
}

char a; // stores incoming character from other device
void loop(){

  if (BT.available()){ //If there is data

    a=(BT.read()); //Read it

    if (a=='1'){
      digitalWrite(13, HIGH); //LED pin high
      BT.println("LED on");
        Serial.println("LED on");
      
    }else if (a=='2'){
      digitalWrite(13, LOW);
      BT.println("LED off");
         Serial.println("LED off");
      
    }else if (a=='?'){
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");

    }   
    }
}

