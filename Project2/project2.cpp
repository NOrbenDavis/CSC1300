/*
    Title: project2.cpp
    Date: 9/29/20
    Author: Nicholas Davis
    Purpose: Playing Mash with generating random numbers

*/
#include <iostream>
#include <ctime>
#include <string>


using namespace std;

int main()
{
    string name1, name2, disName;
    int num1, num2, num3;
    string location1, location2, disLocation; 
    string job1, job2, disJob;
    string company1, company2, disCompany;
    int salary1, salary2, salary3;
    string car1, car2, disCar;
    string chosenName, chosenLocation, chosenCompany, chosenJob, chosenCar, chosenMash;
    int chosenNum, chosenSalary;

    int randNum = 0;
    int menuInput = 0;
    bool replay = true;
    srand(time(0));
    do
    {
        cout << "Menu: \n 1. Start Program (M.A.S.H.) \n 2. End Program" << endl;
        cin >> menuInput;
        switch (menuInput)
        {   
        case 1:
// Three people        
            cout << "You started the program." << endl << endl;
            cout << "Enter in one person you like: ";
            cin.ignore();
            getline(cin, name1);
            cout << "Enter in another person you like: ";
            getline(cin, name2);
            cout << "Enter in a person you hate: ";
            getline(cin, disName);

// Three random nums between 1 and 100            
            cout << "Enter three numbers between 1 and 100, seperated by a space." << endl;
            cin >> num1;
            cin >> num2;
            cin >> num3;
            while (((num1 < 1) || (num1 > 100)) || ((num2 < 1) || (num2 > 100)) || ((num3 < 1) || (num3 > 100)))
            {
                cout << "Invalid Input" << endl;
                cout << "Enter three numbers between 1 and 100, seperated by a space." << endl;
                cin >> num1;
                cin >> num2;
                cin >> num3;
            }
// Three locations
            cout << endl << "Enter in one city, state you like: ";
            cin.ignore();
            getline(cin, location1);
            cout << "Enter in another city, state you like: ";
            getline(cin, location2);
            cout << "Enter in one city, state you hate: ";
            getline(cin, disLocation);
// Job titles          
            cout << endl << "Enter in a awesome job title: ";
            getline(cin, job1);
            cout << "Enter in another awesome job title: ";
            getline(cin, job2);
            cout << "Enter in the worst job title ever: ";
            getline(cin, disJob);
// Three companies            
            cout << endl << "Enter a company or restaurant you like: ";
            getline(cin, company1);
            cout << "Enter another company or restaurant you like: ";
            getline(cin, company2);
            cout << "Enter in a company or restaurant you hate: ";
            getline(cin, disCompany);
// Three salaries  
            cout << endl << "Enter in three numbers between 10,000 and 500,000, seperated by a space:" << endl;
            cin >> salary1;
            cin >> salary2;
            cin >> salary3;
            while ((salary1 < 10000) || (salary1 > 500000))
            {
                cout << "The first number you entered was invalid" << endl;
                cout << "Enter a number between 10,000 and 500,000. : ";
                cin >> salary1;
            }
            while ((salary2 < 10000) || (salary2 > 500000))
            {
                cout << "The second number you entered was invalid" << endl;
                cout << "Enter a number between 10,000 and 500,000. : ";
                cin >> salary2;
            }
            while ((salary3 < 10000) || (salary3 > 500000))
            {
                cout << "The third number you entered was invalid" << endl;
                cout << "Enter a number between 10,000 and 500,000. : ";
                cin >> salary3;
            }
// Three cars   
            cout << endl << "Enter in a car you like: ";
            cin.ignore();
            getline(cin, car1);
            cout << "Enter in another car you like: ";
            getline(cin, car2);
            cout << "Enter in a car that you hate: ";
            getline(cin, disCar);
// Random number generator


//chosenMash
            randNum = rand() % 4 + 1;
            if (randNum == 1)
            {
                chosenMash = "Mansion";
            }
            else if (randNum == 2)
            {
                chosenMash = "Apartment";
            }
            else if (randNum == 3)
            {
                chosenMash = "Shack";
            }
            else if (randNum == 4)
            {
                chosenMash = "House";
            }
            else
            {
                chosenMash = "Error";
            }
// Chosen Name
            randNum = rand() % 3 + 1;
            if (randNum == 1)
            {
                chosenName = name1;
            }
            else if (randNum == 2)
            {
                chosenName = name2;
            }
            else if (randNum == 3)
            {
                chosenName = disName;
            }
            else
            {
                chosenName = "Error";
            }            
// Chosen Number
            randNum = rand() % 3 + 1;
            if (randNum == 1)
            {
                chosenNum = num1;
            }
            else if (randNum == 2)
            {
                chosenNum = num2;
            }
            else if (randNum == 3)
            {
                chosenNum = num3;
            }
            else
            {
                chosenNum = -100;
            } 
// Chosen Location
            randNum = rand() % 3 + 1;
            if (randNum == 1)
            {
                chosenLocation = location1;
            }
            else if (randNum == 2)
            {
                chosenLocation = location2;
            }
            else if (randNum == 3)
            {
                chosenLocation = disLocation;
            }
            else
            {
                chosenLocation = "Error";
            } 
// Chosen Company
            randNum = rand() % 3 + 1;
            if (randNum == 1)
            {
                chosenCompany = company1;
            }
            else if (randNum == 2)
            {
                chosenCompany = company2;
            }
            else if (randNum == 3)
            {
                chosenCompany = disCompany;
            }
            else
            {
                chosenCompany = "Error";
            } 
// Chosen Job
            randNum = rand() % 3 + 1;
            if (randNum == 1)
            {
                chosenJob = job1;
            }
            else if (randNum == 2)
            {
                chosenJob = job2;
            }
            else if (randNum == 3)
            {
                chosenJob = disJob;
            }
            else
            {
                chosenJob = "Error";
            } 
// Chosen Salary
            randNum = rand() % 3 + 1;
            if (randNum == 1)
            {
                chosenSalary = salary1;
            }
            else if (randNum == 2)
            {
                chosenSalary = salary2;
            }
            else if (randNum == 3)
            {
                chosenSalary = salary3;
            }
            else
            {
                chosenSalary = -100;
            } 
// Chosen Car
            randNum = rand() % 3 + 1;
            if (randNum == 1)
            {
                chosenCar = car1;
            }
            else if (randNum == 2)
            {
                chosenCar = car2;
            }
            else if (randNum == 3)
            {
                chosenCar = disCar;
            }
            else
            {
                chosenCar = "Error";
            } 
// Output            
            cout << "******** MASH RESULTS ********" << endl;
            cout << "You will live in a(n) " << chosenMash << "." << endl;
            cout << "You will be happily married to " << chosenName << "." << endl;
            cout << "You and your spouse will have " << chosenNum << " children." << endl;
            cout << "You will live in " << chosenLocation << "." << endl;
            cout << "You will work at " << chosenCompany << " as a " << chosenJob << " making $" << chosenSalary << " a year." << endl;
            cout << "You will drive a " << chosenCar << "." << endl;
            
            
            
            break;
    
        case 2:
            cout << "You ended the program." << endl;
            replay = false;
            break;
        default:
            cout << "Invalid Input" << endl;
// This is to clear cin, was having infinite loop problem for no apparent reason when not clearing.
            cin.clear();
            cin.ignore(255, '\n');
            break;
        }

    }while (replay == true);

    return 0;
}