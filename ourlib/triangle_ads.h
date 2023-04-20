#pragma once
#include "ads.h"
using namespace std;

class triangle_ads : public ads {
private:
	bool check(double a, double b, double c) {
		if (a + b > c && b + c > a && c + a > b) return true;
		else return false;
	} //using triangle inequality
public:
	triangle_ads() : ads() {
		shape = "triangle";
	};

	void set_area() {
		system("cls");
		double a, b, c;
		do {
			cout << "Enter the length of 1st side: ";
			enter(a);
			cout << "Enter the length of 2nd side: ";
			enter(b);
			cout << "Enter the length of 3rd side: ";
			enter(c);
			if (check(a, b, c) == true) break;
			else cout << "These are not the suitable length for a triangle. Please enter again\n";
		} while (true);

		double p = (a + b + c) / 2;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
	}
	void set_price() {
		price = rounding((long long)(priceof1m * area) + 500000);
	}
};