
#include "CLineSegment.h"
#include <sstream>

CLineSegment::CLineSegment(
	const CPoint& startPoint,
	const CPoint& endPoint,
	const uint32_t outlineColor
)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, CShape(outlineColor)
{}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	const CPoint startPoint = GetStartPoint();
	const CPoint endPoint = GetEndPoint();

	return hypot(
		abs(endPoint.GetX() - startPoint.GetX()),
		abs(endPoint.GetY() - startPoint.GetY())
	);
}

std::string CLineSegment::ToString() const
{
	std::stringstream str;

	str << "  TYPE:          " << "Line Segment"          << std::endl;
	str << "  START POINT:   " << m_startPoint.ToString() << std::endl;
	str << "  END POINT:     " << m_endPoint.ToString()   << std::endl;
	str << "  AREA:          " << GetArea()               << std::endl;
	str << "  PERIMETER:     " << GetPerimeter()          << std::endl;
	str << "  OUTLINE COLOR: " << std::hex << GetOutlineColor() << std::endl;

	return str.str();
}

void CLineSegment::Draw(ICanvas& canvas) const
{
	canvas.DrawLine({ m_startPoint, m_endPoint }, GetOutlineColor());
}
