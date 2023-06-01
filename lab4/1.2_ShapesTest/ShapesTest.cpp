
#define CATCH_CONFIG_MAIN 
#include <../catch2/catch.hpp>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include "../1.2_Shapes/CSession.h"
#include "../1.2_Shapes/CPoint.h"
#include "../1.2_Shapes/CCircle.h"
#include "../1.2_Shapes/CTriangle.h"
#include "../1.2_Shapes/CRectangle.h"
#include "../1.2_Shapes/CLineSegment.h"

SCENARIO("Creating shapes")
{
	WHEN("Circle")
	{
		CCircle circle(CPoint(2.0, 3.0), 5.0, std::stoul("ff0000", nullptr, 16), std::stoul("00ff00", nullptr, 16));
		CHECK(circle.GetCenter().GetX() == 2.0);
		CHECK(circle.GetCenter().GetY() == 3.0);
		CHECK(circle.GetRadius() == 5.0);
		CHECK(circle.GetArea() == M_PI * 5.0 * 5.0);
		CHECK(circle.GetPerimeter() == 2 * M_PI * 5.0);
		CHECK(circle.GetOutlineColor() == std::stoul("ff0000", nullptr, 16));
		CHECK(circle.GetFillColor() == std::stoul("00ff00", nullptr, 16));
	}

	WHEN("Line Segment")
	{
		CLineSegment lineSegment(CPoint(2.0, 3.0), CPoint(8.0, 3.0), std::stoul("ff0000", nullptr, 16));
		CHECK(lineSegment.GetStartPoint().GetX() == 2.0);
		CHECK(lineSegment.GetStartPoint().GetY() == 3.0);
		CHECK(lineSegment.GetEndPoint().GetX() == 8.0);
		CHECK(lineSegment.GetEndPoint().GetY() == 3.0);
		CHECK(lineSegment.GetArea() == 0.0);
		CHECK(lineSegment.GetPerimeter() == 6.0);
		CHECK(lineSegment.GetOutlineColor() == std::stoul("ff0000", nullptr, 16));
	}

	WHEN("Rectangle")
	{
		CRectangle rectangle(CPoint(2.0, 3.0), 8.0, 3.0, std::stoul("ff0000", nullptr, 16), std::stoul("00ff00", nullptr, 16));
		CHECK(rectangle.GetLeftTop().GetX() == 2.0);
		CHECK(rectangle.GetRightBottom().GetY() == 6.0);
		CHECK(rectangle.GetWidth() == 8.0);
		CHECK(rectangle.GetHeight() == 3.0);
		CHECK(rectangle.GetArea() == 8.0 * 3.0);
		CHECK(rectangle.GetPerimeter() == 2 * (8.0 + 3.0));
		CHECK(rectangle.GetOutlineColor() == std::stoul("ff0000", nullptr, 16));
		CHECK(rectangle.GetFillColor() == std::stoul("00ff00", nullptr, 16));
	}

	WHEN("Triangle")
	{
		CTriangle triangle(CPoint(2.0, 3.0), CPoint(8.0, 3.0), CPoint(5.0, 6.0), std::stoul("ff0000", nullptr, 16), std::stoul("00ff00", nullptr, 16));
		CHECK(triangle.GetVertex1().GetX() == 2.0);
		CHECK(triangle.GetVertex1().GetY() == 3.0);
		CHECK(triangle.GetVertex2().GetX() == 8.0);
		CHECK(triangle.GetVertex2().GetY() == 3.0);
		CHECK(triangle.GetVertex3().GetX() == 5.0);
		CHECK(triangle.GetVertex3().GetY() == 6.0);
		CHECK(std::round(triangle.GetArea()) == 9);
		CHECK(std::round(triangle.GetPerimeter()) == 14);
		CHECK(triangle.GetOutlineColor() == std::stoul("ff0000", nullptr, 16));
		CHECK(triangle.GetFillColor() == std::stoul("00ff00", nullptr, 16));
	}
}

SCENARIO("Shapes with a maximum area and minimum perimeter")
{
	WHEN("Maximum Area")
	{
		std::stringstream strIn;
		strIn << "circle 1.0 2.0 4 ff0000 00ff00" << std::endl;
		strIn << "linesegment 2.0 3.0 2.0 2.0 ff00f0" << std::endl;
		strIn << "rectangle 3.0 4.0 2 1 ff00ff ff0fff" << std::endl;
		strIn << "triangle 0.0 0.0 5.0 6.0 3.0 4.0 f0ffff f0fff0" << std::endl;
		strIn << EOF;

		std::stringstream strOut;
		strOut << "  TYPE:               Rectangle" << std::endl;
		strOut << "  CENTER:             (1.000000, 2.000000)" << std::endl;
		strOut << "  RADIUS:             4" << std::endl;
		strOut << "  AREA:               50.2655" << std::endl;
		strOut << "  PERIMETER:          25.1327" << std::endl;
		strOut << "  OUTLINE COLOR:      ff0000" << std::endl;
		strOut << "  FILL COLOR:         ff00" << std::endl;

		CSession session(strIn);
		session.ProcessCommand();
		auto maxAreaShapeInfo = session.GetMaxAriaShapeInfo();

		CHECK(maxAreaShapeInfo == strOut.str());
	}
	//изменение окна не должно изменять пропорции
	WHEN("Minimum Perimeter")
	{
		std::stringstream strIn;
		strIn << "circle 1.0 2.0 4 ff0000 00ff00" << std::endl;
		strIn << "linesegment 2.0 3.0 2.0 2.0 ff00f0" << std::endl;
		strIn << "rectangle 3.0 4.0 2 1 ff00ff ff0fff" << std::endl;
		strIn << "triangle 0.0 0.0 5.0 6.0 3.0 4.0 f0ffff f0fff0" << std::endl;
		strIn << "exit" << std::endl;

		std::stringstream strOut;
		strOut << "  TYPE:          Line Segment" << std::endl;
		strOut << "  START POINT:   (2.000000, 3.000000)" << std::endl;
		strOut << "  END POINT:     (2.000000, 2.000000)" << std::endl;
		strOut << "  AREA:          0" << std::endl;
		strOut << "  PERIMETER:     1" << std::endl;
		strOut << "  OUTLINE COLOR: ff00f0" << std::endl;

		CSession session(strIn);
		session.ProcessCommand();
		auto minPerimeterShapeInfo = session.GetMinPerimeterShapeInfo();

		CHECK(minPerimeterShapeInfo == strOut.str());
	}
}