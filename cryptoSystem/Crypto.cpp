#include "Crypto.h"
void MAC(uint8* message,uint8* key, uint8 size)
{
	des_ctx dc;
	//des_ctx dc2;
	uint8* key2=key;
	keyChange(key2, 1 ,size);
	uint8* key3 = key2;
	keyChange(key3, 1,size);


	TripleDES_ENC(&dc, message , 1, key, key2, key3); // 3DES Encrypt
}

//-------------------------------------------------------------------------------------------------------//

void combine_message(uint8* message,uint8* state,uint8 *  temp_mac_message, uint8 state_size, uint8 sizeOfMAC_in_message)
{
	
	for (uint8 i = 0; i < state_size; i++)
	{
		message[i] = state[i];
		
	}
	//uint8 mac_counter = (sizeof(temp_mac_message) ) - sizeOfMAC_in_message; // example : if state.size => 16 then mac counter starts from {12,13,14,15} 
	uint8 mac_counter = 0;																					//message now starts from {16,17,18,19}
	for (uint8 i = 0; i < sizeOfMAC_in_message; i++)
	{
		message[state_size] = temp_mac_message[mac_counter];
		mac_counter++;
		state_size++;
	}

}

//-------------------------------------------------------------------------------------------------------//

void separete_mac(uint8* message, uint8* data, uint8* mac, uint8 message_size, uint8 mac_size)
{
	uint8 data_size = message_size - mac_size;
	for (uint8 i = 0; i < data_size; i++)
	{
		
			data[i] = message[i];
		
			
	}
	for (uint8 i = 0; i < mac_size; i++)
	{
		mac[i] = message[data_size+i];
		data[data_size + i] = 0;
	}
}

//-------------------------------------------------------------------------------------------------------//

void keyChange(uint8* key, uint8 value,uint8 keysize)
{
	for (uint8 i = 0; i < keysize ; i++)
	{
		key[i] += value;
	}
}

//-------------------------------------------------------------------------------------------------------//

void copyArray(uint8* arrOriginal, uint8* arrCopy, uint8 size)
{
	for (uint8 i = 0; i < size; i++)
	{
		arrCopy[i]=arrOriginal[i];
	}
}

bool macCompare(uint8* data, uint8* mac, uint8* mac_key, uint8 data_size, uint8 mac_size)
{
	MAC(data, mac_key, data_size);
	uint8 check_counter = 0;
	for (uint8 i = 0; i < mac_size; i++)
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

uint8 mod(uint8 a , uint8 b)
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

uint8 DH(uint8 Q_prime, uint8 a_num)
{
	// generate Xa < Q_prime
	uint8 Xa = mod(rand(),Q_prime);
	//compute Ya = pow(a_num, Xa)
	uint8 Ya = mod((uint8)pow(a_num, Xa),Q_prime);
	//return Ya
	return Ya;
}

void sequence_key_generator(uint8* enc_key,uint8* mac_key, uint8 mac_size,uint8 shared_key)
{
	uint8 temp_key;
	for (uint8 i = 1; i <= key_size; i++)
	{
		temp_key = mod((i * shared_key + (uint8)pow(i,2)), q);
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