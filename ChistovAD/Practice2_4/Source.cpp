#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
#include "Header.h"
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

int Container::amount(const string& path)
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

//labor::labor(const string& path) {
//	this->n = amount(path);
//	this->w = new worker[n];
//	fstream file;
//	string   id, profession, education, last_job, rsn_dismiss, family_status;
//	int  contact_info;
//	file.open(path);
//	int i = 0, j = 0;
//	string line, s;
//	ifstream in(path);
//	while (getline(in, line))
//	{
//		if (line == "\0") {
//			continue;
//		}
//		stringstream ss(line);
//		while (getline(ss, s, ';')) {
//			switch (i) {
//			case 0:
//				barcode = s;
//				break;
//			case 1:
//				name = s;
//				break;
//			case 2:
//				price = s;
//				break;
//			case 3:
//				count = s;
//				w[j].adding(id, profession, education, last_job, rsn_dismiss, family_status, contact_info);
//				j++;
//				i = -1;
//				break;
//			}
//			i++;
//		}
//	}
//	in.close();
//}



void menu() {
	cout << "MENU:" << endl;
	cout << "1.Scan a product" << endl;
	cout << "2.Delete a product" << endl;
	cout << "3.Add next product" << endl;
	cout << "4.Calculate the amount" << endl;
	cout << "5.Finish shopping" << endl;
	cout << "6.New check" << endl;
	cout << "Your choice:";
	int answer1;
	cin << answer1;
	switch (answer1) {
	case 1: 
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	
	
	}
}

void time (){
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "The local date and time is: " << dt << endl;
}
TContainer::TContainer(int max_size, int step,const string& path) {
	this->max_size = amount(path);
	this->step = step;
	element = new elements[this->max_size];


}

