#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);        // Create MFRC522 instance.
MFRC522::MIFARE_Key key;

int a;
int i;
int RFID_status;
int RFID_read = 0;

void setup() {
        Serial.begin(9600);        // Initialize serial communications with the PC
        while (!Serial);           // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
        SPI.begin();               // Init SPI bus
        mfrc522.PCD_Init();        // Init MFRC522 card
        Serial.println(F("Scan the cards"));
        
        for (i=2;i<=9;i=i+1)
        {pinMode(i, OUTPUT);} 
}

void loop() {
  
        // Look for new cards, and select one if present
        if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
            delay(50);
            return;
        }
              
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

  Serial.println();

        if ((rfidUid == " E9 A0 97 1A") ^ (rfidUid == " 01 02 03 04"))
          {
            Serial.println("Hi Bro!!!!!");
             Serial.println();
          for (i=2;i<=7;i=i+1)
          {digitalWrite(i, HIGH);
          delay(60);
          digitalWrite(i, LOW);
          delay(60);
           }
          } 
         else{  
          Serial.println("Go Away!!!!!");        
          digitalWrite(8, HIGH);
          delay(2000);
          digitalWrite(8, LOW);
          delay(2000);
         }
         
         if (rfidUid == " 01 02 03 04")
         {
           void loop();
         {
         Serial.println("This is Xperia Z3");
         for (a=2;a<=7;a=a+1)
{
  for(i=2;i<=9-a;i=i+1)
  {
    digitalWrite(i, HIGH);
    delay(40);
    digitalWrite(i, LOW);
    delay(40);
  }
  digitalWrite(9-a, HIGH);
}
for (i=2;i<=7;i=i+1)
{
  digitalWrite(i, LOW);
}
}
         }
          
  }
