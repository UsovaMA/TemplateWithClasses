#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;
//----------------------------------------------------------------------START OF CLASS DESCRIPTION----------------------------------------------------------------------
class Date {
private:
	string inputDate;
	vector<string> splitDate;
	const string separator = ".";
	int day, month, year;
	int days;
public:
	Date(string date, string regex);
	Date(string date);
	Date();
	int split(string str, string regex);
	void show(bool mode);
	int getDay();
	int getMonth();
	int getYear();
	friend ostream& operator<<(ostream& out, Date& date);
	friend istream& operator>>(istream& input, Date& date);
	bool operator==(const Date& date) {
		if ((this->day == date.day) && (this->month == date.month) & (this->year == date.year)) return true;
		else return false;
	}
	bool operator!=(const Date& date) {
		if ((this->day == date.day) && (this->month == date.month) & (this->year == date.year)) return false;
		else return true;
	}
	bool operator>(const Date& date) {
		if (this->days > date.days) return true;
		else return false;
	}
	bool operator>=(const Date& date) {
		if (this->days >= date.days) return true;
		else return false;
	}
	bool operator<(const Date& date) {
		if (this->days < date.days) return true;
		else return false;
	}
	bool operator<=(const Date& date) {
		if (this->days <= date.days) return true;
		else return false;
	}
	Date operator+(int inputDays) {
		Date res;
		res.year = this->year;
		res.month = this->month;
		res.day = this->day;
		while (inputDays != 0) {
			inputDays--;
			if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10)) {
				if (res.day == 31) {
					res.month++;
					res.day = 1;
				}
				else
				{
					res.day++;
				}
			}
			if (month == 4 || month == 6 || month == 9 || month == 11) {
				if (res.day == 30) {
					res.month++;
					res.day = 1;
				}
				else
				{
					res.day++;
				}
			}
			if (month == 2) {
				if (res.day == 28) {
					res.month++;
					res.day = 1;
				}
				else
				{
					res.day++;
				}
			}
			if (month == 12) {
				if (res.day == 31) {
					res.year++;
					res.month = 1;
					res.day = 1;
				}
				else
				{
					res.day++;
				}
			}
		}
		return res;
	}
	Date operator-(int inputDays) {
		Date res;
		//res.year = abs(this->year - date.year) % 60;
		//res.month = abs(this->month - date.month - (abs(this->year - date.year) / 60) % 60);
		//res.day = abs(this->day - date.day - (abs(this->month - date.month - (abs(this->year - date.year) / 60)) / 60) % 24);
		return res;
	}
	Date& operator= (const Date& date) {
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
		return *this;
	}
};
//----------------------------------------------------------------------END OF CLASS DESCRIPTION----------------------------------------------------------------------

//-----------------------------------------------------------------------START OF CLASS METHODS-----------------------------------------------------------------------
ostream& operator<<(ostream& out, Date& date) {
	return out << date.getDay() << '.' << date.getMonth() << '.' << date.getYear() << endl;
}
istream& operator>>(istream& input, Date& date) {
	return input >> date.inputDate;
}
//Constructor of class with specified regex
Date::Date(string date, string regex) {
	if (split(date, regex) == 3) {
		day = stoi(splitDate[0]);
		month = stoi(splitDate[1]);
		year = stoi(splitDate[2]);
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			days = day + month * 31 + year * 365;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			days = day + month * 30 + year * 365;
		}
		if (month == 2) {
			days = day + month * 28 + year * 365;
		}
	}
	else {
		cout << "Incorrect date" << endl;
		exit(EXIT_FAILURE);
	}

}
//Constructor of class with default regex (":")
Date::Date(string date) {
	if (split(date, separator) == 3) {
		day = stoi(splitDate[0]);
		month = stoi(splitDate[1]);
		year = stoi(splitDate[2]);
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			days = day + month * 31 + year * 365;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			days = day + month * 30 + year * 365;
		}
		if (month == 2) {
			days = day + month * 28 + year * 365;
		}
	}
	else {
		cout << "Incorrect date" << endl;
		exit(EXIT_FAILURE);
	}

}
Date::Date() {

}
//Split method for splitting input on elements
int Date::split(string str, string regex) {
	vector<string> res;
	int count = 0;
	int start = 0;
	int end;
	do {
		end = str.find(regex);
		res.push_back(str.substr(start, end - start));
		str = str.substr(end + 1, str.size() - 1);
		count++;
	} while (end != -1);
	Date::splitDate = res;
	return count;
}
void Date::show(bool mode) {
	cout << Date::days << endl;
}
int Date::getDay() {
	return Date::day;
}
int Date::getMonth() {
	return Date::month;
}
int Date::getYear() {
	return Date::year;
}
//----------------------------------------------------------------------END OF CLASS METHODS----------------------------------------------------------------------

int main() {
	string DATE1;
	string DATE2;
	int testDays;
	cout << "enter Date" << endl;
	cin >> DATE1;
	cin >> DATE2;
	cin >> testDays;
	Date test1(DATE1);
	Date test2(DATE2);
	Date resM = test1 - testDays;
	Date resP = test1 + testDays;
	if (test1 == test2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	test1.show(true);
	cout << resP;
}