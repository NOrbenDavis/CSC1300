/*
    Title: functions.cpp
    Author: Nicholas Davis
    Date: 11/24/20
    Purpose: Hold functions for geekstore
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include "item.h"


using namespace std;

//Stringtofloat turn strings into floats
float stringToFloat(string str)
{
    float number;
    char convertStr[1000];
    strcpy (convertStr,str.c_str());
    number = atof(convertStr);
    return number;
}




//Display menu and get user choice, whilist validating.
int menu()
{
    int choice = 0;

    do
    {
        cout << endl;
        cout << "1) Add awesome item(s)." << endl;
        cout << "2) Print all items." << endl;
        cout << "3) End the program" << endl;
        cin >> choice;
    } while ((choice > 3) || (choice < 1));
    
    return choice;
}

//Print items stored in itemPointer orderly
void printItems(Item* itemPointer, int numItemsUsed)
{
    if (numItemsUsed > 0)
    {
        cout << "ALL ITEMS:" << endl << endl;
        cout << "______________________________________________" << endl;
        for (int i = 0; i < numItemsUsed; ++i)
        {
            cout << "\t\t Item " << i+1 << endl;
            cout << "Name: " << itemPointer[i].name << endl;
            cout << endl << "Description: " << itemPointer[i].description << endl;
            cout << endl << "Goods Price: " << itemPointer[i].cost.rawMatPrice << endl;
            cout << endl << "Sales Price: " << itemPointer[i].cost.salePrice << endl;
            cout << endl << "Profit: " << itemPointer[i].cost.profit << endl;
            cout << endl << "Stores who sell this item:" << endl;
            for (int j = 0; j < itemPointer[i].numStores; ++j)
            {
                cout << "\t Store " << j+1 << " name: " << itemPointer[i].stores[j] << endl;
            }
            cout << endl << "Creation Date: " << itemPointer[i].creationDate << endl;
            cout << "______________________________________________" << endl;
        }
    }
    else 
    {
        cout << "\nThere are no items to print" << endl;
    }
}




//Add item from either file or manually
void add(Item* itemPointer, int maxItems, int &numItemsUsed)
{
    ifstream file;
    int loopChoice = 0;
    int newInput = 0;
    double doubleInput = 0.0;
    int numInput = 0;
    string inputFileName = " ";
    string temp = " ";
    string input = " ";

    //Temp Values for entering items
    string name, desc, storeNames, creationDate;
    float rawPrice, sellPrice, profit;
    int numStores;
    Money itemValue;
    float floatTemp = 0.0;
    if (numItemsUsed < maxItems)
    {
        do
        {
            do
            {
                cout << endl <<  "1) Add items from a file. " << endl;
                cout << "2) Add one item manually." << endl;
                cout << "3) Return to main menu." << endl;
                cin >> loopChoice;

                if (loopChoice > 3 || loopChoice < 1)
                {
                    cout << endl << "Invalid choice, please enter a number 1 - 3" << endl;
                }
                
            } while (loopChoice > 3 || loopChoice < 1);

            if(loopChoice == 1 && (numItemsUsed < maxItems))
            {
                cin.ignore();
                cout << endl << "What is the name of the file that has the items in it? (Format: 'inventory.txt')" << endl;
                cin >> inputFileName;
                file.open(inputFileName);
                if (file.is_open())
                {
                    do
                    {
                        getline(file, name, '#');
                        getline(file, desc, '#');
                        getline(file, temp, '#');
                        //Couldn't get convertofloat fct to work/ was not given it
                        floatTemp = stringToFloat(temp);
                        rawPrice = floatTemp;
                        getline(file, temp, '#');
                        floatTemp = stringToFloat(temp);
                        sellPrice = floatTemp;
                        getline(file, temp, '#');
                        floatTemp = stringToFloat(temp);
                        profit = floatTemp;
                        getline(file, temp, '#');
                        floatTemp = stringToFloat(temp);
                        numStores = floatTemp;
                        itemValue = Money(rawPrice,sellPrice,profit);
                        //For loop to grab store names before going onto creation date

                        string* stores = new string[numStores];
                        for (int i = 0; i < numStores; ++i)
                        {
                            getline(file, stores[i], '#');
                        }

                        getline(file,creationDate, '#');
                        itemPointer[numItemsUsed]=Item(name,desc,itemValue,numStores,stores,creationDate);
                        //To keep track to make sure doesn't exceed limit
                        ++numItemsUsed;
                        //For output later
                        ++newInput;
                    } while ((!(file.eof())) && (numItemsUsed < maxItems));
                    
                }
                else
                {
                    cout << endl << "File failed to open" << endl;
                }
                file.close();
                cout << newInput << " items inputted from " << inputFileName << endl;
            }

            else if (loopChoice == 2 && (numItemsUsed < maxItems))
            {
                cin.ignore();
                cout << endl << "Please enter the item details below:" << endl << endl;
                cout << "Name: ";
                getline(cin, input);
                name = input;
                cout << endl << endl << "Description: ";
                getline(cin, input);
                desc = input;
                cout << endl << endl << "Raw Material cost (Cost to make the item): $";
                cin >> doubleInput;
                rawPrice = doubleInput;
                cout << endl << endl << "Sale Price (Price when you sell item): $";
                cin >> doubleInput;
                sellPrice = doubleInput;
                //Calc profit
                profit = sellPrice - rawPrice;
                itemValue = Money(rawPrice,sellPrice,profit);
                cout << endl << "Enter the number of stores that supply this item" << endl;
                cin >> numInput;
                cin.ignore();
                numStores = numInput;
                string* stores = new string [numInput];
                for ( int i = 0; i < numStores; ++i)
                {
                    cout << "Store " << i+1 << " name: ";
                    getline(cin,stores[i]);
                }
                cout << endl << endl << "Creation Date (example: 04 02 16)" << endl;
                getline(cin,creationDate);
                itemPointer[numItemsUsed] = Item(name,desc,itemValue,numStores,stores,creationDate);

                ++numItemsUsed;
                
            }

            if (numItemsUsed == maxItems)
            {
                cout << endl << "OOPS! Your factory warehouse is full. Please exit from this menu with 3" << endl;        
            }
        } while (loopChoice != 3);
        
    }

    else 
    {
        cout << endl << "OOPS! Your factory warehouse is full." << endl;
    }

}
//te


//Save items stored in itemPointer to whatever inputted file name is given
void saveInventory(Item* itemPointer,int numItemsUsed)
{
    string fileName = " ";
    if (numItemsUsed > 0)
    {
        cout << "What do you want to name the file (Example 'test.txt')" << endl;
        cin >> fileName;
        ofstream fileCreated;
        fileCreated.open(fileName);
        for (int i = 0; i < numItemsUsed; ++i)
        {
            fileCreated << itemPointer[i].name << "#";
            fileCreated << itemPointer[i].description << "#";
            fileCreated << itemPointer[i].cost.rawMatPrice << "#";
            fileCreated << itemPointer[i].cost.salePrice << "#";
            fileCreated << itemPointer[i].cost.profit << "#";
            fileCreated << itemPointer[i].numStores << "#";
            for (int j = 0; j < itemPointer[i].numStores; ++j)
            {
                fileCreated << itemPointer[i].stores[j] << "#";
            }
            fileCreated << itemPointer[i].creationDate << "#";
        }
        fileCreated.close();
        cout << endl << endl << "All your items have been saved to " << fileName;

    }
    else
    {
        cout << "\nThere are no items to save to a file" << endl;
    }
    

}