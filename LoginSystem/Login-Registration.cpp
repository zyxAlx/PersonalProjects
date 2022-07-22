#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int c;
	cout << "\t\t\t                 Welcome to the login page\n";
	cout << "\t\t\t       Menu\n";
	cout << "\t|Press 1 to LOGIN                    | " << endl;
	cout << "\t|Press 2 to REGISTER                 | " << endl;
	cout << "\t|Press 3 if you forgot your PASSWORD | " << endl;
	cout << "  \t|Press 4 to EXIT                     |" << endl;
	cout << "\n\t\t\t Please enter your choice: ";
	cin >> c;
	cout << endl;

	switch (c)
	{
	case 1:
		login();
		break;
	case 2:
		registration();
		break;
	case 3:
		forgot();
		break;
	case 4:
		cout<<"\t\t\t\Thank you!\n\n";
		break;
	default:
		system("CLS");
		cout << "Please select from the option given!\n";
		break;
		main();
	}

}
void login()
{
	int count;
	string userId, password, id, pass;
	system("CLS");
	cout << "\t\t\t Please enter the username and then the password";
	cout << "\t\t\t USERNAME: ";
	cin >> userId;
	cout << "\t\t\tPassword: ";
	cin >> password;
	ifstream input("records.txt");
	while (input >> id >> pass)
	{
		if (id == userId && pass == password)
		{
			count = 1;
			system("CLS");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << userId << "\n Your LOGIN is succesfull \n Thanks for loggin ! \n";
		main();
	}
	else {
		cout << "Wrong username or password";
	}
	

}
void registration()
{
	string ruserId, rpassword, rid, rpass;
	system("CLS");
	cout << "\t\t\t Enter the username: ";
	cin >> ruserId;
	cout << "\t\t\t Enter the password: ";
	cin >> rpassword;
	ofstream f1("records.txt", ios::app);
	f1 << ruserId << " " << rpassword << endl;
	system("CLS");
	cout << "\n\t\t\tRegistration succesfully!\n";
	main();
}
void forgot()
{
	int option;
	system("CLS");
	cout << "\t\t\t You forgot your password?";
	cout << "1. Yes."<<endl;
	cout << "2. No." << endl;
	cin >> option;
	system("CLS");
	switch (option)
	{
	case 1:
	{int count = 0;
	string suserId, sId, spass;
	cout << "\n\t\t\t Enter the username :";
	cin >> suserId;
	ifstream f2("records.txt");
	while (f2 >> sId >> spass)
	{
		if (sId == suserId)
		{
			count = 1;
		}
	}
	f2.close();
	if (count == 1)
	{
		cout << "Account found!\n";
		cout << "Your Password is: " << spass;
		main();


	}
	else {
		cout << "\n\tSorry! this is not a valid name \n";
		main();
	}
	break;
	}

	case 2:
	 {main();
	 }
	default:
		cout << "\t\t\t Please select one of the choice given!" << endl;
		forgot();
	}
}