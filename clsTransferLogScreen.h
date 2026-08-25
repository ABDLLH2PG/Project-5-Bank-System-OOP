#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintTransferLogLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "";
		cout << "| " << left << setw(23) << TransferLogRecord.DateAndTime;
		cout << "| " << left << setw(8)  << TransferLogRecord.SourceAccount;
		cout << "| " << left << setw(8)  << TransferLogRecord.DistinationAccount;
		cout << "| " << left << setw(8)  << TransferLogRecord.Amount;
		cout << "| " << left << setw(10) << TransferLogRecord.SourceBalance;
		cout << "| " << left << setw(10) << TransferLogRecord.DistinationBalance;
		cout << "| " << left << setw(10) << TransferLogRecord.UserName;
	}

public:
	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();
		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "";
		cout << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8)  << "s.Acct";
		cout << "| " << left << setw(8)  << "d.Acct";
		cout << "| " << left << setw(8)  << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferLogRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else
		{
			for (clsBankClient::stTransferLogRecord& Record : vTransferLogRecord)
			{
				_PrintTransferLogLine(Record);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};