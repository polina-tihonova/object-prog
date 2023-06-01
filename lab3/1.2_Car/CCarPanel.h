#pragma once
#include <map>
#include <optional>

#include "CCar.h"

enum class CommandTypes
{
	Exit,
	Info,
	EngineOn,
	EngineOff,
	SetGear,
	SetSpeed
};

//TODO: <string, func>
const std::map<std::string, CommandTypes> commandIndexMap = {
	{ "Exit",      CommandTypes::Exit },
	{ "Info",      CommandTypes::Info },
	{ "EngineOn",  CommandTypes::EngineOn },
	{ "EngineOff", CommandTypes::EngineOff },
	{ "SetGear",   CommandTypes::SetGear },
	{ "SetSpeed",  CommandTypes::SetSpeed },
};

struct CommandParts
{
	std::string command;
	std::optional<std::string> parameter;
};

class CCarPanel
{
public:
	std::optional<std::string> CatchCommand(std::istream& input);
	bool HandleCommand(CCar& car, std::string inputString, std::ostream& output);
	void PrintInterface(std::ostream& output);

private:
	void Info(CCar& car, std::ostream& output);
	void EngineOn(CCar& car, std::ostream& output);
	void EngineOff(CCar& car, std::ostream& output);
	void SetGear(CCar& car, std::string paramString, std::ostream& output);
	void SetSpeed(CCar& car, std::string paramString, std::ostream& output);
	CommandParts ParceCommandString(std::string inputString);
	std::optional<int> ParseParameter(std::string paramString);
	std::string ltrim(const std::string& s);
	std::string rtrim(const std::string& s);
};
