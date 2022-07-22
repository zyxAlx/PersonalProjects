#include<windows.h>
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;
void menu();
class ManageMenu {
protected:
	string userName;
public :
	ManageMenu()
	{ 
		system("color 0A"); 
		cout << "\n\n\n\n\n\n\t Enter Your Name to Continue : ";
		cin >> userName;
		system("CLS");
		menu();
	}
	~ManageMenu(){}
};
class Customers
{
public:
	string name, gender, adress;
	int age, mobileNo;
	static int cusID;
	char all[999];
	void detDetails()
	{
		ofstream output("old-customers.txt", ios::app);
		{
			cout << "Enter Customer ID";
			cin >> cusID;
			cout << "Enter Name";
			cin >> name;
			cout << "Enter Age";
			cin >> age;
			cout << "Enter Mobile Number";
			cin >> mobileNo;
			cout << "Enter Gender";
			cin >> gender;
			cout << "Enter Adress";
			cin >> adress;
		}
		output << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobil Number: " << mobileNo << "Adress: " << adress << "\nGender: " << gender << endl;
		output.close();
		cout << "\nSAVED\nNOTE: We save your details";
		
	}
	
	void showDetails()
	{
		ifstream in("old-customers.txt");
		{
			if (!in)
			{
				cout << "File Error!" << endl;
			}
			while (!(in.eof()))
			{
				in.getline(all,999);
				cout << all << endl;
			}
			in.close();
		}

	}
};

int Customers::cusID;
class Cabs
{public:
	int cabOption;
	int kilometers;
	float cabCost;
	static float cabCost1;
	void cabInformations()
	{
		cout << "Fastest cab service in the country" << endl;
		cout << "--------AST Cabs ---------\n" << endl;
		cout << "1.Standard Cab - 0.5$ for 1KM" << endl;
		cout << "2.Luxury Cab -1$ for 1 KM" << endl;
		
		cout << "\nThe cost for your jurney:" << endl;
		cout << "Enter which kind of Cab do you need: ";
		cin >> cabOption;
		cout << "Enter how many kilometers you want to travel: ";
		cin >> kilometers;

		int callCab;
		
		if (cabOption == 1)
		{
			cabCost = kilometers * 0.5;
			cout << "\n your cab will cost " << cabCost << endl;
			cout << "Press 1 to hire this cab: or";
			cout << "Press 2 to select another cab: ";
			cin >> callCab;

			system("CLS");
			if (callCab == 1)
			{
				cabCost1 = cabCost;
				cout << "\nSuccessfully hired cab" << endl;
				cout << "Goto Menu and the receipt"<<endl;
			}
			else if (callCab == 2)
			{
				cabInformations();
			}
			else {
				cout << "Invalid Input! Redirecting to menu\n Please Wait!" << endl;
				Sleep(999);
				system("CLS");
				cabInformations();
			}
		}
		else if (cabOption == 2) {
			cabCost = kilometers * 1;
			cout << "\n your cab will cost " << cabCost << endl;
			cout << "Press 1 to hire this cab: or";
			cout << "Press 2 to select another cab: ";
			cin >> callCab;

			system("CLS");
			if (callCab == 1)
			{
				cabCost1 = cabCost;
				cout << "\nSuccessfully hired cab" << endl;
				cout << "Goto Menu and the receipt" << endl;
			}
			else if (callCab == 2)
			{
				cabInformations();
			}
			else {
				cout <<"Invalid Input! Redirecting to menu\n Please Wait!" << endl;
				Sleep(1100);
				system("CLS");
				cabInformations();
			}


		}
		else {
			cout <<"Invalid Input! Redirecting to Menu\n Please Wait!" << endl;
			Sleep(1100);
			system("CLS");
			menu();
		}
		cout << "Press 1 to return to Menu: ";
		cin >> callCab;
		system("CLS");
		if (callCab == 1) {
			menu();
		}
		else {
			menu();
		}
	}

};

float Cabs::cabCost1;

class Booking
{
public:
	int days;
	int choiceHotel;
	int packChoice;
	static float hotelCost;
	void hotels()
	{
		cout << "how many days do you want to stay?"<<endl;
		cin >> days;
		system("CLS");
		string hotelNo[] = { "Hotel1","Hotel2","Hotel3" };
		for (int a = 0; a < 3; a++)
		{
			cout << (a + 1) << " . Hotel  --> " << hotelNo[a]<<endl;
		}
		
		cout << "\nCurrently we collaborated with above hotels" << endl;
		cout << "Press any key to back or \nEnter number of the hotel: ";
		cin >> choiceHotel;
		system("CLS");
		if (choiceHotel == 1)
		{
			cout << "WELCOME TO HOTEL1 \n" << endl<<endl;
			cout << "Packages offered by this hotel: \n" << endl;
			cout << "1. Standard Pack" << endl;
			cout << "\t All basic facilities for just 100$/night"<<endl;
			cout << "2. Premium Pack" << endl;
			cout << "\t All premium facilities for just 200$/night" << endl;
			cout << "3. Luxury Pack" << endl;
			cout << "\t All luxury facilities for just 240$/night" << endl;
			
			
			cout << "\n Press another key to back  or Enter your choice: "<<endl;
			cin >> packChoice;
			if (packChoice == 1)
			{
				hotelCost = 100*days;
				cout << "Succesfully! Go to Menu and take the receipt!" << endl;

			}
			else if (packChoice == 2)
			{
				hotelCost = 200*days;
				cout << "Succesfully! Go to Menu and take receipt! " << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 240*days;
				cout << "Succesfully! The best option you could chose!" << endl;
			}
			
			else {
				cout << "Invalid Input! Redirecting to Previous Menu!\nPlease Wait" << endl;
				Sleep(1100);
				system("CLS");
				hotels();
			}
			int gotomenu;
			cout << "\nPress 1 to redirect to main menu";
			cin >> gotomenu;
			if (gotomenu == 1)
			{
				menu();
			}
			else {
				menu();
			}
		}
		else if (choiceHotel == 2)
		{
			cout << "WELCOME TO HOTEL2 \n" << endl<<endl;
			cout << "Packages offered by this hotel: \n" << endl;
			cout << "1. Standard Pack" << endl;
			cout << "\t All basic facilities for just 100$/night" << endl;
			cout << "2. Premium Pack" << endl;
			cout << "\t All premium facilities for just 200$/night" << endl;
			cout << "3. Luxury Pack" << endl;
			cout << "\t All luxury facilities for just 240$/night" << endl;

			cout << "\n Press another key to back  or Enter your choice: " << endl;
			cin >> packChoice;
			if (packChoice == 1)
			{
				hotelCost = 100*days;
				cout << "Succesfully! Go to Menu and take the receipt!" << endl;

			}
			else if (packChoice == 2)
			{
				hotelCost = 200*days;
				cout << "Succesfully! Go to Menu and take receipt! " << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 240*days;
				cout << "Succesfully! The best option you could chose!" << endl;
			}
			else {
				cout << "Invalid Input! Redirecting to Previous Menu!\nPlease Wait" << endl;
				Sleep(1100);
				system("CLS");
				hotels();
			}
			int gotomenu;
			cout << "\nPress 1 to redirect to main menu";
			cin >> gotomenu;
			if (gotomenu == 1)
			{
				menu();
			}
			else {
				menu();
			}
		}
		else if (choiceHotel == 3)
		{
			cout << "WELCOME TO HOTEL3 \n" << endl<<endl;
			cout << "Packages offered by this hotel: \n" << endl;
			cout << "1. Standard Pack" << endl;
			cout << "\t All basic facilities for just 100$/night" << endl;
			cout << "2. Premium Pack" << endl;
			cout << "\t All premium facilities for just 200$/night" << endl;
			cout << "3. Luxury Pack" << endl;
			cout << "\t All luxury facilities for just 240$/night" << endl;

			cout << "\n Press another key to back  or Enter your choice: " << endl;
			cin >> packChoice;
			if (packChoice == 1)
			{
				hotelCost = 100*days;
				cout << "Succesfully! Go to Menu and take the receipt!" << endl;

			}
			else if (packChoice == 2)
			{
				hotelCost = 200*days;
				cout << "Succesfully! Go to Menu and take receipt! " << endl;
			}
			else if (packChoice == 3)
			{
				hotelCost = 240*days;
				cout << "Succesfully! The best option you could chose!" << endl;
			}
			else {
				cout << "Invalid Input! Redirecting to Previous Menu!\nPlease Wait" << endl;
				Sleep(1100);
				system("CLS");
				hotels();
			}
			int tomenu;
			cout << "\nPress 1 to redirect to main menu";
			cin >> tomenu;
			if (tomenu == 1)
			{
				menu();
			}
			else {
				menu();
			}
		}
		else {
		cout << "Invalid Input!Redirecting to Previous Menu\n Please Wait!" << endl;
		Sleep(1100);
		system("CLS");
		menu();
}

	}
	

};

float Booking::hotelCost;

class Charges : public Booking,Cabs,Customers
{
public:
	void printBill()
	{
		ofstream outf("receipt.txt");
		{
			outf << "----Travel Agency----" << endl;
			outf << "----Receipt----" << endl;
			outf << "___________________________________" << endl;

			outf << "Customer ID: " << Customers::cusID << endl << endl;
			outf << "Description\t\t Total" << endl;
			outf << "Hotel cost:\t\t" << fixed << setprecision(2) << Booking::hotelCost << endl;
			outf << "Travel(cab) cost\t " << fixed << setprecision(2) << Cabs::cabCost1 << endl;

			outf << "_____________________________________" << endl;
			outf << "Total Charge:\t\t" << fixed << setprecision(2) << Booking::hotelCost + Cabs::cabCost1 << endl;
			outf << "_____________________________________" << endl;
			outf << "---------Thank you!------------" << endl;
		}
		outf.close();
	}
	void showBill()
	{
		ifstream inf("receipt.txt");
		{
			if (!inf)
			{
				cout << "Error!Try again later" << endl;
			}
			while (!(inf.eof()))
			{
				inf.getline(all, 999);
				cout << all << endl;
			}
		}
		inf.close();
	}
};
void menu()
{
	int mainChoice;
	int inChoice;
	int gotomenu;
	cout << "\t\t ****Agency Travels****\n" << endl;
	cout << "___________________________Main Menu_________________________" << endl;

	cout << "\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "\t| Customer Management ->1                              |" << endl;
	cout << "\t| Cabs Management ->2                                  |" << endl;
	cout << "\t| Booking Management ->3                               |" << endl;
	cout << "\t| Charges & Bill ->4                                   |" << endl;
	cout << "\t| Close->5                                             |" << endl;
	cout << "\t| - -- - - - - - - - - - - - - - - - - - - - - - - - --  " << endl;

	cout << "\n Enter your Choice: ";
	cin >> mainChoice;
	system("CLS");
	Customers customer;
	Cabs cab;
	Booking b;
	Charges c;
	if (mainChoice == 1)
	{
		cout << "-------Customers-------\n" << endl;
		cout << "1. Enter New Customer" << endl;
		cout << "2. See Customers" << endl;
		cout << "\nEnter Choice: ";
		cin >> inChoice;
		system("CLS");
		if (inChoice == 1)
		{
			customer.detDetails();
		}
		else if (inChoice == 2)
		{
			customer.showDetails();
		}
		else {
			cout << "Invalid Input! Redirecting to Previous Menu \n Please Wait!" << endl;
			Sleep(1100);
			system("CLS");
			menu();
		}
		cout << "\nPress 1 to Redirect main menu " << endl;
		cin >> gotomenu;
		system("CLS");
		if (gotomenu == 1)
		{
			menu();
		}
		else {
			menu();
		}
	}
	else if (mainChoice == 2) {
		cab.cabInformations();
	}
	else if (mainChoice == 3)
	{
		cout << "-->Booking Hotels" << endl;
		b.hotels();
	}
	else if (mainChoice = 4)
	{
		cout << "--> Get your receipt " << endl;
		c.printBill();
		cout << "Your receipt is already printed you can get it from file path" << endl;
		cout << "to display your receipt in the screen,Enter 1: \nor Enter another key to go back to main menu :" << endl;
		cin >> gotomenu;
		if (gotomenu == 1)
		{
			system("CLS");
			c.showBill();
			cout << "\nPress 1 to redirect main menu: ";
			cin >> gotomenu;
			system("CLS");
			if (gotomenu == 1)
			{
				menu();
			}
			else {
				menu();
			}
		}
		else {
			system("CLS");
			menu();
		}
	}
	else if (mainChoice == 5)
	{
		cout << "-->  Have a great day!" << endl;
		Sleep(999);
		system("CLS");
		menu();
		
	}
	else {
		cout << "Invalid Input! Redirecting to Previous Menu \nPlease wait!" << endl;
		Sleep(1100);
		system("CLS");
		menu();
	}
}
int main()
{
	ManageMenu start;
	start.~ManageMenu();
	return 0;
	
}