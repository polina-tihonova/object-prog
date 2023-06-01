
#pragma once

#include "CPoint.h"
#include "CShape.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(
		const CPoint& startPoint,
		const CPoint& endPoint,
		uint32_t outlineColor
	);

	double GetArea() const override;
	double GetPerimeter() const override;

	std::string ToString() const override;
	void Draw(ICanvas& canvas) const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint = CPoint(0, 0);
	CPoint m_endPoint = CPoint(0, 0);
};
