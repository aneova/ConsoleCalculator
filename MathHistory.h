#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>


class MathHistory
{
public:
	static std::vector<std::string> vecHistory;

	MathHistory();
	MathHistory(const MathHistory & mathHist);
 

	void doAction(int userInput);
	void saveResult();


};

