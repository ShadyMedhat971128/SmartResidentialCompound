#pragma once
#include "AES.h"
#include "DES.h"
#include "STD_TYPES.h"
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
void MAC(uint8* message, uint8* key, uint8 size);

// 1- determine the size of mac in the message
// 2- put the first n character from the mac 
//		at the end of the message
void combine_message(uint8* message, uint8* state, uint8* temp_mac_message, uint8 state_size, uint8 sizeOfMAC_in_message);

void separete_mac(uint8* message, uint8* data, uint8* mac, uint8 message_size, uint8 mac_size);

// used in the mac to generate the other 2 needed keys
void keyChange(uint8* key, uint8 value, uint8 keysize);

//	used in order to not destory the original message.
void copyArray(uint8* arrOriginal, uint8* arrCopy, uint8 size);

bool macCompare(uint8* data, uint8* mac, uint8* mac_key, uint8 data_size, uint8 mac_size);

//functions for the Diffie-Hellman Key Exchange Protocol(DH KE)
uint8 mod(uint8 a, uint8 b);

uint8 DH(uint8 Q_prime, uint8 a_num); // return Ya to be shared

// sequence generator for the key
void sequence_key_generator(uint8* enc_key, uint8* mac_key, uint8 mac_size, uint8 shared_key);