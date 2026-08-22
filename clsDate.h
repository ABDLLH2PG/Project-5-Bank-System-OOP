#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class clsDate
{
private:
	short _Day = 0;
	short _Month = 0;
	short _Year = 0;
	short _Hour = 0;
	short _Minute = 0;
	short _Second = 0;

	static int ReadNumber(string Message)
	{
		int Number;
		cout << Message;
		cin >> Number;

		return Number;
	}

	static vector <string> SplitString(string S1, string Delim = " ")
	{
		vector <string> vString;

		short pos = 0;
		string sWord;

		while ((pos = S1.find(Delim)) != string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}

	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string ReplaceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != string::npos)
		{
			S1.replace(pos, StringToReplace.length(), ReplaceTo);
			pos = S1.find(StringToReplace);
		}

		return S1;
	}

public:
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		this->_Day = now->tm_mday;
		this->_Month = now->tm_mon + 1;
		this->_Year = now->tm_year + 1900;

		this->_Hour = now->tm_hour;
		this->_Minute = now->tm_min;
		this->_Second = now->tm_sec;
	}

	clsDate(short Day, short Month, short Year)
	{
		this->_Day = Day;
		this->_Month = Month;
		this->_Year = Year;
	}

	clsDate(string DateString)
	{
		*this = StringToDate(DateString);
	}

	clsDate(short DateOrderInYear, short Year)
	{
		*this = GetDateFromDayOrderInYear(DateOrderInYear, Year);
	}

	short GetDay()
	{
		return _Day;
	}
	void SetDay(short Day)
	{
		this->_Day = Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	short GetMonth()
	{
		return _Month;
	}
	void SetMonth(short Month)
	{
		this->_Month = Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	short GetYear()
	{
		return _Year;
	}
	void SetYear(short Year)
	{
		this->_Year = Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static bool IsLeapYear(short Year)
	{
		// if year is divisible by 4 AND bot divisible by 100
		// OR if year is divisible by 400
		// them it is a leap year

		return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		return (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : NumberOfDays[Month - 1];
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Year, _Month);
	}

	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}

	static int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}
	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Year, _Month);
	}

	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}
	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}

	static short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Year, _Month, _Day);
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date._Year, Date._Month, Date._Day);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return arrDayNames[DayOfWeekOrder];
	}
	string DayshortName()
	{
		return DayShortName(DayOfWeekOrder(_Year, _Month, _Day));
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
							  "Apr", "May", "Jun",
							  "Jul", "Aug", "Sep",
							  "Oct", "Nov", "Dec" };

		return (Months[MonthNumber - 1]);
	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	enum enDayOfWeek { Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri = 7 };
	static string GetDayOfWeek(enDayOfWeek Day)
	{
		switch (Day)
		{
		case enDayOfWeek::Sat:
			return "Saturday";
		case enDayOfWeek::Sun:
			return "Sunday";
		case enDayOfWeek::Mon:
			return "Monday";
		case enDayOfWeek::Tue:
			return "Tuesday";
		case enDayOfWeek::Wed:
			return "Wednesday";
		case enDayOfWeek::Thu:
			return "Thursday";
		case enDayOfWeek::Fri:
			return "Friday";
		default:
			return "Not a valid Day";
		}
	}
	string GetDayOfWeek()
	{
		return GetDayOfWeek(enDayOfWeek(DayOfWeekOrder(_Year, _Month, _Day)));
	}

	enum enMonthOfYear { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };
	static string GetMonthOfYear(enMonthOfYear Month)
	{
		switch (Month)
		{
		case enMonthOfYear::Jan:
			return "January";
		case enMonthOfYear::Feb:
			return "February";
		case enMonthOfYear::Mar:
			return "March";
		case enMonthOfYear::Apr:
			return "April";
		case enMonthOfYear::May:
			return "May";
		case enMonthOfYear::Jun:
			return "June";
		case enMonthOfYear::Jul:
			return "July";
		case enMonthOfYear::Aug:
			return "August";
		case enMonthOfYear::Sep:
			return "September";
		case enMonthOfYear::Oct:
			return "October";
		case enMonthOfYear::Nov:
			return "November";
		case enMonthOfYear::Dec:
			return "December";
		default:
			return "Not a valid Month";
		}
	}
	string GetMonthOfYear()
	{
		return GetMonthOfYear(enMonthOfYear(_Month));
	}

	static void PrintMonthCalendar(short Year, short Month)
	{
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(Year, Month, 1);

		int NumberOfDays = NumberOfDaysInAMonth(Year, Month);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
		{
			printf("     ");
		}

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Year, _Month);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n  _________________________________\n");
		printf("\n         Calendar - %d", Year);
		printf("\n  _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(Year, i);
		}
	}
	void PrintYearCalendar()
	{
		PrintYearCalendar(_Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}

		return (TotalDays + Day);
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Year, Date._Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}
	clsDate GetDateFromDayOrderInYear(short DateOrderInYear)
	{
		return *this = GetDateFromDayOrderInYear(DateOrderInYear, _Year);
	}

	static clsDate ReadFullDate()
	{
		clsDate Date;

		Date._Day = ReadNumber("\nPlease enter a Day? ");
		Date._Month = ReadNumber("\nPlease enter a Month? ");
		Date._Year = ReadNumber("\nPlease enter a Year? ");

		return Date;
	}

	static void PrintDate(const clsDate& Date)
	{
		cout << Date._Day << "/" << Date._Month << "/" << Date._Year << endl;
	}
	void PrintDate()
	{
		PrintDate(*this);
	}

	static bool IsDate1BeforeDate2(const clsDate& Date1, const clsDate& Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year)
			? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month
				? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDate1BeforeDate2(const clsDate& Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(const clsDate& Date1, const clsDate& Date2)
	{
		return (Date1._Year == Date2._Year)
			? ((Date1._Month == Date2._Month)
				? ((Date1._Day == Date2._Day)
					? true : false) : false) : false;
	}
	bool IsDate1EqualDate2(const clsDate& Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(const clsDate& Date1, const clsDate& Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(const clsDate& Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	static enDateCompare CompareDates(const clsDate& Date1, const clsDate& Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}
	enDateCompare CompareDates(const clsDate& Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool IsLastDayInMonth(const clsDate& Date)
	{
		return (Date._Day == NumberOfDaysInAMonth(Date._Year, Date._Month));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static bool IsValidDate(const clsDate& Date)
	{
		if (Date._Day < 1 || Date._Day > 31)
			return false;

		if (Date._Month < 1 || Date._Month > 12)
			return false;

		if (Date._Month == 2)
		{
			if (IsLeapYear(Date._Year))
			{
				if (Date._Day > 29)
					return false;
			}
			else
			{
				if (Date._Day > 28)
					return false;
			}
		}

		short DaysInAMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);

		if (Date._Day > DaysInAMonth)
			return false;

		return true;
	}
	bool IsValidDate()
	{
		return IsValidDate(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate._Year = Date1._Year;
		TempDate._Month = Date1._Month;
		TempDate._Day = Date1._Day;

		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;

		Date2._Year = TempDate._Year;
		Date2._Month = TempDate._Month;
		Date2._Day = TempDate._Day;
	}
	clsDate SwapDates(clsDate& Date2)
	{
		SwapDates(*this, Date2);
		return *this;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return (IncludeEndDay ? ++Days : Days) * SwapFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, IncludeEndDay);
	}

	static clsDate GetSystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);

		Date._Year = now->tm_year + 1900;
		Date._Month = now->tm_mon + 1;
		Date._Day = now->tm_mday;

		return Date;
	}
	clsDate SetToSystemDate()
	{
		return *this = GetSystemDate();
	}

	static clsDate DateAddDays(clsDate& Date, short Days)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date._Day, Date._Month, Date._Year);
		short MonthDays = 0;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		return Date;
	}
	clsDate DateAddDays(short Days)
	{
		return *this = DateAddDays(*this, Days);
	}

	static clsDate IncreaseDateByOneDay(clsDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}
	clsDate IncreaseDateByOneDay()
	{
		return *this = IncreaseDateByOneDay(*this);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}
	clsDate IncreaseDateByXDays(short Days)
	{
		return *this = IncreaseDateByXDays(Days, *this);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}
	clsDate IncreaseDateByOneWeek()
	{
		return *this = IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}
	clsDate IncreaseDateByXWeeks(short Weeks)
	{
		return *this = IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should 
		// not be 31 / 2 / 2022, it should be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);

		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}
	clsDate IncreaseDateByOneMonth()
	{
		return *this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonth(short Months, clsDate& Date)
	{
		for (int i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}
	clsDate IncreaseDateByXMonth(short Months)
	{
		return *this = IncreaseDateByXMonth(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		return Date;
	}
	clsDate IncreaseDateByOneYear()
	{
		return *this = IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date._Year += Years;
		return Date;
	}
	clsDate IncreaseDateByXYears(short Years)
	{
		return *this = IncreaseDateByXYears(Years, *this);
	}

	static clsDate IncreaseDateByOneDecades(clsDate& Date)
	{
		Date._Year += 10;
		return Date;
	}
	clsDate IncreaseDateByOneDecades()
	{
		return *this = IncreaseDateByOneDecades(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decades, clsDate& Date)
	{
		Date._Year += Decades * 10;
		return Date;
	}
	clsDate IncreaseDateByXDecades(short Decades)
	{
		return *this = IncreaseDateByXDecades(Decades, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		Date._Year += 100;
		return Date;
	}
	clsDate IncreaseDateByOneCentury()
	{
		return *this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		Date._Year += 1000;
		return Date;
	}
	clsDate IncreaseDateByOneMillennium()
	{
		return *this = IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}
	clsDate DecreaseDateByOneDay()
	{
		return *this = DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}
	clsDate DecreaseDateByXDays(short Days)
	{
		return *this = DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}
	clsDate DecreaseDateByOneWeek()
	{
		return *this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}
	clsDate DecreaseDateByXWeeks(short Weeks)
	{
		return *this = DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}

		//last check day in date should not exceed max days in the current month
		//example if date is 31/3/2022 decreasing one month should not be 31/2/2022,
		//it should be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);

		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}
	clsDate DecreaseDateByOneMonth()
	{
		return *this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}
	clsDate DecreaseDateByXMonths(short Months)
	{
		return *this = DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date._Year--;
		return Date;
	}
	clsDate DecreaseDateByOneYear()
	{
		return *this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
	{
		Date._Year -= Years;
		return Date;
	}
	clsDate DecreaseDateByXYears(short Years)
	{
		return *this = DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		Date._Year -= 10;
		return Date;
	}
	clsDate DecreaseDateByOneDecade()
	{
		return *this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
	{
		Date._Year -= (Decades * 10);
		return Date;
	}
	clsDate DecreaseDateByXDecades(short Decades)
	{
		return *this = DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		Date._Year -= 100;
		return Date;
	}
	clsDate DecreaseDateByOneCentury()
	{
		return *this = DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		Date._Year -= 1000;
		return Date;
	}
	clsDate DecreaseDateByOneMillennium()
	{
		return *this = DecreaseDateByOneMillennium(*this);
	}
	
	static bool IsEndOfWeek(const clsDate& Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(const clsDate& Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(const clsDate& Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(const clsDate& Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(const clsDate& Date)
	{
		clsDate EndOfMonthDate;
		EndOfMonthDate._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
		EndOfMonthDate._Month = Date._Month;
		EndOfMonthDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(const clsDate& Date)
	{
		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateVacationDays(clsDate DateFrom, const clsDate& DateTo)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DaysCount;
	}
	short CalculateVacationDays(const clsDate& DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	clsDate CalculateVacationReturnDate(short VacationDays)
	{
		return *this = CalculateVacationReturnDate(*this, VacationDays);
	}

	static clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vDate;

		vDate = SplitString(DateString, "/");
		Date._Day = stoi(vDate[0]);
		Date._Month = stoi(vDate[1]);
		Date._Year = stoi(vDate[2]);

		return Date;
	}

	static string DateToString(const clsDate& Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}

	static string DateToStringWithTime(const clsDate& Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year) + " - "
			+ to_string(Date._Hour) + ":" + to_string(Date._Minute) + ":" + to_string(Date._Second);
	}
	string DateToStringWithTime()
	{
		return DateToString(*this);
	}

	static string FormateDate(clsDate Date, string DateFormate = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(DateFormate, "dd", to_string(Date._Day));
		FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = ReplaceWordInStringUsingBuiltInFunction(FormattedDateString, "yyyy", to_string(Date._Year));

		return FormattedDateString;
	}
	string FormateDate(string DateFormate = "dd/mm/yyyy")
	{
		return FormateDate(*this, DateFormate);
	}

	static float HoursToDays(float NumberOfHours)
	{
		return (float)NumberOfHours / 24;
	}

	static float DaysToHours(float NumberOfDays)
	{
		return (float)NumberOfDays * 24;
	}

	static float DaysToWeeks(float NumberOfDays)
	{
		return (float)NumberOfDays / 7;
	}

	static float WeeksToDays(float NumberOfWeeks)
	{
		return (float)NumberOfWeeks * 7;
	}

	static float HoursToWeeks(float NumberOfHours)
	{
		return (float)NumberOfHours / 24 / 7;
	}

	static float WeeksToHours(float NumberOfWeeks)
	{
		return (float)NumberOfWeeks * 7 * 24;
	}	
};