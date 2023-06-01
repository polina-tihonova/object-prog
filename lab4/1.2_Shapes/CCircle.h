
#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CCircle :
    public CSolidShape
{
public:
	CCircle(
		CPoint const center,
		double const radius,
		uint32_t const outlineColor,
		uint32_t const fillColor
	);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(ICanvas& canvas) const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center = CPoint(0, 0);
	double m_radius = 0;
};

