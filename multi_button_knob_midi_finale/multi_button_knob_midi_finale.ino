//basic BLE MIDI controller made by "Chi ha ucciso Il conte?" as part of "Laboratorio Aperto Parma"
//2022 
//more info: 
//https://chihauccisoilconte.eu/
//https://officineonoff.com/


#include <Arduino.h>
#include <BLEMidi.h>


float floatMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 19;     // the number of the pushbutton pin
const int buttonPin2 = 23;
const int buttonPin3 = 18;
const int buttonPin4 = 5;
const int buttonPin5 = 17;

const int ledPin =  14;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

void setup() {

  Serial.begin(115200);

   BLEMidiServer.begin("Basic MIDI device");


  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);

//read the pot values
  int analogValue1 = analogRead(35);
  int analogValue2 = analogRead(33);
  int analogValue3 = analogRead(32);
  int analogValue4 = analogRead(25);

  // Rescale to MIDI values (from 0 to 127):
  int voltage1 = floatMap(analogValue1, 0, 4095, 0, 127);
  int voltage2 = floatMap(analogValue2, 0, 4095, 0, 127);
  int voltage3 = floatMap(analogValue3, 0, 4095, 0, 127);
  int voltage4 = floatMap(analogValue4, 0, 4095, 0, 127);
  
//if the ble is connected send notes and control changes

 if(BLEMidiServer.isConnected()) { 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH); 
    //play note
  BLEMidiServer.noteOn(0, 69, 127);
      delay(1000);
      BLEMidiServer.noteOff(0, 69, 127);        // Then we make a delay of one second before returning to the beginning of the loop
      delay(1000);  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

    if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
     BLEMidiServer.noteOn(0, 70, 127);
      delay(1000);
      BLEMidiServer.noteOff(0, 70, 127);        // Then we make a delay of one second before returning to the beginning of the loop
      delay(1000);  
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

    if (buttonState3 == HIGH) {

       BLEMidiServer.noteOn(0, 71, 127);
      delay(1000);
      BLEMidiServer.noteOff(0, 71, 127);        // Then we make a delay of one second before returning to the beginning of the loop
      delay(1000);  
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

    if (buttonState4 == HIGH) {

       BLEMidiServer.noteOn(0, 72, 127);
      delay(1000);
      BLEMidiServer.noteOff(0, 72, 127);        // Then we make a delay of one second before returning to the beginning of the loop
      delay(1000);  
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

      if (buttonState5 == HIGH) {

         BLEMidiServer.noteOn(0, 73, 127);
      delay(1000);
      BLEMidiServer.noteOff(0, 73, 127);        // Then we make a delay of one second before returning to the beginning of the loop
      delay(1000);  
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

//set control change messages

if (voltage1 > 20) {

  BLEMidiServer.controlChange(0, 1, voltage1);
} else {voltage1 == 0;}

if (voltage2 > 20) {

  BLEMidiServer.controlChange(0, 2, voltage2);
} else {voltage2 == 0;}

if (voltage3 > 20) {

  BLEMidiServer.controlChange(0, 3, voltage3);
} else {voltage3 == 0 ;}

if (voltage4 > 20) {

  BLEMidiServer.controlChange(0, 4, voltage4);
} else {voltage4 == 0 ;}



   }
}

//this machine kills fascista
