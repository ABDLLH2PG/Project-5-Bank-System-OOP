#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

	static void _PrintCurrency(clsCurrency& Currency)
	{
		cout << "\nCurrency Card: ";
		cout << "\n____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n____________________________\n";
	}

public:
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			string CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		char Answer = 'n';
		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate update Successfully :-)\n";
			_PrintCurrency(Currency);
		}
	}
};