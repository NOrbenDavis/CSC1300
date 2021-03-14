/*
    Title: hangman.cpp
    Author: Nicholas Davis
    Date: 10/26/20
    Purpose: Main Fct of hangman game.
*/


#include "hangman.h"

int main()
{
    //File Stream Declaration
    ifstream inFS;

    //Variable Declarations
    int stage = 0;
    char letter = ' ';
    int wordLength = 0;
    bool wordGuessed = false;
    int guessPos = 0;
    //bool letterGuessed = false;
    bool letterInWord = false;
    bool replay = true;
    bool newWord = false;
    string input = "";

    //Array Declarations
    char word[21];
    char underScores[21];
    char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool userGuesses[26];
    

    // Opening of the file
    inFS.open("wordBank.txt");
    if (inFS.is_open())
    {
        //Loop to continue playing/replaying
        do
        {
            stage = 0;
            //Array setups
    
            // userGuesses
            for (int i = 0; i < 26; ++i)
            {
                userGuesses[i] = false;
            }


            // underScores 
            for (int i = 0; i < 21; ++i)
            {
                underScores[i] = '_';
            }
            //Inputting Word from wordbank into Word Array
            inFS >> word;

            //Loop to check if exceeded stage 6 or guessed word
            do
            {
                printStage(stage);
                printWord(word,underScores);
                cout << endl;
                letterInWord = false;
                wordGuessed = false;
                newWord = false;
                printLettersGuessed(userGuesses,alphabet);
                cout << endl << " WHAT LETTER DO YOU GUESS?  ";
                cin >> letter;
                letter = toupper(letter);


                //Setting userGuesses to true in array based on guess letter pos.
                for (int i = 0; i < 26; ++i)
                {
                    if (alphabet[i] == letter)
                    {
                        guessPos = i;
                    }
                }    
                wordLength = strlen (word);
                    
                while(newWord == false)
                {
                    if (userGuesses[guessPos] == true)
                    {
                        cout << "You've already guessed that before, try again: ";
                        cin >> letter;
                        letter = toupper(letter);
                        for (int i = 0; i < 26; ++i)
                        {
                            if (alphabet[i] == letter)
                            {
                                guessPos = i;
                            }
                        }       
                    }
                    if(userGuesses[guessPos] == false)
                    {
                        newWord = true;
                    }
                }
                userGuesses[guessPos] = true;


                //Loop to check if guessed letter is in word
                for (int i = 0; i < wordLength; ++i)
                {
                    if (word[i] == letter)
                    {
                        underScores[i] = word[i];
                        letterInWord = true;
                    }
                }
                if (letterInWord == true)
                {
                    cout << "CORRECT!" << endl;
                }
                else
                {
                    cout << "WRONG!" << endl;
                    if (stage == 5)
                    {
                        ++stage;
                        printStage(stage);
                        cout << "You Lose!" << endl;
                    }
                    else 
                    {
                        ++stage;
                    }
                }
                cout << "Press Enter to continue" << endl;

                    
                



                //Checking if the user has guessed every letter in the word
                if (strncmp (word, underScores, wordLength) == 0)
                {
                    wordGuessed = true;
                    cout << "You have won the game" << endl;
                }
        

            } while ((stage < 6) && (wordGuessed == false));
            //Replay Question Loop
            do 
            {
                cout << "Would you like to replay the game? Y/N. Will repeat if invalid input." << endl;
                cin >> input;
            } while ((input != "Y") && (input != "N"));
            //After loop make sure valid input, perform action to end/continue game.
            if (input == "Y")
            {
                replay = true;
            }
            else if (input == "N")
            {
                replay = false;
            }

        } while (replay == true);
    }
    //If file can't open
    else 
    {
        cout << "Word could not be found in the word bank." << endl;
    }
    inFS.close();

    return 0;
}