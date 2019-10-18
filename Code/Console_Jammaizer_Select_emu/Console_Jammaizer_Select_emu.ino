//  Select/Home Emulator

int P1B1 = 6;                     // choose the input pins for the digital inputs, follows Arduino pinout.
int P1ST = 5;
int P1B4 = 9;
int P1B2 = 7;                     
int P1B3 = 8;  

int P1STO = 0;                      // Sets up button press values. 0 = button not pressed, 1 = button pressed.
int P1SLO = 0;
int P1HO = 0;
int P1B1V = 0;                    
int P1STV = 0;
int P1B4V = 0;
int P1B2V = 0;                    
int P1B3V = 0;

int outputd = 0;
int val = 0;   // variable for reading the pin status (should be zero)

void setup() {
  pinMode(P1B1, INPUT_PULLUP);     // Declares inputs with internal pullup.
  pinMode(P1ST, INPUT_PULLUP);
  pinMode(P1B4, INPUT_PULLUP);
  pinMode(P1B2, INPUT_PULLUP);          
  pinMode(P1B3, INPUT_PULLUP);
 }


void loop(){                     // The main loop of the program. Calls all of the other loops as needed.
  {
  scaninputs();                    // Scans button inputs
  buttoncombos();                // Runs the button combination check.
  setoutputs();}

  DDRD = outputd;                // Sets PORTD outputs based on inputs
}


void setoutputs(){           // Translates button values into port outputs
              
if (P1STO == 1)
  outputd |= 4;                            
if (P1SLO == 1)   
  outputd |= 16;
if (P1HO == 1) 
  outputd |= 8;    
}



void scaninputs(){               // Scans input pins for buttonpresses.

outputd = 0;
P1STO = 0;                      
P1SLO = 0;
P1HO = 0;
P1B1V = 0;                    
P1STV = 0;
P1B4V = 0;
P1B2V = 0;                    
P1B3V = 0;
 
  val = digitalRead(P1ST);        // read input value from data line
  if (val == LOW) {             // check if the data input is LOW (button pressed)
  P1STV = 1;                        // Stores the B button as pressed.
  }
  val = digitalRead(P1B1); 
  if (val == LOW) {       
  P1B1V = 1;
  }
  val = digitalRead(P1B2);
  if (val == LOW) {       
  P1B2V = 1;
  }
  val = digitalRead(P1B3); 
  if (val == LOW) {      
  P1B3V = 1;
  }
  val = digitalRead(P1B4); 
  if (val == LOW) {      
  P1B4V = 1;
  }                            
}

void buttoncombos(){
if (P1STV == 1){
  P1STO = 1;
}
if (P1STV == 1 && (P1B1V == 1 && (P1B2V == 1 ))){       // Checks if p1 ST B1 and B2 are pressed
  P1SLO = 1;                       // Sets Select as pressed       
  P1STO = 0;
}
if (P1STV == 1 && (P1B3V == 1 && (P1B4V == 1 ))){       // Checks if p1 ST B3 and B4 are pressed
  P1HO = 1;                       // Sets HOME as pressed
  P1STO = 0;                        // Sets Start as not pressed
}

}
