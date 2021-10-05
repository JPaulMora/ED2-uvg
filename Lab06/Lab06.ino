
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h" // https://github.com/yuvadm/tiva-c/blob/master/inc/hw_memmap.h

#define p1 PUSH1
#define p2 PUSH2

// j1
#define j11 PB_5
#define j12 PB_0
#define j13 PB_1
#define j14 PE_4
#define j15 PE_5
#define j16 PB_4
#define j17 PA_5
#define j18 PA_6
#define j19 PA_7

// j2

#define j21 PB_2
#define j22 PE_0
#define j23 PF_0
//#define j24 PE_4
#define j25 PB_7
#define j26 PB_6
#define j27 PA_4
#define j28 PA_3
#define j29 PA_2
#define j49 PD_7

//bool playing = false;
int player1 = 0;
int player2 = 0;

int p1state = 0;
int p2state = 0;

int p1old = 0;
int p2old = 0;

bool ganador = false;

void setup()
{
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);

  // j1
  pinMode(j11, INPUT);
  pinMode(j12, INPUT);
  pinMode(j13, INPUT);
  pinMode(j14, INPUT);
  pinMode(j15, INPUT);
  pinMode(j16, INPUT);
  pinMode(j17, INPUT);
  pinMode(j18, INPUT);
  pinMode(j19, INPUT);

  // j2

  pinMode(j21, INPUT);
  pinMode(j22, INPUT);
  pinMode(j23, INPUT);
  pinMode(j25, INPUT);
  pinMode(j26, INPUT);
  pinMode(j27, INPUT);
  pinMode(j28, INPUT);
  pinMode(j29, INPUT);
  pinMode(j49, INPUT);

  // Failed attempt
  //  GPIOPadConfigSet(GPIO_PORTA_BASE,
  //  GPIODirModeSet(GPIO_PORTA_BASE, 0x0 ,GPIO_DIR_MODE_IN);

  Serial.begin(9600);
}

void loop()
{

  // put your main code here, to run repeatedly:
  p1state = digitalRead(p1);

  if (p1state != p1old && !ganador)
  {
    if (p1state == LOW)
    {
      digitalWrite(RED_LED, HIGH);
      player1++;

      Serial.print("Player 1:  ");
      Serial.println(player1);
    }
    else
    {
      digitalWrite(RED_LED, LOW);
    }
    p1old = p1state;
  }

  p2state = digitalRead(p2);

  if (p2state != p2old && !ganador)
  {
    if (p2state == LOW)
    {
      digitalWrite(GREEN_LED, HIGH);
      player2++;

      Serial.print("Player 2:  ");
      Serial.println(player2);
    }
    else
    {
      digitalWrite(GREEN_LED, LOW);
    }
    p2old = p2state;
  }

  
   digitalWrite(BLUE_LED, !ganador);

  
  if (ganador) {
    digitalWrite(RED_LED, ganador && player1 >= 10);
    digitalWrite(GREEN_LED, ganador && player2 >= 10);
  } else {

    switch (player1)
    {
    case 0:
      digitalWrite(j11, LOW);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 1:
      digitalWrite(j11, HIGH);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 2:
      digitalWrite(j11, LOW);
      digitalWrite(j12, HIGH);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 3:
      digitalWrite(j11, LOW);
      digitalWrite(j12, LOW);
      digitalWrite(j13, HIGH);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 4:
      digitalWrite(j11, LOW);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, HIGH);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 5:
      digitalWrite(j11, LOW);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, HIGH);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 6:
      digitalWrite(j11, LOW);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, HIGH);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 7:
      digitalWrite(j11, LOW);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, HIGH);
      digitalWrite(j18, LOW);
      digitalWrite(j19, LOW);
      break;
    case 8:
      digitalWrite(j11, LOW);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, HIGH);
      digitalWrite(j19, LOW);
      break;
    case 9:
      digitalWrite(j11, HIGH);
      digitalWrite(j12, LOW);
      digitalWrite(j13, LOW);
      digitalWrite(j14, LOW);
      digitalWrite(j15, LOW);
      digitalWrite(j16, LOW);
      digitalWrite(j17, LOW);
      digitalWrite(j18, LOW);
      digitalWrite(j19, HIGH);
      break;
    case 10:
      digitalWrite(j11, HIGH);
      digitalWrite(j12, HIGH);
      digitalWrite(j13, HIGH);
      digitalWrite(j14, HIGH);
      digitalWrite(j15, HIGH);
      digitalWrite(j16, HIGH);
      digitalWrite(j17, HIGH);
      digitalWrite(j18, HIGH);
      digitalWrite(j19, HIGH);
      Serial.println("Jugador 1 ha ganado");
      ganador = true;
      break;
    }

    switch (player2)
    {
    case 0:
      digitalWrite(j21, LOW);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 1:
      digitalWrite(j21, HIGH);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 2:
      digitalWrite(j21, LOW);
      digitalWrite(j22, HIGH);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 3:
      digitalWrite(j21, LOW);
      digitalWrite(j22, LOW);
      digitalWrite(j23, HIGH);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 4:
      digitalWrite(j21, LOW);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, HIGH);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 5:
      digitalWrite(j21, LOW);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, HIGH);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 6:
      digitalWrite(j21, LOW);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, HIGH);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 7:
      digitalWrite(j21, LOW);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, HIGH);
      digitalWrite(j29, LOW);
      digitalWrite(j49, LOW);
      break;
    case 8:
      digitalWrite(j21, LOW);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, HIGH);
      digitalWrite(j49, LOW);
      break;
    case 9:
      digitalWrite(j21, HIGH);
      digitalWrite(j22, LOW);
      digitalWrite(j23, LOW);
      digitalWrite(j25, LOW);
      digitalWrite(j26, LOW);
      digitalWrite(j27, LOW);
      digitalWrite(j28, LOW);
      digitalWrite(j29, LOW);
      digitalWrite(j49, HIGH);
      break;
    case 10:
      digitalWrite(j21, HIGH);
      digitalWrite(j22, HIGH);
      digitalWrite(j23, HIGH);
      digitalWrite(j25, HIGH);
      digitalWrite(j26, HIGH);
      digitalWrite(j27, HIGH);
      digitalWrite(j28, HIGH);
      digitalWrite(j29, HIGH);
      digitalWrite(j49, HIGH);
      Serial.println("Jugador 2 ha ganado");
      ganador = true;
      break;
    }
  }

}
