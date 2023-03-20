//Pero. Alex. Sam
//Tic Tac Toe Project
//05/03/2023  **  

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<Windows.h>

int GameMenu(int* menuPointer);// prints intro and lets user chose player vs computer or player vs player
void Player1Turn(char * gridPointer, int* roundPointer);//handles player ones turn
void Player2Turn(char* gridPointer, int* roundPointer);//handles player twos turn
void RefreshGrid(char* gridPointer, int delay);//clears console and printd grid
void printCharacter(char* gridPointer, int line, int location);//fill grid with characters. used with refresh grid.
void ComputerTurn(char* gridPointer, int* roundPointer, int difficulty); //handles computers turn
int convertNumpad(int location); //converts numpad input to relevant grid number
int Checkwin(char* gridPointer, int* roundPointer, int* scorePointer);// Checks for win, retunrs int for winner 
int main() {

	// maximize window
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	//declaring variables
	char gridArray[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char* gridPointer = &gridArray[0];
	int gridPosition, menu[2]={1,1};
	int Round = 0;//variable to keep track of number of turns taken
	int* roundPointer = &Round;
	int* menuPointer = &menu;//stores user options. [0] is opponent, [1] is the difficulty.
	int score[3] = { 0,0,0};//[0] is draws [1] is x wins, [2] is O wins
	int* scorePointer = &score;
	int win=0;
	srand(time(NULL));//seeds random number generator

	GameMenu(menuPointer);

	//main loop for player vs computer
	if (*menuPointer == 1)
	{
		RefreshGrid(gridPointer, 10);
		system("cls");
		Sleep(10);
		RefreshGrid(gridPointer, 0);
		Sleep(10);
		system("cls");
		Sleep(10);
		RefreshGrid(gridPointer, 0);
		Sleep(10);
		system("cls");
		Sleep(10);
		RefreshGrid(gridPointer, 0);

		while (win==0)
		{
			if (Round % 2 == 0 && win == 0)
			{
				Player1Turn(gridPointer,roundPointer);
				RefreshGrid(gridPointer,0);
				win = Checkwin(gridPointer, roundPointer, scorePointer);
			}
			if (Round % 2 != 0&&win==0)
			{
				ComputerTurn(gridPointer,roundPointer, menu[1]);
				RefreshGrid(gridPointer,0);
				win = Checkwin(gridPointer, roundPointer, scorePointer);

			}
		}
	}

	//main loop for player vs player
	if (menu[0] == 2)
	{
		RefreshGrid(gridPointer,10);
		system("cls");
		Sleep(10);
		RefreshGrid(gridPointer, 0);
		Sleep(10);
		system("cls");
		Sleep(10);
		RefreshGrid(gridPointer, 0);
		Sleep(10);
		system("cls");
		Sleep(10);
		RefreshGrid(gridPointer, 0);

		while (win == 0)
		{
			if (Round % 2 == 0 && win == 0)
			{
				Player1Turn(gridPointer, roundPointer);
				RefreshGrid(gridPointer,0);
				win = Checkwin(gridPointer, roundPointer, scorePointer);
			}
			if (Round % 2 != 0 && win == 0)
			{
				Player2Turn(gridPointer, roundPointer);
				RefreshGrid(gridPointer,0);
				win = Checkwin(gridPointer, roundPointer, scorePointer);
			}
		}
	}
	
	return 0;
}

//clears console and prints out the grid
void RefreshGrid(char* gridPointer, int delay)
{
	int line = 1, location;
	system("cls");//clears console

	//prints out the game grid accroding to whats stored in grid array. uses printCharacter function to print x or os

	printf("\n\n    ***************************************** \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    **       "); printf("    **       "); printf("    **       "); printf("    **       \n");Sleep(delay);
	
	for (line = 1; line <= 3; line++)
	{
		printf("    **  ");
		for (location = 0; location <= 2; location++)
		{
			printCharacter(gridPointer, line, location);printf("  **  ");
		}
		printf("\n");
	}

	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");Sleep(delay);
	
	for (line = 1; line <= 3; line++)
	{
		printf("    **  ");
		for (location = 3; location <= 5; location++)
		{
			printCharacter(gridPointer, line, location);printf("  **  ");
		}
		printf("\n");
	}
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");Sleep(delay);

	for (line = 1; line <= 3; line++)
	{
		printf("    **  ");
		for (location = 6; location <= 8; location++)
		{
			printCharacter(gridPointer, line, location);printf("  **  ");
		}
		printf("\n");
	}

	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    ***************************************** \n\n\n");Sleep(delay);

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
		else if (line == 2)
		{
			printf("   *   ");//middle bit of x and spaces
		}
		else
		{
			printf(" *   * ");//top/bottom half of x and spaces
		}
		break;
	case 'O':
		if (line == 1)
		{
			printf(" *   * ");//top/bottom half of o and spaces
		}
		else if (line == 2)
		{
			printf("*     *");//middle bit of o and spaces
		}
		else
		{
			printf(" *   * ");//top/bottom half of o and spaces

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
		//gridPosition = convertNumpad(gridPosition);//converts numpad input to location on the grid 

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
void ComputerTurn(char* gridPointer, int* roundPointer, int difficulty)
{
	int gridPosition,i,sum;
	sum = 0;
	int k = 190;
	int winMove[3] = {0};


	//checks if there is a winning move. 0 = easy, 1 = medium, 2 = hard mode.
	for (i = 0; i < difficulty && sum==0; i++)
	{
		if (*(gridPointer + 0) + *(gridPointer + 1) + *(gridPointer + 2) == k)
		{
			winMove[0] = 0;
			winMove[1] = 1;
			winMove[2] = 2;
			sum = 190;
		}
		else if (*(gridPointer + 3) + *(gridPointer + 4) + *(gridPointer + 5) == k)
		{
			winMove[0] = 3;
			winMove[1] = 4;
			winMove[2] = 5;
			sum = 190;
		}
		else if (*(gridPointer + 6) + *(gridPointer + 7) + *(gridPointer + 8) == k)
		{
			winMove[0] = 6;
			winMove[1] = 7;
			winMove[2] = 8;
			sum = 190;
		}
		else if (*(gridPointer + 0) + *(gridPointer + 4) + *(gridPointer + 8) == k)
		{
			winMove[0] = 0;
			winMove[1] = 4;
			winMove[2] = 8;
			sum = 190;
		}
		else if (*(gridPointer + 2) + *(gridPointer + 4) + *(gridPointer + 6) == k)
		{
			winMove[0] = 2;
			winMove[1] = 4;
			winMove[2] = 6;
			sum = 190;
		}
		else if (*(gridPointer + 0) + *(gridPointer + 3) + *(gridPointer + 6) == k)
		{
			winMove[0] = 0;
			winMove[1] = 3;
			winMove[2] = 6;
			sum = 190;
		}
		else if (*(gridPointer + 1) + *(gridPointer + 4) + *(gridPointer + 7) == k)
		{
			winMove[0] = 1;
			winMove[1] = 4;
			winMove[2] = 7;
			sum = 190;
		}
		else if (*(gridPointer + 2) + *(gridPointer + 5) + *(gridPointer + 8) == k)
		{
			winMove[0] = 2;
			winMove[1] = 5;
			winMove[2] = 8;
			sum = 190;
		}
		k = 208;
	}

	//if winning is possible, computer will pick from that row until succesfull
	while (sum == 190) //attempts to take turn until succefull
	{
		gridPosition = winMove[rand() % 3];


		if (*(gridPointer + gridPosition) == 32)//checks if square is "empty". 32 asci = space
		{
			*(gridPointer + gridPosition) = 79;//places O in grid
			*roundPointer += 1;//incriments the round counter
			sum = 0;

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

	while (*roundPointer %2 != 0) //attempts to take turn until succefull
	{
		gridPosition = rand() % 9;


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
int GameMenu(int* menuPointer)
{


	int delay = 30;

	//Prints title screen
	//Tic
	printf("\n\n    ***********************************************************\n    *                                                         *\n"); Sleep(delay);
	printf("    *   ****************    **************    *************   *\n"); Sleep(delay);
	printf("    *   ****************    **************    *************   *\n"); Sleep(delay);
	printf("    *   ****************    **************    *************   *\n"); Sleep(delay);
	printf("    *        *****              ******        *****           *\n"); Sleep(delay);
	printf("    *        *****              ******        *****           *\n"); Sleep(delay);
	printf("    *        *****              ******        *****           *\n"); Sleep(delay);
	printf("    *        *****              ******        *****           *\n"); Sleep(delay);
	printf("    *        *****              ******        *****           *\n"); Sleep(delay);
	printf("    *        *****          **************    *************   *\n"); Sleep(delay);
	printf("    *        *****          **************    *************   *\n"); Sleep(delay);
	printf("    *        *****          **************    *************   *\n    *                                                         *\n    *                                                         *\n"); Sleep(delay);

	//Tac
	printf("    *   ****************        *             *************   *\n"); Sleep(delay);
	printf("    *   ****************       ***            *************   *\n"); Sleep(delay);
	printf("    *   ****************      *****           *************   *\n"); Sleep(delay);
	printf("    *        *****           *******          *****           *\n"); Sleep(delay);
	printf("    *        *****          **** ****         *****           *\n"); Sleep(delay);
	printf("    *        *****         ****   ****        *****           *\n"); Sleep(delay);
	printf("    *        *****        *************       *****           *\n"); Sleep(delay);
	printf("    *        *****       ***************      *****           *\n"); Sleep(delay);
	printf("    *        *****      *****************     *************   *\n"); Sleep(delay);
	printf("    *        *****     *****         *****    *************   *\n"); Sleep(delay);
	printf("    *        *****    *****           *****   *************   *                                                         \n    *                                                         *\n    *                                                         *\n"); Sleep(delay);

	//Toe
	printf("    *   ****************     *************     ************   *\n"); Sleep(delay);
	printf("    *   ****************     *************     ************   *\n"); Sleep(delay);
	printf("    *   ****************     *************     ************   *\n"); Sleep(delay);
	printf("    *        *****           *****   *****     *****          *\n"); Sleep(delay);
	printf("    *        *****           *****   *****     ************   *\n"); Sleep(delay);
	printf("    *        *****           *****   *****     ************   *\n"); Sleep(delay);
	printf("    *        *****           *****   *****     ************   *\n"); Sleep(delay);
	printf("    *        *****           *****   *****     *****          *\n"); Sleep(delay);
	printf("    *        *****           *************     ************   *\n"); Sleep(delay);
	printf("    *        *****           *************     ************   *\n"); Sleep(delay);
	printf("    *        *****           *************     ************   *"); Sleep(delay);

	printf("    \n    *                                                         *\n    ***********************************************************\n\n"); Sleep(delay);




	//select gamemode
	printf("    Do You Want To Play against:\n    1. The Computer\n    2. Another Player\n ");
	scanf("    %i", menuPointer);

	if (*menuPointer == 1)
	{
		printf("    Select Difficulty:\n    1. Easy\n    2. Normal\n    3. Hard\n ");
		scanf("    %i", menuPointer+1);
	}
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

int Checkwin(char* gridPointer, int* roundPointer, int* scorePointer)
{
	int gridPosition, i;
	int sum = 0;
	int k = 264;
	int winMove[3] = { 0 };


	//checks if there is a winning move. 0 = easy, 1 = medium, 2 = hard mode.
	
		if (*(gridPointer + 0) + *(gridPointer + 1) + *(gridPointer + 2) == k)
		{
			winMove[0] = 0;
			winMove[1] = 1;
			winMove[2] = 2;
			sum = 264;
		}
		else if (*(gridPointer + 3) + *(gridPointer + 4) + *(gridPointer + 5) == k)
		{
			winMove[0] = 3;
			winMove[1] = 4;
			winMove[2] = 5;
			sum = 264;
		}
		else if (*(gridPointer + 6) + *(gridPointer + 7) + *(gridPointer + 8) == k)
		{
			winMove[0] = 6;
			winMove[1] = 7;
			winMove[2] = 8;
			sum = 264;
		}
		else if (*(gridPointer + 0) + *(gridPointer + 4) + *(gridPointer + 8) == k)
		{
			winMove[0] = 0;
			winMove[1] = 4;
			winMove[2] = 8;
			sum = 264;
		}
		else if (*(gridPointer + 2) + *(gridPointer + 4) + *(gridPointer + 6) == k)
		{
			winMove[0] = 2;
			winMove[1] = 4;
			winMove[2] = 6;
			sum = 264;
		}
		else if (*(gridPointer + 0) + *(gridPointer + 3) + *(gridPointer + 6) == k)
		{
			winMove[0] = 0;
			winMove[1] = 3;
			winMove[2] = 6;
			sum = 264;
		}
		else if (*(gridPointer + 1) + *(gridPointer + 4) + *(gridPointer + 7) == k)
		{
			winMove[0] = 1;
			winMove[1] = 4;
			winMove[2] = 7;
			sum = 264;
		}
		else if (*(gridPointer + 2) + *(gridPointer + 5) + *(gridPointer + 8) == k)
		{
			winMove[0] = 2;
			winMove[1] = 5;
			winMove[2] = 8;
			sum = 264;
		}
		
		k = 237;
	if (*(gridPointer + 0) + *(gridPointer + 1) + *(gridPointer + 2) == k)
	{
		winMove[0] = 0;
		winMove[1] = 1;
		winMove[2] = 2;
		sum = 237;
	}
	else if (*(gridPointer + 3) + *(gridPointer + 4) + *(gridPointer + 5) == k)
	{
		winMove[0] = 3;
		winMove[1] = 4;
		winMove[2] = 5;
		sum = 237;
	}
	else if (*(gridPointer + 6) + *(gridPointer + 7) + *(gridPointer + 8) == k)
	{
		winMove[0] = 6;
		winMove[1] = 7;
		winMove[2] = 8;
		sum = 237;
	}
	else if (*(gridPointer + 0) + *(gridPointer + 4) + *(gridPointer + 8) == k)
	{
		winMove[0] = 0;
		winMove[1] = 4;
		winMove[2] = 8;
		sum = 237;
	}
	else if (*(gridPointer + 2) + *(gridPointer + 4) + *(gridPointer + 6) == k)
	{
		winMove[0] = 2;
		winMove[1] = 4;
		winMove[2] = 6;
		sum = 237;
	}
	else if (*(gridPointer + 0) + *(gridPointer + 3) + *(gridPointer + 6) == k)
	{
		winMove[0] = 0;
		winMove[1] = 3;
		winMove[2] = 6;
		sum = 237;
	}
	else if (*(gridPointer + 1) + *(gridPointer + 4) + *(gridPointer + 7) == k)
	{
		winMove[0] = 1;
		winMove[1] = 4;
		winMove[2] = 7;
		sum = 237;
	}
	else if (*(gridPointer + 2) + *(gridPointer + 5) + *(gridPointer + 8) == k)
	{
		winMove[0] = 2;
		winMove[1] = 5;
		winMove[2] = 8;
		sum = 237;
	}

	switch (sum)
	{
	case 0:
		if (*roundPointer < 9) {
			printf("Continue");
			return 0;
		}
		else {
			return 1;
			printf("Draw");
			return 1;
		}
		break;
	case 264:
		printf("X wins");
		*(scorePointer + 1) += 1;
		return 2;
		break;
	case 237:
		printf("O wins");
		*(scorePointer + 2) += 1;
		return 3;
		break;

	}
}