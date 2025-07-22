#pragma once

#include<iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsDepositScreen : protected clsScreen
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

	static void DepositScreen()
	{
		clsScreen::_DrawScreenHeader("\t  Deposit Client Screen");

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
		cout << "\nPlease enter deposit amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'y';
		cout << "\n\nAre you sure you want to deposit (y/n)? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Amount > 0)
			{
				Client.Deposit(Amount);
				cout << "\nAmount deposited Successfully.\n";
				cout << "\nNew balance is: " << Client.AccountBalance << endl;
			}
			else
				cout << "\nFailed to deposit!\n";
		}
		else
			cout << "\nOperation cancelled.\n";
	}
	
};

