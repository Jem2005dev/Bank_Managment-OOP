#pragma once

#include<iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
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

	static void AddNewClient()
	{

		if (!_CheckAccess(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t  Add New Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis account number is already exist,\nplease enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient AddNewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(AddNewClient);

		clsBankClient::enSaveResults SaveResults = AddNewClient.Save();

		switch (SaveResults)
		{
		case clsBankClient::svSucceeded:

			cout << "\nAccount Saved Successfully (-:\n";
			clsAddNewClientScreen::_PrintClient(AddNewClient);
			break;

		case clsBankClient::svFaildEmptyObject:
			cout << "No Client Was Exist!\n";
			break;

		case clsBankClient::svFaildAccountNumberExists:
			cout << "Failed to Save Client Because the account number is already exist!\n";
			break;

		default:
			break;
		}
	}
};

