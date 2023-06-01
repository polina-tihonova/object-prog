
#include "CCarPanel.h"
#include <iostream>

int main()
{
	CCar car;
	CCarPanel carPanel;

	carPanel.PrintInterface(std::cout);
	auto inputCommand = carPanel.CatchCommand(std::cin);

	while (inputCommand)
	{
		bool result = carPanel.HandleCommand(car, inputCommand.value(), std::cout);

		if (result)
		{
			system("pause");
			inputCommand.value().clear();

			carPanel.PrintInterface(std::cout);
			inputCommand = carPanel.CatchCommand(std::cin);
		}
		else
		{
			return 0;
		}
	}
}