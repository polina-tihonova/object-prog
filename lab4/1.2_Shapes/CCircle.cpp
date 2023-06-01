
#include "CCircle.h"
#include <sstream>

#define _USE_MATH_DEFINES
#include <math.h>

CCircle::CCircle(
	CPoint const center,
	double const radius,
	uint32_t const outlineColor,
	uint32_t const fillColor
) : m_center(center)
  , m_radius(radius)
  , CSolidShape(fillColor, outlineColor) {}


double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

std::string CCircle::ToString() const
{
	std::stringstream str;

	str << "  TYPE:               " << "Rectangle" << std::endl;
	str << "  CENTER:             " << m_center.ToString() << std::endl;
	str << "  RADIUS:             " << m_radius << std::endl;
	str << "  AREA:               " << GetArea() << std::endl;
	str << "  PERIMETER:          " << GetPerimeter() << std::endl;
	str << "  OUTLINE COLOR:      " << std::hex << GetOutlineColor() << std::endl;
	str << "  FILL COLOR:         " << std::hex << GetFillColor() << std::endl;

	return str.str();
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.DrawCircle(m_center, m_radius, GetFillColor(), GetOutlineColor());
}
