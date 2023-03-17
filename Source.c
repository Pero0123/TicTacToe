//Pero
//Tic Tac Toe Project
//05/03/2023

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int GameMenu();
void PlayerTurn(char * gridPointer, int* roundPointer);
void Player2Turn(char* gridPointer, int* roundPointer);
void RefreshGrid(char* gridPointer);
void NPCTurn(char* gridPointer, int* roundPointer);
int convertNumpad(int location);

int main() {
	//declaring variables
	char gridArray[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char* gridPointer = &gridArray[0];
	int gridPosition, choice;
	int Round = 0;//variable to keep track of number of turns taken
	int* roundPointer = &Round, choicePointer = &choice;
	
	
	srand(time(NULL));//seeds random number generator

	choice=GameMenu();
	//main loop for player vs computer
	if (choice == 1)
	{
		RefreshGrid(gridPointer);
		while(Round<8)
		{
			if (Round % 2 == 0)
			{
				PlayerTurn(gridPointer,roundPointer);
				RefreshGrid(gridPointer);
			}
			if (Round % 2 != 0)
			{
				NPCTurn(gridPointer,roundPointer);
				RefreshGrid(gridPointer);
			}
		}
	}

	//main loop for player vs player
	if (choice == 2)
	{
		RefreshGrid(gridPointer);
		while (Round < 8)
		{
			if (Round % 2 == 0)
			{
				PlayerTurn(gridPointer, roundPointer);
				RefreshGrid(gridPointer);
			}
			if (Round % 2 != 0)
			{
				Player2Turn(gridPointer, roundPointer);
				RefreshGrid(gridPointer);
			}
		}

	}
	
	return 0;
}

//clears console and prints out the grid
void RefreshGrid(char* gridPointer)
{
	int i, j, n=0;
	system("cls");//clears console

	//prints out the grid array with brackets around each grid location

	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", *(gridPointer +0), *(gridPointer + 1), *(gridPointer + 2));
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", *(gridPointer + 3), *(gridPointer + 4), *(gridPointer + 5));			
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", *(gridPointer + 6), *(gridPointer + 7), *(gridPointer + 8));
	printf("     |     |     \n");
	printf("\n");
}

//promts player for a position and checks if its valid
void PlayerTurn(char* gridPointer, int* roundPointer)
{
	
	int gridPosition;
	while (*roundPointer%2==0)//attempts turn until succefull
	{
		printf("Player 1:");
		scanf("%i", &gridPosition);
		printf("\n");
		gridPosition = convertNumpad(gridPosition);//converts numpad input to location on the grid 

		if (*(gridPointer + gridPosition) == 32)//checks if square is empty, 32 asci = space
		{
			*(gridPointer + gridPosition) = 88;//replaces sqaure with x
			*roundPointer += 1;//incriments the round counter
		}
		else
		{
			printf("Move not allowed!\n");
			printf("\n");
		}

	}
}

//handles turn for player 2
void Player2Turn(char* gridPointer, int* roundPointer)
{

	int gridPosition;
	while (*roundPointer % 2 != 0) //attempts to take turn until succefull
	{
		printf("Player 2:");
		scanf("%i", &gridPosition);
		printf("\n");
		gridPosition = convertNumpad(gridPosition);//converts numpad input to location on the grid 

		if (*(gridPointer + gridPosition) == 32)//checks if square is "empty". 32 asci = space
		{
			*(gridPointer + gridPosition) = 79;//places O in grid
			*roundPointer += 1;//incriments the round counter
		}
		else
		{
			printf("Invalid Move!\n");
			printf("\n");
		}

	}
}

//npc opponent. randomly picks a grid location for now
void NPCTurn(char* gridPointer, int* roundPointer)
{
	int gridPosition;

	while (*roundPointer %2 != 0) //attempts to take turn until succefull
	{
		gridPosition = rand() % 9;
		//printf("%i \n", gridPosition);//temporary

		if (*(gridPointer + gridPosition) == 32)//checks if square is "empty". 32 asci = space
		{
			*(gridPointer + gridPosition) = 79;//places O in grid
			*roundPointer += 1;//incriments the round counter

			//creates small delay during npc turn
			printf(".");
			Sleep(200);
			printf(".");
			Sleep(200);
			printf(".");
			Sleep(200);
			printf(".");
			Sleep(200);
			printf(".");
			Sleep(200);
		}
		
	}
}

//game menu, displays before game starts
int GameMenu()
{
	
	
	int menu;

	//Prints title screen
	//Tic
	printf("****************       ******       *************\n");
	printf("*              *       *    *       *           *\n");
	printf("******   *******       *    *       *   *********\n");
	printf("     *   *             *    *       *   *\n");
	printf("     *   *             *    *       *   *\n");
	printf("     *   *             *    *       *   *\n");
	printf("     *   *             *    *       *   *\n");
	printf("     *   *             *    *       *   *\n");
	printf("     *   *             *    *       *   *********\n");
	printf("     *   *             *    *       *           *\n");
	printf("     *****             ******       *************\n\n\n\n");

	//Tac
	printf("****************        *             *************\n");
	printf("*              *       * *            *           *\n");
	printf("******   *******      *   *           *   *********\n");
	printf("     *   *           *     *          *   *\n");
	printf("     *   *          *   *   *         *   *\n");
	printf("     *   *         *   * *   *        *   *\n");
	printf("     *   *        *   *****   *       *   *\n");
	printf("     *   *       *             *      *   *\n");
	printf("     *   *      *   *********   *     *   *********\n");
	printf("     *   *     *   *         *   *    *           *\n");
	printf("     *****    *****           *****   *************\n\n\n\n");

	//Toe
	printf("****************     *************     ************\n");
	printf("*              *     *           *     *          *\n");
	printf("******   *******     *   *****   *     *   ********\n");
	printf("     *   *           *   *   *   *     *   *\n");
	printf("     *   *           *   *   *   *     *   ********\n");
	printf("     *   *           *   *   *   *     *          *\n");
	printf("     *   *           *   *   *   *     *   ********\n"); 
	printf("     *   *           *   *   *   *     *   *\n");
	printf("     *   *           *   *****   *     *   ********\n");
	printf("     *   *           *           *     *          *\n");
	printf("     *****           *************     ************\n\n\n\n");


	printf("Do You Want To Play against:\n1. The Computer\n2. Another Player\n ");
	scanf("%i", &menu);

	return menu;
}

int convertNumpad(int location)
{
	switch (location)
	{
	case 1:
		location = 6;
		break;
	case 2:
		location = 7;
		break;
	case 3:
		location = 8;
		break;
	case 4:
		location = 3;
		break;
	case 5:
		location = 4;
		break;
	case 6:
		location = 5;
		break;
	case 7:
		location = 0;
		break;
	case 8:
		location = 1;
		break;
	case 9:
		location = 2;
		break;

	default:
		break;
	}
	return location;
}