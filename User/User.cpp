#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <lmcons.h>
#include "Header.h"
using namespace std;



class Ingredient
{
	string name;
	int weight;
	int count;
public:
	Ingredient() {}

	Ingredient(const string name, const int weight) {
		setName(name);
		setWeight(weight);
	}

	Ingredient(Ingredient*& other) {
		setName(other->getName());
		setWeight(other->getWeight());
	}

	void setName(const string name) {
		this->name = name;
	}
	string getName() const { return name; }

	void setWeight(const int weight) {
		this->weight = weight;
	}
	int getWeight() const { return weight; }


	void ShowIngres() {
		cout << "\t\t\t\t\t\t\t  Ingredient Name: " << name << endl
			<< "\t\t\t\t\t\t\t  Ingredients Weight: " << weight << " g" << endl;
	}


};

class Meal
{
protected:
	string name;
	int count;
	double total;
	double price;
	vector<Ingredient*> ingredients;
public:

	Meal() {}

	Meal(const string name, const double price, vector<Ingredient*> ingrs) {
		setName(name);
		setPrice(price);
		ingredients = ingrs;
	}

	void setIngredients(vector<Ingredient*> ingrs) {
		ingredients = ingrs;
	}


	void setName(const string name) {
		this->name = name;
	}
	string getName() const { return name; }

	void setCount(const int count) {
		this->count = count;
	}
	int getCount() const { return count; }

	void setPrice(const double price) {
		this->price = price;
	}
	double getPrice() const { return price; }

	void setTotal(const double total) {
		this->total = total;
	}
	double getTotal() const { return total; }

	void Show() {
		cout << "\n\t\t\t\t\t\t\t##############################\n\n";
		for (size_t i = 0; i < ingredients.size(); i++)
		{
			ingredients[i]->ShowIngres();
		}
		cout << "\n\t\t\t\t\t\t\t##############################\n";
	}

	void ShowOrderListEle() {
		char c = 205;
		char a = 201;
		char x = 187;
		char d = 186;
		char e = 188;
		char g = 200;

		cout << "\n";
		cout << setw(43) << a;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << x << endl;

		cout << setw(109) << d << "\r" <<
			setw(100) << total << " AZN" << "\r" <<
			setw(82) << price << " AZN\r" <<
			setw(65) << count << "\r" <<
			setw(45 + name.length()) << name << "\r" << d;
		cout << "\r";
		cout << setw(43) << d << endl;
		cout << setw(109) << e << "\r";
		cout << setw(43) << g;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << endl;
	}




	virtual void Print() {};

};


class Chicken : public Meal
{
	int id;
	string piece;
	static int objId;
public:
	Chicken() {}

	Chicken(const string name, const double price, const string piece, vector<Ingredient*> ingredients) :Meal(name, price, ingredients) {
		setId();
		setPiece(piece);
	}

	void setId(const int id) {
		this->id = id;
	}

	void setId() {
		objId++;
		id = objId;
	}
	int getId() const { return id; }

	void setPiece(const string piece) {
		this->piece = piece;
	}
	string getPiece() const { return piece; }

	void Print() override {
		char c = 205;
		char a = 201;
		char x = 187;
		char d = 186;
		char e = 188;
		char g = 200;

		cout << "\n";
		cout << setw(43) << a;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << x << endl;

		cout << setw(109) << d << "\r" <<
			setw(97) << price << " AZN" << "\r" <<
			setw(80) << piece << "\r" <<
			setw(57 + name.length()) << name << "\r" <<
			setw(47) << id << "\r" << d;
		cout << "\r";
		cout << setw(43) << d << endl;
		cout << setw(109) << e << "\r";
		cout << setw(43) << g;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << endl;
	}

};
int Chicken::objId = -1;


class Burger :public Meal
{
	int id;
	static int objId;
public:
	Burger() {}

	Burger(const string name, const double price, vector<Ingredient*> ingredients) :Meal(name, price, ingredients) {
		setId();
	}
	void setId(const int id) {
		this->id = id;
	}
	void setId() {
		objId++;
		id = objId;
	}
	int getId() const { return id; }


	void Print() {
		char c = 205;
		char a = 201;
		char x = 187;
		char d = 186;
		char e = 188;
		char g = 200;

		cout << "\n";
		cout << setw(43) << a;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << x << endl;

		cout << setw(109) << d << "\r" <<
			setw(97) << price << " AZN" << "\r" <<
			setw(65 + name.length()) << name << "\r" <<
			setw(47) << id << "\r" << d;
		cout << "\r";
		cout << setw(43) << d << endl;
		cout << setw(109) << e << "\r";
		cout << setw(43) << g;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << endl;
	}


};
int Burger::objId = -1;

class Sandwiche : public Meal
{
	int id;
public:
	Sandwiche() {}

	Sandwiche(const string name, const double price, vector<Ingredient*> ingredients) :Meal(name, price, ingredients) {}

	void setId(const int id) {
		this->id = id;
	}
	int getId() const { return id; }

	void Print() {
		char c = 205;
		char a = 201;
		char x = 187;
		char d = 186;
		char e = 188;
		char g = 200;

		cout << "\n";
		cout << setw(43) << a;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << x << endl;

		cout << setw(109) << d << "\r" <<
			setw(97) << price << " AZN" << "\r" <<
			setw(65 + name.length()) << name << "\r" <<
			setw(47) << id << "\r" << d;
		cout << "\r";
		cout << setw(43) << d << endl;
		cout << setw(109) << e << "\r";
		cout << setw(43) << g;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << endl;
	}

};

class Snack : public Meal
{
	int id;
public:
	Snack() {}

	Snack(const string name, const double price, vector<Ingredient*> ingredients) :Meal(name, price, ingredients) {}

	void setId(const int id) {
		this->id = id;
	}
	int getId() const { return id; }

	void Print() {
		char c = 205;
		char a = 201;
		char x = 187;
		char d = 186;
		char e = 188;
		char g = 200;

		cout << "\n";
		cout << setw(43) << a;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << x << endl;

		cout << setw(109) << d << "\r" <<
			setw(97) << price << " AZN" << "\r" <<
			setw(65 + name.length()) << name << "\r" <<
			setw(47) << id << "\r" << d;
		cout << "\r";
		cout << setw(43) << d << endl;
		cout << setw(109) << e << "\r";
		cout << setw(43) << g;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << endl;
	}

};

class Sauce : public Meal
{
	int id;
public:
	Sauce() {}

	Sauce(const string name, const double price, vector<Ingredient*> ingredients) :Meal(name, price, ingredients) {}

	void setId(const int id) {
		this->id = id;
	}
	int getId() const { return id; }

	void Print() {
		char c = 205;
		char a = 201;
		char x = 187;
		char d = 186;
		char e = 188;
		char g = 200;

		cout << "\n";
		cout << setw(43) << a;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << x << endl;

		cout << setw(109) << d << "\r" <<
			setw(97) << price << " AZN" << "\r" <<
			setw(65 + name.length()) << name << "\r" <<
			setw(47) << id << "\r" << d;
		cout << "\r";
		cout << setw(43) << d << endl;
		cout << setw(109) << e << "\r";
		cout << setw(43) << g;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << endl;
	}

};

class Drink : public Meal
{
	int id;
public:
	Drink() {}

	Drink(const string name, const double price, vector<Ingredient*> ingredients) :Meal(name, price, ingredients) {}

	void setId(const int id) {
		this->id = id;
	}
	int getId() const { return id; }

	void Print() {
		char c = 205;
		char a = 201;
		char x = 187;
		char d = 186;
		char e = 188;
		char g = 200;

		cout << "\n";
		cout << setw(43) << a;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << x << endl;

		cout << setw(109) << d << "\r" <<
			setw(97) << price << " AZN" << "\r" <<
			setw(65 + name.length()) << name << "\r" <<
			setw(47) << id << "\r" << d;
		cout << "\r";
		cout << setw(43) << d << endl;
		cout << setw(109) << e << "\r";
		cout << setw(43) << g;
		for (size_t i = 0; i < 65; i++)
		{
			cout << c;
		}
		cout << endl;
	}

};



static string getPath() {
	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;

	GetUserName((TCHAR*)username, &username_len);

	wstring wstr = L"";
	for (int i = 0; i < username_len - 1; i++)
		wstr += username[i];
	string mainPath(wstr.begin(), wstr.end());
	return mainPath;
}

void WriteFile(vector<string> foodbase) {
	ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\foodbase.txt");
	for (size_t i = 0; i < foodbase.size(); i++)
	{
		MyFile << foodbase[i] << '#';
	}
	MyFile.close();
}

void ShowPart1(vector<vector<Meal*>>& products);
void ShowMenu(vector<vector<Meal*>>& products);
void ShowMealsInfo(vector<vector<Meal*>>& products, vector<Meal*> meal);
void ShowOrderList(vector<vector<Meal*>>& products);
void ShowPart3(int productIndex, vector<vector<Meal*>>& products);


void UserDesign() {

	bool b = true;
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	cout << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "\t\t\t\t\t" << a;
	for (size_t i = 0; i < 70; i++)
	{
		cout << c;
	}
	cout << x << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << setw(112) << d;
		cout << "\r";
		if (b && i == 2) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << setw(70) << "\t\t\t\t<>  Restaurant Management System   <> ";
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
		cout << c;
	}

	cout << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << "\n";
}

void ShowBeforeOrder(int productIndex, vector<Meal*> meal) {
	UserDesign();
	meal[productIndex]->Print();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	meal[productIndex]->Show();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "\n\n";
}


void ShowPart2(int productIndex, vector<vector<Meal*>>& products, vector<Meal*> meal) {
	ShowBeforeOrder(productIndex, meal);
	int count;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(77) << "Enter Count: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	count = _getch();
	if (count == 27) {
		system("CLS");
		UserDesign();
		ShowMealsInfo(products, meal);
	}
	cin >> count;
	cout << endl << setw(73) << "Total: " << count * meal[productIndex]->getPrice() << " AZN";
	cout << endl;
	cout << endl;
	string arr[]{ "Edit Order","Add Order List" };
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	int index = 0;
	char s;
	while (true)
	{
		for (int i = 0; i < 2; i++) {
			string str;
			if (i == 1)
				str = "\t\t\t\t\t\t\t\t  ";
			else
				str = "\t\t\t\t\t\t\t\t    ";
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
			}
		}
		s = _getch();
		if (int(s) == 13) {
			system("cls");
			if (index == 0)
			{
				ShowBeforeOrder(productIndex, meal);
				cout << setw(77) << "Enter Count: ";
				cin >> count;
				cout << endl << setw(73) << "Total: " << count * meal[productIndex]->getPrice() << " AZN";
				cout << endl << endl;
			}
			else {
				meal[productIndex]->setCount(count);
				meal[productIndex]->setTotal(count * meal[productIndex]->getPrice());
				products[products.size() - 1].push_back(meal[productIndex]);
				UserDesign();
				ShowMealsInfo(products, meal);
			}
		}
		else if (int(s) == 27)
		{
			system("cls");
			UserDesign();
			ShowMealsInfo(products, meal);
		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == 2) {
				index = 0;
			}
			system("cls");
			ShowBeforeOrder(productIndex, meal);
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = 1;
			}
			else
				index--;
			system("cls");
			ShowBeforeOrder(productIndex, meal);
		}
	}




}


void ShowMealsInfo(vector<vector<Meal*>>& products, vector<Meal*> meal) {
	int index = 0;
	char s;
	while (true)
	{
		for (int i = 0; i < meal.size(); i++) {
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				meal[i]->Print();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				meal[i]->Print();
			}
		}
		s = _getch();
		if (int(s) == 13) {
			system("cls");
			ShowPart2(index, products, meal);
		}
		if (int(s) == 27) {
			system("cls");
			UserDesign();
			ShowMenu(products);
			break;
		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == meal.size()) {
				index = 0;
			}
			system("CLS");
			UserDesign();
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = meal.size() - 1;
			}
			else
				index--;
			system("CLS");
			UserDesign();
		}
	}
}


void ShowMenu(vector<vector<Meal*>>& products) {
	string arr[]{ "Chicken","Burgers","Sandwiches","Snacks","Sauces","Drinks" };
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	int index = 0;
	char s;
	while (true)
	{
		for (int i = 0; i < 6; i++) {
			string str;
			if (i == 2)
				str = "\t\t\t\t\t\t\t\t    ";
			else
				str = "\t\t\t\t\t\t\t\t     ";
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
			}
		}
		s = _getch();
		if (int(s) == 13) {
			system("cls");
			UserDesign();
			ShowMealsInfo(products, products[index]);
		}
		if (int(s) == 27) {
			system("cls");
			ShowPart1(products);
			break;
		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == 6) {
				index = 0;
			}
			system("cls");
			UserDesign();
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = 5;
			}
			else
				index--;
			system("cls");
			UserDesign();
		}
	}
}

void OrderDesign() {
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << setw(43) << a;
	for (size_t i = 0; i < 65; i++)
	{
		cout << c;
	}
	cout << x << endl;

	cout << setw(109) << d << "\r" <<
		setw(102) << "Total " << char(216) << "\r" <<
		setw(85) << "Price " << char(216) << " \r" <<
		setw(68) << "Count " << char(216) << "\r" <<
		setw(50) << "Name " << char(216) << "\r" << d;
	cout << "\r";
	cout << setw(43) << d << endl;
	cout << setw(109) << e << "\r";
	cout << setw(43) << g;
	for (size_t i = 0; i < 65; i++)
	{
		cout << c;
	}

	cout << endl;
	cout << setw(65) << a;
	for (size_t i = 0; i < 20; i++)
	{
		cout << c;
	}
	cout << x << endl;
	cout << setw(86) << d << "\r" << setw(80) << "Order List" << "\r" << setw(65) << d << endl;
	cout << setw(65) << g;
	for (size_t i = 0; i < 20; i++)
	{
		cout << c;
	}
	cout << e << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Edit(int productIndex, vector<vector<Meal*>>& products) {
	UserDesign();
	cout << "\n\n";
	int count;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "<> Enter Count: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> count;
	products[products.size() - 1][productIndex]->setCount(count);
	products[products.size() - 1][productIndex]->setTotal(count * products[products.size() - 1][productIndex]->getPrice());
	system("cls");
	UserDesign();
	return;

}


void ShowIngredients(int productIndex, vector<vector<Meal*>>& products) {
	UserDesign();
	int s;
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	products[products.size() - 1][productIndex]->Show();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	s = _getch();
	if (s == 27) {
		system("cls");
		ShowPart3(productIndex, products);
	}
}

void Delete(int productIndex, vector<vector<Meal*>>& products) {
	UserDesign();
	products[products.size() - 1].erase(products[products.size() - 1].begin() + productIndex);
	cout << "\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "<>  Deleted Succesfully  <>\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("pause");
	system("cls");
	ShowOrderList(products);

}

void ShowPart3(int productIndex, vector<vector<Meal*>>& products) {
	string arr[]{ "Edit", "Show Ingredients","Delete" };
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	int index = 0;
	char s;
	UserDesign();
	while (true)
	{
		for (int i = 0; i < 3; i++) {
			string str;
			if (i == 1)
				str = "\t\t\t\t\t\t\t\t";
			else if (i == 2) {
				str = "\t\t\t\t\t\t\t\t     ";
			}
			else
				str = "\t\t\t\t\t\t\t\t      ";
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
			}
		}
		s = _getch();
		if (int(s) == 13) {
			system("cls");
			if (index == 0)
			{
				Edit(productIndex, products);
			}
			else if (index == 1)
			{
				ShowIngredients(productIndex, products);
			}
			else if (index == 2)
			{
				Delete(productIndex, products);
			}

		}
		if (int(s) == 27) {
			system("cls");
			ShowOrderList(products);

		}
		else if (int(s) == 80) { 
			index++;
			if (index == 3) {
				index = 0;
			}
			system("cls");
			UserDesign();
		}
		else if (int(s) == 72) { 
			if (index == 0)
			{
				index = 2;
			}
			else
				index--;
			system("cls");
			UserDesign();
		}
	}
}

void ConfirmDesign(double total) {
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(74) << "<>   TOTAL: " << total << " AZN" << endl;
	cout << setw(84) << "<>   Are you sure ?  <>" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void ConfirmOrder(vector<vector<Meal*>>& products, vector<Meal*> orderList) {
	system("cls");
	double total = 0;
	string arr[]{ "Yes","No" };
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	int index = 0;
	char s;
	UserDesign();
	for (size_t i = 0; i < orderList.size(); i++)
	{
		total += orderList[i]->getTotal();
	}
	ConfirmDesign(total);
	while (true)
	{
		for (int i = 0; i < 2; i++) {
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << setw(73) << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << setw(73) << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
			}
		}
		s = _getch();
		if (int(s) == 13) {
			if (index == 0)
			{
				system("cls");
				UserDesign();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << setw(101) << "<>  Thanks, your order will be ready in 10 minutes  <>\n\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				orderList.clear();
				products[6].clear();
				system("pause");
				system("cls");
				ShowPart1(products);
			}
			else
			{
				ShowOrderList(products);
			}
		}
		if (int(s) == 27) {
			ShowOrderList(products);
		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == 2) {
				index = 0;
			}
			system("cls");
			UserDesign();
			ConfirmDesign(total);
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = 1;
			}
			else
				index--;
			system("cls");
			UserDesign();
			ConfirmDesign(total);
		}
	}
}

void ShowOrderList(vector<vector<Meal*>>& products) {
	system("cls");
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	int index = 0;
	int len = products.size() - 1;
	bool boo = false;
	char s;
	UserDesign();
	OrderDesign();
	while (true)
	{
		if (index == products[len].size()) {
			boo = true;
		}
		for (int i = 0; i < products[len].size(); i++) {
			if (i == index && boo == false) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				products[len][i]->ShowOrderListEle();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				products[len][i]->ShowOrderListEle();
			}
		}
		if (boo) {
			boo = false;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << endl;
			cout << setw(65) << a;
			for (size_t i = 0; i < 20; i++)
			{
				cout << c;
			}
			cout << x << endl;
			cout << setw(86) << d << "\r" << setw(81) << "Cofrim Order" << "\r" << setw(65) << d << endl;
			cout << setw(65) << g;
			for (size_t i = 0; i < 20; i++)
			{
				cout << c;
			}
			cout << e << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else {
			cout << endl;
			cout << setw(65) << a;
			for (size_t i = 0; i < 20; i++)
			{
				cout << c;
			}
			cout << x << endl;
			cout << setw(86) << d << "\r" << setw(81) << "Cofrim Order" << "\r" << setw(65) << d << endl;
			cout << setw(65) << g;
			for (size_t i = 0; i < 20; i++)
			{
				cout << c;
			}
			cout << e << endl;
		}
		s = _getch();
		if (!products[products.size() - 1].empty())
		{
			if (int(s) == 13) {
				system("cls");
				if (index == products[len].size()) {
					ConfirmOrder(products, products[len]);
				}
				else {
					ShowPart3(index, products);
				}

			}
		}
		else {
			system("cls");
			ShowPart1(products);
		}
		if (int(s) == 27) {
			system("cls");
			ShowPart1(products);
		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == products[len].size() + 1) {
				index = 0;
			}
			system("cls");
			UserDesign();
			OrderDesign();
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = products[len].size();
			}
			else
				index--;
			system("cls");
			UserDesign();
			OrderDesign();
		}
	}
}


void ShowPart1(vector<vector<Meal*>>& products) {
	string arr[]{ "Menu","Order List","Exit" };
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	int index = 0;
	char s;
	UserDesign();
	while (true)
	{
		for (int i = 0; i < 3; i++) {
			string str;
			if (i == 1)
				str = "\t\t\t\t\t\t\t\t    ";
			else
				str = "\t\t\t\t\t\t\t\t      ";
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else
			{
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << str << arr[i] << "\r" << setw(62) << d << endl;
				cout << setw(62) << g;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << e << endl;
			}
		}
		s = _getch();
		if (int(s) == 13) {
			system("cls");
			UserDesign();
			if (index == 0)
			{
				ShowMenu(products);
			}
			else if (index == 1)
			{
				ShowOrderList(products);
			}
			else if (index == 2)
			{
				for (size_t i = 0; i < 11; i++)
				{

					if (i % 2) system("color 9");
					else system("color 7");
					cout << "\n\n\n\n\t\t\t\t\t\t\t<<>>   Thank you for choosing us   <<>>" << endl;
					Sleep(400);
					system("cls");
					UserDesign();
				}
				exit(0);
				break;

			}
		}
		if (int(s) == 27) {
			system("cls");
			UserDesign();
			for (size_t i = 0; i < 11; i++)
			{
				if (i % 2) system("color 9");
				else system("color 7");
				cout << "\n\n\n\n\t\t\t\t\t\t\t<<>>   Thank you for choosing us   <<>>" << endl;
				Sleep(400);
				system("cls");
				UserDesign();
			}
			exit(0);
			break;
		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == 3) {
				index = 0;
			}
			system("cls");
			UserDesign();
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = 2;
			}
			else
				index--;
			system("cls");
			UserDesign();
		}
	}
}


void ReadFile(string& arr, string path) {
	ifstream MyFile(path);
	string str = "";
	string val;
	while (!MyFile.eof()) {
		getline(MyFile, val);
		str += val;
	}
	arr.append(str);
	MyFile.close();
}

void FoodBaseCheck(string main, vector<string>& products) {
	vector<string> arr{ main };
	string str;
	string c;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				products.push_back(c);
				c = "";
			}
			else {
				c += str[i];
			}
		}
		str.clear();
	}
}

void ChickenCheck(vector<string>& arr, vector<Meal*>& chickens, vector<string>& foodbase) {
	vector<string> strArr;
	string str;
	string c;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				strArr.push_back(c);
				c = "";
			}
			else {
				c += str[i];
			}
		}
		strArr.push_back("");
		int b = 0;
		Chicken* c = new Chicken();

		vector<Ingredient*> ings;

		c->setId(stoi(strArr[0]));
		c->setName(strArr[1]);
		c->setPrice(stod(strArr[2]));
		c->setPiece(strArr[3]);
		int size = stoi(strArr[4]);
		for (size_t i = 0, a = 5; i < size; i++, a++)
		{
			int count = 0;
			int index = 0;
			for (size_t j = 0; j < foodbase.size(); j++)
			{
				if (foodbase[j] == strArr[a])
				{
					count = stoi(foodbase[++j]);
					index = j;
					break;
				}
			}
			if (count - stoi(strArr[++a]) >= 0)
			{
				foodbase[index] = to_string(count - stoi(strArr[a]));
				WriteFile(foodbase);
				Ingredient* ins = new Ingredient();
				ins->setName(strArr[--a]);
				ins->setWeight(stoi(strArr[++a]));
				ings.push_back(ins);
				ins = nullptr;
				b++;
			}
		}
		if (b == size) {
			c->setIngredients(ings);
			chickens.push_back(c);
		}

		c = nullptr;
		ings.clear();
		strArr.clear();
		str.clear();
	}

}
void ChickenReadFiletoString(string& arr, vector<Meal*>& chickens, vector<string>& foodbase) {
	vector<string> w;
	string b;
	for (size_t i = 0; i < arr.length(); i++)
	{
		if (arr[i] != '@') {
			b += arr[i];
		}
		else {
			w.push_back(b);
			b = "";
		}
	}
	ChickenCheck(w, chickens, foodbase);
	arr.clear();
}


void BurgerCheck(vector<string>& arr, vector<Meal*>& burgers, vector<string>& foodbase) {
	vector<string> strArr;
	string str;
	string c;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				strArr.push_back(c);
				c = "";
			}
			else {
				c += str[i];
			}
		}
		strArr.push_back("");
		int b = 0;
		Burger* c = new Burger();

		vector<Ingredient*> ings;

		c->setId(stoi(strArr[0]));
		c->setName(strArr[1]);
		c->setPrice(stod(strArr[2]));
		int size = stoi(strArr[3]);
		for (size_t i = 0, a = 4; i < size; i++, a++)
		{
			int count = 0;
			int index = 0;
			for (size_t j = 0; j < foodbase.size(); j++)
			{
				if (foodbase[j] == strArr[a])
				{
					count = stoi(foodbase[++j]);
					index = j;
					break;
				}
			}
			if (count - stoi(strArr[++a]) >= 0)
			{
				foodbase[index] = to_string(count - stoi(strArr[a]));
				WriteFile(foodbase);
				Ingredient* ins = new Ingredient();
				ins->setName(strArr[--a]);
				ins->setWeight(stoi(strArr[++a]));
				ings.push_back(ins);
				ins = nullptr;
				b++;
			}
		}
		if (b == size)
		{
			c->setIngredients(ings);
			burgers.push_back(c);
		}

		c = nullptr;
		ings.clear();
		strArr.clear();
		str.clear();
	}

}
void BurgerReadFiletoString(string& arr, vector<Meal*>& burgers, vector<string>& foodbase) {
	vector<string> w;
	string b;
	for (size_t i = 0; i < arr.length(); i++)
	{
		if (arr[i] != '@') {
			b += arr[i];
		}
		else {
			w.push_back(b);
			b = "";
		}
	}
	BurgerCheck(w, burgers, foodbase);
	arr.clear();
}


void SandwicheCheck(vector<string>& arr, vector<Meal*>& sandwiches, vector<string> foodbase) {
	vector<string> strArr;
	string str;
	string c;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				strArr.push_back(c);
				c = "";
			}
			else {
				c += str[i];
			}
		}
		strArr.push_back("");

		int b = 0;
		Sandwiche* c = new Sandwiche();

		vector<Ingredient*> ings;

		c->setId(stoi(strArr[0]));
		c->setName(strArr[1]);
		c->setPrice(stod(strArr[2]));
		int size = stoi(strArr[3]);
		for (size_t i = 0, a = 4; i < size; i++, a++)
		{
			int count = 0;
			int index = 0;
			for (size_t j = 0; j < foodbase.size(); j++)
			{
				if (foodbase[j] == strArr[a])
				{
					count = stoi(foodbase[++j]);
					index = j;
					break;
				}
			}
			if (count - stoi(strArr[++a]) >= 0)
			{
				foodbase[index] = to_string(count - stoi(strArr[a]));
				WriteFile(foodbase);
				Ingredient* ins = new Ingredient();
				ins->setName(strArr[--a]);
				ins->setWeight(stoi(strArr[++a]));
				ings.push_back(ins);
				ins = nullptr;
				b++;
			}
		}
		if (b == size)
		{
			c->setIngredients(ings);
			sandwiches.push_back(c);
		}
		c = nullptr;
		ings.clear();
		strArr.clear();
		str.clear();
	}
}
void SandwicheReadFiletoString(string& arr, vector<Meal*>& sandwiches, vector<string> foodbase) {
	vector<string> w;
	string b;
	for (size_t i = 0; i < arr.length(); i++)
	{
		if (arr[i] != '@') {
			b += arr[i];
		}
		else {
			w.push_back(b);
			b = "";
		}
	}
	SandwicheCheck(w, sandwiches, foodbase);
	arr.clear();
}



void SnackCheck(vector<string>& arr, vector<Meal*>& snacks, vector<string> foodbase) {
	vector<string> strArr;
	string str;
	string c;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				strArr.push_back(c);
				c = "";
			}
			else {
				c += str[i];
			}
		}
		strArr.push_back("");

		int b = 0;
		Snack* c = new Snack();

		vector<Ingredient*> ings;

		c->setId(stoi(strArr[0]));
		c->setName(strArr[1]);
		c->setPrice(stod(strArr[2]));
		int size = stoi(strArr[3]);
		for (size_t i = 0, a = 4; i < size; i++, a++)
		{
			int count = 0;
			int index = 0;
			for (size_t j = 0; j < foodbase.size(); j++)
			{
				if (foodbase[j] == strArr[a])
				{
					count = stoi(foodbase[++j]);
					index = j;
					break;
				}
			}
			if (count - stoi(strArr[++a]) >= 0)
			{
				foodbase[index] = to_string(count - stoi(strArr[a]));
				WriteFile(foodbase);
				Ingredient* ins = new Ingredient();
				ins->setName(strArr[--a]);
				ins->setWeight(stoi(strArr[++a]));
				ings.push_back(ins);
				ins = nullptr;
				b++;
			}
		}
		if (b == size)
		{
			c->setIngredients(ings);
			snacks.push_back(c);
		}
		c = nullptr;
		ings.clear();
		strArr.clear();
		str.clear();
	}
}
void SnackReadFiletoString(string& arr, vector<Meal*>& snacks, vector<string> foodbase) {
	vector<string> w;
	string b;
	for (size_t i = 0; i < arr.length(); i++)
	{
		if (arr[i] != '@') {
			b += arr[i];
		}
		else {
			w.push_back(b);
			b = "";
		}
	}
	SnackCheck(w, snacks, foodbase);
	arr.clear();
}


void SauceCheck(vector<string>& arr, vector<Meal*>& sauces, vector<string> foodbase) {
	vector<string> strArr;
	string str;
	string c;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				strArr.push_back(c);
				c = "";
			}
			else {
				c += str[i];
			}
		}
		strArr.push_back("");

		int b = 0;
		Sauce* c = new Sauce();

		vector<Ingredient*> ings;

		c->setId(stoi(strArr[0]));
		c->setName(strArr[1]);
		c->setPrice(stod(strArr[2]));
		int size = stoi(strArr[3]);
		for (size_t i = 0, a = 4; i < size; i++, a++)
		{
			int count = 0;
			int index = 0;
			for (size_t j = 0; j < foodbase.size(); j++)
			{
				if (foodbase[j] == strArr[a])
				{
					count = stoi(foodbase[++j]);
					index = j;
					break;
				}
			}
			if (count - stoi(strArr[++a]) >= 0)
			{
				foodbase[index] = to_string(count - stoi(strArr[a]));
				WriteFile(foodbase);
				Ingredient* ins = new Ingredient();
				ins->setName(strArr[--a]);
				ins->setWeight(stoi(strArr[++a]));
				ings.push_back(ins);
				ins = nullptr;
				b++;
			}
		}
		if (b == size)
		{
			c->setIngredients(ings);
			sauces.push_back(c);
		}
		c = nullptr;
		ings.clear();
		strArr.clear();
		str.clear();
	}
}
void SauceReadFiletoString(string& arr, vector<Meal*>& sauces, vector<string> foodbase) {
	vector<string> w;
	string b;
	for (size_t i = 0; i < arr.length(); i++)
	{
		if (arr[i] != '@') {
			b += arr[i];
		}
		else {
			w.push_back(b);
			b = "";
		}
	}
	SauceCheck(w, sauces, foodbase);
	arr.clear();
}



void DrinkCheck(vector<string>& arr, vector<Meal*>& drinks, vector<string> foodbase) {
	vector<string> strArr;
	string str;
	string c;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				strArr.push_back(c);
				c = "";
			}
			else {
				c += str[i];
			}
		}
		strArr.push_back("");

		int b = 0;
		Drink* c = new Drink();

		vector<Ingredient*> ings;

		c->setId(stoi(strArr[0]));
		c->setName(strArr[1]);
		c->setPrice(stod(strArr[2]));
		int size = stoi(strArr[3]);
		for (size_t i = 0, a = 4; i < size; i++, a++)
		{
			int count = 0;
			int index = 0;
			for (size_t j = 0; j < foodbase.size(); j++)
			{
				if (foodbase[j] == strArr[a])
				{
					count = stoi(foodbase[++j]);
					index = j;
					break;
				}
			}
			if (count - stoi(strArr[++a]) >= 0)
			{
				foodbase[index] = to_string(count - stoi(strArr[a]));
				WriteFile(foodbase);
				Ingredient* ins = new Ingredient();
				ins->setName(strArr[--a]);
				ins->setWeight(stoi(strArr[++a]));
				ings.push_back(ins);
				ins = nullptr;
				b++;
			}
		}
		if (b == size)
		{
			c->setIngredients(ings);
			drinks.push_back(c);
		}
		c = nullptr;
		ings.clear();
		strArr.clear();
		str.clear();
	}
}
void DrinkReadFiletoString(string& arr, vector<Meal*>& drinks, vector<string> foodbase) {
	vector<string> w;
	string b;
	for (size_t i = 0; i < arr.length(); i++)
	{
		if (arr[i] != '@') {
			b += arr[i];
		}
		else {
			w.push_back(b);
			b = "";
		}
	}
	DrinkCheck(w, drinks, foodbase);
	arr.clear();
}


class System
{
public:

	static void User() {

		TCHAR username[UNLEN + 1];
		DWORD username_len = UNLEN + 1;

		GetUserName((TCHAR*)username, &username_len);

		wstring wstr = L"";
		for (int i = 0; i < username_len - 1; i++)
			wstr += username[i];
		string mainPath(wstr.begin(), wstr.end());




		string arr;
		vector<Meal*> chickens;
		vector<Meal*> burgers;
		vector<Meal*> sandwiches;
		vector<Meal*> snacks;
		vector<Meal*> sauces;
		vector<Meal*> drinks;
		vector<Meal*> orderList;

		string base;
		vector<string> foodbase;

		ReadFile(base, "C:\\Users\\"+mainPath+"\\source\\repos\\Restaurant-Management-System\\New folder\\foodbase.txt");
		FoodBaseCheck(base, foodbase);

		ReadFile(arr, "C:\\Users\\"+mainPath+"\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt");
		ChickenReadFiletoString(arr, chickens, foodbase);

		ReadFile(arr, "C:\\Users\\"+mainPath+"\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt");
		BurgerReadFiletoString(arr, burgers, foodbase);

		ReadFile(arr, "C:\\Users\\"+mainPath+"\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt");
		SandwicheReadFiletoString(arr, sandwiches, foodbase);

		ReadFile(arr, "C:\\Users\\"+mainPath+"\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt");
		SnackReadFiletoString(arr, snacks, foodbase);

		ReadFile(arr, "C:\\Users\\"+mainPath+"\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt");
		SauceReadFiletoString(arr, sauces, foodbase);


		ReadFile(arr, "C:\\Users\\"+mainPath+"\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt");
		DrinkReadFiletoString(arr, drinks, foodbase);


		vector<vector<Meal*>>products{ chickens,burgers,sandwiches ,snacks,sauces,drinks,orderList };
		
		Design();

		system("cls");
		ShowPart1(products);
	}
};


void main() {

	System::User();

}
