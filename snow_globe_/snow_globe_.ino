/*
  Based on Tom Igoe's code
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
#include <Servo.h>

//constants wont change. theyre used here to set up pin numbers: 
  const int buttonPin = 2;     // the number of the push button pin 
   const int ledPin = 3;       // the number of LED pin
   const int ledPin2 = 6;      // the number of LED pin
   const int ledPin3 = 9;     // the number of LED pin
  const int buzzerPin = 12;    // the number of buzzer pin 
Servo myServo;
  
//varibles will change 
 int buttonState = 0;         // variable for reading the pushbutton status
 
void setup() {
  // initalize all LEDs as an output:
        pinMode(ledPin, OUTPUT);
        pinMode(ledPin2, OUTPUT);
        pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
        pinMode(buttonPin, INPUT); 
  myServo.attach (12); 
}

//notes in melody: 
// use 0 for a rest 
//put each measure on its own line 
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_C3, NOTE_C4, NOTE_C4, NOTE_C3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C3,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_G5,
  NOTE_C4, NOTE_C4, NOTE_C3, NOTE_C4, NOTE_C4, NOTE_C3, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C3,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_C5


  
};
        
        // note durations: 1 = whole note, 4 = quarter note, 8 = eighth note, etc.:
        // be sure each note or rest in the melody above has a corresponding duration below
        // put each measure on its own line
        int noteDurations[] = {
         4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 8,
         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8,
         4, 4, 8, 4, 4, 8, 4, 4, 4, 4, 8, 
         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8, 8,
        };
        
  // set the tempo
  // a tempo of 60 is one beat per second
  // a tempo of 120 would be twice as fast
  int beatsPerMinute = 100;

void loop() {
  // read the state of the pushbutton value:
        buttonState = digitalRead(buttonPin); 
     // initialize digital pin LED_BUILTIN as an output.
//check if the pushbutton is pressed. if it is, the buttonState is HIGH:
  if (buttonState == HIGH) { 
       digitalWrite(ledPin, HIGH);      // turn random LED on HIGH voltage  
       delay(1000);                     //wait for a second
       digitalWrite(ledPin2, HIGH);     // turn random LED on HIGH voltage 
       delay(1000);                     //wait for a second
       digitalWrite(ledPin3, HIGH);     // turn random LED on HIGH voltage 
       delay(1000);                     //wait for a second
           myServo.write(180); 
           delay(1000); 
           myServo.write(0);
           delay(1000);
           
// iterate over the notes of the melody:
    int len = sizeof(melody)/sizeof(melody[0]);
    for (int thisNote = 0; thisNote < len; thisNote++) {
  
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
      tone(buzzerPin, melody[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(buzzerPin);
    }
  } else {
  //stop melody:
  digitalWrite(ledPin, LOW); 
   
    digitalWrite(ledPin, LOW);      // turn random LED on LOW voltage
    digitalWrite(ledPin2, LOW);      // turn random LED on LOW voltage
    digitalWrite(ledPin3, LOW);      // turn random LED on LOW voltage
  // Pause before playing again 
  delay(2000);
  }
}
