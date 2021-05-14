/*
  Простой телеграфный маяк для экспериментов

  Исходный код:
  Written by Nicola Salsotto IN3GJH
  https://github.com/NicoVarg99

  Модификация сделана: 
  UA6HJQ 18.11.2018 (добавлено управление радиостанцией)
  UR5NBC 12.10.2019 (добавлено управление для радиостанций с полярным PTT)
         16.11.2019 (добавлена пауза для подачи немодулированной несущей)

  Интервал между передачей:
  10мин= 600000 (передача примерно 20 секунд)
  5мин = 300000
  3мин = 180000
  2мин = 120000
*/

#define SPEED (24)  //скорость в WPM
#define DOTLEN (1200/SPEED)
#define DASHLEN (3*(1200/SPEED))
#define PAUSE (180000)  //пауза между передачами маяка в милисекундах
#define CARRIER (10000)  //пауза для подачи немодулированной несущей в милисекундах символ $

int txPin=10;       //управление PTT (включение, длительное нажатие)
int txoffPin=11;       //управление выключением PTT (выключение, однократное нажатие)
int ledPin=13;      //мигать встроенным светодиодом или подключить внешний на пин 13
int tonePin=5;      //выход звука
int toneFreq=1209;   //Частота звука (выбирайте между 800 - 1500Гц)

void sendMsg(char*);
void dash();
void dot();


void setup()
  {
    pinMode(ledPin, OUTPUT);
    pinMode(txPin, OUTPUT); 
    pinMode(txoffPin, OUTPUT);
  }


void loop()
  {
    digitalWrite(txPin, HIGH);
    delay(900);    //txdelay - задержка после нажатия PTT
  
      sendMsg("VVV UR4NWJ UR4NWJ TEST BEACON KN49 KN49 PWR 3 W ANT DIPOLE POL VERT ASL 255 M PSE SWL $ K"); //текст маяка

    delay(20);
    digitalWrite(txPin, LOW);
    digitalWrite(txoffPin, HIGH);
    delay(1000);
	  digitalWrite(txoffPin, LOW);
    delay(PAUSE);
  }


void dash()
  {
    digitalWrite(ledPin, HIGH);
    tone(tonePin, toneFreq);
    delay(DASHLEN);
    digitalWrite(ledPin, LOW);
    noTone(tonePin);
    delay(DOTLEN);
  }


void dot()
  {
    digitalWrite(ledPin, HIGH) ;
    tone(tonePin, toneFreq);
    delay(DOTLEN);
    digitalWrite(ledPin, LOW);
    noTone(tonePin);
    delay(DOTLEN);
  }


void sendMsg(char *str)
{
  int i;

   delay(500);
 
  for(i=0;i<strlen(str);i++)
  {
    switch (str[i])
    {
    case 'A':
      dot();dash();break;
    case 'B':
      dash();dot();dot();dot();break;
    case 'C':
      dash();dot();dash();dot();break;
    case 'D':
      dash();dot();dot();break;
    case 'E':
      dot();break;
    case 'F':
      dot();dot();dash();dot();break;
    case 'G':
      dash();dash();dot();break;
    case 'H':
      dot();dot();dot();dot();break;
    case 'I':
      dot();dot();break;
    case 'J':
      dot();dash();dash();dash();break;
    case 'K':
      dash();dot();dash();break;
    case 'L':
      dot();dash();dot();dot();break;
    case 'M':
      dash();dash();break;
    case 'N':
      dash();dot();break;
    case 'O':
      dash();dash();dash();break;
    case 'P':
      dot();dash();dash();dot();break;
    case 'Q':
      dash();dash();dot();dash();break;
    case 'R':
      dot();dash();dot();break;
    case 'S':
      dot();dot();dot();break;
    case 'T':
      dash();break;
    case 'U':
      dot();dot();dash();break;
    case 'V':
      dot();dot();dot();dash();break;
    case 'W':
      dot();dash();dash();break;
    case 'X':
      dash();dot();dot();dash();break;
    case 'Y':
      dash();dot();dash();dash();break;
    case 'Z':
      dash();dash();dot();dot();break;
    case ' ':
      delay(DOTLEN*5);break;
    case '.':
      dot();dash();dot();dash();dot();dash();break;
    case ',':
      dash();dash();dot();dot();dash();dash();break;
    case ':':
      dash();dash();dash();dot();dot();break;
    case '?':
      dot();dot();dash();dash();dot();dot();break;
    case '\'':
      dot();dash();dash();dash();dash();dot();break;
    case '-':
      dash();dot();dot();dot();dot();dash();break;
    case '/':
      dash();dot();dot();dash();dot();break;
    case '(':
    case ')':
      dash();dot();dash();dash();dot();dash();break;
    case '\"':
      dot();dash();dot();dot();dash();dot();break;
    case '@':
      dot();dash();dash();dot();dash();dot();break;
      case '$':
      delay(CARRIER);break;
    case '=':
      dash();dot();dot();dot();dash();break;
    case '0':
     dash();dash();dash();dash();dash();break;
    case '1':
     dot();dash();dash();dash();dash();break;
    case '2':
     dot();dot();dash();dash();dash();break;
    case '3':
     dot();dot();dot();dash();dash();break;
    case '4':
     dot();dot();dot();dot();dash();break;
    case '5':
     dot();dot();dot();dot();dot();break;
    case '6':
     dash();dot();dot();dot();dot();break;
    case '7':
     dash();dash();dot();dot();dot();break;
    case '8':
     dash();dash();dash();dot();dot();break;
    case '9':
     dash();dash();dash();dash();dot();break;

    }
    delay(2*DOTLEN);
  }

}
