#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);        // Create MFRC522 instance.
MFRC522::MIFARE_Key key;

#include <Wire.h> 

void setup() {

        Serial.begin(9600);
        SPI.begin();               // Init SPI bus
        mfrc522.PCD_Init();        // Init MFRC522 card      
        Serial.print("Please Scan...");            
}

void loop() {
  
        // Look for new cards, and select one if present
        if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
            delay(1000);
            return;
        }     
         
           
    String rfidUid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfidUid += String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    rfidUid += String(mfrc522.uid.uidByte[i], HEX); 
  }
  rfidUid.toUpperCase();
        if (rfidUid == " E9 A0 97 1A"){
          Serial.println("Welcome");          
        }
        else{          
           Serial.println("Sorry, Please try again");
        }
        delay(3000);
         Serial.println("Please Scan...");
                      
    }
            

