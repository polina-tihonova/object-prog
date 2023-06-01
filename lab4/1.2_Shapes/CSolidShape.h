
#pragma once
#include "ISolidShape.h"
#include "CShape.h"

class CSolidShape :
	public CShape,
	public ISolidShape
{
public:
	CSolidShape(
		const uint32_t fillColor,
		const uint32_t outlineColor
	);
	uint32_t GetOutlineColor() const override { return CShape::GetOutlineColor(); }
	uint32_t GetFillColor() const override;

private:
	uint32_t m_fillColor = 000000;
};