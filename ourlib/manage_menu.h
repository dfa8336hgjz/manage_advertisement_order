#pragma once
#include "list.h"
#include "support_functions.h"

class manage {
private:
	order_list* main_list;
public:
	manage(order_list* a) {
		main_list = a;
	}
	void menu();
	void submenu1();
	void submenu1_1();
	void submenu1_2(ads_node* a);
	void submenu1_3();
	void submenu2();
	void submenu3();
	void submenu4();
	void change_area(ads_node* a);
	void change_shape(ads_node* a, string shape);
};

void manage::menu() {
	system("cls");
	int choice = 0;
	cout << "             ***********************************************************************************************\n";
again:
	cout << "                                       +----------------------------------------+\n";
	cout << "                                       | ADVERTISEMENTS ORDER MANAGEMENT SYSTEM |\n";
	cout << "                                       +----------------------------------------+\n";
	cout << "                                                   |    MAIN MENU    |\n";
	cout << "             ***********************************************************************************************\n";
	cout << "             |                                                                                             |\n";
	cout << "             |         1. Add, edit or delete an order                                                     |\n";
	cout << "             |         2. Search for an order                                                              |\n";
	cout << "             |         3. Search  for  orders  with  a  billboard  area larger than 1 input number         |\n";
	cout << "             |         4. Statistics of orders  with installation costs greater than 10 million VND        |\n";
	cout << "             |         5. Show the order list                                                              |\n";
	cout << "             |         6. Exit                                                                             |\n";
	cout << "             |                                                                                             |\n";
	cout << "             ***********************************************************************************************\n";
	cout << "                                              ENTER YOUR NUMBER OF OPTION: ";
	cin >> choice;
	switch (choice)
	{
	case(1):
		submenu1();
		break;
	case(2):
		submenu2();
		break;
	case(3):
		submenu3();
		break;
	case(4):
		submenu4();
		break;
	case(5):
		main_list->print();
		menu();
		break;
	case(6):
		exit(0);
		break;
	default:
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			system("cls");
			cout << "             ************************************ Please type a number!!! ***********************************\n";
			goto again;
		}
		system("cls");
		cout << "             *********************************** Invalid option number!!! ***********************************\n";
		goto again;
		break;
	}
	return;
}
void manage::submenu1() {
	system("cls");
	int choice = 0;
	cout << "             *********************************************************************************************\n";
again:
	cout << "\n                                      MAIN OPTION 1: Add, edit or delete an order\n";
	cout << "             ***********************************************************************************************\n";
	cout << "             |                                                                                             |\n";
	cout << "             |         1. Add an order                                                                     |\n";
	cout << "             |         2. Edit an order                                                                    |\n";
	cout << "             |         3. Delete an order                                                                  |\n";
	cout << "             |         4. Return                                                                           |\n";
	cout << "             |                                                                                             |\n";
	cout << "             ***********************************************************************************************\n";
	cout << "                                              ENTER YOUR NUMBER OF OPTION: ";
	cin >> choice;

	if (choice == 1)
	{
		submenu1_1();
	}

	else if (choice == 2 )
	{
		if (main_list->is_empty()) {
			system("cls");
			cout << "There is no order in the list!" << endl;
			pause(2);
			submenu1();
		}
		ads_node* a = main_list->find();
		if (a == NULL) {
			pause(1);
			submenu1();
		}
		else {
			if (choice == 2) submenu1_2(a);
		}
	}
	else if (choice == 3) {
		submenu1_3();
	}
	else if (choice == 4)
	{
		menu();
	}
	else {
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			system("cls");
			cout << "             ************************************ Please type a number!!! **********************************\n";
			goto again;
		}
		system("cls");
		cout << "             *********************************** Invalid option number!!! **********************************\n";
		goto again;
	}
}
void manage::submenu1_1() {
	system("cls");
	int choice = 0;
	cout << "             ***********************************************************************************************\n";
again:
	cout << "\n                                                 OPTION 1.1: Add an order\n";
	cout << "             ***********************************************************************************************\n";
	cout << "             |                                                                                             |\n";
	cout << "             |         WHICH SHAPE OF ADVERTISEMENT DO YOU WANT?                                           |\n";
	cout << "             |         1. Triangle                                                                         |\n";
	cout << "             |         2. Circle                                                                           |\n";
	cout << "             |         3. Rectangle                                                                        |\n";
	cout << "             |         4. Rhombus                                                                          |\n";
	cout << "             |         5. Other                                                                            |\n";
	cout << "             |         6. Return                                                                           |\n";
	cout << "             |                                                                                             |\n";
	cout << "             ***********************************************************************************************\n";
	cout << "                                              ENTER YOUR NUMBER OF OPTION: ";
	cin >> choice;
	bool check;
	ads* new_order=NULL;
	if (choice == 1)
	{
		triangle_ads *a=new triangle_ads;
		check=a->set_infor();
		new_order = a;
		if (check) {
			main_list->add(new_order);
		}
		else submenu1_1();
	}
	else if (choice == 2)
	{
		circle_ads *a=new circle_ads;
		check = a->set_infor();
		new_order = a;
		if (check) {
			main_list->add(new_order);
		}
		else submenu1_1();
	}
	else if (choice == 3)
	{
		rectangle_ads *a=new rectangle_ads;
		check = a->set_infor();
		new_order = a;
		if (check) {
			main_list->add(new_order);
		}
		else submenu1_1();
	}
	else if (choice == 4)
	{
		rhombus_ads *a=new rhombus_ads;
		check = a->set_infor();
		new_order = a;
		if (check) {
			main_list->add(new_order);
		}
		else submenu1_1();
	}
	else if (choice == 5)
	{
		ads *a=new ads;
		system("cls");
		string shape;
		cout << " Enter your advertisement's shape: ";
		cin.ignore();
		getline(cin, shape);
		standardlize(shape);
		a->set_shape(shape);
		check = a->set_infor();
		new_order = a;
		if (check) {
			main_list->add(new_order);
		}
		else submenu1_1();
	}
	else if (choice == 6)
	{
		submenu1();
	}
	else {
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			system("cls");
			cout << "             ************************************ Please type a number!!! **********************************\n";
			goto again;
		}
		system("cls");
		cout << "             *********************************** Invalid option number!!! **********************************\n";
		goto again;
	}

	// just for fun :)))
	cout << "Loading ";
	for (int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(300);
	}
	cout << "Data has been saved!!!\n";
	pause(1);
	menu();
}
void manage::submenu1_2(ads_node* a) {
	system("cls");
	int choice = 0;
	cout << "             ***********************************************************************************************\n";
again:
	cout <<setw(75) << right << "Your order's information: " << endl;
	a->value->detail();
	cout << "\n                                                   OPTION 1.2: Edit order\n";
	cout << "             ***********************************************************************************************\n";
	cout << "             |                                                                                             |\n";
	cout << "             |         WHICH COMPONENT OF ORDER DOES YOU WANT TO EDIT?                                     |\n";
	cout << "             |         1. Name                                                                             |\n";
	cout << "             |         2. Address                                                                          |\n";
	cout << "             |         3. Area                                                                             |\n";
	cout << "             |         4. Shape (also change order's area)                                                 |\n";
	cout << "             |         5. Return                                                                           |\n";
	cout << "             |                                                                                             |\n";
	cout << "             ***********************************************************************************************\n";
	cout << "                                              ENTER YOUR NUMBER OF OPTION: ";
	cin >> choice;

	if (choice == 1)
	{
		system("cls");
		string name;
		cout << "Enter new name: ";
		cin.ignore();
		enter(name);
		a->value->set_name(name);
		cout << "Your name has been changed into " << standardlize(name) << "!" << endl;
		pause(1);
	}
	else if (choice == 2)
	{
		system("cls");
		string address;
		cout << "Enter new address: ";
		cin.ignore();
		enter(address);
		a->value->set_address(address);
		cout << "Your address has been changed into " << standardlize(address) << "!" << endl;
		pause(1);
	}
	else if (choice == 3)
	{
		change_area(a);
	}
	else if (choice == 4)
	{
		system("cls");
		string shape;
		cout << "Enter new shape: ";
		cin.ignore();
		enter(shape);
		change_shape(a, shape);
	}
	else if (choice == 5)
	{
	}
	else {
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			system("cls");
			cout << "             ************************************ Please type a number!!! **********************************\n";
			goto again;
		}
		system("cls");
		cout << "             *********************************** Invalid option number!!! **********************************\n";
		goto again;
	}
	submenu1();
}

void manage::submenu1_3() {
	main_list->del();
	submenu1();
}

void manage::submenu2() {
	system("cls");
	if (main_list->is_empty()) {
		cout << "There is no order here!" << endl;
		pause(2);
	}
	else {
		ads_node* a = main_list->find();
		if (a != NULL) {
			system("cls");
			a->value->detail();
		}
		pause(1);
	}
	menu();
}
void manage::submenu3() {
	system("cls");
	if (main_list->is_empty()) {
		cout << "There is no order here!" << endl;
		pause(2);
	}
	else {
		cout << "Enter the area: ";
		float a;
		enter(a);
		main_list->print_inputarea(a);
	}
	menu();
}
void manage::submenu4() {
	system("cls");
	if (main_list->is_empty()) {
		cout << "There is no order here!" << endl;
		pause(2);
	}
	else {
		main_list->print_10m();
	}
	menu();
}

//definition of functions for edit option
void manage::change_area(ads_node* a) {
	a->value->set_area();
	cout << "Your order's area has been changed!!!" << endl;
	pause(2);
}
void manage::change_shape(ads_node* a, string shape) {
	//replace old object by a new one with changed data
	delete_space(shape);
	shape = lowercase(shape);
	if (shape == "triangle") {
		triangle_ads *replace_node=new triangle_ads;
		replace_node->copy(a->value);
		replace_node->set_shape(shape);
		delete a->value;
		a->value = replace_node;
	}
	else if (shape == "rectangle") {
		rectangle_ads* replace_node = new rectangle_ads;
		replace_node->copy(a->value);
		replace_node->set_shape(shape);
		delete a->value;
		a->value = replace_node;
	}
	else if (shape == "rhombus") {
		rhombus_ads* replace_node = new rhombus_ads;
		replace_node->copy(a->value);
		replace_node->set_shape(shape);
		delete a->value;
		a->value = replace_node;
	}
	else if (shape == "circle") {
		circle_ads* replace_node = new circle_ads;
		replace_node->copy(a->value);
		replace_node->set_shape(shape);
		delete a->value;
		a->value = replace_node;
	}
	else {
		ads* replace_node = new ads;
		replace_node->copy(a->value);
		replace_node->set_shape(shape);
		delete a->value;
		a->value = replace_node;
	}
	cout << "Your order's shape has been changed!!!" << endl;
	pause(2);
}