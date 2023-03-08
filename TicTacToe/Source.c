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
	char gridArray[3][3] = {'-','-','-','-','-','-','-','-','-'}, i;
	char* gridPointer = &gridArray[0];
	int gridPosition;
	
	srand(time(NULL));//seeds random number generator


	//main game loop -currently just runs 5 times
	for (i = 0; i < 5; i++)
	{
		RefreshGrid(gridPointer);//print array
		PlayerTurn(gridPointer);//player turn
		RefreshGrid(gridPointer);//print array
		NPCTurn(gridPointer);//computer turn
	}

	return 0;

}


//clear console and prints out the grid
void RefreshGrid(char* gridPointer)
{
	int i, j, n=0;
	system("cls");//clears console

	//prints out the grid array with brackets around each grid location

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("[");
			printf("%c", *(gridPointer + n));
			printf("]");
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

		if (*(gridPointer + gridPosition) == 45)//checks if square is empty
		{
			*(gridPointer + gridPosition) = 88;//replaces sqaure with x
			k = 0; //k = 0 when player succefully places x. exits loop

		}
		else
		{
			printf("Invalid Move!\n");
			printf("\n");
		}
	}
}

//npc opponent. randomly picks a grid location for now
void NPCTurn(char* gridPointer)
{
	
	int k = 1, gridPosition;

	while (k == 1)
	{
		gridPosition = rand() % 9;
		printf("%i \n", gridPosition);

		if (*(gridPointer + gridPosition) == 45)//checks if square is "empty"
		{
			*(gridPointer + gridPosition) = 79;//places 0 in grid
			k = 0;//exits loop when computer placed 0
		}
	}
}