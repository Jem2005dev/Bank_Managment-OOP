#pragma once

#include<iostream>
#include<string>

using namespace std;

class clsInputValidate
{

public:

	template <typename T> T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;

		while (!(cin >> Number))
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (From <= Number && To >= Number)
			return 1;

		return 0;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (From <= Number && To >= Number)
			return 1;

		return 0;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (From <= Number && To >= Number)
			return 1;

		return 0;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;

		while (!(cin >> Number))
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number = 0;

		while (!(cin >> Number))
		{
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static int ReadIntegerNumberBetween(int From, int To, string Message = "Number not within range\n")
	{
		int Number = ReadIntNumber();
		
		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message << endl;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static double ReadDoubleNumberBetween(double From, double To, string Message = "Number not within range\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << Message << endl;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static string ReadString()
	{
		string S1 = "";

		// Usage of std::ws will extract all the whitespace character.
		getline(cin >> ws, S1);
		return S1;
	}

	static char ReadChar()
	{
		char Char = ' ';

		cin >> Char;

		return Char;
	}
};