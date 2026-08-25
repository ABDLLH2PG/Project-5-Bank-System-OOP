#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		string AccountNumberFrom;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumberFrom = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumberFrom))
		{
			cout << "\nClient with [" << AccountNumberFrom << "] does not exist.\n";
			cout << "\nPlease Enter Account Number to Transfer From: ";
			AccountNumberFrom = clsInputValidate::ReadString();
		}

		clsBankClient ClientFrom = clsBankClient::Find(AccountNumberFrom);
		_PrintClient(ClientFrom);

		string AccountNumberTo;
		cout << "\nPlease Enter Account Number to Transfer To: ";
		AccountNumberTo = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumberTo))
		{
			cout << "\nClient with [" << AccountNumberTo << "] does not exist.\n";
			cout << "\nPlease Enter Account Number to Transfer To: ";
			AccountNumberTo = clsInputValidate::ReadString();
		}

		clsBankClient ClientTo = clsBankClient::Find(AccountNumberTo);
		_PrintClient(ClientTo);

		double TransferAmount;
		cout <<"\nEnter Transfer Amount? ";
		TransferAmount = clsInputValidate::ReadDblNumber();

		while (ClientFrom.AccountBalance < TransferAmount)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			TransferAmount = clsInputValidate::ReadDblNumber();
		}

		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (clsBankClient::TransferBetweenAccount(ClientFrom, ClientTo, TransferAmount))
			{
				cout << "\nTransfer done successfully\n";

				_PrintClient(ClientFrom);
				_PrintClient(ClientTo);
			}
			else
			{
				cout << "\nTransfer failed";
			}
		}
	}
};