/*
 ============================================================================
 Name        : my.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

int main() {

	srand(time(NULL));

	char guessWords[][16] = {
		"green",
		"airplane",
		"purple",
		"superman",
		"woman",
		"orange"
	};

	// index for random word
	int randomIndex = rand() % 6;

	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;

	int lengthOfWord = strlen(guessWords[randomIndex]);

	//					     0 1 2 3 4 5
	//				         p u r p l e
	//  letterGuessed[8] = { 0,0,0,0,0,0,0,0 };
	int letterGuessed[8] = { 0,0,0,0,0,0,0,0 };

	int quit = 0;

	int loopIndex = 0;
	int reguessed = 0; // EDIT

	char guess[16];
	char letterEntered;

    // game loop
	printf("\n\n\t\t\t ** HANGMAN ** \n");
				printf("\n\t\t\t**************\t\t\t");
					printf("\n\t\t\t..............\n\n  ");

printf("In this game you have to try to guess the word.\n");
printf("You are given five lives, which means you can guess wrong five times\n\n");
printf("Guess the word:");

	while ( numCorrect < lengthOfWord ) {

		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {

			if(letterGuessed[loopIndex] == 1) {
				printf("%c",guessWords[randomIndex][loopIndex]);
			} else {
				printf("-");
			}

		}

		printf("\n");

		printf("Number Correct So Far:%d\n\n",numCorrect);
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);

		if( strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}

		letterEntered = guess[0];
		reguessed = 0;

		printf("You Entered:%c\n",letterEntered);

		oldCorrect = numCorrect;

		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {

			if(letterGuessed[loopIndex] == 1) {
				if(guessWords[randomIndex][loopIndex] == letterEntered) {
					reguessed = 1;
					break;
				}
				continue;
			}

			if( letterEntered == guessWords[randomIndex][loopIndex] ) {
				letterGuessed[loopIndex] = 1;
				numCorrect++;
			}

		}

		if( oldCorrect == numCorrect && reguessed == 0) {
			numLives--;
			printf("Sorry, wrong guess, please try again\n\n");
			if (numLives == 0) {
				break;
			}
		} else if( reguessed == 1) {
			printf("Already Guessed!!\n");
		} else {
			printf("Congratulation, Correct guess :)\n");
		}

	} // while loop

	if( quit == 1 ) {
		printf("\n");
		printf("The user quit early");
		printf("\n");
	} else if (numLives == 0) {
		printf("\nSorry you lose, the word was: %s\n",
		guessWords[randomIndex]);
	} else  {
		printf("The word is :%s \n",guessWords[randomIndex]);
		printf("\nCongratulation, YOU WIN!!! :)\n");

	}


	return 0;
}
