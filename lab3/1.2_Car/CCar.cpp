
#include "CCar.h"

bool CCar::IsTurnedOn()
{
	return m_isEngineOn;
}

int CCar::GetGear()
{
	return m_gear;
}

int CCar::GetSpeed()
{
	return m_speed;
}

std::string CCar::GetDirection()
{
	auto directionName = MAP_DIRECTION_NAME.find(m_direction);

	if (directionName != MAP_DIRECTION_NAME.end())
	{
		return directionName->second;
	}
	else
	{
		return "Unknown";
	}
}

bool CCar::TurnOnEngine()
{
	m_isEngineOn = true;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (m_gear == NEUTRAL_GEAR && m_speed == 0)
	{
		m_isEngineOn = false;
		return true;
	}

	return false;
}

bool CCar::SetGear(int gear)
{
	if ((m_isEngineOn || gear == NEUTRAL_GEAR)
		&& IsValidGear(gear)
		&& IsValidDirectionSwitch(gear)
		&& IsValidSpeedForGear(m_speed, gear))
	{
		m_gear = gear;

		SetDirection();

		return true;
	}

	return false;
}

void CCar::SetDirection()
{
	if (m_speed == 0)
	{
		m_direction = StandingStill;
	}
	else if (m_direction == Backward || m_gear == BACKWARD_GEAR && m_speed > 0)
	{
		m_direction = Backward;
	}
	else
	{
		m_direction = Forward;
	}
}

bool CCar::SetSpeed(int speed)
{
	if ((m_isEngineOn || speed == 0)
		&& IsValidSpeedForGear(speed, m_gear)
		&& (m_gear != NEUTRAL_GEAR || m_speed > speed || speed == 0))
	{
		m_speed = speed;

		SetDirection();

		return true;
	}

	return false;
}

bool CCar::IsValidGear(const int gear)
{
	return MAP_GEAR_SPEED_RANGES.find(gear) != MAP_GEAR_SPEED_RANGES.end();
}

bool CCar::IsValidDirectionSwitch(const int gear)//rename
//проверки в разных функциях
{
	return m_direction == StandingStill
		|| m_direction == Backward && gear == NEUTRAL_GEAR
		|| m_direction == Forward && gear > BACKWARD_GEAR;
}

//const не нужен
bool CCar::IsValidSpeedForGear(const int speed, const int gear)
{
	auto gearSpeedRangePair = MAP_GEAR_SPEED_RANGES.find(gear);

	if (gearSpeedRangePair != MAP_GEAR_SPEED_RANGES.end())
	{
		auto speedRange = gearSpeedRangePair->second;
		return speed >= speedRange.first && speed <= speedRange.second;
	}

	return false;
}