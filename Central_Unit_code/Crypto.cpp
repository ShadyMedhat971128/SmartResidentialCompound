#include "Crypto.h"
void MAC(char* message,char* key, char size)
{
     des_ctx dc;
     //des_ctx dc2;
     char* key2=key;
     keyChange(key2, 1 ,size);
     char* key3 = key2;
     keyChange(key3, 1,size);


     TripleDES_ENC(&dc, message , 1, key, key2, key3); // 3DES Encrypt
}

//-------------------------------------------------------------------------------------------------------//

void combine_message(char* message,char* state,char *  temp_mac_message, char state_size, char sizeOfMAC_in_message)
{
     
     for (char i = 0; i < state_size; i++)
     {
          message[i] = state[i];
          
     }
     //char mac_counter = (sizeof(temp_mac_message) ) - sizeOfMAC_in_message; // example : if state.size => 16 then mac counter starts from {12,13,14,15} 
     char mac_counter = 0;                                                                                                        //message now starts from {16,17,18,19}
     for (char i = 0; i < sizeOfMAC_in_message; i++)
     {
          message[state_size] = temp_mac_message[mac_counter];
          mac_counter++;
          state_size++;
     }

}

//-------------------------------------------------------------------------------------------------------//

void separete_mac(char* message, char* data, char* mac, char message_size, char mac_size)
{
     char data_size = message_size - mac_size;
     for (char i = 0; i < data_size; i++)
     {
          
               data[i] = message[i];
          
               
     }
     for (char i = 0; i < mac_size; i++)
     {
          mac[i] = message[data_size+i];
          data[data_size + i] = 0;
     }
}

//-------------------------------------------------------------------------------------------------------//

void keyChange(char* key, char value,char keysize)
{
     for (char i = 0; i < keysize ; i++)
     {
          key[i] += value;
     }
}

//-------------------------------------------------------------------------------------------------------//

void copyArray(char* arrOriginal, char* arrCopy, char size)
{
     for (char i = 0; i < size; i++)
     {
          arrCopy[i]=arrOriginal[i];
     }
}

bool macCompare(char* data, char* mac, char* mac_key, char data_size, char mac_size)
{
     MAC(data, mac_key, data_size);
     char check_counter = 0;
     for (char i = 0; i < mac_size; i++)
     {
          if (data[i] == mac[i])
          {
               check_counter++;
          }
     }
     if (check_counter >= mac_size)
          return true;
     else
          return false;
}

//------------------------------------------------------------------------------------------------------//

char mod(char a , char b)
{

     return a % b;
     /*if (a < b)
     {
          return a;
     }
     else
     {
          mod((a - b), b);
     }*/
}

char DH(char Q_prime, char* a_num)
{
     // generate Xa < Q_prime
     char Xa = mod(rand(),Q_prime);
     //compute Ya = pow(a_num, Xa)
     //char Ya = mod((char)pow(a_num, Xa),Q_prime);
     //return Ya
     return Xa;
}

void sequence_key_generator(char* enc_key,char* mac_key, char mac_size,char shared_key)
{
     char temp_key;
     for (char i = 1; i <= key_size; i++)
     {
          temp_key = mod((i * shared_key + (char)pow(i,2)), q);
          enc_key[i - 1] = temp_key;
          if (i <= (key_size - mac_size))
          {
               mac_key[i - 1] = temp_key;
          }
          else
          {
               mac_key[i - 1] = 0;
          }

     }

}
