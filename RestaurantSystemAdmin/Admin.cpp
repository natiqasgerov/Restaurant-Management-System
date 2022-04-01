#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <lmcons.h>
using namespace std;

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
	int id;
	string productName;
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

	void setProductName(const string productName) {
		this->productName = productName;
	}
	string getProductName() const { return productName; }

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

	virtual void setId(const int id) {
		this->id = id;
	}

	virtual int getId() const { return id; };

	virtual void Print() {};

	virtual void WriteMainFile() {};

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

	void WriteMainFile() {
		ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt", ios::app);
		MyFile << id << "#" << name << "#" << price << "#" <<
			piece << "#" << ingredients.size() << "#";
		for (size_t i = 0; i < ingredients.size(); i++)
		{
			MyFile << ingredients[i]->getName() << "#" << ingredients[i]->getWeight() << "#";
		}
		MyFile << "@" << endl;
		MyFile.close();

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

	void WriteMainFile() {
		ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt", ios::app);
		MyFile << id << "#" << name << "#" << price << "#" << ingredients.size() << "#";
		for (size_t i = 0; i < ingredients.size(); i++)
		{
			MyFile << ingredients[i]->getName() << "#" << ingredients[i]->getWeight() << "#";
		}
		MyFile << "@" << endl;
		MyFile.close();

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

	void WriteMainFile() {
		ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt", ios::app);
		MyFile << id << "#" << name << "#" << price << "#" << ingredients.size() << "#";
		for (size_t i = 0; i < ingredients.size(); i++)
		{
			MyFile << ingredients[i]->getName() << "#" << ingredients[i]->getWeight() << "#";
		}
		MyFile << "@" << endl;
		MyFile.close();

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

	void WriteMainFile() {
		ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt", ios::app);
		MyFile << id << "#" << name << "#" << price << "#" << ingredients.size() << "#";
		for (size_t i = 0; i < ingredients.size(); i++)
		{
			MyFile << ingredients[i]->getName() << "#" << ingredients[i]->getWeight() << "#";
		}
		MyFile << "@" << endl;
		MyFile.close();

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

	void WriteMainFile() {
		ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt", ios::app);
		MyFile << id << "#" << name << "#" << price << "#" << ingredients.size() << "#";
		for (size_t i = 0; i < ingredients.size(); i++)
		{
			MyFile << ingredients[i]->getName() << "#" << ingredients[i]->getWeight() << "#";
		}
		MyFile << "@" << endl;
		MyFile.close();

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

	void WriteMainFile() {
		ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt", ios::app);
		MyFile << id << "#" << name << "#" << price << "#" << ingredients.size() << "#";
		for (size_t i = 0; i < ingredients.size(); i++)
		{
			MyFile << ingredients[i]->getName() << "#" << ingredients[i]->getWeight() << "#";
		}
		MyFile << "@" << endl;
		MyFile.close();

	}
};





void WriteFile(vector<string> foodbase) {
	ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\foodbase.txt");
	for (size_t i = 0; i < foodbase.size(); i++)
	{
		MyFile << foodbase[i] << '#';
	}
	MyFile.close();
}

void ShowPart1Admin(vector<vector<Meal*>>& products);
void ShowMenuAdmin(vector<vector<Meal*>>& products);
void ShowPart2Admin(vector<vector<Meal*>>& products, vector<Meal*>& meal);
void ShowMealsInfoAdmin(vector<vector<Meal*>>& products, vector<Meal*>& meal);
void EditPart1Admin(vector<vector<Meal*>>& products, vector<Meal*>& meal);
void EditPart2Admin(int productIndex, vector<vector<Meal*>>& products, vector<Meal*>& meal);
void FoodBase(vector<vector<Meal*>>& products);
void FoodBaseCheck(string main, vector<string>& products);
void ReadFile(string& arr, string path);


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
		if (b && i == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << setw(70) << "\t\t\t\t<>  Restaurant Management System   <> ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

		}
		if (b && i == 3) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << setw(65) << "\t\t\t <>  ADMIN   <> ";
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


void ShowMealsInfoAdmin(vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	int index = 0;
	char s;
	while (true)
	{
		for (int i = 0; i < meal.size(); i++) {
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				meal[i]->Print();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << endl;
				meal[i]->Show();
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
			UserDesign();
		}
		else if (int(s) == 27) {
			system("cls");
			UserDesign();
			ShowPart2Admin(products, meal);
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

void EditName(int productIndex, vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	system("cls");
	UserDesign();
	string name;
	int s;
	cout << "\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> name;
	meal[productIndex]->setName(name);
	string path, str = meal[productIndex]->getProductName();
	if (str == "Chicken") {
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt";
	}
	else if (str == "Burger")
	{
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt";
	}
	else if (str == "Sandwiche") {
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt";
	}
	else if (str == "Snack") {
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt";
	}
	else if (str == "Sauce") {
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt";
	}
	else if (str == "Drink") {
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt";
	}
	ofstream My(path);
	My << "";
	My.close();
	for (size_t i = 0; i < meal.size(); i++)
	{
		meal[i]->WriteMainFile();
	}
	s = _getch();
	if (int(s) == 27)
	{
		system("cls");
		UserDesign();
		EditPart2Admin(productIndex, products, meal);
	}

}

void EditPrice(int productIndex, vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	system("cls");
	UserDesign();
	double price;
	int s;
	cout << "\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	meal[productIndex]->setPrice(price);
	string path, str = meal[productIndex]->getProductName();
	if (str == "Chicken") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt";
	}
	else if (str == "Burger")
	{
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt";
	}
	else if (str == "Sandwiche") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt";
	}
	else if (str == "Snack") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt";
	}
	else if (str == "Sauce") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt";
	}
	else if (str == "Drink") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt";
	}
	ofstream My(path);
	My << "";
	My.close();
	for (size_t i = 0; i < meal.size(); i++)
	{
		meal[i]->WriteMainFile();
	}
	s = _getch();
	if (int(s) == 27)
	{
		system("cls");
		UserDesign();
		EditPart2Admin(productIndex, products, meal);
	}

}


void EditIngredient(int productIndex, vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	system("cls");
	UserDesign();
	vector<Ingredient*>ings;
	int size, weight, s;
	string name;
	cout << "\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(83) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(83) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(84) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	meal[productIndex]->setIngredients(ings);

	string path, str = meal[productIndex]->getProductName();
	if (str == "Chicken") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt";
	}
	else if (str == "Burger")
	{
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt";
	}
	else if (str == "Sandwiche") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt";
	}
	else if (str == "Snack") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt";
	}
	else if (str == "Sauce") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt";
	}
	else if (str == "Drink") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt";
	}
	ofstream My(path);
	My << "";
	My.close();
	for (size_t i = 0; i < meal.size(); i++)
	{
		meal[i]->WriteMainFile();
	}
	s = _getch();
	if (int(s) == 27)
	{
		system("cls");
		UserDesign();
		EditPart2Admin(productIndex, products, meal);
	}


}


void EditAll(int productIndex, vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	system("cls");
	UserDesign();
	vector<Ingredient*>ings;
	string name;
	double price;
	string IngredientName;
	int weight, size, s;

	cout << "\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(78) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> name;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(78) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(83) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(83) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(84) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	meal[productIndex]->setName(name);
	meal[productIndex]->setPrice(price);
	meal[productIndex]->setIngredients(ings);
	string path, str = meal[productIndex]->getProductName();
	if (str == "Chicken") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt";
	}
	else if (str == "Burger")
	{
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt";
	}
	else if (str == "Sandwiche") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt";
	}
	else if (str == "Snack") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt";
	}
	else if (str == "Sauce") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt";
	}
	else if (str == "Drink") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt";
	}
	ofstream My(path);
	My << "";
	My.close();
	for (size_t i = 0; i < meal.size(); i++)
	{
		meal[i]->WriteMainFile();
	}
	s = _getch();
	if (int(s) == 27)
	{
		system("cls");
		UserDesign();
		EditPart2Admin(productIndex, products, meal);
	}
}


void EditPart2Admin(int productIndex, vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	string arr[]{ "Edit Name","Edit Price","Edit Ingredients","Edit All" };
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
		for (int i = 0; i < 4; i++) {
			string str;
			if (i == 2)
				str = "\t\t\t\t\t\t\t\t ";
			else
				str = "\t\t\t\t\t\t\t\t   ";
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
				EditName(productIndex, products, meal);
			}
			else if (index == 1)
			{
				EditPrice(productIndex, products, meal);
			}
			else if (index == 2)
			{
				EditIngredient(productIndex, products, meal);
			}
			else if (index == 3)
			{
				EditAll(productIndex, products, meal);
			}
		}
		if (int(s) == 27) {
			system("cls");
			UserDesign();
			EditPart1Admin(products, meal);

		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == 4) {
				index = 0;
			}
			system("cls");
			UserDesign();
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = 3;
			}
			else
				index--;
			system("cls");
			UserDesign();
		}
	}
}


void EditPart1Admin(vector<vector<Meal*>>& products, vector<Meal*>& meal) {
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
			UserDesign();
			EditPart2Admin(index, products, meal);
		}
		else if (int(s) == 27) {
			system("cls");
			UserDesign();
			ShowPart2Admin(products, meal);
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
};


void Delete(int productIndex, vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	meal.erase(meal.begin() + productIndex);
	string path, str = meal[0]->getProductName();
	if (str == "Chicken") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt";
	}
	else if (str == "Burger")
	{
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt";
	}
	else if (str == "Sandwiche") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt";
	}
	else if (str == "Snack") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt";
	}
	else if (str == "Sauce") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt";
	}
	else if (str == "Drink") {
		path = "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt";
	}
	ofstream My(path);
	My << "";
	My.close();
	for (size_t i = 0; i < meal.size(); i++)
	{
		meal[i]->WriteMainFile();
	}
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "<>  Deleted Succesfully  <>" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("pause");
	system("cls");
	UserDesign();
	ShowPart2Admin(products, meal);
}


void DeletePart1(vector<vector<Meal*>>& products, vector<Meal*>& meal) {
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
			UserDesign();
			Delete(index, products, meal);
		}
		else if (int(s) == 27) {
			system("cls");
			UserDesign();
			ShowPart2Admin(products, meal);
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

void AddChicken(vector<Meal*>& meal) {
	Chicken* c = new Chicken();
	vector<Ingredient*>ings;
	int size, weight;
	string name, piece;
	double price;
	if (meal[0]->getId() == 0)
	{
		c->setId(meal.size());
	}
	else {
		c->setId(meal.size() + 1);
	}
	c->setId(meal.size() + 1);
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, name);
	c->setName(name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	c->setPrice(price);
	cin.ignore();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Piece: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, piece);
	c->setPiece(piece);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(87) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(88) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	cin.ignore();
	c->setIngredients(ings);
	meal.push_back(c);
}

void AddBurger(vector<Meal*>& meal) {
	Burger* c = new Burger();
	vector<Ingredient*>ings;
	int size, weight;
	string name;
	double price;
	if (meal[0]->getId() == 0)
	{
		c->setId(meal.size());
	}
	else {
		c->setId(meal.size() + 1);
	}
	c->setId(meal.size() + 1);
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, name);
	c->setName(name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	c->setPrice(price);
	cin.ignore();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(87) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(88) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	cin.ignore();
	c->setIngredients(ings);
	meal.push_back(c);
}

void AddSandwiche(vector<Meal*>& meal) {
	Sandwiche* c = new Sandwiche();
	vector<Ingredient*>ings;
	int size, weight;
	string name;
	double price;
	if (meal[0]->getId() == 0)
	{
		c->setId(meal.size());
	}
	else {
		c->setId(meal.size() + 1);
	}
	c->setId(meal.size() + 1);
	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, name);
	c->setName(name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	c->setPrice(price);
	cin.ignore();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(87) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(88) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	cin.ignore();
	c->setIngredients(ings);
	meal.push_back(c);

}

void AddSnack(vector<Meal*>& meal) {
	Snack* c = new Snack();
	vector<Ingredient*>ings;
	int size, weight;
	string name;
	double price;
	if (meal[0]->getId() == 0)
	{
		c->setId(meal.size());
	}
	else {
		c->setId(meal.size() + 1);
	}

	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, name);
	c->setName(name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	c->setPrice(price);
	cin.ignore();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(87) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(88) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	cin.ignore();
	c->setIngredients(ings);
	meal.push_back(c);

}

void AddSauce(vector<Meal*>& meal) {
	Sauce* c = new Sauce();
	vector<Ingredient*>ings;
	int size, weight;
	string name;
	double price;
	if (meal[0]->getId() == 0)
	{
		c->setId(meal.size());
	}
	else {
		c->setId(meal.size() + 1);
	}

	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, name);
	c->setName(name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	c->setPrice(price);
	cin.ignore();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(87) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(88) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	cin.ignore();
	c->setIngredients(ings);
	meal.push_back(c);

}

void AddDrink(vector<Meal*>& meal) {
	Drink* c = new Drink();
	vector<Ingredient*>ings;
	int size, weight;
	string name;
	double price;
	if (meal[0]->getId() == 0)
	{
		c->setId(meal.size());
	}
	else {
		c->setId(meal.size() + 1);
	}

	cout << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, name);
	c->setName(name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Price: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> price;
	c->setPrice(price);
	cin.ignore();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(87) << "Enter Ingredient size: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> size;
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		Ingredient* in = new Ingredient();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(87) << "Enter Ingredient Name: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> name;
		in->setName(name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << setw(88) << "Enter Ingredient Weight: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> weight;
		in->setWeight(weight);
		ings.push_back(in);
		in = nullptr;
	}
	cin.ignore();
	c->setIngredients(ings);
	meal.push_back(c);

}

void Add(vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	string path, str = meal[0]->getProductName();
	if (str == "Chicken") {
		AddChicken(meal);
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt";
	}
	else if (str == "Burger")
	{
		AddBurger(meal);
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt";
	}
	else if (str == "Sandwiche") {
		AddSandwiche(meal);
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt";
	}
	else if (str == "Snack") {
		AddSnack(meal);
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt";
	}
	else if (str == "Sauce") {
		AddSauce(meal);
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt";
	}
	else if (str == "Drink")
	{
		AddDrink(meal);
		path = "C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt";
	}
	ofstream My(path);
	My << "";
	My.close();
	for (size_t i = 0; i < meal.size(); i++)
	{
		meal[i]->WriteMainFile();
	}
	system("pause");
	system("cls");
	UserDesign();
	ShowPart2Admin(products, meal);
}


void ShowPart2Admin(vector<vector<Meal*>>& products, vector<Meal*>& meal) {
	string arr[]{ "Menu","Edit","Delete","Add" };
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
		for (int i = 0; i < 4; i++) {
			string str;
			if (i == 2)
				str = "\t\t\t\t\t\t\t\t    ";
			else if (i == 3)
				str = "\t\t\t\t\t\t\t\t      ";
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
			if (index == 0)
			{
				ShowMealsInfoAdmin(products, meal);
			}
			else if (index == 1) {
				EditPart1Admin(products, meal);
			}
			else if (index == 2)
			{
				DeletePart1(products, meal);
			}
			else if (index == 3)
			{
				Add(products, meal);
			}
		}
		if (int(s) == 27) {
			system("cls");
			UserDesign();
			ShowMenuAdmin(products);

		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == 4) {
				index = 0;
			}
			system("cls");
			UserDesign();
		}
		else if (int(s) == 72) { // yuxari
			if (index == 0)
			{
				index = 3;
			}
			else
				index--;
			system("cls");
			UserDesign();
		}
	}
}


void ShowMenuAdmin(vector<vector<Meal*>>& products) {
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
			ShowPart2Admin(products, products[index]);
		}
		if (int(s) == 27) {
			system("cls");
			ShowPart1Admin(products);
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

void ShowBase(vector<string> foodbase, vector<vector<Meal*>>& products) {
	system("cls");
	UserDesign();
	char c = 205;
	char a = 201;
	char x = 187;
	char d = 186;
	char e = 188;
	char g = 200;
	int s;

	for (int i = 0; i < foodbase.size(); i++) {


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << setw(55) << a;
		for (size_t i = 0; i < 40; i++)
		{
			cout << c;
		}
		cout << x << endl;
		cout << setw(96) << d << "\r" << setw(85) << foodbase[i++] + " " + foodbase[i] + " g/ml" << "\r" << setw(55) << d << endl;
		cout << setw(55) << g;
		for (size_t i = 0; i < 40; i++)
		{
			cout << c;
		}
		cout << e << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << endl << endl;

	}
	system("pause");
	system("cls");
	FoodBase(products);

}
void AddFoodBase(vector<string>&foodbase) {
	UserDesign();
	cout << "\n\n\n";
	string name, weight;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Name: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	getline(cin, name);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << setw(80) << "Enter Weight: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> weight;
	foodbase.push_back(name);
	foodbase.push_back(weight);

	ofstream MyFile("C:\\Users\\"+getPath()+"\\source\\repos\\Restaurant-Management-System\\New folder\\foodbase.txt", ios::app);
	MyFile << name << "#" << weight << "#";
	MyFile.close();
	system("cls");
	UserDesign();

}

void FoodBase(vector<vector<Meal*>>& products) {
	string base;
	vector<string> foodbase;

	ReadFile(base, "C:\\Users\\" + getPath() + "\\source\\repos\\Restaurant-Management-System\\New folder\\foodbase.txt");
	FoodBaseCheck(base, foodbase);
	string arr[]{ "Show","Add" };
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
		for (int i = 0; i < 2; i++) {
			if (i == index) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << setw(62) << a;
				for (size_t i = 0; i < 20; i++)
				{
					cout << c;
				}
				cout << x << endl;
				cout << setw(83) << d << "\r" << setw(74) << arr[i] << "\r" << setw(62) << d << endl;
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
				cout << setw(83) << d << "\r" << setw(74) << arr[i] << "\r" << setw(62) << d << endl;
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
			if (index==0)
			{
				ShowBase(foodbase,products);
			}
			else if (index==1)
			{
				system("cls");
				AddFoodBase(foodbase);
			}
			
		}
		if (int(s) == 27) {
			system("cls");
			ShowPart1Admin(products);
		}
		else if (int(s) == 80) { // asagi
			index++;
			if (index == 2) {
				index = 0;
			}
			system("cls");
			UserDesign();
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
		}
	}
}

void ShowPart1Admin(vector<vector<Meal*>>& products) {
	string arr[]{ "Menu","FoodBase","Exit" };
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
			if (i==1)
			{
				str = "\t\t\t\t\t\t\t\t    ";
			}
			else
			{
				str = "\t\t\t\t\t\t\t\t      ";
			}
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
				ShowMenuAdmin(products);
			}
			else if (index == 1)
			{
				system("cls");
				FoodBase(products);
			}
			else if (index == 2)
			{
				system("cls");
				exit(0);
				break;

			}
		}
		if (int(s) == 27) {
			system("cls");
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
		c->setProductName("Chicken");
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

		c->setProductName("Burger");
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


void SandwicheCheck(vector<string>& arr, vector<Meal*>& sandwiches, vector<string>& foodbase) {
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

		c->setProductName("Sandwiche");
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
void SandwicheReadFiletoString(string& arr, vector<Meal*>& sandwiches, vector<string>& foodbase) {
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

void SnackCheck(vector<string>& arr, vector<Meal*>& snacks, vector<string>& foodbase) {
	vector<string> strArr;
	string str;
	string ctr;

	for (size_t j = 0; j < arr.size(); j++)
	{
		str = arr[j];
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '#') {
				strArr.push_back(ctr);
				ctr = "";
			}
			else {
				ctr += str[i];
			}
		}
		strArr.push_back("");
		int b = 0;

		Snack* c = new Snack();

		vector<Ingredient*> ings;

		c->setProductName("Snack");
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
void SnackReadFiletoString(string& arr, vector<Meal*>& snacks, vector<string>& foodbase) {
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


void SauceCheck(vector<string>& arr, vector<Meal*>& sauces, vector<string>& foodbase) {
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

		c->setProductName("Sauce");
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
void SauceReadFiletoString(string& arr, vector<Meal*>& sauces, vector<string>& foodbase) {
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


void DrinkCheck(vector<string>& arr, vector<Meal*>& drinks, vector<string>& foodbase) {
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

		c->setProductName("Drink");
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
void DrinkReadFiletoString(string& arr, vector<Meal*>& drinks, vector<string>& foodbase) {
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

		string base;
		vector<string> foodbase;

		ReadFile(base, "C:\\Users\\" + mainPath + "\\source\\repos\\Restaurant-Management-System\\New folder\\foodbase.txt");
		FoodBaseCheck(base, foodbase);

		ReadFile(arr, "C:\\Users\\" + mainPath + "\\source\\repos\\Restaurant-Management-System\\New folder\\chickens.txt");
		ChickenReadFiletoString(arr, chickens, foodbase);

		ReadFile(arr, "C:\\Users\\" + mainPath + "\\source\\repos\\Restaurant-Management-System\\New folder\\burgers.txt");
		BurgerReadFiletoString(arr, burgers, foodbase);

		ReadFile(arr, "C:\\Users\\" + mainPath + "\\source\\repos\\Restaurant-Management-System\\New folder\\sandwiches.txt");
		SandwicheReadFiletoString(arr, sandwiches, foodbase);

		ReadFile(arr, "C:\\Users\\" + mainPath + "\\source\\repos\\Restaurant-Management-System\\New folder\\snacks.txt");
		SnackReadFiletoString(arr, snacks, foodbase);

		ReadFile(arr, "C:\\Users\\" + mainPath + "\\source\\repos\\Restaurant-Management-System\\New folder\\sauces.txt");
		SauceReadFiletoString(arr, sauces, foodbase);


		ReadFile(arr, "C:\\Users\\" + mainPath + "\\source\\repos\\Restaurant-Management-System\\New folder\\drinks.txt");
		DrinkReadFiletoString(arr, drinks, foodbase);

		vector<vector<Meal*>>products{ chickens,burgers,sandwiches,snacks,sauces,drinks };


		system("pause");
		system("cls");
		ShowPart1Admin(products);
	}
};


void main() {


	System::User();

}






