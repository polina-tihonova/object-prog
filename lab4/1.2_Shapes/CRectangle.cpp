
#include "CRectangle.h"
#include <sstream>

CRectangle::CRectangle(
	const CPoint leftTop,
	const double width,
	const double height,
	const uint32_t outlineColor,
	const uint32_t fillColor
)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, CSolidShape(fillColor, outlineColor) {}

double CRectangle::GetArea() const
{
	return m_height * m_width;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_height + m_width);
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return CPoint(
		m_leftTop.GetX() + m_width,
		m_leftTop.GetY() + m_height
	);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

std::string CRectangle::ToString() const
{
	std::stringstream str;

	str << "  TYPE:               " << "Rectangle" << std::endl;
	str << "  LEFT TOP POINT:     " << m_leftTop.ToString() << std::endl;
	str << "  RIGHT BOTTOM POINT: " << GetRightBottom().ToString() << std::endl;
	str << "  HEIGHT:             " << m_height << std::endl;
	str << "  WIDTH:              " << m_width << std::endl;
	str << "  AREA:               " << GetArea() << std::endl;
	str << "  PERIMETER:          " << GetPerimeter() << std::endl;
	str << "  OUTLINE COLOR:      " << std::hex << GetOutlineColor() << std::endl;
	str << "  FILL COLOR:         " << std::hex << GetFillColor() << std::endl;

	return str.str();
}

void CRectangle::Draw(ICanvas& canvas) const
{
	CPoint leftTop = m_leftTop;
	CPoint rightBottom = GetRightBottom();

	std::vector<CPoint> points = {
		{ leftTop.GetX(),     leftTop.GetY() },
		{ rightBottom.GetX(), leftTop.GetY() },
		{ rightBottom.GetX(), rightBottom.GetY() },
		{ leftTop.GetX(),	  rightBottom.GetY() }
	};

	canvas.DrawPoligon(points, GetFillColor(), GetOutlineColor());
}

