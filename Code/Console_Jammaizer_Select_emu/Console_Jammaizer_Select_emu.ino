
//  Select/Home Emulator for Console JAMMAizer 
//  ARTHRIMUS, 2019
//  Configured for use with ATTINY87/167

int P1ST = 8;                     // choose the input pins for the digital inputs, follows Arduino pinout.
int P1B1 = 0;
int P1B2 = 1;                     
int P1B3 = 2;
int P2ST = 7;                   
int P2B1 = 6;
int P2B2 = 5;                     
int P2B3 = 4;
int ENABLE = 14;

int P1STO = 0;                      // Sets up button press values. 0 = button not pressed, 1 = button pressed.
int P1SLO = 0;
int P1HO = 0;
int P1B1V = 0;                    
int P1STV = 0;
int P1B2V = 0;                    
int P1B3V = 0;
int P2STO = 0;                    
int P2SLO = 0;
int P2HO = 0;
int P2B1V = 0;                    
int P2STV = 0;
int P2B2V = 0;                    
int P2B3V = 0;
int ENVAL = 0;

int outputa = 0;
int outputb = 0;

int val = 0;   // variable for reading the pin status (should be zero)

void setup() {
  pinMode(P1B1, INPUT_PULLUP);     // Declares inputs with internal pullup.
  pinMode(P1ST, INPUT_PULLUP);
  pinMode(P1B2, INPUT_PULLUP);          
  pinMode(P1B3, INPUT_PULLUP);
  pinMode(P2B1, INPUT_PULLUP);   
  pinMode(P2ST, INPUT_PULLUP);
  pinMode(P2B2, INPUT_PULLUP);          
  pinMode(P2B3, INPUT_PULLUP);
  pinMode(ENABLE, INPUT_PULLUP);
 }


void loop(){                       // The main loop of the program. Calls all of the other loops as needed.
  {
  scaninputs();                    // Scans button inputs and records them to variables.
  buttoncombos();                  // Checks for button combinations and stets values.
  setoutputs();                    // Sets output values for port manipulation based on button input variables.
  }

  DDRA = outputa;                  // Sets PORTA outputs based on inputs
  DDRB = outputb;
}


void setoutputs(){                 // Translates button values into port outputs
              
if (P1STO == 1)
  outputb |= 2;                            
if (P1SLO == 1)   
  outputa |= 8;
if (P1HO == 1) 
  outputb |= 8;    
if (P2STO == 1)
  outputb |= 4;                            
if (P2SLO == 1)   
  outputb |= 32;
if (P2HO == 1) 
  outputb |= 16;    
}



void scaninputs(){               // Scans input pins for buttonpresses.

outputa = 0;
outputb = 0;

P1STO = 0;                      
P1SLO = 0;
P1HO = 0;
P1B1V = 0;                    
P1STV = 0;
P1B2V = 0;                    
P1B3V = 0;
P2STO = 0;                      
P2SLO = 0;
P2HO = 0;
P2B1V = 0;                    
P2STV = 0;
P2B2V = 0;                    
P2B3V = 0;
ENVAL = 0;
 
  val = digitalRead(P1ST);        // read input value from data line
  if (val == LOW) {               // check if the data input is LOW (button pressed)
  P1STV = 1;                      // store value of button state
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
  val = digitalRead(P2ST);        
  if (val == LOW) {             
  P2STV = 1;                        
  }
  val = digitalRead(P2B1); 
  if (val == LOW) {       
  P2B1V = 1;
  }
  val = digitalRead(P2B2);
  if (val == LOW) {       
  P2B2V = 1;
  }
  val = digitalRead(P2B3); 
  if (val == LOW) {      
  P2B3V = 1;
  }
  val = digitalRead(ENABLE); 
  if (val == LOW) {      
  ENVAL = 1;                    
  }
}

void buttoncombos(){
if (P1STV == 1){
  P1STO = 1;
}
if (P2STV == 1){
  P2STO = 1;
}
if (P1STV == 1 && (P1B1V == 1 && (P1B2V == 1 && (ENVAL == 1)))){       // Checks if p1 ST B1 and B2 are pressed
  P1SLO = 1;                                            // Sets Select as pressed       
  P1STO = 0;
}
if (P2STV == 1 && (P2B1V == 1 && (P2B2V == 1 && (ENVAL == 1)))){     
  P2SLO = 1;                      
  P2STO = 0;
}
if (P1STV == 1 && (P1B2V == 1 && (P1B3V == 1 && (ENVAL == 1)))){       // Checks if p1 ST B3 and B4 are pressed
  P1HO = 1;                                             // Sets HOME as pressed
  P1STO = 0;                                            // Sets Start as not pressed
}
if (P2STV == 1 && (P2B2V == 1 && (P2B3V == 1 && (ENVAL == 1)))){   
  P2HO = 1;                       
  P2STO = 0;                       
  }
}
