//Pero//Alex
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

int main() {
	//declaring variables
	char gridArray[3][3] = {'1','2','3','4','5','6','7','8','9'}, i;
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


//clear console and prints out the grid
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

		if (*(gridPointer + gridPosition-1) <= 57&& *(gridPointer + gridPosition-1)>=48)//checks if square is empty
		{
			*(gridPointer + gridPosition-1) = 88;//replaces sqaure with x
			*roundPointer += 1;//incriments the round counter
		}
		else
		{
			printf("Move not allowed!\n");
			printf("\n");
		}

	}
}
//checks turn for player 2
void Player2Turn(char* gridPointer, int* roundPointer)
{

	int gridPosition;
	while (*roundPointer % 2 != 0) //The attempts to take turn until succefull
	{
		printf("Player 2:");
		scanf("%i", &gridPosition);
		printf("\n");

		if (*(gridPointer + gridPosition-1) <= 57 && *(gridPointer + gridPosition-1) >= 48)//checks if square is "empty"
		{
			*(gridPointer + gridPosition-1) = 79;//places O in grid
			*roundPointer += 1;//incriments the round counter
		}
		else
		{
			printf("Move not allowed\n");
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

		if (*(gridPointer + gridPosition) <= 57 && *(gridPointer + gridPosition) >= 48)//checks if square is "empty"
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



int GameMenu()
{
	int menu1;
	printf("Pick who you would like to play against:\n1. The Computer\n2. Another Player\n: ");
	scanf("%i", &menu1);

	return menu1;
}
