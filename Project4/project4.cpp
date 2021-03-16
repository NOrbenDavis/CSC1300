/*
    Title: project4.cpp
    Author: Nicholas Davis
    Date: 11/8/2020
    Purpose: Madlibs game

*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Funnctions

// Show Menu, return user choice in terms of file name
int showMenuGetChoice();

//Dynamically allocates a new string array of given size and returns pointer to it
string* createStringArray(int size);

//Supplies user with each question or prompt and then allows the user to enter in an answer
void getInfoFromUser(string* questionArray, string* answerArray, int size);

//Opens appropriate file, inputs in answer and prints story with anwer array used
void printStory(int choice,string array[], int size);



int main()
{   
    int size = 0;
    string question = " ";
    ifstream fileused;
    //Replay loop until hit return 0;
    do
    {
    
    
        int choice = showMenuGetChoice();
        switch (choice)
        {
            case 1:
            fileused.open("starWars.txt");
            break;

            case 2:
            fileused.open("dog.txt");
            break;

            case 3:
            fileused.open("pirate.txt");
            break;

            case 4:
            return 0;
            break;
        }
        if (fileused.is_open())
        {
            fileused >> size;

            //Create Arrays
            string* questionArray = createStringArray(size);
            string* answerArray = createStringArray(size);

            //from line in to getline so need ignore
            fileused.ignore();
            for (int i = 0; i < size; ++i)
            {
                getline(fileused, question);
                *(questionArray + i) = question;
            }
            fileused.close();

            getInfoFromUser(questionArray, answerArray, size);
            printStory(choice, answerArray, size);

            delete[] questionArray;
            delete[] answerArray;
        }
        else
        {
            cout << endl << "File Failed to Open" << endl;
            return 0;
        }
    } while (true);
}


//Function Descriptions are at the top

int showMenuGetChoice()
{
    int choice = 0;
    cout << endl << endl;
    cout << "Let's Play some MADLIBS!" << endl << endl;
    cout << "Choose a MAD LIBS game: " << endl << "1. The power of the Force (Star Wars Mad libs)" << endl;
    cout << "2. Dog Days (Dog ate my Mad Libs)" << endl << "3. Talk like a Pirate (Pirates Mad libs)" << endl;
    cout << "4. End Game" << endl << endl;
    do
    {
        cout << "Choose 1-4:  ";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    return choice;
}

string* createStringArray(int size)
{
    string* createdPointer;
    createdPointer = new string [size];
    return createdPointer;
}

void getInfoFromUser(string* questionArray, string* answerArray, int size)
{
    string userinput = " ";
    for (int i = 0; i < size; ++i)
    {
        cout << *(questionArray + i) << ": ";
        cin >> *(answerArray + i);
    }
    
}

void printStory(int choice,string* answerArray, int size)
{
    ifstream filestory;
    string storyline = " ";
    switch (choice)
    {
    case 1:
        filestory.open("starWarsText.txt");
        break;
    
    case 2:
        filestory.open("dogText.txt");
        break;

    case 3:
        filestory.open("pirateText.txt");
        break;

    default:
        break;
    }
    if (filestory.is_open())
    {
        for (int i = 0; i < size; ++i)
        {
            getline(filestory, storyline);
            cout << storyline << *(answerArray+i);
        }
    }
    else
    {
        cout << endl << "File failed to open" << endl;
    }
    filestory.close();
}