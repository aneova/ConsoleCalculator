#include <iostream>
#include <string>
#include "Math.h"


enum CalculationActions
{
    ADDITION,
    MULTIPLICATION,
    DIVISION,
    SUBTRACT,
    TRY_IT_AGAIN,
    BACK_TO_MAIN_MENU
} mathMenu;

 
Math::Math()
{
}

double Math::getSum(double x, double y)
{
    return (x +y);
}

double Math::getSubtract(double x, double y)
{
    return (x - y);
}

double Math::getMultiplication(double x, double y)
{
    return (x * y);
}

double Math::getDivision(double x, double y)
{
    return (x / y);
}



void Math::Calculation(int userInput, MathHistory mathHist)
{
    double a = 0, b = 0;

    switch (userInput)
    {
    case ADDITION:
    {
        std::cout << "The First argument: ";
        std::cin >> a;
        std::cout << "The Second argument: ";
        std::cin >> b;
        
        double result = this->getSum(a, b);
        std::string sResult = std::to_string((int)a) + " + " + std::to_string((int)b) + " = " + std::to_string((int)result);
        mathHist.vecHistory.push_back(sResult);

        std::cout << "The sum is: " << result << std::endl;
        system("pause");
    }
    break;
    case MULTIPLICATION:
    {
        std::cout << "The First argument: ";
        std::cin >> a;
        std::cout << "The Second argument: ";
        std::cin >> b;

        double result = this->getMultiplication(a, b);
        std::string sResult = std::to_string((int)a) + " * " + std::to_string((int)b) + " = " + std::to_string((int)result);
        mathHist.vecHistory.emplace_back(sResult);
        std::cout << "Result is: " <<result << std::endl;
        
        
    }
    break;
    case DIVISION:
    {
        std::cout << "Enter here first argument: ";
        std::cin >> a;
        std::cout << "Enter here second argument: ";
        std::cin >> b;

        double result = this->getDivision(a, b);
        std::cout << "Result is: " << result << std::endl;

        std::string sResult = std::to_string((int)a) + " / " + std::to_string((int)b) + " = " + std::to_string((int)result);
        mathHist.vecHistory.push_back(sResult);
    }
    break;
    case SUBTRACT:
    {
        std::cout << "Enter here first argument: ";
        std::cin >> a;
        std::cout << "Enter here second argument: ";
        std::cin >> b;
       
        double result = this->getSubtract(a, b);
        std::cout << "Result is: " << result << std::endl;

        std::string sResult = std::to_string((int)a) + " - " + std::to_string((int)b) + " = " + std::to_string((int)result);
        mathHist.vecHistory.push_back(sResult);

         
    }
    break;
    default:
        std::cout << "Bad input! "<<std::endl;
        
        break;
    }
    for (auto i = mathHist.vecHistory.begin(); i != mathHist.vecHistory.end(); ++i)
        std::cout << *i <<'\n';
    system("pause");
}