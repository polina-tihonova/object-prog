
#include "CSession.h"
#include <iostream>

int main()
{
	CSession session(std::cin);

	std::cout << "Enter shapes:" << std::endl;
	session.ProcessCommand();

	std::cout << "Max area shape info:" << std::endl;
	std::cout << session.GetMaxAriaShapeInfo() << std::endl;

	std::cout << "Min perimeter shape info:" << std::endl;
	std::cout << session.GetMinPerimeterShapeInfo() << std::endl;

	session.DrawShapes();
}
