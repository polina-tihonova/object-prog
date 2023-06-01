#include "PrimeNumbers.h"

std::optional<Args> GetNumberFromInput(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count." << std::endl;
		std::cout << "Usage: 4.4_PrimeNumbers.exe <your number>." << std::endl;
		return std::nullopt;
	}

	Args number;

	try
	{
		number.upperBound = std::stoul(argv[1]);

		// [Исправлено] Удалила избыточную проверку upperBound < 0
		// [Исправлено] Перенесла проверку из ф-ии GeneratePrimeNumbersSet сюда
		if (number.upperBound > MAX_UPPER_BOUND)
		{
			std::cout << "Entered value is out of range." << std::endl;
			return std::nullopt;
		}

		return number;
	}
	catch (const std::exception)
	{
		return std::nullopt;
	}
}

std::vector<bool> GeneratePrimeNumbersSieve(unsigned int upperBound)
{
	// [Исправлено] Тут подчеркивалось - теперь не подчеркивается
	std::vector<bool> prime(upperBound + 1, true);

	prime[0] = false;

	// [Исправлено] Для 1 может не быть
	if (upperBound > 0)
	{
		prime[1] = false;
	}

	for (unsigned int i = 2; i * i <= upperBound; ++i) // Добавить тест для <=
	{
		if (prime[i])
		{
			// [Исправлено] Ускорение для i > 2, шаг 2i
			unsigned int step = i > 2 ? 2 * i : i;

			for (unsigned int j = i * i; j <= upperBound; j += step)
			{
				prime[j] = false;
			}
		}
	}
	return prime;
}

std::set<int> GeneratePrimeNumbersSet(unsigned int upperBound)
{
	std::set<int> set;

	// [Исправлено] Проверка на максимальный диапазон
	if (upperBound > MAX_UPPER_BOUND)
	{
		return set;
	}

	// [Исправлено] Переименовала Grid -> Sieve (решето)
	// vector<bool>? - Для хранения каждого элемента он использует 1 бит информации
	auto isPrime = GeneratePrimeNumbersSieve(upperBound);

	// [Исправлено] prime.size() тип size_t -> int
	for (int i = 2; i < static_cast<int>(isPrime.size()); i++)
	{
		if (isPrime[i])
		{
			// [Исправлено] insert с подсказкой
			set.insert(set.end(), i);
		}
	}
	return set;
}

void PrintSet(std::ostream& output, std::set<int> const& primeSet)
{
	// [Исправлено] Передача по константной ссылке
	// [Исправлено] Переименована переменная set -> primeSet
	std::copy(primeSet.begin(), primeSet.end(), std::ostream_iterator<unsigned int>(output, " "));
}