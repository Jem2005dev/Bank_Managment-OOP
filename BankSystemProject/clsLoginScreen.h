#pragma once

#include<iostream>
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		
		bool FailedToLogin = false;

		string Username, Password;
		short FailedAttempets = 0;

		do
		{
			system("cls");

			clsScreen::_DrawScreenHeader("\t      Login Screen");

			if (FailedToLogin)
			{
				FailedAttempets++;
				
				cout << "\nInvalid username/password!\n";
				cout << "\nYou have [" << 3 - FailedAttempets << "] attempets";
			}
			
			if (FailedAttempets == 3)
			{
				cout << "\nYou are locked after [" << FailedAttempets << "] "
					<< "attempets.";

				return false;
			}

			cout << "\nEnter username: ";
			Username = clsInputValidate::ReadString();

			cout << "\nEnter password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);

			FailedToLogin = CurrentUser.IsEmpty();

		} while (FailedToLogin);

		cout << "\nWelcome " << Username << '!' << endl;
		cout << "\nPress any button to enter.";
		system("pause>0");

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool LogInScreen()
	{
		system("cls");
		return _Login();
	}
};

