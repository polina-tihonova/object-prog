
#include "CTriangle.h"
#include <sstream>
#include <cmath>

CTriangle::CTriangle(
	const CPoint vertex1,
	const CPoint vertex2,
	const CPoint vertex3,
	const uint32_t outlineColor,
	const uint32_t fillColor
)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape(fillColor, outlineColor) {}

double CTriangle::GetArea() const
{
	double length1 = GetLength(m_vertex1, m_vertex2);
	double length2 = GetLength(m_vertex2, m_vertex3);
	double length3 = GetLength(m_vertex3, m_vertex1);
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - length1) * (p - length2) * (p - length3));
}

double CTriangle::GetPerimeter() const
{
	double length1 = GetLength(m_vertex1, m_vertex2);
	double length2 = GetLength(m_vertex2, m_vertex3);
	double length3 = GetLength(m_vertex3, m_vertex1);
	return length1 + length2 + length3;
}

//âûíåñòè
double CTriangle::GetLength(CPoint vertex1, CPoint vertex2) const
{
	double ñathetus1 = vertex2.GetX() - vertex1.GetX();
	double ñathetus2 = vertex2.GetY() - vertex1.GetY();
	double hypotenuse = sqrt(pow(ñathetus1, 2) + pow(ñathetus2, 2));
	return hypotenuse;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

std::string CTriangle::ToString() const
{
	std::stringstream str;

	str << "  TYPE:               " << "Rectangle" << std::endl;
	str << "  VERTEX 1:           " << m_vertex1.ToString() << std::endl;
	str << "  VERTEX 2:           " << m_vertex2.ToString() << std::endl;
	str << "  VERTEX 3:           " << m_vertex3.ToString() << std::endl;
	str << "  AREA:               " << GetArea() << std::endl;
	str << "  PERIMETER:          " << GetPerimeter() << std::endl;
	str << "  OUTLINE COLOR:      " << std::hex << GetOutlineColor() << std::endl;
	str << "  FILL COLOR:         " << std::hex << GetFillColor() << std::endl;

	return str.str();
}

void CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points = {
		   { m_vertex1.GetX(), m_vertex1.GetY() },
		   { m_vertex2.GetX(), m_vertex2.GetY() },
		   { m_vertex3.GetX(), m_vertex3.GetY() }
	};
	canvas.DrawPoligon(points, GetFillColor(), GetOutlineColor());
}
