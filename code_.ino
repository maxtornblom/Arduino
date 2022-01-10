const int buttonPin = 13;    
const int buzzer = 9;

int buttonState = LOW;             
int lastButtonState = LOW;  
int doesitwork = LOW;  

int pause_value = 100;  
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

  
  
  if (buttonState && lastButtonState)       
  {
    ++signal_length;       
    if (signal_length<2*pause_value)        
    {                                       
    tone(buzzer, 460) ;
    }
    else
    {
      tone(buzzer, 460) ;
      }
  }
  else if(!buttonState && lastButtonState)          
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
  else if(buttonState && !lastButtonState)          
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
      printaj(morse);
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
void printaj(String prevodilac)   
{                                 
                                   
  if (prevodilac=="*-")
    Serial.print("A");
  else if (prevodilac=="-***")  
    Serial.print("B");
  else if (prevodilac=="-*-*")  
    Serial.print("C");
  else if (prevodilac=="-**")  
    Serial.print("D");
  else if (prevodilac=="*")  
    Serial.print("E");
  else if (prevodilac=="**-*")  
    Serial.print("F");
  else if (prevodilac=="--*")  
    Serial.print("G");
  else if (prevodilac=="****")  
    Serial.print("H");
  else if (prevodilac=="**")  
    Serial.print("I");
  else if (prevodilac=="*---")  
    Serial.print("J");
  else if (prevodilac=="-*-")  
    Serial.print("K");
  else if (prevodilac=="*-**")  
    Serial.print("L");
  else if (prevodilac=="--")  
    Serial.print("M");
  else if (prevodilac=="-*")  
    Serial.print("N");
  else if (prevodilac=="---")  
    Serial.print("O");
  else if (prevodilac=="*--*")  
    Serial.print("P");
  else if (prevodilac=="--*-")  
    Serial.print("Q");
  else if (prevodilac=="*-*")  
    Serial.print("R");
  else if (prevodilac=="***")  
    Serial.print("S");
  else if (prevodilac=="-")  
    Serial.print("T");
  else if (prevodilac=="**-")  
    Serial.print("U");
  else if (prevodilac=="***-")  
    Serial.print("V");
  else if (prevodilac=="*--")  
    Serial.print("W");
  else if (prevodilac=="-**-")  
    Serial.print("X");
  else if (prevodilac=="-*--")  
    Serial.print("Y");
  else if (prevodilac=="--**")  
    Serial.print("Z");

  else if (prevodilac=="*----")  
    Serial.print("1");
  else if (prevodilac=="**---")  
    Serial.print("2");
  else if (prevodilac=="***--")  
    Serial.print("3");
  else if (prevodilac=="****-")  
    Serial.print("4");
  else if (prevodilac=="*****")  
    Serial.print("5");
  else if (prevodilac=="-****")
    Serial.print("6");
  else if (prevodilac=="--***")  
    Serial.print("7");
  else if (prevodilac=="---**")  
    Serial.print("8");
  else if (prevodilac=="----*")  
    Serial.print("9");
  else if (prevodilac=="-----")  
    Serial.print("0");
  
  Serial.print(" ");
    
  prevodilac=""; 
}