
#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(
		CPoint const leftTop,
		double const width,
		double const height,
		uint32_t const outlineColor,
		uint32_t const fillColor
	);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(ICanvas& canvas) const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;

	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop = CPoint(0, 0);
	double m_width = 0;
	double m_height = 0;
};
