//Pero
//Tic Tac Toe Project
//05/03/2023

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void PlayerOne(int* grid, int* position);
void PlayerTwo(int* grid, int* position);
void CheckWin(int* grid);

int main() {
	//declaring variables
	int gridArray[3][3] = { 0 }, i, gridPosition[2][2];
	int* gridPointer = &gridArray[0], PositionPointer = &gridPosition[0];




		
	return 0;

}
void PlayerOne(int* grid, int* position)
{
	printf("Player 1 enter grid location (x y): ");
	scanf("%i,%i",*position, *position+1);
	
	grid[*position][(position + 1)] = 1;

}
void PlayerTwo(int* grid, int* position)
{
	printf("Player 2 enter grid location (x y): ");
	scanf("%i,%i", *position, *position + 1);

	grid[*position][(position + 1)] = 2;

}
void CheckWin(int* grid)
{
	int winCheck = 0, i;

	if (*grid[0][0])
	{

	}
}