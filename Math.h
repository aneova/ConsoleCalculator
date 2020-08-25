#pragma once
#include "MathHistory.h"

class Math  
{

public:

	Math();
	double getSum(double x, double y);
	double getSubtract(double x, double y);
	double getMultiplication(double x, double y);
	double getDivision(double x, double y);
	void Calculation(int userInput, MathHistory mathHist);

};

