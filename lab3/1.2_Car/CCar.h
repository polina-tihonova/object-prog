#pragma once
#include <map>
#include <string>

enum Direction
{
	Forward,
	Backward,
	StandingStill
};

const std::map<int, std::pair<int, int>> MAP_GEAR_SPEED_RANGES =
{
	{ -1, { 0,  20  }},
	{ 0,  { 0,  150 }},
	{ 1,  { 0,  30  }},
	{ 2,  { 20, 50  }},
	{ 3,  { 30, 60  }},
	{ 4,  { 40, 90  }},
	{ 5,  { 50, 150 }},
};

const int NEUTRAL_GEAR = 0;
const int BACKWARD_GEAR = -1;
const int FIRST_GEAR = 1;

const std::map<Direction, std::string> MAP_DIRECTION_NAME =
{
	{ StandingStill, "Standing still" },
	{ Backward,      "Backward" },
	{ Forward,       "Forward"}
};


class CCar
{
public
	//const :
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	bool IsTurnedOn();
	int GetGear();
	int GetSpeed();
	//enum
	std::string GetDirection();

private:
	void SetDirection();
	bool IsValidGear(const int gear);
	bool IsValidDirectionSwitch(const int gear);
	bool IsValidSpeedForGear(const int speed, const int gear);

	bool m_isEngineOn = false;
	int  m_gear = 0;
	int  m_speed = 0;
	Direction m_direction = Direction::StandingStill;
};
