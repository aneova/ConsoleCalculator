// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Math.h"


enum MenuSystem
{
    MAIN_MENU,
    MATHACTIONS,
    HISTORY,
    EXITPROGRAM
} menu;


int main(int argc, char** argv) {
   
    int input;
    int lastAction = -1;

    bool exit = false;
   
    auto mathHist   = std::make_unique<MathHistory>();
    auto mathAction = std::make_unique<Math>();

    while (!exit)
    {
        
        switch (menu)
        {
        case HISTORY:
        {
            system("cls");
            std::cout << "Choose an action: "
                << "\n [0] Save the result to the file"
                << "\n [1] Don't save the last result"
                << "\n [2] Calculator History"
                << "\n [3] Back to Main Menu" << std::endl;

            std::cout << "Enter here: ";
            std::cin >> input;

            if (input == 3)  menu = MAIN_MENU;
            else  mathHist->doAction(input);
        }
        break;
        case MATHACTIONS:
            {
                system("cls");
                std::cout << "Choose an action: "
                    << "\n [0] +"
                    << "\n [1] *"
                    << "\n [2] /"
                    << "\n [3] -"
                    << "\n [4] Try it again"
                    << "\n [5] Back to Main Menu"<< std::endl;

                std::cout << "Enter here: ";
                std::cin >> input;
                
                if (input == 4)
                {
                    
                   mathAction->Calculation(lastAction,  *mathHist);
                }
                else
                {
                    if (input == 5) menu = MAIN_MENU;
                    else {
                             lastAction = input;
                             mathAction->Calculation(input, *mathHist);
                    }
                }   //try it again block
            }
                break;
            default:
                system("cls");
                std::cout << "What would you like to do ?"
                    << "\n [1] Do Calculation"
                    << "\n [2] Show History"
                    << "\n [3] Exit"<< std::endl;

                std::cout << "Enter here: ";
                std::cin >> input;

                if (input == 1) {
                    menu = MATHACTIONS;
                }
                else if (input == 2) {
                    menu = HISTORY;
                }
                else if (input == 3) {
                    exit = true;
                }

             break;
        }

    }

    std::cin.get();

    return 0;

}
