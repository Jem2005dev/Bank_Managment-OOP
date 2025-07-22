#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n_______________________";
		cout << "\nFirstName       : " << Client.FirstName;
		cout << "\nLastName        : " << Client.LastName;
		cout << "\nFullName        : " << Client.FullName();
		cout << "\nEmail           : " << Client.Email;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nAcc. Number     : " << Client.AccountNumber();
		cout << "\nPassword        : " << Client.PinCode;
		cout << "\nBalance         : " << Client.AccountBalance;
		cout << "\n_______________________\n";
	}

public:

	static void WithdrawScreen()
	{
		clsScreen::_DrawScreenHeader("\t  Withdraw Client Screen");

		string AccountNumber = "";

		cout << "\nPlease enter account number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis account number is already exist, try another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		double Amount = 0;
		cout << "\nPlease enter amount to Withdraw: ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'y';
		cout << "\n\nAre you sure you want to Withdraw (y/n)? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.AccountBalance > Amount)
			{
				Client.Withdraw(Amount);
				cout << "\nAmount Withdrew Successfully.\n";
			}
			else
				cout << "\nCannot withdraw, Insuffecient balance!\n";
		}
		else
			cout << "\nOperation cancelled.\n";
	}
};