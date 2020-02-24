int dialPin = 0; // Analog 0 fÃ¼r Messung am Telefon
int dialVal = 0;
int dialValStat = 0;

int nummer = 0;
int taste = 10;

unsigned long int signalstart = 0;
unsigned long int signalstop = 0;

unsigned long int signalzeit = 0;
unsigned long int keinsignalzeit = 0;

unsigned long int auszeit = 200;
unsigned long int zwischenzeit = 100;

int midValue = 400; // der Schwellenwert um aufgelegt (LOW) von abgenommen (HIGH) zu unterscheiden

boolean dialing = false;
boolean aufgelegt = false;


void setup() 
{
  // Serial Schnittstelle inititalisieren
  Serial.begin(9600);

  Serial.println("Arduino");
  Serial.println("Impulswahltelefon Version 1.0");
  Serial.println();

  pinMode(dialPin, INPUT);

   Serial.print("Analog 0 ");
   Serial.println(analogRead(0));
}


void loop() 
{
  if (analogRead(dialPin) > midValue)
  {
    dialVal = 1;
  } else {
    dialVal = 0;
  }

  /*
  *  Wahlvorgang
   */

  if ( dialVal != dialValStat )
  {
    dialValStat = dialVal;

    // bei hochziehen der Waehlscheibe kommt einmalig ein Signal
    if (dialVal == HIGH)
    {
      dialing = true;
      if (aufgelegt)
      {
        Serial.print("telefon ");
        Serial.print("abgehoben");
        Serial.println();
        aufgelegt = false;
        signalstop = millis();
      }
    } 

    else if (dialVal == LOW)
    {
      signalstop = millis();

      //if (dialing)
      //{
      nummer++;
      Serial.print("telefon ");
      Serial.print("klackern");
      Serial.println();

      //udp.sendStr("/Dial", "klacker");
      //}
    }
  }

  /*
  *   Abfrage ob waehlscheibe runtergelaufen
  */
  keinsignalzeit = millis() - signalstop;
  
  if ( dialing == true )
  {

    if ( keinsignalzeit > zwischenzeit )
    {
      if (nummer == 10) 
      {
        taste = 0;
      } 
      else if (nummer > 0) {
        taste = nummer;
      }
      if (taste < 10) 
      {
        Serial.print("telefon ");
        Serial.print(taste);
        Serial.println();

        //udp.sendInt("/Dial", taste);
      }

      dialing = false;
      nummer = 0;
      taste = 10;
    }
  }

  /*
  *   abfrage ob hoerer aufgelegt
   */
  if ( dialVal == LOW )
  {
    if ( keinsignalzeit > auszeit && aufgelegt == false)
    {
      Serial.print("telefon ");
      Serial.print("aufgelegt");
      Serial.println();
      aufgelegt = true;
      dialing = false;
      nummer = 0;
      taste = 10;
    }
  } 
}
