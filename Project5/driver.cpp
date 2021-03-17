/*
    Title: driver.cpp
    Author: Nicholas Davis
    Date: 11/24/20
    Purpose: Main fct for Geekstore. Hold inventory and locations for different items. Add or Print Items. Save to file upon exit
*/

#include "item.h"


using namespace std;

int menu();
void add(Item* itemPointer, int maxItems, int &numItemsUsed);
void printItems(Item* itemPointer, int numItemsUsed);
void saveInventory(Item* itemPointer,int numItemsUsed);

int main()
{
    cout << "Geek Factory" << endl << endl;
    int maxItems = 0;
    int choice = 0;
    int numItemsUsed = 0;
    cout << "What is the maximum number of items your factory can hold?" << endl;
    do
    {
        cin >> maxItems;
        if (maxItems < 1)
        {
            cout << endl << "Enter a number greater than 0" << endl;
        }
    } while (maxItems < 1);
    Item* itemPointer = new Item[maxItems];

    do
    {
        choice = menu();
        if (choice == 1)
        {
            add(itemPointer, maxItems, numItemsUsed);
        }
        else if (choice == 2)
        {
            printItems(itemPointer, numItemsUsed);
        }
        else if (choice == 3)
        {
            saveInventory(itemPointer, numItemsUsed);
        }
    } while (choice != 3);
    
    cout << endl << "Goodbye!" << endl;


    delete [] itemPointer;

    return 0;
}