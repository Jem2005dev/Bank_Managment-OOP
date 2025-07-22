#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCardInfo(clsCurrency Currency)
	{
		cout << "\nCurrency Info:\n";

		cout << "\n_____________________________\n";
		cout << "Country  : " << Currency.Country() << endl;
		cout << "Code     : " << Currency.CurrencyCode() << endl;
		cout << "Name     : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) : " << Currency.Rate() << endl;
		cout << "\n_____________________________\n";
	}

	static float _ReadNewRate()
	{
		float NewRate = 0;
		NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}

public:

	static void UpdateCurrency()
	{
		clsScreen::_DrawScreenHeader("\t  Update Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease enter currency code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nWrong Code!\nPlease Enter another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyCardInfo(Currency);

		char Answer = ' ';

		cout << "\n\nAre you sure you want to update currency rate (y/n)? ";
		Answer = clsInputValidate::ReadChar();
		

		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate currency rate:\n";
			cout << "_________________________";
			cout << "\nEnter new rate: ";
			
			Currency.UpdateRate(_ReadNewRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n\n";
			_PrintCurrencyCardInfo(Currency);
		}
		else
		{
			cout << "\nOperation cancelled.";
		}
	}
};