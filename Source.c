//Pero
//Tic Tac Toe Project
//05/03/2023

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>



void RefreshGrid(int* gridPointer);

int main() {
	//declaring variables
	int gridArray[3][3] = { 0 }, i, j,k=1, gridPosition;
	int* gridPointer = &gridArray[0];


	
	while (k==1)
	{
		printf("enter a position on the grid (0-9)");
		scanf("%i", &gridPosition);
		printf("\n");
		
		if (*(gridPointer+gridPosition) == 0)
		{
			*(gridPointer + gridPosition) = 1;
			RefreshGrid(gridPointer);
			k = 1;

		}
		else
		{
			printf("Invalid Move!\n");
			printf("\n");
		}
	}
		
	return 0;

}


//clear console and prints out the grid
void RefreshGrid(int* gridPointer)
{
	int j, k, n=0;
	system("cls");
	for (j = 0; j < 3; j++)
	{
		for (k = 0; k < 3; k++)
		{
			printf("%i ", *(gridPointer + n));
			n++;
		}
		printf("\n");
	}
}

