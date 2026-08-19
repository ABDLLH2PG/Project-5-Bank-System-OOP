#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		this->_Value = "";
	}

	clsString(string Value)
	{
		this->_Value = Value;
	}

	void SetValue(string Value)
	{
		this->_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}
	short Length()
	{
		return _Value.length();
	}

	static short CountWords(string S1)
	{
		string delim = " ";
		short Counter = 0;
		short pos = 0;
		string sWord;

		while ((pos = S1.find(delim)) != string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				Counter++;
			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		// no need to return value , this function will directly update the object value
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		// no need to return value , this function will directly update the object value
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}

		return S1;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	enum enWhatToCount { CapitalLetters = 0, SmallLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			{
				Counter++;
			}

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}
	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
	{
		return CountLetters(_Value, WhatToCount);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}

		return Counter;
	}
	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
	}

	static short CountVowels(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}

		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static vector <string> Split(string S1, string Delim)
	{
		vector <string> vString;

		short pos = 0;
		string sWord;

		while ((pos = S1.find(Delim)) != string::npos)
		{
			sWord = S1.substr(0, pos);

			//if (sWord != "")
			//{
				vString.push_back(sWord);
			//}

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}
	vector <string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}

		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length() - 1; i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}

		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector <string> vString, string Delim)
	{
		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string S1)
	{
		vector <string> vString = Split(S1, " ");
		S1 = "";

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S1 += *iter + " ";
		}

		return S1.substr(0, S1.length() - 1);
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
	{
		vector <string> vString = Split(S1, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sReplaceTo;
				}
			}
		}

		return JoinString(vString, " ");
	}
	string ReplaceWord(string StringToReplace, string sReplaceTo, bool MatchCase = true)
	{
		return ReplaceWord(_Value, StringToReplace, sReplaceTo, MatchCase);
	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};