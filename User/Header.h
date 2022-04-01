#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

void ProgressBar() {
	cout << "\n\n\n" << setw(80) << "Loading..." << endl << endl;
	cout << setw(103) << "]";
	cout << "\r\r" << setw(4);
	for (size_t i = 0; i < 99; i++)
		cout << char(219);
	cout << "\r" << setw(50) << "[";
	for (size_t i = 0; i < 52; i++)
	{
		Sleep(40);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << char(178);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	cout << endl << endl;
}

void Design() {


	bool b = true;
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;

	system("pause");
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t" << a;
	for (size_t i = 0; i < 70; i++)
	{
		Sleep(25);
		cout << c;
	}
	cout << x << endl;
	for (size_t i = 0; i < 5; i++)
	{
		Sleep(25);
		cout << setw(112) << d;
		cout << "\r";
		if (b && i == 2) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << setw(72) << "\t\t\t\t<>    Restaurant Management System    <> ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			b = false;
		}
		cout << "\r";
		cout << setw(41) << d << endl;

	}
	cout << setw(112) << e << "\r\t\t\t\t\t ";
	cout << "\r\t\t\t\t\t" << g;
	for (size_t i = 0; i < 70; i++)
	{
		Sleep(25);
		cout << c;
	}

	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	ProgressBar();



}

#pragma once
