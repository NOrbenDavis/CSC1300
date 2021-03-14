/*
    Title: Project2.cpp
    Author: Nicholas Davis
    Date: Sept 14 , 2020
    Purpose: This program will determine your personality based on four criteria

*/


#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;


int main(){
    int introvert = 0, extrovert = 0;
    int positive = 0, negative = 0;
    int silly = 0, serious = 0;
    int spontaneous = 0, planner = 0;
    int questionNum = 0;
    bool replay = true;
    char input = 0;
//Intro Sequence

    cout << setfill('-') << setw(36) << "" << endl << "         PERSONALITY TEST" << endl; 
    cout << setfill('-') << setw(36) << "" << setfill(' ') << endl; 
    cout << "Answer the following twelve questions to " << endl << "find out about your personality." << endl << endl;

// Start of Questions
    while (replay == true)
    {
    // Reset of Variables for Loop    
    introvert = 0, extrovert = 0;
    positive = 0, negative = 0;
    silly = 0, serious = 0;
    spontaneous = 0, planner = 0;
    questionNum = 0;      
        while (questionNum == 0)
        {
            cout << endl << "     When you are around a lot of people you feel:" << endl;
            cout << " A. Happy\n B. Comfortable\n C. Uncomfortable\n D. Repulsed/Tired" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                extrovert += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                extrovert += 2;
                ++questionNum;
            }
            else if (input == 'C')
            {
                introvert += 1;
                ++questionNum;
            }
            else if (input == 'D')
            {
                introvert += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }
        while (questionNum == 1)
        {
            cout << endl << "     When somebody cancels plans with you do you feel:" << endl;
            cout << " A. Disappointed\n B. Neutral\n C. Relieved" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                extrovert += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                introvert += 1;
                extrovert += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                introvert += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
            
        }   
        while (questionNum == 2)
        {
            cout << endl << "     When having to do a speech infront of a class do you feel:" << endl;
            cout << " A. Excited\n B. Indifferent\n C. Anxious" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                extrovert += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                extrovert += 1;
                introvert += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                introvert += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }             


// Positive Vs. Negative Questions


        while (questionNum == 3)
        {
            cout << endl << "     Do you see the glass as:" << endl;
            cout << " A. Half Full\n B. Who cares, just get some more\n C. Half Empty" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                positive += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                positive += 1;
                negative += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                negative += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }
        while (questionNum == 4)
        {
            cout << endl << "     Are you enjoying taking this personality test:" << endl;
            cout << " A. Yes\n B. Sortof\n C. No" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                positive += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                positive += 1;
                negative += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                negative += 1;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }
        while (questionNum == 5)
        {
            cout << endl << "     I generally believe that everyone has good in them:" << endl;
            cout << " A. True\n B. Neither True nor False\n C. False\n" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                positive += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                positive +=1;
                negative += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                negative += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }


// Silly Vs. Serious Questions


        while (questionNum == 6)
        {
            cout << endl << "     I do not generally take myself seriously:" << endl;
            cout << " A. True\n B. Neither True nor False\n C. False\n" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                silly += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                silly += 1;
                serious += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                serious += 1;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }
        while (questionNum == 7)
        {
            cout << endl << "     How do you fel about the existence of Aliens:" << endl;
            cout << " A. I'm pretty sure some of my classmates are Aliens\n B. I believe in Aliens theoretically\n C. I'll believe them when I see them" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                silly += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                silly += 1;
                serious += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                serious += 1;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }
        while (questionNum == 8)
        {
            cout << endl << "     Upon seeing your friend's birthday marked on a calendar do you:" << endl;
            cout << " A. Plan a prank centered around his birthday\n B. Plan his surprise birthday party\n C. Buy him a card and gift ahead of time" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                silly += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                serious += 1;
                silly += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                serious += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }


// Spontaneous vs. Planner Questions


        while (questionNum == 9)
        {
            cout << endl << "     In your friend group, you are usually the one that gets everyone together to do things:" << endl;
            cout << " A. True\n B. Neither True nor False\n C. False" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                planner += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                planner += 1;
                spontaneous += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                spontaneous += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }
        while (questionNum == 10)
        {
            cout << endl << "     When thrust into an unknown situation you:" << endl;
            cout << " A. Panic\n B. Roll with it\n C. Make the best of the situation" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                planner += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                planner += 1;
                spontaneous += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                spontaneous += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }
        while (questionNum == 11)
        {
            cout << endl << "     I'm slow to embrace new ideas:" << endl;
            cout << " A. True\n B. Neither True nor False\n C. False" << endl;
            cin >> input;
            input = toupper(input);
            cout << endl;
            if (input == 'A')
            {
                planner += 2;
                ++questionNum;
            }   
            else if (input == 'B') 
            {
                planner += 1;
                spontaneous += 1;
                ++questionNum;
            }
            else if (input == 'C')
            {
                spontaneous += 2;
                ++questionNum;
            }
            else
            {
                cout << "Error, Invalid Input. Try Again." << endl;
            }
        }


//End Of Questions

//Results Checker

    cout << endl << endl << endl << "     Results" << endl;
    cout << setfill('-') << setw(36) << "" << setfill(' ') << endl << endl; 

// Ext v Intr
    if (extrovert > introvert)
    {
        cout << "You are an extrovert." << endl;
    }
    else if (extrovert == introvert)
    {
        cout << "You are not an introvert or extrovert" << endl;
    }
    else 
    {
        cout << "You are an introvert." << endl;
    }
// Pos v Neg
    if (positive > negative)
    {
        cout << "You are a positive person." << endl;
    }
    else if (positive == negative)
    {
        cout << "You are not an positive or negative person." << endl;
    }
    else 
    {
        cout << "You are a negative person." << endl;
    }
// Silly v. Serious
    if (silly > serious)
    {
        cout << "You are a silly person." << endl;
    }
    else if (silly == serious)
    {
        cout << "You are not a silly or serious person." << endl;
    }
    else
    {
        cout << "You are a serious person." << endl;
    }
// Spont V Planner
    if (spontaneous > planner)
    {
        cout << "You are a spontaneous person." << endl;
    }
    else if (spontaneous == planner)
    {
        cout << "You are not a spontaneous person or a planner." << endl;
    }
    else
    {
        cout << "You are a planner." << endl;
    }
    cout << setfill('-') << setw(36) << "" << setfill(' ') << endl << endl; 



// Replay Loop Test
    while (questionNum == 12)
    {
        cout << "Do you want to try the test again? Y/N" << endl;
        cin >> input;
        input = toupper(input);
        if ( input == 'Y')
        {
            replay = true;
            questionNum = 0;
        }
        else if ( input == 'N')
        {
            replay = false;
            return 0;
        }
        else 
        {
            cout << "Error, Invalid Input. Try Again." << endl;
        }  
    }        
}
return 0;

}