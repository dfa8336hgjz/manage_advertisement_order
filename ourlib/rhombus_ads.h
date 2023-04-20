#pragma once
#include "ads.h"
using namespace std;

class rhombus_ads : public ads {
public:
	rhombus_ads() : ads() {
		shape = "rhombus";
	};
	void set_area() {
		system("cls");
		double a, b;
		cout << "Enter the length of 1st diagonal: ";
		enter(a);
		cout << "Enter the length of 2nd diagonal: ";
		enter(b);
		area = a * b / 2;
	}
};