/*    -------------------------------------------------
      +===============================================+
      |  ARDUINO IR-REMOTE HOME AUTOMATION MK1v1      |
      |               (OPENSOURCE)                    |
      |mail me: privatemail.suhail@gmail.com         |
      +===============================================+
      -------------------------------------------------
instagram @techy_jr


*/
#include <IRremote.h>

int RECV_PIN = 12;    //tsop1738 output pin connected to D8
#define buzzer 10  //buzzer conected pin 12

int a = 1;
int b = 1;
int c = 1;
int d = 1;


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{

  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  Serial.begin(9600);

  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);

    {
      if (results.value == 0x1FE48B7) // paste your hex code

      {
        a++;
        int x = a % 2;
        digitalWrite(7, x);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
      }
      else if (results.value == 0x1FE50AF) //paste your hex code
      {

        b++;
        int x = b % 2;
        digitalWrite(6, x);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
      }
      else if (results.value == 0x1FED827) //paste your hex code
      {
        c++;
        int x = c % 2;
        digitalWrite(5, x);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
      }
      else if (results.value == 0x1FEF807) ///paste your hex code
      {
        b++;
        int x = d % 2;
        digitalWrite(4, x);
        digitalWrite(buzzer, HIGH);
        delay(200);
        digitalWrite(buzzer, HIGH);
      }


      irrecv.resume(); //resume,continue recieving ir-signals
    }
  }
}



/*
  +=================================================================+
  | /////////////////////////////////////////////////////////////// |
  +=================================================================+

*/
