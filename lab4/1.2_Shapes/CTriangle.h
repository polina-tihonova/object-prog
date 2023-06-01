
#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CTriangle :
    public CSolidShape
{
public:
	CTriangle(
		CPoint const vertex1,
		CPoint const vertex2,
		CPoint const vertex3,
		uint32_t const outlineColor,
		uint32_t const fillColor
	);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(ICanvas& canvas) const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:

	double GetLength(CPoint vertex1, CPoint vertex2) const;

	CPoint m_vertex1 = CPoint(0, 0);
	CPoint m_vertex2 = CPoint(0, 0);
	CPoint m_vertex3 = CPoint(0, 0);
};
