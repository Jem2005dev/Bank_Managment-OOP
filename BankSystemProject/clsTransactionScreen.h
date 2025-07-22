#pragma once

#include<iostream>
#include<iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferListScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen
{
private:

    enum enTransactionsMenueOptions
    {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTransfer = 4, eTransferList = 5, eShowMainMenue = 6
    };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Choice = clsInputValidate::
            ReadIntegerNumberBetween(1, 6, "Enter Number between 1 to 6? ");

        return Choice;
    }


    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";

        clsDepositScreen::DepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
       // cout << "\n Withdraw Screen will be here.\n";

        clsWithdrawScreen::WithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Balances Screen will be here.\n";

        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        //cout << "\nTransfer Screen will be here...\n";

        clsTransferScreen::Transfer();
    }

    static void _ShowTransferListScreen()
    {
        //cout << "\nTransfer Screen List will be here...\n";

        clsTransferListScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");

        ShowTransactionsMenue();
    }


    static void _PerformTransactionsMenueOption
    (enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eTransferList:
            system("cls");
            _ShowTransferListScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            // do nothing here the main screen will handle it :-)
        }
        }
    }

public:

    static void ShowTransactionsMenue()
    {
        if (!_CheckAccess(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Show Transfer List.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }
};

