//PASWSWORD
int pass[] = {6,3,7,2,4};

//pins
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int length = 50;
int BEEP_SEP = length*5;
int NUM_SEP = length*10;
int led = 13;
int values[5] = {0};
int j = 0;
int waitForBeepSep = 0;
unsigned int time;
int first0occ = 0;
int first40occ = 0;

boolean array_cmp(int *a, int *b, int len_a, int len_b){
      int n;

      // if their lengths are different, return false
      if (len_a != len_b) return false;

      // test each element to be the same. if not, return false
      for (n=0;n<len_a;n++) if (a[n]!=b[n]) return false;

      //ok, if we have not returned yet, they are equal :)
      return true;
}


// the setup routine runs once when you press reset:
void setup() {
    // initialize the digital pin as an output.
    Serial.begin(9600);

   pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  

}


void loop() {

    int sensorValue = analogRead(A0);
    setColor(sensorValue, 0, 0);  // blue
    time = millis();


    if (sensorValue > 120) { // this is a beep  
        waitForBeepSep = 1;
        first40occ = 0;


    }

    else if (sensorValue < 3) { // found a "zero"

        if (first0occ == 0) // first time we hit a zero
            first0occ = time; // save it's time

        if (waitForBeepSep == 1 && ((time - first0occ) > BEEP_SEP)) { // we had a beep lets count it 
            values[j]++;
            Serial.println(values[j]);
            
            waitForBeepSep = 0; //already found this seperator
            first0occ = 0;

        }
    } else if ((sensorValue > 20 && sensorValue < 60)) { // this is num seperator

        first0occ = 0;

        if (first40occ == 0 && values[j] != 0) {
            first40occ = time;

        }
        if (values[j] != 0 && ((time - first40occ) > NUM_SEP)) { // don't move to the next number more then once
            j++; // move to count the next number

        }
    }




    if (j == 5) {
        Serial.println("------VALUE----------");
        Serial.println(values[0]); //2
        Serial.println(values[1]); //3
        Serial.println(values[2]); //4
        Serial.println(values[3]); 
        Serial.println(values[4]);
        
        if(array_cmp(values,pass,5,5)){ // if password matches
            setColor(0, 255, 0); // green
            while (true);
        }
        
        else{
            while(true){
               setColor(0, 0, 255);  // red   // turn the LED on (HIGH is the voltage level)
               delay(500);               // wait for a second
                setColor(0,0, 0);  // red    // turn the LED off by making the voltage LOW
                delay(500); 
            }
        }
         
        
      //  Serial.println(values[5]);


         // stop
    }
    
    //delay(10);

}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}


