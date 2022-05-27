#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GDate(long JDate, int& year, int& month, int& day) {
	unsigned long A = (JDate * 4L - 7468865L) / 146097L;
	A = (JDate > 2299160) ? JDate + 1 + A - (A / 4L) : JDate;
	long B = A + 1524;
	long C = (B * 20L - 2442L) / 7305L;
	long D = (C * 1461L) / 4L;
	long E = (10000L * (B - D)) / 306001L;
	day = int(B - D - ((E * 306001L) / 10000L));
	month = int((E <= 13) ? E - 1 : E - 13);
	year = int(C - ((month > 2) ? 4716 : 4715));
}

class Date {
private:
	string inputDate;
	vector<string> splitDate;
	const string separator = ".";
	int day, month, year;
	unsigned long JDate;
public:
	Date(string date);
	int split(string str, string regex);
	friend ostream& operator<<(ostream& out, Date& date);
	friend istream& operator>>(istream& input, Date& date);
	friend void GDate(long JD, int& y, int& m, int& d);

	bool operator==(const Date& date) {
		return (this->JDate == date.JDate);
	}
	bool operator!=(const Date& date) {
		return (this->JDate != date.JDate);
	}
	bool operator>(const Date& date) {
		return (this->JDate > date.JDate);
	}
	bool operator>=(const Date& date) {
		return (this->JDate >= date.JDate);
	}
	bool operator<(const Date& date) {
		return (this->JDate < date.JDate);
	}
	bool operator<=(const Date& date) {
		return (this->JDate <= date.JDate);
	}
	Date operator+(int inputDays) {
		GDate(this->JDate + inputDays, this->year, this->month, this->day);
		return *this;
	}
	Date operator-(int inputDays) {
		GDate(this->JDate - inputDays, this->year, this->month, this->day);
		return *this;
	}
	Date& operator=(const Date& date) {
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
		return *this;
	}
};

ostream& operator<<(ostream& out, Date& date) {
	return out << date.day << '.' << date.month << '.' << date.year << endl;
}
istream& operator>>(istream& input, Date& date) {
	return input >> date.inputDate;
}

Date::Date(string date) {
	if (split(date, separator) == 3) {
		day = stoi(splitDate[0]);
		month = stoi(splitDate[1]);
		year = stoi(splitDate[2]);
		if (month <= 2) {
			year--;
			month += 12;
		};
		int A = year / 100;
		A = 2 - A + (A / 4);
		JDate = 1461L * long(year);
		JDate /= 4L;
		unsigned long K = 306001L * long(month + 1);
		K /= 10000L;
		JDate += K + day + 1720995L + A;
	}
	else {
		cout << "Дата введена неправильно!" << endl;
		exit(EXIT_FAILURE);
	}

}

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

int main() {
	setlocale(LC_ALL, "Russian");

	string DATE1;
	string DATE2;
	int countDays;

	cout << "Введите первую дату(ДЕНЬ.МЕСЯЦ.ГОД):" << endl;
	cin >> DATE1;
	cout << "Введите вторую дату(ДЕНЬ.МЕСЯЦ.ГОД):" << endl;
	cin >> DATE2;
	cout << "Введите количество дней, которые хотите вычесть/сложить с первой датой:" << endl;
	cin >> countDays;

	Date test1(DATE1);
	Date test2(DATE2);

	Date resMinus = test1 - countDays;
	Date resPlus = test1 + countDays;
	cout << "Результат вычитания: " << resMinus << endl;
	cout << "Результат сложения: " << resPlus << endl;

	if (test1 == test2)
	{
		cout << "Даты равны" << endl;
	}
	else
	{
		cout << "Даты не равны" << endl;
	}
	return 0;
}