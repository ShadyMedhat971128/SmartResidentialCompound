#include <SPI.h>    //include the SPI bus library
#include <MFRC522.h>    //include the RFID reader library
#include <Servo.h>
#include <Wire.h>

//-----------------------------------------------------------------------------------------------------------//
#define SS_PIN 10 //slave select pin
#define RST_PIN 5 //reset pin

//---states for the RFID-----//
#define default_case    'x' //"def"
/*        owner cases       */
#define owner_entered     '0'
/*        service case      */
#define service_entred   '2'
#define service_exited    '3'
/*        guest cases       */
#define visitor_entred    '4'
#define visitor_exited    '5'
//---------------------------//
// arduino i2c wiring: A4 --> SDA, A5 -->SCL
char data;
char data1;
char CLASS = default_case;
Servo myservo;
int pos = 0;

MFRC522 mfrc522(SS_PIN, RST_PIN); // instatiate a MFRC522 reader object.
MFRC522::MIFARE_Key key; //create a MIFARE_Key struct esmd 'key', which will hold the card information

//-----------------------------------------------------------------------------------------------------------//
typedef struct {

  char n;

  String esm;

  int prp;

  byte prpAcess[16]; //an array with 16 bytes to GIVE PROPERTY ACCESs

  bool v;

  bool s;

}
owner;

//-----------------------------------------------------------------------------------------------------------//
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
//-----------------------------------------------------------------------------------------------------------//
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


//-----------------------------------------------------------------------------------------------------------//
#define block 4
#define blockx 2
byte readbackblock[18];
char Oesm;
owner O[3]; //suppose we have 3 owners as a sample
//int Vid;
String entery;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// i2c request function
void requestEvent()
{

  Wire.write(CLASS);  /*send string on request */
  CLASS = default_case;
  //CLASS= guest_entred;
  //Serial.println("in the request ");
}
//-----------------------------------------------------------
// reset function
int j = 0;
void(* resetFunc) (void) = 0;  // declare reset fuction at address 0
//-----------------------------------------------------------
void setup() {
  // I2C intis
  Wire.begin(8);                /* join i2c bus with address 8 */
  Wire.onRequest(requestEvent); /* register request event */
  //---------------------------------------------------------------------------
  myservo.attach(9);
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin(); // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
  //mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details

  //-----------------------------------------------------------------------------------------------------------//
  // OWNERS DATABASE
  O[0] = {'a', "ahmed wael", 2, {0x02, 0x02, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, true, false};
  O[1] = {'s', "shady medhat", 1, {0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false, false};
  O[2] = {'y', "youssef ayman", 1, {0x01, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, false, true};

  //-----------------------------------------------------------------------------------------------------------//
  // Prepare the security key for the read and write functions.
  for (byte i = 0; i < 6; i++) {

    key.keyByte[i] = 0xFF; //keyByte is defined in the "MIFARE_Key" 'struct' definition in the .h file of the library
  }

}

void loop()
{
  data = 0;
  delay(100);
  Serial.println("Good Morning ");
  if (!Serial.available())
  {
    if (mfrc522.PICC_IsNewCardPresent())
    {
      while ( ! mfrc522.PICC_ReadCardSerial()) {
        return;
      }
      readBlock(block, readbackblock);
      if (readbackblock[6] == 0x19)
      {
        Serial.println("welcome back sir");
        // opens the door
        for (pos = 0; pos <= 180; pos += 1)
        {
          myservo.write(pos);    //OPENS THE DOOR
          delay(15);
        }
        for (pos = 180; pos >= 0; pos -= 1)
        {
          myservo.write(pos);    //CLOSES THE DOOR
          delay(15);
        }
        CLASS = owner_entered;
      }

    }

  }
  else if (Serial.available())
  {
    data = Serial.read();

    Serial.println(data);
    switch (data)
    {
      /****************** CASE A VISITOR IS ENTERING *********************/
      case 'v' :
        Serial.println(data);
        Serial.println("Enter Owner Data");
        delay(7000);
        while (Serial.available())
        {
          data1 = Serial.read();
        }
        Serial.println(data1);
        for (int i = 0; i < 3; i++)
        {
          if (data1 == O[i].n)
          {
            Serial.println("NAME FOUND");
            if (O[i].v == true)
            {
              Serial.print("writting access card to MR ");
              Serial.print(O[i].esm);
              Serial.println("'s Property");
              while (!mfrc522.PICC_IsNewCardPresent())
              {
                //Serial.print(",");
              }
              if ( ! mfrc522.PICC_ReadCardSerial()) {
                return;
              }
              
              writeBlock(block, O[i].prpAcess);
              writeBlock(blockx, O[i].prpAcess);
              
              //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
              //Serial.print("PROPERTY NO: ");
              
              Serial.print("Access card to property ");
              Serial.print(O[i].prp);
              Serial.println(" was written");
              CLASS = visitor_entred;
              for (pos = 0; pos <= 180; pos += 1)
              {
                myservo.write(pos);    //OPENS THE DOOR
                delay(15);
              }
              for (pos = 180; pos >= 0; pos -= 1)
              {
                myservo.write(pos);    //CLOSES THE DOOR
                delay(15);
              }
              
              
              
              
                
                  resetFunc(); //call reset
                  
              

            }

          }
        }
        break;
      /****************** CASE A SERVICE IS ENTERING *********************/
      case 'x' :
        Serial.println("Enter Owner Data");
        delay(7000);
        while (Serial.available())
        {
          data1 = Serial.read();
        }
        Serial.println(data1);


        for (int i = 0; i < 3; i++)
        {
          if (data1 == O[i].n)
          {
            if (O[i].s == true)
            {

              // write on card access to the owner property only
              //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
              Serial.print("writting access card to MR. ");
              Serial.print(O[i].esm);
              Serial.println("'s Property");
              while (!mfrc522.PICC_IsNewCardPresent()) {}
              if ( ! mfrc522.PICC_ReadCardSerial()) {
                return;
              }
              writeBlock(block, O[i].prpAcess);
              writeBlock(blockx, O[i].prpAcess);
              
              //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
              //Serial.print("PROPERTY NO: ");
              Serial.print("Access card to property ");
              Serial.print(O[i].prp);
              Serial.println(" was written");
              CLASS = service_entred;
              for (pos = 0; pos <= 180; pos += 1)
              {
                myservo.write(pos);    //OPENS THE DOOR
                delay(15);
              }
              delay(1000);
              for (pos = 180; pos >= 0; pos -= 1)
              {
                myservo.write(pos);    //CLOSES THE DOOR
                delay(15);
              }
              
              resetFunc(); //call reset
            }
          }
        }
      /****************** CASE A VISITOR IS LEAVING *********************/
      case 'l':
        CLASS = visitor_exited;
        break;
      /****************** CASE A SERVICE IS LEAVING *********************/
      case 'n':
        CLASS = service_exited;
        break;
      /****************** CASE OWNER IS ENTERING *********************/
      default :
        break;
        //Serial.println("End of case");

    }
  }
}
