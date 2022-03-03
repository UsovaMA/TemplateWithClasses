#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;
class Weight {
private:
	float mass;
	string type;
	vector<string> splitMass;
	const string separator = " ";
	string inputWeight;
public:
	Weight(float mass, string type);
	Weight(float mass);
	Weight();
	void split(string str, string regex);
	float getMass();
	string getType();
	float fromKgtoGramm(float mass);
	float fromPoundtoGramm(float mass);
	friend ostream& operator<<(ostream& out, Weight& weight);
	friend istream& operator>>(istream& input, Weight& weight);
	bool operator==(const Weight& weight) {

	}
	bool operator!=(const Weight& weight) {

	}
	bool operator>(const Weight& weight) {
		if (this->mass > weight.mass) return true;
		else return false;
	}
	bool operator>=(const Weight& weight) {
		if (this->mass >= weight.mass) return true;
		else return false;
	}
	bool operator<(const Weight& weight) {
		if (this->mass < weight.mass) return true;
		else return false;
	}
	bool operator<=(const Weight& weight) {
		if (this->mass <= weight.mass) return true;
		else return false;
	}
};

ostream& operator<<(ostream& out, Weight& waight) {
	return out << waight.getMass() << ' ' << waight.getType() << endl;
}
istream& operator>>(istream& input, Weight& waight) {
	return input >> waight.inputWeight;
}

float Weight::fromKgtoGramm(float mass) {
	return mass * 1000.0;
}
float Weight::fromPoundtoGramm(float mass) {
	return mass * 453.5;
}
Weight::Weight(float mass, string type) {
	if (type == "kg") {
		this->mass = Weight::fromKgtoGramm(mass);
	}
	if (type == "pound") {
		this->mass = Weight::fromPoundtoGramm(mass);
	}
}
Weight::Weight(float mass) {

}
Weight::Weight() {

}
void Weight::split(string str, string regex) {
	vector<string> res;
	int start = 0;
	int end;
	do {
		end = str.find(regex);
		res.push_back(str.substr(start, end - start));
		str = str.substr(end + 1, str.size() - 1);
	} while (end != -1);
	Weight::mass = stof(res[0]);
	Weight::type = res[1];
}
float Weight::getMass() {
	return Weight::mass;
}
string Weight::getType() {
	return Weight::type;
}

void main() {

}