/********************************************************************************
 * TODO: do the thing where bits of the board gets revealed if there isn't a mine
 * 	 do the thing where it shows how many mines are next to the square
 *
 * *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "minesweeper.h"

char board[5][5] = {{'#','#','#','#','#'},
		    {'#','#','#','#','#'},
		    {'#','#','#','#','#'},
		    {'#','#','#','#','#'},
		    {'#','#','#','#','#'}};
int horizontal;
int vertical;
bool winCheck = true;
int mines[5][5] = {{0,0,0,0,0},
		   {0,0,0,0,0},
		   {0,0,0,0,0},
		   {0,0,0,0,0}};

int main(int argc, char* argv[]) {

	//initialise mines
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		mines[(rand() % 4 + 0)][(rand() % 4 + 0)] = 1;
	}
	
	printf("DEBUG MINE MAP\n");
	printf("[ ][0][1][2][3][4]\n");
	for (int i = 0; i < 5; i++) {
		printf("[%i]", i);
		for (int j = 0; j < 5; j++) {
			printf("[%i]", mines[i][j]);
		}
		printf("\n");
	}


				
	do {
		//get user input
		do {
			horizontal = userInput();
			vertical = userInput();
		} while (board[horizontal][vertical] == ' ');

		if (mines[horizontal][vertical] == 1) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (mines[i][j] == 1) {
						board[i][j] = 'X';
					}
				}
			}
			printf("you lose!\n");
			winCheck = false;
		} else if (board[horizontal][vertical] == '#') {
			board[horizontal][vertical] = ' ';
		}


		printf("[ ][0][1][2][3][4]\n");
		for (int i = 0; i < 5; i++) {
			printf("[%i]", i);
			for (int j = 0; j < 5; j++) {
				printf("[%c]", board[i][j]);
			}
			printf("\n");
		}
	} while (winCheck == true);
	return EXIT_SUCCESS;
}

int userInput(void) {
	int input = -1;
	do {
		printf("please enter coord: ");
		scanf("%i", &input);
	} while ((input < 0) || (input > 4));
	return input;
}
