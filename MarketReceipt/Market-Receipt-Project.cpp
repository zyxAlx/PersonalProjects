#include <iostream>
#include <fstream>
#include<windows.h>
//system(color 0A);

using namespace std;
class shopping
{
private: 
	int pcode;
	float price;
	float dis;
	string pname;

public : 
	void menu();
	void administrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
};

void shopping::menu()
{
	m:
	int choice;
	string email;
	string password;

	cout << "\t\t\t\t______________________________________\n";
	cout << "\t\t\t\t                                        \n";
	cout << "\t\t\t\t               Market Main Menu          \n";
	cout << "\t\t\t\t                                        \n";
	cout << "\t\t\t\t______________________________________\n";
	cout << "\t\t\t\t                                        \n";
	cout << "\t\t\t\t|     1) Administrator     |\n";
	cout << "\t\t\t\t                                        \n";
	cout << "\t\t\t\t|     2) Buyer             |\n";
	cout << "\t\t\t\t                                        \n";
	cout << "\t\t\t\t|     3) Exit              |\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\t\t\t Please login\n";
		cout << "\t\t\t Enter email:  ";
		cin >> email;
		cout << "\t\t\t Password:  ";
		cin >> password;
		if (email == "alex1@email.com" && password == "me22")
		{
			administrator();
		}
		else
		{
			cout << "Invalid email/password";

		}
		break;
	case 2:
	{
		buyer();
	}
	case 3:
	{
		exit(0);
	}
	default:
	{
		cout << "please select one of the given options!" << endl;
	}
	}
	goto m;
}
void shopping::administrator()
{ m:
	int choice;
	cout << "\n\n\n\t\t\t Administrator menu";
	cout << "\n\t\t\t_______1) Add the product";
	cout << "\n\t\t\t_______2)Modify the product";
	cout << "\n\t\t\t_______3)Delete the product";
	cout << "\n\t\t\t_______4)Back to main menu";
	cout << "\n\n\t        Please enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		add();
		break;
	case 2:
		edit();
		break;
	case 3:
		rem();
		break;
	case 4:
		menu();
		break;
	default:
		cout << "Invalid choice";
	}
	goto m;
}
void shopping::buyer()
{   m:
	int choice;
	cout << "\t\t\t Buyer \n";
	cout << "\t\t\t_____________________\n";
	cout << "\t\t\t 1) Buy product \n";
	cout << "\t\t\t 2) Go back       \n";
	cout << "\t\t\t Enter your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		receipt();
		break;
	case 2:
		menu();
	default: 
		cout << "invalid choice";
	}
	goto m;
}
void shopping::add()
{   m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	cout << "\n\n\t\t\tAdd new product";
	cout << "\n\n\t Enter product code ";
	cin >> pcode;
	cout << "\n\n\t Name of the product ";
	cin >> pname;
	cout << "\n\n\t Price of the product";
	cin >> price;
	cout << "\n\n\t Discount on product ";
	cin >> dis;
	data.open("database.txt", ios::in);
	if (!data)
	{
		data.open("database.txt", ios::app | ios::out);
		data << " " << pcode << " " << pname << " " << price << " " << dis << " " << "\n";
		data.close();
	}
	else
	{
		data >> c >> n >> p >> d;
		while (!data.eof())
		{
			if (c == pcode)
			{
				token++;
			}
			data >> c >> n >> p >> d;
		}
		data.close();

		if (token == 1)

			goto m;

		else
		{
			data.open("database.txt", ios::app | ios::out);
			data << " " << pcode << " " << pname << " " << price << " " << dis << " " << "\n";
			data.close();
		}
	}
	cout << "\n\n\t\t Record inserted!";
}
void shopping::edit()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	int c;
	float p;
	float d;
	string n;
	cout << "\n\t\t\t Modify the record";
	cout << "\n\t\t\t Product code: ";
	cin >> pkey;

	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\nFile doesn t exist!";
	}
	else {
		
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			if (pkey == pcode)
			{
				cout <<     "\n\t\t Product new code :";
					cin >> c;
					cout << "\n\t\t Name of the product : ";
					cin >> n;
					cout << "\n\t\t Price : ";
					cin >> p;
					cout << "\n\t\t Discount : ";
					cin >> d;
					data1 << " " << c << " " << n << " " << p << " " << d << "\n";
					cout << "\n\n\t Record edited";
					
					token++;
			}
			else {
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >> price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
		if (token == 0)
		{
			cout << "\n\n Record not found sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data, data1;
	int pkey;
	int token = 0;
	cout << "\n\n\t Delete product";
	cout << "\n\n\t Product code: ";
	cin >> pkey;
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "file doesnt exist";

	}
	else {
		data1.open("database1.txt", ios::app | ios::out);
		data >> pcode >> pname >> price >> dis;
		while (!data.eof())
		{
			if (pcode == pkey)
			{
				cout << "\n\n\t Product deleted succesfully";
				token++;
			}
			else
			{
				data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
			}
			data >> pcode >> pname >>price >> dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt", "database.txt");
		if (token == 0)
		{
			cout << "\n\nRecord not found";
		}
	}
}
void shopping::list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout << "\n\n________________________________________\n";
	cout << "ProNo\t\t Name \t\t Price \n";
	cout << "\n\n__________________________________________\n";
	data >> pcode >> pname >> price >> dis;
	while (!data.eof())
	{
		cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
		data >> pcode >> pname >> price >> dis;
	}
	data.close();
}

void shopping::receipt()
{   m:
	fstream data;
	int arrc[100];
	int arrq[100];
	int choice;
	int c = 0;
	float amount = 0;
	float dis = 0;
	float total = 0;
	cout << "\n\n\t\t\t RECEIPT ";
	data.open("database.txt", ios::in);
	if (!data)
	{
		cout << "\n\nEmpty database";
	}
	else
	{   
		data.close();
		list();
		cout << "\n___________________________________\n";
		cout << "\n_____________________________________\n";
		cout << "\n        Please place the order         \n";
		cout << "\n__________________________________________\n";
		do
		{
			cout << "\n\nEnter Product code: ";
			cin >> arrc[c];
			cout << "\n\nEnter the product quantity: ";
			cin >> arrq[c];
			for (int i = 0; i < c; i++)
			{
				if (arrc[c] == arrc[i])
				{
					cout << "\n\n Same product code.Please try again";
					goto m;
				}
			}
			c++;
			cout << "\n\n Do you want to buy another product? \nIf yes press 1 else no : ";
			cin >> choice;
		} while (choice == 1);
		cout << "\n\n\t\t\t _______________________BILL__________________\n";
		cout << "\n Product no. \t\t Product Name \t\t Product quantity \t\t price \t\tAmount with discount\n\n";
		for (int i = 0; i < c; i++)
		{
			data.open("database.txt", ios::in);
			data >> pcode >> pname >> price >> dis;
			while (!data.eof())
			{
				if (pcode == arrc[i])
				{
					amount = price * arrq[i];
					dis = amount - (amount * dis / 100);
					total = total + dis;
					cout << "\n " <<pcode <<"\t\t" << pname <<"\t\t" << arrq[i] <<"\t\t" << price << amount << dis;
				}
				data >> pcode >> pname >> price >> dis;
			}
			
		}
		data.close();
		
	}
	cout << "\n Total Amount : " << total << endl<<endl;
}
int main()
{
	shopping s;
	s.menu();
}

