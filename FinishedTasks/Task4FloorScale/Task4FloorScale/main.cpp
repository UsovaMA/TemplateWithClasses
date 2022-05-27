#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

class Observation {
private:
	string name;
	double kg;
	double gr;
	int firstDay;
	int firstMonth;
	int firstYear;
	int day;
	int month;
	int year;
public:
	Observation();
	~Observation();

	string getName();
	int getKg();
	int getGr();
	int getDay();
	int getMonth();
	int getYear();
	void setName(string name);
	void randKg();
	void randGr();
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int startDay();
	int startMonth();
	int startYear();
};

Observation::Observation() {
	firstDay = 1;
	firstMonth = 1;
	firstYear = 2022;
}

Observation::~Observation() {

}

string Observation::getName() {
	return name;
}

int Observation::getKg() {
	return kg;
}

int Observation::getGr() {
	return gr;
}

int Observation::getDay() {
	return day;
}

int Observation::getMonth() {
	return month;
}

int Observation::getYear() {
	return year;
}

void Observation::setName(string newName) {
	name = newName;
}

void Observation::randKg() {
	kg = 50 + rand() % 110;
}

void Observation::randGr() {
	gr = 1 + rand() % 50;
}

void Observation::setDay(int newDay) {
	day = newDay;
}

void Observation::setMonth(int newMonth) {
	month = newMonth;
}

void Observation::setYear(int newYear) {
	year = newYear;
}

int Observation::startDay() {
	return firstDay;
}

int Observation::startMonth() {
	return firstMonth;
}

int Observation::startYear() {
	return firstYear;
}


class FloorScales {
private:
	vector<Observation> observations;
	string name;
	int day;
	int month;
	int year;
	int kg;
	int gr;
public:
	FloorScales();
	~FloorScales();
	void startDate();
	void addObservation();
	void findWeight();
	void MinWeight(int var);
	void MaxWeight(int var);
	void MidWeight(int var);
	void addInf();
};

FloorScales::FloorScales() {

}

FloorScales::~FloorScales() {

}

void FloorScales::addInf() {
	cout << "Введите имя: ";
	cin >> name;
	cout << "Введите день: ";
	cin >> day;
	cout << "Введите месяц: ";
	cin >> month;
	cout << "Введите год: ";
	cin >> year;
}

void FloorScales::startDate() {
	Observation temp;
	cout << "Начальная дата наблюдений: " << temp.startDay() << "." << temp.startMonth() << "." << temp.startYear() << endl;
}

void FloorScales::addObservation() {
	Observation observation = Observation();
	Observation temp;
	bool flag = true;

	addInf();

	observation.setName(name);

	for (int i = 0; i < observations.size(); i++) {
		temp = observations.at(i);
		if (temp.getName() == name)
			if (temp.getDay() == day)
				if (temp.getMonth() == month)
					if (temp.getYear() == year) {
						temp.randKg();
						temp.randGr();
						cout << "Ваш новый вес: " << temp.getKg() << "кг " << temp.getGr() << "гр" << endl;
						flag = false;
					}
	}
	if (flag) {
		observation.setDay(day);
		observation.setMonth(month);
		observation.setYear(year);
		observation.randKg();
		observation.randGr();
		cout << "Ваш вес: " << observation.getKg() << "кг " << observation.getGr() << "гр" << endl;
	}
	observations.push_back(observation);
}

void FloorScales::findWeight() {
	Observation temp;
	bool flag = true;

	addInf();

	for (int i = 0; i < observations.size(); i++) {
		temp = observations.at(i);
		if (temp.getName() == name)
			if (temp.getDay() == day)
				if(temp.getMonth() == month)
					if (temp.getYear() == year) {
						cout << "На введенную дату ваш вес сотсавлял: " << temp.getKg() << "кг " << temp.getGr() << "гр" << endl;
						flag = false;
					}
	}
	if (flag) {
		cout << "На введенную дату нет показаний!" << endl;
	}
}

void FloorScales::MinWeight(int var) {
	if (var == 1) {

	}
	else if (var == 2) {

	}
	else {

	}
}

void FloorScales::MidWeight(int var) {
	if (var == 1) {

	}
	else if (var == 2) {

	}
	else {

	}
}

void FloorScales::MaxWeight(int var) {
	if (var == 1) {

	}
	else if (var == 2) {

	}
	else {

	}
}




int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	FloorScales s = FloorScales();
	s.startDate();
	s.addObservation();
	s.findWeight();

	return 0;
}