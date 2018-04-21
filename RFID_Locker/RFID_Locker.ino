#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);      
MFRC522::MIFARE_Key key;


#include <Servo.h> 
Servo myservo;

boolean dong = false; 
int green = 4;
int red = 5;

void setup() {
                 
        SPI.begin();             
        mfrc522.PCD_Init();          
        pinMode(green, OUTPUT);
        pinMode(red, OUTPUT);       
        myservo.attach(6);   
        
        
}

void loop() {
  
        
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

         
               
         
          
        
        if (rfidUid == " A4 C7 44 08")
        {
          dong = !dong;          
          
          digitalWrite(green, HIGH);
          delay(1000);          
          digitalWrite(green, LOW);
          myservo.write(1);
         
            
          }
                              
        else{
          
          myservo.write(89);
          digitalWrite(red, HIGH);
          delay(1000);
          digitalWrite(red, LOW);
          delay(50);
          
              
        } 
        
          if (dong == false){
                   
          digitalWrite(green, HIGH);
          digitalWrite(red, HIGH);
          delay(500);
          digitalWrite(green, LOW);
          digitalWrite(red, LOW);
          delay(100);
          myservo.write(89);
          
          }
       
    }
            

