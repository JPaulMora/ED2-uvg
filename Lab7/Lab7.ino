/*
  SD Card Read
  
 created  28 Sep 2021
 by Juan Pablo Mora
 */

// include the SD library:
#include <SPI.h>
#include <SD.h>
#define file1 "A.txt"
#define file2 "B.txt"

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = PA_3; //cs PIN

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
 
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

  // print the type of card
  Serial.print("\nCard type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }


  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                            // SD card blocks are always 512 bytes
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);


  Serial.println("\nFiles found on the card: ");
  root.openRoot(volume);

  // list all files in the card with date and size
  // root.ls(LS_R | LS_DATE | LS_SIZE);
  root.ls(LS_R);
  
  Serial.println("Escriba el nombre del archivo que desea leer: ");
}

int opt = 0;

File dataFile;

void loop(void) {
  if (Serial.available() > 0) {
    // read the incoming byte:
    opt = Serial.read();
    Serial.print("Opening file ");
    Serial.print(opt);

    if(opt == 48) {
          dataFile= SD.open(file1);
    } else if (opt == 49) {
          dataFile= SD.open(file2);
    } else {
      Serial.println("Opcion no existe");
    }

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
    Serial.println("\nEscriba el nombre del archivo que desea leer: ");
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening file");
    Serial.println("Escriba el nombre del archivo que desea leer: ");
  }
  }
} 
