#pragma once
#include "advertisement.h"

class ads_node {
public:
	ads *value;
	ads_node* next;

	//constructor
	ads_node(ads* a) {
		value = a;
		next = NULL;
	}
};

class order_list {
public:
	// head of the list
	ads_node* head;

	//constructor
	order_list() {
		head = NULL;
	};
	//destructor
	~order_list();

	bool is_empty() {
		return head == NULL;
	}
	void add(ads* a); // add an order to the list
	void del(); //delete an order from the list
	ads_node* find(); // find an order 
	void print(); // print the list
	void print_10m(); // print all the orders whose installation costs greater than 10 million VND
	void print_inputarea(double a); // print all the orders whose area larger than 'a'
};

//class order_list
order_list::~order_list() {
	ads_node* run = head;
	while (run != NULL) {
		ads_node* cur = run;
		run = run->next;
		delete cur->value;
		delete cur;
	}
}
void order_list::add(ads* a) {
	ads_node* new_node = new ads_node(a);
	if (is_empty()) {
		head = new_node;
	}
	else {
		ads_node* cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = new_node;
	}
}

void order_list::del() {
	system("cls");
	if (this->is_empty()) {
		cout << "There is no order in the list!" << endl;
		pause(2);
		return;
	}
	string name, shape, address;
	cin.ignore(1000, '\n');
	cout << "Enter your name : ";
	enter(name);
	cout << "Enter your address: ";
	enter(address);
	cout << "Enter your advertisement's shape: ";
	enter(shape);
	delete_space(shape);
	ads a(standardlize(name), standardlize(address), lowercase(shape));
	int count = 0;
	ads_node* cur = head;
	while (cur != NULL) {
		if (*(cur->value) == a) {
			count++;
		}
		cur = cur->next;
	}
	if (count == 0) {
		cout << "This order does not exist!" << endl;
		pause(1);
		return;
	}
	else if (count == 1) {
		cur = head;
		if (a == *head->value) head = head->next;
		else {
			ads_node* prev = NULL;
			while (cur != NULL) {
				if (*(cur->value) == a && prev != NULL) {
					prev->next = cur->next;
					break;
				}
				prev = cur;
				cur = cur->next;
			}
		}
		cout << "Your order has been deleted!" << endl;
		pause(1);
		return;
	}
	else {
		system("cls");
		ads_node* cur = head;
		bool title_printed = false;
		int i1 = 1, i2;
		while (cur != NULL) {
			if (*(cur->value) == a) {
				if (!title_printed)
				{
					cout << setw(4) << left << "ID" << setw(30) << left << "Name" << setw(20) << left << "Address" << setw(15) << left << "Shape" << setw(20) << left << "Area (m^2)" << setw(20) << right << "Price (VND)" << endl;
					cout << setfill('-') << setw(120) << " " << setfill(' ') << endl;

					title_printed = true;
				}
				cout << setw(4) << left << i1++ << setw(30) << left << cur->value->get_name() << setw(20) << left << cur->value->get_address() << setw(15) << left << cur->value->get_shape() << setw(20) << left << setprecision(6) << (double)cur->value->get_area() << setw(20) << right << formal_price(cur->value->get_price()) << endl;
			}
			cur = cur->next;
		}
		cout << "Enter your order's ID: ";

		enter(i2);
		while (i2 > i1 - 1 || i2 < 0) {
			cout << "Invalid input. Enter again: ";
			enter(i2);
		}
		cin.ignore();
		if (a==*(head->value) && i2==1) head = head->next;
		else {
			cur = head;
			ads_node* prev = NULL;
			while (cur != NULL) {
				if (*(cur->value) == a) {
					if (i2 == 1) {
						prev->next = cur->next;
						break;
					}
					else {
						i2--;
					}
				}
				prev = cur;
				cur = cur->next;
			}
		}
		cout << "Your order has been deleted!" << endl;
		pause(1);
		return;
	}
	

}
ads_node* order_list::find() {
	system("cls");
	string name, shape, address;
	cin.ignore(1000, '\n');
	cout << "Enter your name : ";
	enter(name);
	cout << "Enter your address: ";
	enter(address);
	cout << "Enter your advertisement's shape: ";
	enter(shape);
	delete_space(shape);
	ads a(standardlize(name), standardlize(address), lowercase(shape));
	int count = 0;
	ads_node* cur = head;
	ads_node* result = NULL;
	while (cur != NULL) {
		if (*(cur->value) == a) {
			count++;
			result = cur;
		}
		cur = cur->next;
	}
	if (count == 0) {
		cout << "This order does not exist!" << endl;
		return NULL;
	}
	else if (count == 1) {
		return result;
	}
	else {
		system("cls");
		ads_node* cur = head;
		bool title_printed = false;
		int i1 = 1, i2;
		while (cur != NULL) {
			if (*(cur->value)== a) {
				if (!title_printed)
				{
					cout << setw(4) << left << "ID" << setw(30) << left << "Name" << setw(20) << left << "Address" << setw(15) << left << "Shape" << setw(20) << left << "Area (m^2)" << setw(20) << right << "Price (VND)" << endl;
					cout << setfill('-') << setw(120) << " " << setfill(' ') << endl;
					
					title_printed = true;
				}
				cout << setw(4) << left << i1++ << setw(30) << left << cur->value->get_name() << setw(20) << left << cur->value->get_address() << setw(15) << left << cur->value->get_shape() << setw(20) << left << setprecision(6) << (double)cur->value->get_area() << setw(20) << right << formal_price(cur->value->get_price()) << endl;
			}
			cur = cur->next;
		}
		cout << "Enter your order's ID: ";

		cin >> i2;
		while (i2 > i1 - 1 || i2 < 0) {
			cout << "Invalid input. Enter again: ";
			cin >> i2;
		} 
		cin.ignore();
		cur = head;
		while (cur != NULL) {
			if (*(cur->value) == a ) {
				if (i2 == 1) {
					return cur;
				}
				else i2--;
			}
			cur = cur->next;
		}
		system("cls");
	}
}
void order_list::print() {
	system("cls");
	if (is_empty()) {
		cout << "List is empty!" << endl;
	}
	else {
		ads_node* cur = head;
		int i = 1; // to print in an order (ID)
		cout << setw(4) << left << "ID" << setw(30) << left << "Name" << setw(20) << left << "Address" << setw(15) << left << "Shape" << setw(20) << left << "Area (m^2)" << setw(20) << right << "Price (VND)" << endl;
		cout << setfill('-') << setw(120) << " " << setfill(' ') << endl;
		while (cur != NULL) {
			cout << setw(4) << left << i++ << setw(30) << left << cur->value->get_name() << setw(20) << left << cur->value->get_address() << setw(15) << left << cur->value->get_shape() << setw(20) << left << setprecision(6) << (double)cur->value->get_area() << setw(20) << right << formal_price(cur->value->get_price()) << endl;
			cur = cur->next;
		}
	}
	pause(2);
}
void order_list::print_10m() {
	system("cls");
	ads_node* cur = head;
	bool title_printed = false;
	int i = 0;
	while (cur != NULL) {
		if (cur->value->get_price() > 10000000) {
			if (!title_printed)
			{
				cout << setw(30) << left << "Name" << setw(20) << left << "Address" << setw(15) << left << "Shape" << setw(6) << left << "Area (m^2)" << setw(20) << right << "Price (VND)" << endl;
				cout << setfill('-') << setw(120) << " " << setfill(' ') << endl;
				title_printed = true;
			}
			i++;
			cout << setw(30) << left << cur->value->get_name() << setw(20) << left << cur->value->get_address() << setw(15) << left << cur->value->get_shape() << setw(6) << left << setprecision(4) << (double)cur->value->get_area() << setw(20) << right << formal_price(cur->value->get_price()) << endl;
		}
		cur = cur->next;
	}
	if (i == 0)
	{
		cout << "There is no order with installation costs greater than 10 million VND" << endl;
	}
	pause(2);
	return;
}
void order_list::print_inputarea(double a) {
	system("cls");
	ads_node* cur = head;
	bool title_printed = false;
	int i = 0;
	while (cur != NULL) {
		if (cur->value->get_area() > a) {
			if (!title_printed)
			{
				cout << setw(30) << left << "Name" << setw(20) << left << "Address" << setw(15) << left << "Shape" << setw(6) << left << "Area (m^2)" << setw(20) << right << "Price (VND)" << endl;
				cout << setfill('-') << setw(120) << " " << setfill(' ') << endl;
				title_printed = true;
			}
			i++;
			cout << setw(30) << left << cur->value->get_name() << setw(20) << left << cur->value->get_address() << setw(15) << left << cur->value->get_shape() << setw(6) << left << setprecision(4) << cur->value->get_area() << setw(20) << right << formal_price(cur->value->get_price()) << endl;
		}
		cur = cur->next;
	}
	if (i == 0)
	{
		cout << "There is no order with a  billboard  area larger than " << a << " m^2 !!!" << endl;
	}
	pause(2);
	return;
}