//Pero
//Tic Tac Toe Project
//05/03/2023  **  

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int GameMenu();// prints intro and lets user chose player vs computer or player vs player
void Player1Turn(char * gridPointer, int* roundPointer);//handles player ones turn
void Player2Turn(char* gridPointer, int* roundPointer);//handles player twos turn
void RefreshGrid(char* gridPointer);//clears console and printd grid
void printCharacter(char* gridPointer, int line, int location);//fill grid with characters. used with refresh grid.
void ComputerTurn(char* gridPointer, int* roundPointer); //handles computers turn
int convertNumpad(int location); //converts numpad input to relevant grid number

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
				Player1Turn(gridPointer,roundPointer);
				RefreshGrid(gridPointer);
			}
			if (Round % 2 != 0)
			{
				ComputerTurn(gridPointer,roundPointer);
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
				Player1Turn(gridPointer, roundPointer);
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
	int line = 1, location;
	system("cls");//clears console

	//prints out the game grid accroding to whats stored in grid array. uses printCharacter function to print x or os

	printf("\n\n    ***************************************** \n");
	printf("    ***************************************** \n");
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");
	printf("    **  "); location = 0; printCharacter(gridPointer, line, location); printf("  **  "); location = 1; printCharacter(gridPointer, line, location); printf("  **  "); location = 2; printCharacter(gridPointer, line, location); printf("  **  \n"); line = 2;
	printf("    **  "); location = 0; printCharacter(gridPointer, line, location); printf("  **  "); location = 1; printCharacter(gridPointer, line, location); printf("  **  "); location = 2; printCharacter(gridPointer, line, location); printf("  **  \n"); line = 1;
	printf("    **  "); location = 0; printCharacter(gridPointer, line, location); printf("  **  "); location = 1; printCharacter(gridPointer, line, location); printf("  **  "); location = 2; printCharacter(gridPointer, line, location); printf("  **  \n");
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");
	printf("    ***************************************** \n");
	printf("    ***************************************** \n");
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");
	printf("    **  "); location = 3; printCharacter(gridPointer, line, location); printf("  **  "); location = 4; printCharacter(gridPointer, line, location); printf("  **  "); location = 5; printCharacter(gridPointer, line, location); printf("  **  \n"); line = 2;
	printf("    **  "); location = 3; printCharacter(gridPointer, line, location); printf("  **  "); location = 4; printCharacter(gridPointer, line, location); printf("  **  "); location = 5; printCharacter(gridPointer, line, location); printf("  **  \n"); line = 1;
	printf("    **  "); location = 3; printCharacter(gridPointer, line, location); printf("  **  "); location = 4; printCharacter(gridPointer, line, location); printf("  **  "); location = 5; printCharacter(gridPointer, line, location); printf("  **  \n");
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");
	printf("    ***************************************** \n");
	printf("    ***************************************** \n");
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");
	printf("    **  "); location = 6; printCharacter(gridPointer, line, location); printf("  **  "); location = 7; printCharacter(gridPointer, line, location); printf("  **  "); location = 8; printCharacter(gridPointer, line, location); printf("  **  \n"); line = 2;
	printf("    **  "); location = 6; printCharacter(gridPointer, line, location); printf("  **  "); location = 7; printCharacter(gridPointer, line, location); printf("  **  "); location = 8; printCharacter(gridPointer, line, location); printf("  **  \n"); line = 1;
	printf("    **  "); location = 6; printCharacter(gridPointer, line, location); printf("  **  "); location = 7; printCharacter(gridPointer, line, location); printf("  **  "); location = 8; printCharacter(gridPointer, line, location); printf("  **  \n");
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");
	printf("    ***************************************** \n");
	printf("    ***************************************** \n");
}

//prints out an x or o in the grid location. used by the refresh grid funtion
void printCharacter(char* gridPointer, int line, int location)
{
	switch (*(gridPointer + location))
	{
	case 'X':
		if (line == 1)
		{
			printf(" *   * ");//top/bottom half of x and spaces
		}
		else
		{
			printf("   *   ");//middle bit of x and spaces
		}
		break;
	case 'O':
		if (line == 1)
		{
			printf(" *   * ");//top/bottom half of o and spaces
		}
		else
		{
			printf("*     *");//middle bit of o and spaces
		}
		break;
	default:
		printf("       ");//prints the expty space inside the grid for each line
		break;
	}
}

//promts player for a position and checks if its valid
void Player1Turn(char* gridPointer, int* roundPointer)
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

//computer opponent. randomly picks a grid location for now
void ComputerTurn(char* gridPointer, int* roundPointer)
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
	printf("\n\n    ***********************************************************\n    *                                                         *\n");
	printf("    *   ****************    **************    *************   *\n");
	printf("    *   ****************    **************    *************   *\n");
	printf("    *   ****************    **************    *************   *\n");
	printf("    *        *****              ******        *****           *\n");
	printf("    *        *****              ******        *****           *\n");
	printf("    *        *****              ******        *****           *\n");
	printf("    *        *****              ******        *****           *\n");
	printf("    *        *****              ******        *****           *\n");
	printf("    *        *****          **************    *************   *\n");
	printf("    *        *****          **************    *************   *\n");
	printf("    *        *****          **************    *************   *\n    *                                                         *\n    *                                                         *\n");

	//Tac
	printf("    *   ****************        *             *************   *\n");
	printf("    *   ****************       ***            *************   *\n");
	printf("    *   ****************      *****           *************   *\n");
	printf("    *        *****           *******          *****           *\n");
	printf("    *        *****          **** ****         *****           *\n");
	printf("    *        *****         ****   ****        *****           *\n");
	printf("    *        *****        *************       *****           *\n");
	printf("    *        *****       ***************      *****           *\n");
	printf("    *        *****      *****************     *************   *\n");
	printf("    *        *****     *****         *****    *************   *\n");
	printf("    *        *****    *****           *****   *************   *                                                         \n    *                                                         *\n    *                                                         *\n");

	//Toe
	printf("    *   ****************     *************     ************   *\n");
	printf("    *   ****************     *************     ************   *\n");
	printf("    *   ****************     *************     ************   *\n");
	printf("    *        *****           *****   *****     *****          *\n");
	printf("    *        *****           *****   *****     ************   *\n");
	printf("    *        *****           *****   *****     ************   *\n");
	printf("    *        *****           *****   *****     ************   *\n"); 
	printf("    *        *****           *****   *****     *****          *\n");
	printf("    *        *****           *************     ************   *\n");
	printf("    *        *****           *************     ************   *\n");
	printf("    *        *****           *************     ************   *");

	printf("    \n    *                                                         *\n    ***********************************************************\n\n");

	//select gamemode
	printf("    Do You Want To Play against:\n    1. The Computer\n    2. Another Player\n ");
	scanf("    %i", &menu);

	return menu;
}

//converts input from numpad to relevant grid position
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