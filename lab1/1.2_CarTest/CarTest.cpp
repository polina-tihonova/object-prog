
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "../lab3/1.2_Car/CCar.cpp"


SCENARIO("TurnOnEngine")
{
	WHEN("Engine was off")
	{
		CCar car;
		CHECK(car.TurnOnEngine() == true);
	}

	WHEN("Engine was on")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.TurnOnEngine() == true);
	}
}

SCENARIO("TurnOffEngine")
{
	WHEN("Engine was off")
	{
		CCar car;
		CHECK(car.TurnOffEngine() == true);
	}

	WHEN("Engine was on")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.TurnOffEngine() == true);
	}

	WHEN("Engine was on, gear is not neutral")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		CHECK(car.TurnOffEngine() == false);
	}

	WHEN("Engine was on, speed is not 0")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(10);
		CHECK(car.TurnOffEngine() == false);
	}
}

SCENARIO("SetGear")
{
	WHEN("Engine was off, gear changes to neutral")
	{
		CCar car;
		CHECK(car.SetGear(0) == true);
	}

	WHEN("Engine was off, gear changes not to neutral")
	{
		CCar car;
		CHECK(car.SetGear(1) == false);
	}

	WHEN("Engine was on, gear changes with valid speed")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(20);
		CHECK(car.SetGear(2) == true);
	}

	WHEN("Engine was on, gear changes with invalid speed")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(10);
		CHECK(car.SetGear(2) == false);
	}

	WHEN("Engine was on, gear changes to back with 0 speed")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.SetGear(-1) == true);
	}

	WHEN("Engine was on, gear changes to back with not 0 speed")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(10);
		CHECK(car.SetGear(-1) == false);
	}
}

SCENARIO("SetSpeed")
{
	WHEN("Engine was off")
	{
		CCar car;
		CHECK(car.SetSpeed(20) == false);
	}

	WHEN("Engine was on, gear is neutral")
	{
		CCar car;
		car.TurnOnEngine();
		CHECK(car.SetSpeed(20) == false);
	}

	WHEN("Engine was on, gear is first, speed is valid")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		CHECK(car.SetSpeed(20) == true);
	}

	WHEN("Engine was on, gear is first, speed is not invalid")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		CHECK(car.SetSpeed(40) == false);
	}

	//TODO: could only downcrease speed on neutral gear
	WHEN("Engine was on, gear is neutral, speed increases")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(20);
		car.SetGear(0);
		CHECK(car.SetSpeed(30) == false);
	}

	WHEN("")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(-1);
		car.SetSpeed(10);
		CHECK(car.SetGear(1) == false);
	}

	WHEN("Swith from neutral without stop to first gear")
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(-1);
		car.SetSpeed(5);
		car.SetGear(0);
		CHECK(car.SetGear(1) == false);
	}
}
