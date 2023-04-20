#pragma once
#include "ads.h"
using namespace std;

class circle_ads : public ads {
public:

	circle_ads() : ads() {
		shape = "circle";
	};
	
	void set_area() {
		system("cls");
		double r;
		cout << "Enter the length of radius: ";
		enter(r);
		area = r * r * 3.14;
	}

	void set_price() {
		price = rounding((long long)(priceof1m * area) + 500000);
	}
};