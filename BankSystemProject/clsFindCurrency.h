#pragma once

#include<iostream>
#include"clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrency : protected clsScreen
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

public:

	static void FindCurrency()
	{
		int Choice = 0;

		clsScreen::_DrawScreenHeader("\t  Find Currency Screen");

		cout << "Find By:\n\n";
		cout << "[1] Currency Code.\n";
		cout << "[2] Countrey Name.\n";

		cout << "Answer: ";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
		{
			cout << "\n\nPlease Enter Currency Code: ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			if (!Currency.IsEmpty())
			{
				cout << "\nCurrency found :-)\n";
				_PrintCurrencyCardInfo(Currency);
			}
			else
			{
				cout << "\nCurrency NOT found.";
			}
			
			break;
		}
			

		case 2:
		{
			cout << "\n\nPlease Enter Country Name: ";
			string CountryName = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

			if (!Currency.IsEmpty())
			{
				cout << "\nCountry found :-)\n";
				_PrintCurrencyCardInfo(Currency);
			}
			else
			{
				cout << "\nNo Country have this name.";
			}

			break;
		}
		}
	}
};

