#pragma once

#include<iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFindUserScreen : protected clsScreen
{
private:

	static void _PrintUserInfo(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n_______________________";
		cout << "\nFirstName       : " << User.FirstName;
		cout << "\nLastName        : " << User.LastName;
		cout << "\nFullName        : " << User.FullName();
		cout << "\nEmail           : " << User.Email;
		cout << "\nPhone           : " << User.Phone;
		cout << "\nUsername        : " << User.UserName;
		cout << "\nPassword        : " << User.Password;
		cout << "\nPermissions     : " << User.Permission;
		cout << "\n_______________________\n";
	}

public:

	static void FindUser()
	{
		clsScreen::_DrawScreenHeader("\t  Find User Screen");

		cout << "\nEnter username: ";
		string UserName = clsInputValidate::ReadString();

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser found :-)\n";
			_PrintUserInfo(User);
		}
		else
			cout << "\nNo user was Exist by this username.";
	}
};

