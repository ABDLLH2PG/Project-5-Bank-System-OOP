#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
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

	static void _ShowResults(clsCurrency& Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t  Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country? ";
		short FindBy = clsInputValidate::ReadShortNumberBetween(1, 2);

		if (FindBy == 1)
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Currency);
		}
		if (FindBy == 2)
		{
			cout << "\nPlease Enter Country Name: ";
			string CurrencyCountry = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCountry);

			_ShowResults(Currency);
		}
	}
};