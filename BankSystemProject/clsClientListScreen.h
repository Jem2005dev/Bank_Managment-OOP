#pragma once

#include<iostream>
#include<iomanip>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

    static void _PrintClientsRecords(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(30) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

public:

    static void ShowClientsList()
    {
        if (!_CheckAccess(clsUser::enPermissions::pListClients))
        {
            return;
        }

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Client List Screen";
        string SubTitle = "\t     (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(30) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________________\n" << endl;


        if (vClients.size() == 0)
            cout << "No Clients Here Yet!";
        else
        {
            for (clsBankClient& Client : vClients)
            {
                clsClientListScreen::_PrintClientsRecords(Client);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________________\n" << endl;
    }
};
