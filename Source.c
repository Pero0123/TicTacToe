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
void RefreshGrid(char* gridPointer);
void NPCTurn(char* gridPointer, int* roundPointer);

int main() {
	//declaring variables
	char gridArray[3][3] = {'1','2','3','4','5','6','7','8','9'}, i;
	char* gridPointer = &gridArray[0];
	int gridPosition, choice;
	int Round = 0;//variable to keep track of number of turns taken
	int* roundPointer = &Round, choicePointer = & choice;
	
	
	srand(time(NULL));//seeds random number generator


	//main game loop for playing against the  computer
	if (GameMenu() == 1)
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
	
	int k = 1, gridPosition;
	while (*roundPointer%2==0)
	{
		printf("enter a position on the grid (1-9)");
		scanf("%i", &gridPosition);
		printf("\n");

		if (*(gridPointer + gridPosition-1) <= 57&& *(gridPointer + gridPosition-1)>=48)//checks if square is empty
		{
			*(gridPointer + gridPosition-1) = 88;//replaces sqaure with x
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
	int k = 1, gridPosition;

	while (*roundPointer %2 != 0)
	{
		gridPosition = rand() % 9;
		//printf("%i \n", gridPosition);//temporary

		if (*(gridPointer + gridPosition) <= 57 && *(gridPointer + gridPosition) >= 48)//checks if square is "empty"
		{
			*(gridPointer + gridPosition) = 79;//places O in grid
			*roundPointer += 1;//incriments the round counter

		}
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



int GameMenu()
{
	int choice;
	printf("Do You Want To Play against:\n1. The Computer\n2. Another Player\n: ");
	scanf("%i", &choice);

	return choice;
}