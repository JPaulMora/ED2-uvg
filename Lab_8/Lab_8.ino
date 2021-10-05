// Include application, user and local libraries
#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include <SPI.h>
#include <SD.h>
#define tux "tux.bmp"
#define tux2 "tux2.bmp"

#define p1 PUSH1
#define p2 PUSH2

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;
File dataFile;


int p1state = 0;
int p2state = 0;

int p1old = 0;
int p2old = 0;

const int chipSelect = PA_3; //cs PIN

#define SCREEN_WIDTH 180
#define SCREEN_HEIGHT 220

#define TFT_RST PD_0
#define TFT_RS  PD_2
#define TFT_CS  PD_1 // SS
#define TFT_SDI PD_3 // MOSI
#define TFT_CLK PE_1 // SCK
#define TFT_LED 0 // 0 if wired to +5V directly

#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

// Use software SPI (slower)
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED, TFT_BRIGHTNESS);

// Variables and constants
//uint16_t x, y;
int a = 0;
boolean flag = false;

void LoadImage(File& file)
{
  SPI.setModule(0);
    for (int y = 0; y < SCREEN_HEIGHT && file.available(); y++) {
        for (int x = SCREEN_WIDTH - 1; x >= 0; x--) {
            byte l = file.read();
            byte h = file.read();
            tft.drawPixel(x, y, ((uint16_t)h << 8) | l);
        }
   //     SPI.setModule(2);
        SPI.setModule(0);
    }
}

// Setup
void setup() {
  tft.begin();
  Serial.begin(9600);

  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);
 
  SPI.setModule(0);
  if (!SD.begin(PA_3)){
    Serial.println("Error reading SD");
  }

  Serial.print("\nInitializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(PA_3, OUTPUT);     // change this to 53 on a mega


  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card is inserted?");
    Serial.println("* Is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }
  
}

// Loop
void loop() {
  p1state = digitalRead(p1);
  if (p1state != p1old)
  {
    if (p1state == LOW)
    { 
      dataFile= SD.open(tux);
      LoadImage(dataFile);
    }
    p1old = p1state;
  }


  p2state = digitalRead(p2);
  if (p2state != p2old)
  {
    if (p2state == LOW)
    { 
      dataFile= SD.open(tux2);
      LoadImage(dataFile);
    }
    p2old = p2state;
  }

  
}
