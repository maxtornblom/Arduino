const int buttonPin = // Button PIn ;    
const int buzzer = // Speaker Pin ;

int buttonState = LOW;             
int lastButtonState = LOW;  
int doesitwork = LOW;  

int pause_value = 100; // depending on your skill and how fast your fingers are you can change this value to make typing a message faster or slower 
long signal_length = 0;
long pause = 0;

String morse = "";
String dash = "-";
String dot = "*";

boolean cheker = false;
boolean linecheker = false;

long lastDebounceTime = 0;  
long debounceDelay = 0;    
void setup()
{
  Serial.begin(9600);
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  
  Serial.println("Morse Code: ");

  while(!digitalRead(buttonPin))
    ;
  
}

void loop() {
 
  buttonState = digitalRead(buttonPin) == LOW;

  
  
  if (buttonState && lastButtonState)  // basic state machine depending on the state of the signal from the button     
  {
    ++signal_length;       
    if (signal_length<2*pause_value)   //this help to notice that there is a change in the signal length        
    {                                  // best use for the measuring of signal_length would be use of the millis() but this was used  for simplicity      
    tone(buzzer, 460) ;
    }
    else
    {
      tone(buzzer, 460) ;
      }
  }
  else if(!buttonState && lastButtonState)   //this part of the code happens when the button is released and it send either * or - into the buffer      
  {
     
     if (signal_length>50 && signal_length<2*pause_value )
     {
       morse =  morse + dot;
     } 
      else if (signal_length>2*pause_value)
      {
        morse = morse +  dash;
      }
    signal_length=0; 
    digitalWrite(13, LOW); 
    noTone(buzzer); 
  }
  else if(buttonState && !lastButtonState)  // this part happens when the button is pressed and its use to reset several values        
  {
    pause=0;
    digitalWrite(13, HIGH);  
    cheker = true;
    linecheker = true;
  }
  else if (!buttonState && !lastButtonState)
  {  
    ++pause;
    if (( pause>3*pause_value ) && (cheker))
    { 
      print(morse);
      cheker = false;
      morse = "";
    }
    if ((pause>20*pause_value) && (linecheker))
    {
      Serial.print(' ');
      linecheker = false;
    }
  }
  lastButtonState=buttonState;
  delay(1);
}
void print(String translator)   
{                                 
                                   
  if (translator=="*-")
    Serial.print("A");
  else if (translator=="-***")  
    Serial.print("B");
  else if (translator=="-*-*")  
    Serial.print("C");
  else if (translator=="-**")  
    Serial.print("D");
  else if (translator=="*")  
    Serial.print("E");
  else if (translator=="**-*")  
    Serial.print("F");
  else if (translator=="--*")  
    Serial.print("G");
  else if (translator=="****")  
    Serial.print("H");
  else if (translator=="**")  
    Serial.print("I");
  else if (translator=="*---")  
    Serial.print("J");
  else if (translator=="-*-")  
    Serial.print("K");
  else if (translator=="*-**")  
    Serial.print("L");
  else if (translator=="--")  
    Serial.print("M");
  else if (translator=="-*")  
    Serial.print("N");
  else if (translator=="---")  
    Serial.print("O");
  else if (translator=="*--*")  
    Serial.print("P");
  else if (translator=="--*-")  
    Serial.print("Q");
  else if (translator=="*-*")  
    Serial.print("R");
  else if (translator=="***")  
    Serial.print("S");
  else if (translator=="-")  
    Serial.print("T");
  else if (translator=="**-")  
    Serial.print("U");
  else if (translator=="***-")  
    Serial.print("V");
  else if (translator=="*--")  
    Serial.print("W");
  else if (translator=="-**-")  
    Serial.print("X");
  else if (translator=="-*--")  
    Serial.print("Y");
  else if (translator=="--**")  
    Serial.print("Z");

  else if (translator=="*----")  
    Serial.print("1");
  else if (translator=="**---")  
    Serial.print("2");
  else if (translator=="***--")  
    Serial.print("3");
  else if (translator=="****-")  
    Serial.print("4");
  else if (translator=="*****")  
    Serial.print("5");
  else if (translator=="-****")
    Serial.print("6");
  else if (translator=="--***")  
    Serial.print("7");
  else if (translator=="---**")  
    Serial.print("8");
  else if (translator=="----*")  
    Serial.print("9");
  else if (translator=="-----")  
    Serial.print("0");
  
  Serial.print(" ");
    
  translator=""; 
}
