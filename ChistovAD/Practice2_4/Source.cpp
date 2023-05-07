#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Container.h"
using namespace std;

string get_path() {
	string path;
	do {
		cout << "Enter the file path:";
		cin >> path;
		ifstream in(path);
		if (!in.is_open()) {
			cout << "Ooops.....Something went wrong......" << endl;
		}
		else {
			in.close();
			return path;
		}
	} while (true);
}

int amount(const string& path)
{
	fstream file;
	file.open(path);
	string line;
	int count{ 0 };
	ifstream in(path);
	while (getline(in, line))
	{
		if (line != "\0") {
			count++;
		}
	}
	in.close();
	return count;
}

//void menu() {
//	cout << "MENU:" << endl;
//	cout << "1.Scan a product" << endl;
//	cout << "2.Delete a product" << endl;
//	cout << "3.Add next product" << endl;
//	cout << "4.Calculate the amount" << endl;
//	cout << "5.Finish shopping" << endl;
//	cout << "6.New check" << endl;
//	cout << "Your choice:";
//	int answer1;
//	cin >> answer1;
//	switch (answer1) {
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//	case 6:
//	}
//}

void time() {
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
}


//Container::TContainer(int max_size, int step, const string& path) {
//	this->max_size = amount(path);
//	this->step = step;
//	element = new elements[this->max_size];
//
//
//}