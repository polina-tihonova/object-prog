
#include <iostream>
#include <string>
#include <regex>

#include "CCarPanel.h"

std::optional<std::string> CCarPanel::CatchCommand(std::istream& input)
{
	std::string commandLine;

	if (std::getline(input, commandLine))
	{
		commandLine = ltrim(rtrim(commandLine));
		return commandLine;
	}

	return std::nullopt;
}

CommandParts CCarPanel::ParceCommandString(std::string inputString)
{
	CommandParts commandParts;

	size_t delimeterIndex = inputString.find(" ");
	if (delimeterIndex != -1)
	{
		commandParts.command = inputString.substr(0, delimeterIndex);
		commandParts.parameter = inputString.substr(delimeterIndex + 1, inputString.length() - delimeterIndex - 1);
	}
	else
	{
		commandParts.command = inputString;
		commandParts.parameter = std::nullopt;
	}

	return commandParts;
}

bool CCarPanel::HandleCommand(CCar& car, std::string inputCommand, std::ostream& output)
{
	CommandParts commandParts = ParceCommandString(inputCommand);
	auto commandIndex = commandIndexMap.find(commandParts.command);

	if (commandIndex != commandIndexMap.end())
	{
		switch (commandIndex->second)
		{
		case CommandTypes::Exit:
			return false;
		case CommandTypes::Info:
			Info(car, output);
			break;
		case CommandTypes::EngineOn:
			EngineOn(car, output);
			break;
		case CommandTypes::EngineOff:
			EngineOff(car, output);
			break;
		case CommandTypes::SetGear:
			if (commandParts.parameter)
			{
				SetGear(car, commandParts.parameter.value(), output);
			}
			break;
		case CommandTypes::SetSpeed:
			if (commandParts.parameter)
			{
				SetSpeed(car, commandParts.parameter.value(), output);
			}
			break;
		default:
			break;
		}
	}
	else
	{
		output << "Invalid command!" << std::endl;
	}

	return true;
}

void CCarPanel::Info(CCar& car, std::ostream& output)
{
	output << "Gear  - " << car.GetGear() << std::endl;
	output << "Speed - " << car.GetSpeed() << std::endl;

	if (car.IsTurnedOn())
	{
		output << "Engine - On" << std::endl;
	}
	else
	{
		output << "Engine - Off" << std::endl;
	}

	output << "Direction - " << car.GetDirection() << std::endl;
}

void CCarPanel::EngineOn(CCar& car, std::ostream& output)
{
	if (car.TurnOnEngine())
	{
		output << "Engine turned on." << std::endl;
	}
	else
	{
		output << "Can't turn engine on." << std::endl;
	}
}

void CCarPanel::EngineOff(CCar& car, std::ostream& output)
{
	if (car.TurnOffEngine())
	{
		output << "Engine turned off." << std::endl;
	}
	else
	{
		output << "Can't turn engine off." << std::endl;
	}
}

void CCarPanel::SetGear(CCar& car, std::string paramString, std::ostream& output)
{
	auto gear = ParseParameter(paramString);

	if (gear) {
		if (car.SetGear(gear.value()))
		{
			std::cout << "Gear changed to " << gear.value() << "." << std::endl;
		}
		else
		{
			std::cout << "Can't change gear." << std::endl;
		}
	}
}

void CCarPanel::SetSpeed(CCar& car, std::string paramString, std::ostream& output)
{
	auto speed = ParseParameter(paramString);

	if (speed) {
		if (car.SetSpeed(speed.value()))
		{
			std::cout << "Speed changed to " << speed.value() << "." << std::endl;
		}
		else
		{
			std::cout << "Can't change speed." << std::endl;
		}
	}
}

std::optional<int> CCarPanel::ParseParameter(std::string paramString)
{
	try
	{
		int speed = std::stoi(paramString);
		return speed;
	}
	catch (...)
	{
		std::cout << "Invalid parameter." << std::endl;
		return std::nullopt;
	}
}

void CCarPanel::PrintInterface(std::ostream& output)
{
	system("CLS");
	output << "Commands:" << std::endl;

	auto it = commandIndexMap.begin();
	while (it != commandIndexMap.end())
	{
		output << " > " << it->first << std::endl;
		it++;
	}

	output << std::endl;

	output << "Enter:" << std::endl;
	output << " > ";
}

std::string CCarPanel::ltrim(const std::string& s) {
	return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string CCarPanel::rtrim(const std::string& s) {
	return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}