// Uses a PIR sensor to detect movement, fades an LED

// more info here: makeprojects.com/Project/PIR-Sensor-ArduinoAlarm/72/1 

int ledPin = 9;                // choose the pin for the LED 
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

int inputPin = 2;               // choose the input pin (for PIR sensor) 

int pirState = LOW;             // we start, assuming no motion detected 

int val = 0;                    // variable for reading the pin status 

int pinSpeaker = 10;           //Set up a speaker on a PWM pin (digital 9, 10, or 11) 

void setup() { 

  pinMode(ledPin, OUTPUT);      // declare LED as output 

  pinMode(inputPin, INPUT);     // declare sensor as input 

  pinMode(pinSpeaker, OUTPUT); 

  Serial.begin(9600); 

} 

void loop(){ 

  val = digitalRead(inputPin);  // read input value 

  if (val == HIGH) {            // check if the input is HIGH 
    for (int i = 1; i<255; i= i+5) {
      
       Serial.println(i);
      // digitalWrite(ledPin, HIGH);  // turn LED ON  
      analogWrite(ledPin, i);    

      // wait for 30 milliseconds to see the dimming effect    
      delay(30);                            
    }
     analogWrite(ledPin, 0);


    if (pirState == LOW) { 

      // we have just turned on 

      Serial.println("Motion detected!"); 

      // We only want to print on the output change, not state 

      pirState = HIGH; 

    } 

  } 

} 



