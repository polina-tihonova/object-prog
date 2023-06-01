
#include "CSolidShape.h"

CSolidShape::CSolidShape(
	const uint32_t fillColor,
	const uint32_t outlineColor
)
	: m_fillColor(fillColor)
	, CShape(outlineColor) {}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}
