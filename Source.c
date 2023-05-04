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
void Player1Turn(char * gridPointer, int* roundPointer,int* menuPointer);//handles player ones turn
void Player2Turn(char* gridPointer, int* roundPointer, int* menuPointer);//handles player twos turn
void RefreshGrid(char* gridPointer, int delay, int *scorePointer, int* menuPointer);//clears console and printd grid
void printCharacter(char* gridPointer, int line, int location, int* menuPointer);//fill grid with characters. used with refresh grid.
void ComputerTurn(char* gridPointer, int* roundPointer, int difficulty); //handles computers turn
int convertNumpad(int location); //converts numpad input to relevant grid number
int Checkwin(char* gridPointer, int* roundPointer, int* scorePointer);// Checks for win, retunrs int for winner 
void Winner(int gameState);//prints out who won
int CheckUserInput(int low, int high, int input);//funciton to test if user input is within allowed range low-high

int main() {

	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);//maximises window

	//declaring variables
	char gridArray[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};//stores the x/o in grid
	int gridPosition, menu[4]={1,1,1,1};//location where player/computer wants to place aan x/o
	int score[3] = { 0,0,0 };//[0] is draws [1] is x wins, [2] is O wins
	int Round = 0;//variable to keep track of number of turns taken
	int gameState = 0,i;// equal to zero until the game is over
	int* roundPointer = &Round;
	int* scorePointer = &score;
	int* menuPointer = &menu;//stores user options. [0] is opponent, [1] is the difficulty. [2] replay. game continues while = 1. [3] = numpad or numrow
	char* gridPointer = &gridArray[0];
	
	srand(time(NULL));//seeds random number generator

	GameMenu(menuPointer);//prints out title and menu
	while (*(menuPointer+2) == 1||*(menuPointer+2) ==3)
	{

		//resets game state except scores
		Round = 0;
		gameState = 0;
		for (i = 0; i < 9; i++)
		{
			*(gridPointer + i) = ' ';
		}
		
		//loads menu and resets score if user selects main menu
		if (*(menuPointer+2)==3)
		{
			GameMenu(menuPointer);//prints out title and menu
			for (i = 0; i < 3; i++)
			{
				*(scorePointer + i) = 0;//resets scores
			}
		}

		//main loop for player vs computer
		if (*menuPointer == 1)
		{
			//"animation" for loading the grid at start
			RefreshGrid(gridPointer, 10, scorePointer,menuPointer);
			system("cls");
			Sleep(10);
			RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
			Sleep(10);
			system("cls");
			Sleep(10);
			RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
			Sleep(10);
			system("cls");
			Sleep(10);
			RefreshGrid(gridPointer, 0, scorePointer, menuPointer);

			//loop continues until there is a winner/looser/draw
			while (gameState == 0)
			{
				if (Round % 2 == 0 && gameState == 0)//even rounds
				{
					Player1Turn(gridPointer, roundPointer, menuPointer);
					gameState = Checkwin(gridPointer, roundPointer, scorePointer);
					RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
				}
				if (Round % 2 != 0 && gameState == 0)//odd rounds
				{
					ComputerTurn(gridPointer, roundPointer, menu[1]);//computers turn. menu [1] stores the selected difficulty
					gameState = Checkwin(gridPointer, roundPointer, scorePointer);
					RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
				}
				Winner(gameState);
			}
		}
		//main loop for player vs player.
		if (menu[0] == 2)
		{
			//"animation" for loading the grid at start
			RefreshGrid(gridPointer, 10, scorePointer, menuPointer);
			system("cls");
			Sleep(10);
			RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
			Sleep(10);
			system("cls");
			Sleep(10);
			RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
			Sleep(10);
			system("cls");
			Sleep(10);
			RefreshGrid(gridPointer, 0, scorePointer, menuPointer);

			//loop continues until there is a winner/looser/draw
			while (gameState == 0)
			{
				if (Round % 2 == 0 && gameState == 0)//even rounds
				{

					Player1Turn(gridPointer, roundPointer, menuPointer);
					gameState = Checkwin(gridPointer, roundPointer, scorePointer);
					RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
				}
				if (Round % 2 != 0 && gameState == 0)//odd rounds
				{

					Player2Turn(gridPointer, roundPointer, menuPointer);
					gameState = Checkwin(gridPointer, roundPointer, scorePointer);
					RefreshGrid(gridPointer, 0, scorePointer, menuPointer);
				}
				Winner(gameState);
			}
		}

		do {
			printf("\n\n    1. Play Again\n    2. Quit \n    3. Back To Main Menu(will reset scores)\n");
			scanf("%i", &*(menuPointer+2));
		} while (CheckUserInput(1,3,*(menuPointer+2))==1);

			if (*(menuPointer+2) == 1)
			{
				do {
				printf("    Select Difficulty:\n    1. Really Easy\n    2. Easy\n    3. Normal\n");
				scanf("    %i", (menuPointer + 1));
			} while (CheckUserInput(1, 3, *(menuPointer + 1)) == 1);
			}
		
		
	}
	return 0;

	system("pause");
	system("taskkill /F /IM cmd.exe");
}

//clears console and prints out the grid
void RefreshGrid(char* gridPointer, int delay, int *scorePointer, int* menuPointer)
{
	int line = 1, location;

	system("cls");//clears console

	printf("\n\n\n    SCORE: X's = %i    O's = %i    Draws's = %i",*(scorePointer+1), *(scorePointer+2),*scorePointer);

	//prints out the game grid accroding to whats stored in grid array. uses printCharacter function to print x or os

	printf("\n\n    ***************************************** \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    **       "); printf("    **       "); printf("    **       "); printf("    **       \n");Sleep(delay);
	
	for (line = 1; line <= 3; line++)
	{
		printf("    **  ");
		for (location = 0; location <= 2; location++)
		{
			printCharacter(gridPointer, line, location, menuPointer);printf("  **  ");
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
			printCharacter(gridPointer, line, location, menuPointer);printf("  **  ");
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
			printCharacter(gridPointer, line, location, menuPointer);printf("  **  ");
		}
		printf("\n");
	}

	printf("    **         "); printf("  **         "); printf("  **         "); printf("  **  \n");Sleep(delay);
	printf("    ***************************************** \n");Sleep(delay);
	printf("    ***************************************** \n\n\n");Sleep(delay);

}

//prints out an x or o in the grid location. used by the refresh grid funtion
void printCharacter(char* gridPointer, int line, int location, int* menuPointer)
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
		
		if (line == 1)
		{
			printf("       ");//prints the expty space inside the grid for each line
		}
		else if (line == 2)
		{
			if (*(menuPointer + 3) == 2)
			{
				printf("   %i   ", location);//prints the expty space inside the grid for each line
			}
			else
			{
				printf("       ");//prints the expty space inside the grid for each line
			}
		}
		else
		{
			printf("       ");//prints the expty space inside the grid for each line

		}
		break;
		
		break;
	}
}

//promts player for a position and checks if its valid
void Player1Turn(char* gridPointer, int* roundPointer, int* menuPointer)
{
	
	int gridPosition;
	while (*roundPointer%2==0)//attempts turn until succefull
	{
		printf("    Player 1:");
		scanf("%i", &gridPosition);
		printf("\n");
		if (*(menuPointer + 3) == 1)
		{
			gridPosition = convertNumpad(gridPosition);//converts numpad input to location on the grid 
		}
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
void Player2Turn(char* gridPointer, int* roundPointer, int* menuPointer)
{

	int gridPosition;//stores user input

	while (*roundPointer % 2 != 0) //attempts to take turn until succefull
	{
		printf("   Player 2:");
		scanf("%i", &gridPosition);
		printf("\n");

		if (*(menuPointer + 3) == 1)
		{
			gridPosition = convertNumpad(gridPosition);//converts numpad input to location on the grid 
		}


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

	system("cls");

	int delay = 20;

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
	do{
	printf("    Do You Want To Play against:\n    1. The Computer\n    2. Another Player\n ");
	scanf("    %i", menuPointer);
	} while (CheckUserInput(1, 2, *menuPointer) == 1);

	if (*menuPointer == 1)
	{
		do{
		printf("    Select Difficulty:\n    1. Really Easy\n    2. Easy\n    3. Normal\n");
		scanf("    %i", menuPointer+1);
	} while (CheckUserInput(1, 3, *(menuPointer+1)) == 1);
	}
	do{
	printf("    Do you want to play with numberpad or number row?\n    1. Number pad\n    2. Number Row\n");
	scanf("    %i", menuPointer + 3);
	} while (CheckUserInput(1, 2, *(menuPointer + 3)) == 1);
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
//function to check for win/loss/draw. also incriments score array. returns 1 for draw, 2 for x win 3 for O win and 0 for continue
int Checkwin(char* gridPointer, int* roundPointer, int* scorePointer)
{
	int gridPosition, i,j;
	int sum = 0;
	int k = 264;
	int winMove[3] = { 0 };


	//checks for x win
	//rows
	if (*(gridPointer + 0) + *(gridPointer + 1) + *(gridPointer + 2) == k)
		{
		sum = 264;
	}
	else if (*(gridPointer + 3) + *(gridPointer + 4) + *(gridPointer + 5) == k)
	{
		sum = 264;
	}
	else if (*(gridPointer + 6) + *(gridPointer + 7) + *(gridPointer + 8) == k)
	{
		sum = 264;
	}

	//diagonals
	else if (*(gridPointer + 0) + *(gridPointer + 4) + *(gridPointer + 8) == k)
	{
		sum = 264;
	}
	else if (*(gridPointer + 2) + *(gridPointer + 4) + *(gridPointer + 6) == k)
	{
		sum = 264;
	}

	
	//columbs
	else if (*(gridPointer + 0) + *(gridPointer + 3) + *(gridPointer + 6) == k)
	{
		sum = 264;
	}
	else if (*(gridPointer + 1) + *(gridPointer + 4) + *(gridPointer + 7) == k)
	{
		sum = 264;
	}
	else if (*(gridPointer + 2) + *(gridPointer + 5) + *(gridPointer + 8) == k)
	{
		sum = 264;
	}

	//checks for 0 win
	k = 237;
	if (*(gridPointer + 0) + *(gridPointer + 1) + *(gridPointer + 2) == k)
	{
		sum = 237;
	}
	else if (*(gridPointer + 3) + *(gridPointer + 4) + *(gridPointer + 5) == k)
	{
		sum = 237;
	}
	else if (*(gridPointer + 6) + *(gridPointer + 7) + *(gridPointer + 8) == k)
	{
		sum = 237;
	}
	else if (*(gridPointer + 0) + *(gridPointer + 4) + *(gridPointer + 8) == k)
	{
		sum = 237;
	}
	else if (*(gridPointer + 2) + *(gridPointer + 4) + *(gridPointer + 6) == k)
	{
		sum = 237;
	}
	else if (*(gridPointer + 0) + *(gridPointer + 3) + *(gridPointer + 6) == k)
	{
		sum = 237;
	}
	else if (*(gridPointer + 1) + *(gridPointer + 4) + *(gridPointer + 7) == k)
	{
		sum = 237;
	}
	else if (*(gridPointer + 2) + *(gridPointer + 5) + *(gridPointer + 8) == k)
	{
		sum = 237;
	}


	//resturns value depending on win/loose/draw/continue
	switch (sum)
	{
	case 0:
		if (*roundPointer < 9) {
		//returns if game should continue
			return 0;
		}
		else {
		*scorePointer += 1;
		return 1;//returns if draw
		}
		break;
	case 264:
		*(scorePointer + 1) += 1;//returns if x wins
		return 2;
		break;
	case 237:
		*(scorePointer + 2) += 1;//return if O wins
		return 3;
		break;
	}
}

//prints out winner
void Winner(int gameState)
{
	switch (gameState)
	{
	case 1:
		printf("  *************   ***   **********\n");
		printf("  *************   ***   **********\n");
		printf("       ***        ***   ***\n");
		printf("       ***        ***   *********\n");
		printf("       ***        ***   *********\n");
		printf("       ***        ***   ***\n");
		printf("       ***        ***   **********\n");
		printf("       ***        ***   **********\n");
		break;
	case 2:
		printf("  ***      ***");printf("    ***          **         ***  ***   ****     ***   **********\n");
		printf("   ***    ***");printf("      ***        ****       ***   ***   *****    ***   **********\n");
		printf("    ***  ***");printf("        ***      ******     ***    ***   ******   ***    ***   ***\n");
		printf("     ******");printf("          ***    ***  ***   ***     ***   *** ***  ***      ***\n");
		printf("     ******");printf("           ***  ***    *** ***      ***   ***  *** ***        ***\n");
		printf("    ***  ***");printf("           ******      ******      ***   ***   ******   ***    ***\n");
		printf("   ***    ***");printf("           ****        ****       ***   ***    *****   **********\n");
		printf("  ***      ***");printf("           **          **        ***   ***     ****   **********\n");
		break;
	case 3:
		printf("     *******");printf("        ***          **         ***  ***   ****     ***   **********\n");
		printf("   ***********");printf("       ***        ****       ***   ***   *****    ***   **********\n");
		printf("  ****     ****");printf("       ***      ******     ***    ***   ******   ***    ***   ***\n");
		printf("  ***       ***");printf("        ***    ***  ***   ***     ***   *** ***  ***      ***\n");
		printf("  ***       ***");printf("         ***  ***    *** ***      ***   ***  *** ***        ***\n");
		printf("  ****     ****");printf("          ******      ******      ***   ***   ******   ***    ***\n");
		printf("   ***********");printf("            ****        ****       ***   ***    *****   **********\n");
		printf("     ******* ");printf("              **          **        ***   ***     ****   **********\n");
		break;
	default:
		break;
	}
}

//checks of user input is within the specified range low-high
int CheckUserInput(int low,int high, int input)//function to test if user input is a vallid option
{
	if(input >=low && input <=high)
	{
		return 0; // returns o if input is valid
	}
	else
	{
		printf("\n\n     Invalid option!\n\n"); //prints if numper entered is outside of allowed range
		fflush(stdin); //clears input buffer
		return 1; //returns 1 if input is invalid
	}
}