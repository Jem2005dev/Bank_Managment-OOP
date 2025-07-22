#pragma once

#include<iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone Number: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password (Pin Code): ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

	static void _Print(clsBankClient Client)
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

	static void UpdateClient()
	{
		if (!_CheckAccess(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t  Update Client Screen");

		string AccountNumber = "";

		cout << "\nPlease enter client account number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_Print(Client1);

		cout << "\n\nUpdate Client Info:";
		cout << "\n_______________________\n";

		_ReadClientInfo(Client1);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client1.Save();

		switch (SaveResult)
		{

		case clsBankClient::svSucceeded:
			cout << "\nAccount Updated Successfully :-)\n";
			_Print(Client1);
			break;

		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not saved because it's empty.";
			break;

		default:
			break;
		}
	}
};

