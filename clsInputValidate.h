#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (clsDate::IsDate1AfterDate2(DateFrom, DateTo))
			clsDate::SwapDates(DateFrom, DateTo);

		return clsPeriod::IsDateInPeriod(Date, clsPeriod(DateFrom, DateTo));
	}

	static short ReadShortNumber(string IncorrectMessage = "Invalid Number, Enter again:\n")
	{
		short Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << IncorrectMessage;
			cin >> Number;
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string IncorrectMessage = "Number is not within range, enter again:")
	{
		short Number = 0;
		bool Valid = true;

		do
		{
			if (!Valid)
				cout << IncorrectMessage << endl;

			Number = ReadIntNumber("Invalid Number, Enter again:\n");

			Valid = IsNumberBetween(Number, From, To);

		} while (!Valid);

		return Number;
	}

	static int ReadIntNumber(string IncorrectMessage = "Invalid Number, Enter again:\n")
	{
		int Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << IncorrectMessage;
			cin >> Number;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string IncorrectMessage = "Number is not within range, enter again:")
	{
		int Number = 0;
		bool Valid = true;

		do
		{
			if (!Valid)
				cout << IncorrectMessage << endl;

			Number = ReadIntNumber("Invalid Number, Enter again:\n");

			Valid = IsNumberBetween(Number, From, To);

		} while (!Valid);

		return Number;
	}

	static float ReadFloatNumber(string IncorrectMessage = "Invalid Number, Enter again:\n")
	{
		float Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << IncorrectMessage;
			cin >> Number;
		}

		return Number;
	}

	static float ReadIntNumberBetween(float From, float To, string IncorrectMessage = "Number is not within range, enter again:")
	{
		float Number = 0;
		bool Valid = true;

		do
		{
			if (!Valid)
				cout << IncorrectMessage << endl;

			Number = ReadIntNumber("Invalid Number, Enter again:\n");

			Valid = IsNumberBetween(Number, From, To);

		} while (!Valid);

		return Number;
	}

	static double ReadDblNumber(string IncorrectMessage = "Invalid Number, Enter again:\n")
	{
		double Number = 0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << IncorrectMessage;
			cin >> Number;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string IncorrectMessage = "Number is not within range, enter again:")
	{
		double Number = 0;
		bool Valid = true;

		do
		{
			if (!Valid)
				cout << IncorrectMessage << endl;

			Number = ReadDblNumber("Invalid Number, Enter again:\n");

			Valid = IsNumberBetween(Number, From, To);

		} while (!Valid);

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
};