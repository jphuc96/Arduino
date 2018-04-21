#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);        // Create MFRC522 instance.
MFRC522::MIFARE_Key key;

int red = 7;
int yellow = 6;

void setup() {
        Serial.begin(9600);        // Initialize serial communications with the PC
        while (!Serial);           // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
        SPI.begin();               // Init SPI bus
        mfrc522.PCD_Init();        // Init MFRC522 card
        Serial.println(F("Scan the cards"));
        
        pinMode(red, OUTPUT);
        pinMode(yellow, OUTPUT);  
}

void loop() {
  
        // Look for new cards, and select one if present
        if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
            delay(50);
            return;
        }
        
        // Now a card is selected. The UID and SAK is in mfrc522.uid.
        
        // Dump UID
        Serial.print(F("Card UID:"));
        for (byte i = 0; i < mfrc522.uid.size; i++) {
                Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                Serial.print(mfrc522.uid.uidByte[i], HEX);
        } 
        Serial.println();
        
    String rfidUid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfidUid += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    rfidUid += String(mfrc522.uid.uidByte[i], HEX); 
  }
  rfidUid.toUpperCase();

  Serial.println(rfidUid);

        if (rfidUid == " E9 A0 97 1A"){
          digitalWrite(red, HIGH);
          delay(2000);
          digitalWrite(red, LOW);
          delay(2000);
        }
        else{
          digitalWrite(yellow, HIGH);
          delay(2000);
          digitalWrite(yellow, LOW);
          delay(2000);
        }       
}
