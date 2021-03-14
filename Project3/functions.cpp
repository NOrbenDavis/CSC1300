/************************************************************
 *	File Name:		functions.cpp                           *
 *	Author: Nicholas Davis                                  *
 *	Date Created: 10/23/20                                  *
 *	Date Modified:                                          *
 *	Purpose:  Game of Hangman Functions						*
 ************************************************************/

#include <string.h>
#include <iostream>
using namespace std;

/* FUNCTION: printLettersGuessed
    This function prints out letters the users has guessed so far (correct & incorrect)
*/
void printLettersGuessed(bool userGuesses[], char alphabet[])
{
    cout << " LETTERS YOU HAVE ALREADY GUESSED: ";
    for (int i = 0; i < 26; ++i)
    {
        if (userGuesses[i] == true)
        {
            cout << alphabet[i];
        }

    }
}



/* FUNCTION: printWord
    This function prints out letters of word correctly guessed. All underscores at the beginning
*/
void printWord(char word[], char underScores[])
{
    cout << "WORD: ";
    int wordLength = 0;
    wordLength = strlen(word);
    for (int i = 0; i < wordLength; ++i)
    {
        cout << underScores[i] << " ";
    }
}


/*	FUNCTION:  printStage
	This function prints out the diagram representing each
	stage of the game.  There are seven different diagrams.
*/
void printStage(int stage)
{
	switch(stage)
	{	
		case 0:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;
		
		case 1:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 2:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |        \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 3:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |     |\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 4:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 5:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |      \\      \n";
					cout << "     |              \n";
					cout << "     |              \n";
					cout << "  --------------    \n";
					break;	
		case 6:   	cout << "                    \n";
					cout << "     +-----+        \n";
					cout << "     |     |        \n";
					cout << "     |     O        \n";
					cout << "     |    /|\\      \n";
					cout << "     |     |        \n";
					cout << "     |    / \\      \n";
					cout << "     |              \n";
					cout << "     |   DEAD!      \n";
					cout << "  --------------    \n";
					break;	
	}
	cout << "\n\n";
}