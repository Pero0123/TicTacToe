//Pero
//Tic Tac Toe Project
//05/03/2023

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


void PlayerTurn(char * gridPointer);
void RefreshGrid(char* gridPointer);
void NPCTurn(char* gridPointer);

int main() {
	//declaring variables
	char gridArray[3][3] = {'#','#','#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' }, i, j, k=1, n = 0;
	char* gridPointer = &gridArray[0];
	int gridPosition;
	for (i = 0; i < 5; i++)
	{
		RefreshGrid(gridPointer);
		PlayerTurn(gridPointer);
		RefreshGrid(gridPointer);
		NPCTurn(gridPointer);

	
	}

	return 0;

}


//clear console and prints out the grid
void RefreshGrid(char* gridPointer)
{
	int j, k, n=0;
	system("cls");
	for (j = 0; j < 3; j++)
	{
		for (k = 0; k < 3; k++)
		{
			printf("%c ", *(gridPointer + n));
			n++;
		}
		printf("\n");
	}
}

//promts player for a position and checks if its valid
void PlayerTurn(char* gridPointer)
{
	
	int k = 1, gridPosition;
	while (k == 1)
	{
		printf("enter a position on the grid (0-8)");
		scanf("%i", &gridPosition);
		printf("\n");

		if (*(gridPointer + gridPosition) == 35)
		{
			*(gridPointer + gridPosition) = 88;
			RefreshGrid(gridPointer);
			k = 0;

		}
		else
		{
			printf("Invalid Move!\n");
			printf("\n");
		}
	}
}

//npc opponent. generates randomly pick a grid location for now
void NPCTurn(char* gridPointer)
{
	
	int k = 1, gridPosition;

	while (k == 1)
	{
		srand(time(NULL));
		gridPosition = rand() % 9;
		printf("%i \n", gridPosition);

		if (*(gridPointer + gridPosition) == 35)
		{
			*(gridPointer + gridPosition) = 79;
			RefreshGrid(gridPointer);
			k = 0;
		}
	}
}