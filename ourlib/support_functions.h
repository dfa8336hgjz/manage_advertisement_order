#pragma once
#include <bits/stdc++.h>
using namespace std;

//result approximation
long long rounding(long long a) {
	if (a % 1000 != 0 && a >= 1000) {
		a += 500;
		a /= 1000;
		a *= 1000;
	}
	return a;
}
// pause screen function
void pause(int a) {
	cout << " Type \"enter\" to go back";
	cin.ignore(a);
}
// string condition
bool is_letter(char a) {
	int b = a;
	if ((b >= 65 && b <= 90) || (b <= 122 && b >= 97)) {
		return true;
	}
	return false;
}
bool is_number(char a) {
	int b = a;
	if (b >= 48 && b <= 57) return true;
	return false;
}
bool is_valid(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (is_letter(a[i]) == false && is_number(a[i]) == false && a[i] != ' ') {
			return false;
		}
	}
	return true;
}
// string handling
void delete_space(string& a) {
	int i = 0;
	while (a[i] == ' ' && i < a.length()) {
		a.erase(i, 1);
	} //delete space on the head of string
	while (i < a.length()) {
		if (a[i] == ' ' && a[i + 1] == ' ') {
			a.erase(i, 1);
		}
		else i++;
	} //delete space in the middle of string
	i = a.length() - 1;
	while (i >= 0 && a[i] == ' ') {
		a.erase(i, 1);
	} //delete space at the bottom of string
}
void capitalize(string& a) {
	a[0] = toupper(a[0]);
	int i = 1;
	while (i < a.length()) {
		if (a[i - 1] == ' ' && a[i] != ' ') {
			a[i] = toupper(a[i]);
		}
		else a[i] = tolower(a[i]);
		i++;
	}
}
string standardlize(string a) {
	delete_space(a); // to delete all redundant spaces
	capitalize(a); // to capitalize the first character of each word
	return a;
}
string lowercase(string a) {
	for (int i = 0; i < a.length(); i++)
	{
		a[i] = tolower(a[i]);
	}
	return a;
}
// enter with condition function
void enter(string& a) {
	getline(cin, a);
	bool check = false; // to check if the condition has been satisfied or not
	while (!check) {
		// case 1: string has special symbol
		if (!is_valid(a)) {
			cout << " The string you enter is not valid!!! Please enter again: ";
			getline(cin, a);
		}
		//case 2: only press enter 
		else if (a.length() == 0) {
			cout << " You haven't type anything!!! Please enter again: ";
			getline(cin, a);
		}
		//case 3: satisfied
		else check = true;
	}
	a = standardlize(a);
}
template <class kdl> void enter(kdl& a) {
	cin >> a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << " Invalid input. Enter again: " ;
		cin >> a;
	}
}
//print the price of each order in a formal way
string formal_price(long long a) {
	string price = "";
	int i = 0;
	while (a != 0) {
		i++;
		int num = a % 10;
		a /= 10;
		price.insert(0, 1, char(num + 48));
		if (i % 3 == 0 && a != 0) price.insert(0, 1, ',');
	}
	return price;
}