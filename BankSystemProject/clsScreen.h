#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include "Global.h"

using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n";
        cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::GetSystemDateInAString()
            << "\n\n";

    }

    static bool _CheckAccess(clsUser::enPermissions Permissions)
    {
        if (!CurrentUser.CheckPermission(Permissions))
        {
            cout << "\t\t\t\t\t_________________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t_________________________________________";

            return false;
        }
        else
            return true;
    }
};

