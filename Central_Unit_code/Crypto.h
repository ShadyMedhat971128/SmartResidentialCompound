#pragma once
#include "AES.h"
#include "DES.h"
//#include "STD_TYPES.h"
#include "stdio.h"
#include "stdlib.h"
#include <cmath>

//#include <Arduino.h>
// 

#define key_size 16

//macros for DH KE protocol
#define q 251
#define num 7
// generate a mac version of the message => using 3DES
void MAC(char* message, char* key, char size);

// 1- determine the size of mac in the message
// 2- put the first n character from the mac 
//          at the end of the message
void combine_message(char* message, char* state, char* temp_mac_message, char state_size, char sizeOfMAC_in_message);

void separete_mac(char* message, char* data, char* mac, char message_size, char mac_size);

// used in the mac to generate the other 2 needed keys
void keyChange(char* key, char value, char keysize);

//   used in order to not destory the original message.
void copyArray(char* arrOriginal, char* arrCopy, char size);

bool macCompare(char* data, char* mac, char* mac_key, char data_size, char mac_size);

//functions for the Diffie-Hellman Key Exchange Protocol(DH KE)
char mod(char a, char b);

char DH(char Q_prime, char a_num); // return Ya to be shared

// sequence generator for the key
void sequence_key_generator(char* enc_key, char* mac_key, char mac_size, char shared_key);
