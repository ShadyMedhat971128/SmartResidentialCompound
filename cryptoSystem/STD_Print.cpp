#include "STD_Print.h"


void printMessage(uint8* message, uint8 size, const char* DisplayMessage)
{
	printf("%s\n", DisplayMessage);
	//printf("%d , %d\n", size, sizeof(message));
	if (size >= 4)
	{
		for (uint8 i = 0; i < size; i += 4)
		{
			for (uint8 j = 0; j < 4; j++)
			{
				printf("%x\t", message[i + j]);
			}
			printf("\n");
		}
	}
	else
	{
		for (uint8 j = 0; j < size; j++)
		{
			printf("%x\t", message[ j]);
		}
		printf("\n");
	}
	printLine();
}

//-------------------------------------------------------------------------------------------------------//

void printLine()
{
	printf("----------------------------------------------------------------------------------------\n");
}

//-------------------------------------------------------------------------------------------------------//