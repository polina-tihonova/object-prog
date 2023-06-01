
#include "CCanvas.h"
#include "CCircle.h"
#include "CSession.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CLineSegment.h"
#include <map>
#include <regex>

// Дублирование при выводе фигур - пример с объемными телами
const std::map <std::string, Shapes> mapCommandShape = {
	{ "circle",      Shapes::Circle      },
	{ "linesegment", Shapes::LineSegment },
	{ "rectangle",   Shapes::Rectangle   },
	{ "triangle",    Shapes::Triangle    },
};

CSession::CSession(std::istream& input)
	: m_input(input) {}

void CSession::ProcessCommand()
{
	std::string commandLine;
	std::vector<std::string> commands;

	while (std::getline(m_input, commandLine))
	{
		commandLine = Trim(commandLine);
		commands = Split(commandLine);

		if (!commands.empty())
		{
			auto it = mapCommandShape.find(commands.front());
			if (it != mapCommandShape.end())
			{
				Shapes shape = it->second;
				commands.erase(commands.begin());

				CSession::CreateShape(shape, commands);
			}
		}
	}
}

std::string CSession::GetMaxAriaShapeInfo() const
{
	if (m_shapes.empty())
	{
		return "No shapes to process";
	}

	auto maxAreaIndex = 0;

	for (int i = 0; i != m_shapes.size(); ++i)
	{
		if (m_shapes[i]->GetArea() > m_shapes[maxAreaIndex]->GetArea())
		{
			maxAreaIndex = i;
		}
	}

	return m_shapes[maxAreaIndex]->ToString();
}

std::string CSession::GetMinPerimeterShapeInfo() const
{
	if (m_shapes.empty())
	{
		return "No shapes to process";
	}

	auto minPerimeterIndex = 0;

	for (int i = 0; i != m_shapes.size(); ++i)
	{
		if (m_shapes[i]->GetArea() < m_shapes[minPerimeterIndex]->GetArea())
		{
			minPerimeterIndex = i;
		}
	}

	return m_shapes[minPerimeterIndex]->ToString();
}

void CSession::CreateShape(Shapes shape, std::vector<std::string>& parameters)
{
	switch (shape)
	{
		case Shapes::LineSegment:
		{
			CSession::CreateLineSegment(parameters);
			break;
		}
		case Shapes::Rectangle:
		{
			CSession::CreateRectangle(parameters);
			break;
		}
		case Shapes::Triangle:
		{
			CSession::CreateTriangle(parameters);
			break;
		}
		case Shapes::Circle:
		{
			CSession::CreateCircle(parameters);
			break;
		}
		default:
		{
			throw std::invalid_argument("Unknown command.");
			break;
		}
	}
}

void CSession::CreateLineSegment(std::vector<std::string>& parameters)
{
	try
	{
		CLineSegment lineSegment(
			CPoint(std::stod(parameters[0]), std::stod(parameters[1])),
			CPoint(std::stod(parameters[2]), std::stod(parameters[3])),
			stoul(parameters[4], nullptr, 16)
		);

		m_shapes.push_back(std::make_unique<CLineSegment>(lineSegment));
	}
	catch (const std::logic_error&)
	{
		throw std::invalid_argument("Invalid parameters for Rectangle.");
	}
}

void CSession::CreateRectangle(std::vector<std::string>& parameters)
{
	try
	{
		CRectangle rectangle(
			CPoint(std::stod(parameters[0]), std::stod(parameters[1])),
			std::stod(parameters[2]),
			std::stod(parameters[3]),
			stoul(parameters[4], nullptr, 16),
			stoul(parameters[5], nullptr, 16)
		);

		m_shapes.push_back(std::make_unique<CRectangle>(rectangle));
	}
	catch (const std::logic_error&)
	{
		throw std::invalid_argument("Invalid parameters for Rectangle.");
	}
}

void CSession::CreateTriangle(std::vector<std::string>& parameters)
{
	try
	{
		CTriangle triangle(
			CPoint(std::stod(parameters[0]), std::stod(parameters[1])),
			CPoint(std::stod(parameters[2]), std::stod(parameters[3])),
			CPoint(std::stod(parameters[4]), std::stod(parameters[5])),
			stoul(parameters[6], nullptr, 16),
			stoul(parameters[7], nullptr, 16)
		);

		m_shapes.push_back(std::make_unique<CTriangle>(triangle));
	}
	catch (const std::logic_error&)
	{
		throw std::invalid_argument("Invalid parameters for Rectangle.");
	}
}

void CSession::CreateCircle(std::vector<std::string>& parameters)
{
	try
	{
		CCircle triangle(
			CPoint(std::stod(parameters[0]), std::stod(parameters[1])),
			std::stod(parameters[2]),
			stoul(parameters[3], nullptr, 16),
			stoul(parameters[4], nullptr, 16)
		);

		m_shapes.push_back(std::make_unique<CCircle>(triangle));
	}
	catch (const std::logic_error&)
	{
		throw std::invalid_argument("Invalid parameters for Rectangle.");
	}
}

void CSession::DrawShapes() const
{
	if (!m_shapes.empty())
	{
		sf::RenderWindow window(sf::VideoMode(800, 800), "Draw Shapes");
		CCanvas canvas(window);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
				if (event.type == sf::Event::Closed)
					window.close();

			window.clear(sf::Color::Black);

			for (const auto& shape : m_shapes)
				shape->Draw(canvas);

			window.display();
		}
	}
}

std::vector<std::string> CSession::Split(const std::string& line)
{
	const char delimeter = ' ';

	size_t initialPosition = 0;
	size_t position = line.find(delimeter);

	std::string part;
	std::vector<std::string> strParts;
	strParts.clear();

	while (position != std::string::npos) {
		part = line.substr(initialPosition, position - initialPosition);

		if (part != "") {
			strParts.push_back(part);
		}

		initialPosition = position + 1;
		position = line.find(delimeter, initialPosition);
	}

	part = line.substr(initialPosition, line.size() - initialPosition + 1);
	strParts.push_back(part);

	return strParts;
}

std::string CSession::Trim(const std::string& s) {
	return LTrim(RTrim(s));
}

std::string CSession::LTrim(const std::string& s) {
	return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string CSession::RTrim(const std::string& s) {
	return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}
