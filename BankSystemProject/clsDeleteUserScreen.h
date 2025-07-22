#pragma once

#include<iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsDeleteUserScreen : protected clsScreen
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

	static void DeleteUser()
	{
		clsScreen::_DrawScreenHeader("\t  Delete User Screen");

		string UserName = "";

		cout << "\nPlease Enter account number: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "No Client found have this UserName, try again: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		_PrintUserInfo(User1);

		char Answer = 'n';

		cout << "\nAre you sure you want to delete this user (y/n)? ";
		Answer = clsInputValidate::ReadChar();

		if (Answer == 'y' || Answer == 'Y')
		{
			User1.Delete();

			cout << "\nUser deleted successfully.";

			_PrintUserInfo(User1);
		}
		else
			cout << "\nOperation cancelled.\n";
	}


};

