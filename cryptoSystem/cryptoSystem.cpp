/* cryptoSystem.cpp : This file contains the 'main' function.Program execution begins and ends there.
*   
*   author    : Shady Medhat
*   Project   : SmartCompound  
*   supervised by: Dr. Nabil Hamdy
*   university : misr international university
*/

#include <iostream>
#include "Crypto.h"
#include "STD_TYPES.h"
#include "STD_Print.h"
#include <string>

#define mac_size 3
using namespace std;

int main()
{

 
    // separate the input string
    //1- input the message;
    // either take it from the UART
    // ot take it from the 
    //the message will be 16 char
    const int n = 48;
    uint8 input[n]= "the amazing shady";
    uint8 Eindex = 0;
    uint8 Oindex = 0;
    uint8 Iindex = 0;
    uint8 encrypted_message[n] = {0};
    uint8 output[n] = {0};
    cout << "input message :" << endl;
    for (int i = 0; i <n; i++)
    {
        printf("%c", input[i]);
    }
    //printLine();
    cout << endl;

    //share the key
    uint8 key___ = DH(q, num);
    uint8 key_AES[16];
    uint8 key_MAC[16];



   for (int index = 0 ; index < n ; index+=12 )
   {
       sequence_key_generator(key_AES, key_MAC, mac_size, key___);
        
        uint8 state[16] = { 0 };
        uint8 message[16];
        for (int i = 0; i < 12; i++)
        {
            state[i] = input[Iindex];
            Iindex++;
        }
        
            // generating key for the final AES
             
            // generating key for the MAC
        
            //sent messgae
            //printMessage(state, (uint8)sizeof(state), "sent message");

            //-----------------------------------------------//

            // get the MAC for authintication 
            unsigned char temp_mac_message[16];
            copyArray(state, temp_mac_message, (uint8)sizeof(state));
            MAC(temp_mac_message, key_MAC, (uint8)sizeof(state));

            //printMessage(temp_mac_message, (uint8)sizeof(temp_mac_message), "encryption after mac");

            //-----------------------------------------------//
            //combine the state with the mac

            combine_message(message, state, temp_mac_message, (uint8)sizeof(state) - mac_size, mac_size);
            //printMessage(message, (uint8)sizeof(message), "combining the message");

            //----------------------------------------------//

            //AES for the message for confidientiallyty 
            aes_enc_dec(message, key_AES, 0);
            //printMessage(message, (uint8)sizeof(message), "AES enc Messgae ");

            for (uint8 i = 0; i < 12; i++)
            {
                encrypted_message[Eindex] = message[i];
                Eindex++;
            }


            /*----------------------------------------------------------------------------------------*/
            // reciving side
            /*----------------------------------------------------------------------------------------*/
            

            uint8 REC_key_AES[16] ;
            uint8 REC_key_MAC[16] ;
            sequence_key_generator(REC_key_AES, REC_key_MAC, mac_size, key___);
            aes_enc_dec(message, REC_key_AES, 1);
            //decryption testing
            uint8 data[16];
            uint8 temp_data[16];
            uint8 mac[mac_size];
            // separate the mac from the message
            separete_mac(message, data, mac, (uint8)sizeof(message), mac_size);
            //printMessage(data, 16, "display recieved data");
            //printMessage(mac, mac_size, "display mac to check");

            //generate the mac from the message again
            copyArray(data, temp_data, (uint8)sizeof(data));

            // compare the mac 
            if (macCompare(temp_data, mac, REC_key_MAC, (uint8)sizeof(data), mac_size))
            {
                //printf("message recieved successfully");
            }
            for (uint8 i = 0; i < 12; i++)
            {
                output[Oindex] = message[i];
                Oindex++;
            }
        
        
   }

    printf("\nTransmitting the message......\n\n ");
    cout << "encrypted message :" << endl;
    for (int i = 0; i < n; i++)
    {
        printf("%c", encrypted_message[i]);
    }
    cout << endl<<endl;
    printf("Receiving the message......\n\n ");
    cout << "Output :" << endl;
    for (int i = 0; i <n; i++)
    {
        printf("%c", output[i]);
    }
    cout << endl;

}
