#include <MFRC522.h>    //include the RFID reader library
#include <SPI.h>
#define SS_PIN 10 //slave select pin
#define RST_PIN 5 //reset pin
#define block 4                                       //BLOCK 4 IN CARD FOR OWNER CHECK                                        //BLOCK 4 IN CARD FOR OWNER PROPERTY NO CHECK                                //BLOCK 8 IN CARD FOR PROPERTY EXIT                                 //BLOCK 9 IN CARD FOR PARKING EXIT 
#define building_one_num 0x25
#define building_two_num 0x20 
;
byte blockcontent[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
byte Ucard[16]={0, 0, 0, 0, 0,0xAA,0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte O1_card[16]={0, 0, 0, 0, 0,0,0x19, 0x01, 0, 0, 0, 0, 0, 0, 0, 0};
byte O2_card[16]={0, 0, 0, 0, 0,0,0x19, 0x02, 0, 0, 0, 0, 0, 0, 0, 0};


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

void setup()
{
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin(); // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
  /*** Prepare the security key for the read and write functions. ***/
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF; //keyByte is defined in the "MIFARE_Key" 'struct' definition in the .h file of the library
  }

}

void loop()
{

  /******************** ENETERING PROPERTIES & PARKING AREAS ***************************/
                                    /**creating card **/

  while(!mfrc522.PICC_IsNewCardPresent()){}
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  writeBlock(block,O2_card);
  writeBlock(6,blockcontent);
  writeBlock(5,blockcontent);
  writeBlock(2,blockcontent);
  writeBlock(8,blockcontent);
  //writeBlock(Ublock,U_card);  
   mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
