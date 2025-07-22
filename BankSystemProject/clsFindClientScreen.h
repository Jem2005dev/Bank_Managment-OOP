#pragma	once

#include<iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

	static void FindClient()
	{
		if (!_CheckAccess(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t  Find Client Screen");

		cout << "\nEnter account number: ";
		string AccountNumber = clsInputValidate::ReadString();

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient found :-)";
			_PrintClient(Client);
		}
		else
			cout << "\nClient NOT found!";
	}
};