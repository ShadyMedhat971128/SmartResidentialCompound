#include <SPI.h>    //include the SPI bus library
#include <MFRC522.h>    //include the RFID reader library
#include <Servo.h>
#include <Wire.h>


int SERVO_INIT=120;
int SERVO_END= 300;
// arduino i2c wiring: A4 --> SDA, A5 -->SCL
//---states for the RFID-----//
#define default_case    'x' //"def"
/*        owner cases       */
#define owner_entered   'o'
#define owner_exited    'y'
#define owner_incprp    't'
/*        guest cases       */
#define guest_entred    'g'
#define guest_incprp    'l'
#define guest_exit      'L'
/*        guard cases       */
#define guard_ext       'z'
#define guard_ent       'j'
/*        ERASING CARDS    */
#define code_erased     'e'
//---------------------------//

typedef struct {

  char n;

  String esm;

  int prp;

  byte prpAcess[16]; //an array with 16 bytes to GIVE PROPERTY ACCESs

  bool v;

  bool s;

}
owner;
//----------------------------------------//
Servo myservo;
int pos = 0;

#define SS_PIN 10 //slave select pin spi
#define RST_PIN 5 //reset pin        spi

MFRC522 mfrc522(SS_PIN, RST_PIN); // instatiate a MFRC522 reader object.
MFRC522::MIFARE_Key key; //create a MIFARE_Key struct esmd 'key', which will hold the card information

void writeBlock(int blockNumber, byte arrayAddress[])
{

  //this makes sure that we only write into data blocks. Every 4th block is a trailer block for the access/security info.
  int largestModulo4Number = blockNumber / 4 * 4;

  int trailerBlock = largestModulo4Number + 3; //determine trailer block for the sector
  if (blockNumber > 2 && (blockNumber + 1) % 4 == 0) {
    Serial.print(blockNumber);
    Serial.println(" is a trailer block:");
    return 2;
  }

  Serial.print(blockNumber);

  Serial.println(" is a data block:");

  //authentication of the desired block for access
  byte status =
    mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &
                             key, & (mfrc522.uid));

  if (status != MFRC522::STATUS_OK) {

    Serial.print("PCD_Authenticate() failed: ");

    Serial.println(mfrc522.GetStatusCodeName(status));

    return 3; //return "3" as error message
  }

  //writing the block
  status = mfrc522.MIFARE_Write(blockNumber, arrayAddress, 16);

  //status = mfrc522.MIFARE_Write(9, value1Block, 16);
  if (status != MFRC522::STATUS_OK) {

    Serial.print("MIFARE_Write() failed: ");

    Serial.println(mfrc522.GetStatusCodeName(status));

    return 4; //return "4" as error message
  }

  Serial.println("block was written");
}
int readBlock(int blockNumber, byte arrayAddress[])
{
  int largestModulo4Number = blockNumber / 4 * 4;
  int trailerBlock = largestModulo4Number + 3; //determine trailer block for the sector

  //authentication of the desired block for access
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));

  //reading a block
  byte buffersize = 180;//we need to define a variable with the read buffer size, since the MIFARE_Read method below needs a pointer to the variable that contains the size...
  status = mfrc522.MIFARE_Read(blockNumber, arrayAddress, &buffersize);//&buffersize is a pointer to the buffersize variable; MIFARE_Read requires a pointer instead of just a number

  // Halt PICC
  mfrc522.PICC_HaltA();
  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();
}


#define block 4
#define blockx 2
#define building_one_num 0x01
#define building_two_num 0x02

#define building_no 0x01
byte readbackblock[18];
byte readbackblockx[18];
byte blockcontent[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
char Oesm;
owner O[3];
char CLASS = default_case;
int ledPin = 3;
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;
int d = 2000;
void requestEvent()
{

  Wire.write(CLASS);  /*send string on request */
  CLASS = default_case;
  //CLASS= guest_entred;
  Serial.println("in the request ");
}
void(* resetFunc) (void) = 0;  // declare reset fuction at address 0
void setup()
{
  // OWNERS DATABASE
  O[0] = {'a', "ahmed wael", 2, {0x02, 0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, true, false};
  O[1] = {'s', "shady medhat", 1, {0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false, true};
  O[2] = {'y', "youssef ayman", 1, {0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, true, false};

  Wire.begin(8);                /* join i2c bus with address 8 */
  Wire.onRequest(requestEvent); /* register request event */
  myservo.attach(9);               // attaches the servo on pin 9 to the servo object
  //pinMode(ledPin, OUTPUT);      // declare LED as output

  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin(); // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
  //mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details

  // Prepare the security key for the read and write functions.
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
  }

}

void loop()
{
  //val = digitalRead(inputPin);  // read input value
  while (digitalRead(inputPin) == HIGH)    // check if the input is HIGH
  {
    //digitalWrite(ledPin, HIGH);  // turn LED ON
    Serial.println("Exit code Activated");
    /******************** EXITING PROPERTIES ***************************/
    while (!mfrc522.PICC_IsNewCardPresent()) {}
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      return;
    }
    readBlock(blockx, readbackblockx);
    delay(15);
    readBlock(block, readbackblock);

    /***************************** ADMINS SITUATION ****************************/
    if (readbackblock[5] == 0xAA)
    {
     for(pos = SERVO_INIT; pos <= SERVO_END; pos += 1)
      {
        myservo.write(pos);              // OPENS THE DOOR
        delay(15);
      }
      delay(1000);
      for (pos=SERVO_END; pos>=SERVO_INIT; pos -= 1)
      {
        myservo.write(pos);              // CLOSES THE DOOR
        delay(15);
      }
      Serial.println("Guard Left Property 1");
      CLASS = guard_ext;
    }
    /***************************** OWNERS SITUATION ****************************/
    else if (readbackblock[6] == 0x19)
    {
      if (readbackblock[7] == building_no)
      {
        for (int i = 0; i < 3; i++)
        {
          if (readbackblock[7] == O[i].prp)
          {
            Serial.print("An owner in property ");
            Serial.print(O[i].prp);
            Serial.println(" left property 1");
            break;
          }
        }
        CLASS = owner_exited;

       for (pos = SERVO_INIT; pos <= SERVO_END; pos += 1)
        {
          myservo.write(pos);              // OPENS THE DOOR
          delay(15);
        }
        delay(1000);
        for (pos=SERVO_END; pos>=SERVO_INIT; pos -= 1)
        {
          myservo.write(pos);              // CLOSES THE DOOR
          delay(15);
        }
      }
    }

    /***************************** NOT OWNERS SITUATION ***************************/
    else
    {
      if (readbackblockx[0] == building_no)
      {
        Serial.println("Exit Code Erased");
        CLASS = code_erased;

        for (pos = SERVO_INIT; pos <= SERVO_END; pos += 1)
        {
          myservo.write(pos);              // OPENS THE DOOR
          delay(15);
        }
        delay(1000);
        for (pos=SERVO_END; pos>=SERVO_INIT; pos -= 1)
        {
          myservo.write(pos);              // CLOSES THE DOOR
          delay(15);
        }
        Serial.println("guest left property 1");
        CLASS = guest_exit;

      }
    }
  }
while (digitalRead(inputPin) == LOW)
  {
    /******************** ENETERING PROPERTIES ***************************/
    Serial.println("PROPERTY 1");
     while(!mfrc522.PICC_IsNewCardPresent()) {}
      if ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
      }
      readBlock(block, readbackblock);
      /***************************** ADMINS SITUATION ****************************/
      if (readbackblock[5] == 0xAA)
      {
       for (pos = SERVO_INIT; pos <= SERVO_END; pos += 1)
        {
          myservo.write(pos);              // OPENS THE DOOR
          delay(15);
        }
        for (pos=SERVO_END; pos>=SERVO_INIT; pos -= 1)
        {
          myservo.write(pos);              // CLOSES THE DOOR
          delay(15);
        }
        Serial.println("GUARD ENTERED PROPERTY 1");
        CLASS = guard_ent;
        delay(d);
      }
      else
      {
        /***************************** OWNERS SITUATION ****************************/
        if (readbackblock[6] == 0x19)
        {
          if (readbackblock[7] == building_no)
          {
            Serial.println("Owner enterd property 1");
            CLASS = owner_entered;

           for (pos = SERVO_INIT; pos <= SERVO_END; pos += 1)
            {
              myservo.write(pos);              // OPENS THE DOOR
              delay(15);
            }
            delay(1000);
            for (pos=SERVO_END; pos>=SERVO_INIT; pos -= 1)
            {
              myservo.write(pos);              // CLOSES THE DOOR
              delay(15);
            }
            delay(d);
          }
          else
          {
            for (int i = 0; i < 3; i++)
            {
              if (readbackblock[7] == O[i].prp)
              {
                Serial.print("An owner in property ");
                Serial.print(O[i].prp);
                Serial.println(" is trying to enter wrong property 1");
                CLASS = owner_incprp;
                delay(d);
                break;
              }

            }

          }
        }

        else
        {
          /***************************** GUEST SITUATION ****************************/

          if (readbackblock[0] == building_no)
          {
            Serial.println("ACCESS GRANTED for Guest in property 1");
            while (!mfrc522.PICC_IsNewCardPresent()) {}
            if ( ! mfrc522.PICC_ReadCardSerial()) {
              return;
            }
            writeBlock(block, blockcontent);
            for (pos = SERVO_INIT; pos <= SERVO_END; pos += 1)
            {
              myservo.write(pos);              // OPENS THE DOOR
              delay(15);
            }
            delay(1000);
            for (pos=SERVO_END; pos>=SERVO_INIT; pos -= 1)
            {
              myservo.write(pos);              // CLOSES THE DOOR
              delay(15);
            }
            //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
            CLASS = guest_entred;
            Serial.println("ENTERY CODE ERASED");
            CLASS = code_erased;
            delay(d);

            resetFunc(); //call reset
          }
          /************************** BREAK IN TRIAL CASE *******************************/
          else
          {
            Serial.println("Guest is trying to enter incorrect property");
            CLASS = guest_incprp;
            delay(d);
          }

        }
      }
    }
  }




//
