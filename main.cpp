#include <bits/stdc++.h>
#include <Windows.h>
#include "ourlib/manage_menu.h"
#include "ourlib/list.h"
using namespace std;

// MAIN
int main() {
	order_list main_list;
	manage main_menu(&main_list);
	system("Color A");
	main_menu.menu();
}


/*This program does not work on Linux/Mac systems (because of the Windows.h library)
* Members:
* Phung Minh Chien
* Mai Thanh Vinh
* Nguyen Phuc Thanh
* Nguyen Dinh Thuan 
*/