#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void mainMenu();


class Management
{
public:
	Management()
	{
		mainMenu();
	}
};
class Details {
public:
	static string  name, gender;
	int phoneNo;
	int age;
	string address;
	static int Id;
	char arry[100];

	void information()
	{
		cout << "\n Enter the customer ID: ";
		cin >> Id;
		cout << "Enter the name :";
		cin >> name;
		cout << "Enter the age:";
		cin >> age;
		cout << "Adress: ";
		cin >> address;
		cout << "Gender: ";
		cin >> gender;
	}
};

int Details::Id;
string Details::name;
string Details::gender;

class registration {
public:
	static int choice;
	int choice1;
	int back;
	static float charges;

	void flights()
	{
		string  flightN[] = { "Bucuresti","Cluj","Iasi","America","Madrid" };
		for (int i = 0; i < 5; i++)
		{
			cout << (i + 1) << ".flight to" << flightN[i] << endl;
		}
		cout << "\n\t\t Welcome to the Airlines!" << endl;
		cout << "Press the number asociated with the country which do you want to travel!";
		cin >> choice;
		switch (choice)
		{
		case 1:{
			cout << "The airline to Bucuresti";
			cout << "Chose one of the above options:"<<endl;
			cout << "Fly 1: 1200$ at 9:00-12:00";
			cout << "Fly 2: 1300$ at 10:00-13:00";
			cout << "Fly 3: 1400$ at 15:00-18:30";
			cout << "\t\tEnter your option: ";
			
			cin >> choice1;
			if (choice1 == 1)
			{
				cout << "You have selected first option! This flight will cost is 1200$";
				charges = 1200;
				break;
			}
			else if (choice1 == 2)
			{
				cout << "You have selected second option!This flight will cost 1300$";
				charges = 1300;

			}
			else if (choice1 == 3)
			{
				
				cout << "You have selected the third option! This flight will cost 1400$";
				charges = 1400;
			}
			else {
				cout << "This option doesn t exist";
				flights();
			}
			break;
		}
		case 2:
		{
			cout << "The airline to Cluj";
			cout << "Chose one of the above options:" << endl;
			cout << "Fly 1: 1200$ at 9:00-12:00";
			cout << "Fly 2: 1300$ at 10:00-13:00";
			cout << "Fly 3: 1400$ at 15:00-18:30";
			cout << "\t\tEnter your option: ";
			cin >> choice1;
			if (choice1 == 1)
			{
				cout << "You have selected first option! This flight will cost is 1200$";
				charges = 1200;
			}
			else if (choice1 == 2)
			{
				cout << "You have selected second option!This flight will cost 1300$";
				charges = 1300;
			}
			else if (choice1 == 3)
			{
				cout << "You have selected the third option! This flight will cost 1400$";
				charges = 1400;
			}
			else {
				cout << "This option doesn t exist";
				flights();
			}
			break;
		}
		case 3: {cout << "The airline to Iasi"<<endl;
			cout << "Chose one of the above options:" << endl;
			cout << "Fly 1: 1200$ at 9:00-12:00";
			cout << "Fly 2: 1300$ at 10:00-13:00";
			cout << "Fly 3: 1400$ at 15:00-18:30"; }
			  cout << "\t\tEnter your option: ";
			  cin >> choice1;
			  if (choice1 == 1)
			  {
				  cout << "You have selected first option! This flight will cost is 1200$";
				  charges = 1200;
			  }
			  else if (choice1 == 2)
			  {
				  cout << "You have selected second option!This flight will cost 1300$";
				  charges = 1300;
			  }
			  else if (choice1 == 3)
			  {
				  cout << "You have selected the third option! This flight will cost 1400$";
				  charges = 1400;
			  }
			  else {
				  cout << "This option doesn t exist";
				  flights();
			  }


		case 4: {cout << "The airline to America";
			cout << "Chose one of the above options:" << endl;
			cout << "Fly 1: 1200$ at 9:00-12:00";
			cout << "Fly 2: 1300$ at 10:00-13:00";
			cout << "Fly 3: 1400$ at 15:00-18:30"; }
			  cout << "\t\tEnter your option: ";
			  cin >> choice1;
			  if (choice1 == 1)
			  {
				  cout << "You have selected first option! This flight will cost is 1200$";
				  charges = 1200;
				 
			  }
			  else if (choice1 == 2)
			  {
				  cout << "You have selected second option!This flight will cost 1300$";
				  charges = 1300;
			  }
			  else if (choice1 == 3)
			  {
				  cout << "You have selected the third option! This flight will cost 1400$";
				  charges = 1400;
			  }
			  else {
				  cout << "This option doesn t exist";
				  flights();
			  }

		case 5: {cout << "The airline to Madrid";
			cout << "Chose one of the above options:" << endl;
			cout << "Fly 1: 1200$ at 9:00-12:00";
			cout << "Fly 2: 1300$ at 10:00-13:00";
			cout << "Fly 3: 1400$ at 15:00-18:30"; }
			  cout << "\t\tEnter your option: ";
			  cin >> choice1;
			  if (choice1 == 1)
			  {
				  cout << "You have selected first option! This flight will cost is 1200$";
				  charges = 1200;
			  }
			  else if (choice1 == 2)
			  {
				  cout << "You have selected second option!This flight will cost 1300$";
				  charges = 1300;
			  }
			  else if (choice1 == 3)
			  {
				  cout << "You have selected the third option! This flight will cost 1400$";
				  charges = 1400;
			  }
			  else {
				  cout << "This option doesn t exist";
				  flights();
			  }

		default: {cout << "This option is invalid!"; }
		}
		
	}
};
class ticket : public registration, Details
{
public:
	void Bill()
	{
		string destination = "";
		ofstream outf("records.txt");
		{
			outf << "________Alex Airlines_________" << endl;
			outf << "Customer Name: " << Details::name << endl;
			outf << "Customer Gender: " << Details::gender << endl;
			outf << "\tDescription\n";

			if (registration::choice == 1)
			{
				destination = "Bucuresti";
			}
			else if (registration::choice == 2)
			{
				destination = "Cluj";
			}
			else if (registration::choice == 3)
			{
				destination = "Iasi";
			}
			else if (registration::choice == 4)
			{
				destination = "America";
			}
			else if (registration::choice == 5)
			{
				destination = "Madrid";
			}
			outf << "Destination   " << destination << endl;
			outf << "Flight will cost : " << registration::charges << endl;
		}
		outf.close();
	}
	void displayBill()
	{
		ifstream ifs("records.txt");
		{
			if (!ifs)
			{
				cout << "Error!";
			}
			while (!ifs.eof())
			{
				ifs.getline(arry, 100);
				cout << arry << endl;
			}
			ifs.close();
		}
	}
};

void mainMenu() {
	int lChoice;
	int sChoice;
	
	int back;
	cout << "\t          Alex Airlines \n" << endl;
	cout << "\t         &&&Main Menu&&&\n" << endl;
	cout << endl << endl;
	cout << "\t\t Press 1 to add the Customer Details  \t" << endl;
	cout << "\t\t Press 2 for Registration \t" << endl;
	cout << "\t\t Press 3 for Tiket\t" << endl;
	cout << "\t\tPress 4 to Exit\t" << endl;
	cout << endl;

	cout << "Enter your choice here : ";
	cin >> lChoice;
	Details d;
	registration r;
	ticket t;

	switch (lChoice)
	{
	case 1:
	{
		cout << "_______Customers________ \n" << endl;
		d.information();
		cout << "Press 1 to go to Main Menu ";
		cin >> back;
		if (back == 1)
		{
			mainMenu();
		}
		else
		{
			mainMenu();
		}
		break;
	}
	case 2:
	{
		cout << "Serch a flight in the system  \n" << endl;
		r.flights();
		mainMenu();
		break;
	}
	case 3:
	{
		cout << "_______TAKE YOUR TIKET_______\n" << endl;
		t.Bill();
		cout << "Collect your ticket!" << endl;
		cout << "Press 1 to see the ticker!" << endl;
		cin >> back;
		if (back == 1)
		{
			t.displayBill();
			cout << "Press any key to go back to Menu."<<endl;
			cin >> back;
			mainMenu();
		}
	case 4:
	{
		cout << "Thank you for visit our site!" << endl;
		break;
	}
	default:
		cout << "Chose a valid option!" << endl;
		mainMenu();
	}
	}
}
float registration::charges;
int registration::choice;

int main()
{
	Management Mobj;
	return 0;
}

