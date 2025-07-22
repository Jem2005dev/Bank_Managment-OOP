#pragma once

#include <iostream>
#include <vector>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrencyListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExhangeScreen : protected clsScreen
{
private:

    enum enCurrencyExhange 
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        CurrencyCalculator = 4, eMainMenue = 5
    };

    static short _ReadCurrencyExhange()
    {
        short Choice = 0;

        cout << "\t\t\t\t     Choose what do you want to do 1 to 5 ? ";
        Choice = clsInputValidate::ReadIntegerNumberBetween(1, 5);

        return Choice;
    }

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");

        ShowCurrenciesMenue();
    }

    static void _ShowCurrencyList()
    {
        //cout << "\nCurrency List will be here...\n";

        clsCurrencyListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrency()
    {
        //cout << "\nFind Currency will be here...\n";

        clsFindCurrency::FindCurrency();
    }

    static void _ShowUpdateCurrency()
    {
        //cout << "\nUpdate Currency will be here...\n";

        clsUpdateCurrencyScreen::UpdateCurrency();
    }

    static void _ShowCurrencyCalculator()
    {
       // cout << "\nCurrency Calculator will be here...\n";

        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrenciesMainMenueOptions
    (enCurrencyExhange CurrencyExhangeOption)
    {
        switch (CurrencyExhangeOption)
        {
        case clsCurrencyExhangeScreen::eListCurrencies:
        {
            system("cls");
            _ShowCurrencyList();
            _GoBackToCurrenciesMenue();
            break;
        }
          
        case clsCurrencyExhangeScreen::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrency();
            _GoBackToCurrenciesMenue();
            break;
        }

        case clsCurrencyExhangeScreen::eUpdateRate:
        {
            system("cls");
            _ShowUpdateCurrency();
            _GoBackToCurrenciesMenue();
            break;
        }

        case clsCurrencyExhangeScreen::CurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackToCurrenciesMenue();
            break;
        }

        case clsCurrencyExhangeScreen::eMainMenue:
        {
        
            break;
        }
        }
    }

public:

    static void ShowCurrenciesMenue()
    {

        system("cls");
        _DrawScreenHeader("    Currancy Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOptions((enCurrencyExhange)_ReadCurrencyExhange());
    }
};
