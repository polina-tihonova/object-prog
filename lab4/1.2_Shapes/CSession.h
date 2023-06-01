
#pragma once

#include "IShape.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

enum class Shapes
{
	LineSegment,
	Rectangle,
	Triangle,
	Circle
};

class CSession
{
public:
	CSession(std::istream& input);

	void ProcessCommand();
	std::string GetMaxAriaShapeInfo() const;
	std::string GetMinPerimeterShapeInfo() const;
	void DrawShapes() const;

private:
	std::istream& m_input;
	std::vector<std::unique_ptr<IShape>> m_shapes;

	void CreateShape(Shapes shape, std::vector<std::string>& parameters);
	void CreateLineSegment(std::vector<std::string>& parameters);
	void CreateRectangle(std::vector<std::string>& parameters);
	void CreateTriangle(std::vector<std::string>& parameters);
	void CreateCircle(std::vector<std::string>& parameters);

	std::vector<std::string> Split(const std::string& line);
	std::string Trim(const std::string& s);
	std::string LTrim(const std::string& s);
	std::string RTrim(const std::string& s);
};
