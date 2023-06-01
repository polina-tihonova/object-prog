#pragma once
#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CCanvas
	: public ICanvas
{
public:
	// Fill
	CCanvas(sf::RenderWindow& window);
	void DrawLine(std::vector<CPoint> const& points, uint32_t const& color) const override;
	void DrawPoligon(std::vector<CPoint> const& points, uint32_t const& fillColor, uint32_t const& outlineColor) const override;
	void DrawCircle(CPoint const& centerPoint, double const& radius, uint32_t const& fillColor, uint32_t const& outlineColor) const override;
private:
	// Интерфейс по заданию
	// Картинку 
	//Зависимость от RenderTarger
	sf::RenderWindow& m_window;
	sf::Color GetRGB(uint32_t const& color) const;
};