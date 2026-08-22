#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;

		string Username, Password;
		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!";
				cout << "\nYou have " << (3 - FaildLoginCount) << " Trias to login.\n\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}

			cout << "Enter UserName? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;
			
			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{	
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};