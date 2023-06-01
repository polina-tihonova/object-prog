
#pragma once
#include "IShape.h"
#include "CPoint.h"

class CShape : virtual public IShape
{
public:
	CShape(uint32_t outlineColor);
	uint32_t GetOutlineColor() const override;

private:
	uint32_t m_outlineColor = 000000;
};
