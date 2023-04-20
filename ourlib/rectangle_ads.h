#pragma once
#include "ads.h"
using namespace std;

class rectangle_ads : public ads {
public:
	rectangle_ads() : ads() {
		shape = "rectangle";
	};
	void set_area() {
		system("cls");
		double a, b;
		cout << "Enter your advertisement's length: ";
		enter(a);
		cout << "Enter your advertisement's width: ";
		enter(b);
		area = a * b;
	}
};