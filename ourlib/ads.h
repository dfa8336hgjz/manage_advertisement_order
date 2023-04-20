#pragma once
#include <bits/stdc++.h>
#include "support_functions.h"
using namespace std;

class ads {
protected:
	string shape;  //shape of advertisement
	string customer_name; //name of customer
	string address; //address of customer
	double area; //area of the advertisement
	long long priceof1m; //price of 1 meter square
	long long price; //total price 

public:
	// constructors
	ads();
	ads(string name, string address, string shape);

	void detail(); //detail of an order
	bool operator==(const ads a); // to check if 2 object has same name, address and shape
	void copy(ads *a); // to support for edit functions

	//// setters and getters
	virtual void set_area(); // can be changed according to the shape
	double get_area() {
		return area;
	}
	long long get_price() {
		return price;
	}
	virtual void set_price(); // with circle and triangle ads, installation cost will increase by 500000VND 
	string get_name() {
		return customer_name;
	}
	void set_name(string name) {
		customer_name = standardlize(name);
	}
	string get_address() {
		return address;
	}
	void set_address(string address) {
		this->address = standardlize(address);
	}
	string get_shape() {
		return shape;
	}
	void set_shape(string shape) {
		this->shape = shape;
	}
	bool set_infor();

};
ads::ads() {
	shape = "";
	customer_name = "";
	address = "";
	area = 0;
	priceof1m = 50000;
}


ads::ads(string name, string address, string shape) {
	standardlize(name);
	standardlize(address);
	standardlize(shape);
	this->shape = shape;
	this->customer_name = name;
	this->address = address;
	this->area = 0;
	this->priceof1m = 50000;
}
void ads::set_area() {
	cout << "Enter your advertisement's area: ";
	enter(area);
};
void ads::set_price() {
	price = rounding((long long)(priceof1m * area));
}
void ads::detail() {
	cout << setw(45) << " " << "Customer's name: " << customer_name << endl;
	cout << setw(45) << " " << "Address: " << address << endl;
	cout << setw(45) << " " << "Order's detail:" << endl;
	cout << setw(45) << " " << "\tShape: " << shape << endl;
	cout << setw(45) << " " << "\tArea: " << area << " m^2" << endl;
	cout << setw(45) << " " << "\tPrice: " << formal_price(price) << " VND" << endl;
}
bool ads::set_infor() {
	set_area();
	set_price();
	int choice = 0;
	// calculate and print the price for confirmation
	system("cls");
	cout << " Your order will cost " << get_price() << " VND. Do you want to confirm your order?" << endl;
	cout << "\t1. Yes\n\t2. No\n Enter your option: ";
again:
	enter(choice);
	if (choice == 2)
	{
		return false;
	}
	else if (choice != 1) {
		// typing condition
		cout << " Please type only 1 or 2. Type again: ";
		goto again;
	}
	else {
		// enter personal information to confirm the order
		system("cls");
		cin.ignore();
		cout << "Enter your name: ";
		enter(this->customer_name);
		cout << "Enter your address: ";
		enter(this->address);
		return true;
	}
}
void ads::copy(ads *a) {
	this->set_area();
	this->set_price();
	this->customer_name = a->customer_name;
	this->address = a->address;
}
bool ads::operator==(const ads a) {
	if (this->customer_name == a.customer_name && this->address == a.address && this->shape == a.shape) return true;
	return false;
}
