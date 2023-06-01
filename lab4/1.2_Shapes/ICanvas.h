#pragma once
#include "CPoint.h"
#include <vector>

class ICanvas
{
public:
	virtual ~ICanvas() = default;
	//const убрать
	virtual void DrawLine(std::vector<CPoint> const& points, uint32_t const& color) const = 0;
	virtual void DrawPoligon(std::vector<CPoint> const& points, uint32_t const& fillColor, uint32_t const& outlineColor) const = 0;
	virtual void DrawCircle(CPoint const& centerPoint, double const& radius, uint32_t const& fillColor, uint32_t const& outlineColor) const = 0;
};
