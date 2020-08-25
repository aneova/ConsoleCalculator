
#include "MathHistory.h"

enum HistorySystem
{
	SAVE_TO_FILE,
	DO_NOT_SAVE,
	PRINT_OUT_HISTRORY
} menu;

 std::vector<std::string> MathHistory::vecHistory = { " " };

MathHistory::MathHistory()
{
}

MathHistory::MathHistory(const MathHistory & mathHist)
{
}

 
void MathHistory::doAction(int userInput)
{ 
	switch (userInput)
	{
	case SAVE_TO_FILE:

		this->saveResult();

		break;

	case DO_NOT_SAVE:
		if (this->vecHistory.size() > 1)
		{
			this->vecHistory.pop_back();
			std::cout << "The last result was deleted." << "\n";
		} else std::cout << "There is no a result for deleting." << "\n";
		system("pause");
	break;

	case PRINT_OUT_HISTRORY:
	{
		if (this->vecHistory.size() > 1)
		{
			for (auto const& value : this->vecHistory) 
				std::cout << value << "\n";
		}
		else
		{
			std::cout << "Calculation history is empty now." << "\n";
		}
		system("pause");
	}
		break;

	default:
		std::cout << "Bad input!" << std::endl;
		system("pause");
		break;
	}
}

void MathHistory::saveResult()
{
	std::ofstream myfile;
	myfile.open("CalculationResults.txt");

	for (auto const& value : this->vecHistory) {
		myfile << value << "\n";
	}
	
	myfile.close();
	std::cout << "The result have been saved to the file CalculationResults.txt" << "\n";
}

 
