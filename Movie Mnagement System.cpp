#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<iomanip>
#include <windows.h>
#include<conio.h>
using namespace std;
void base();
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class USER {
protected:
	int temp_price[10]; int temp = 0; int count = 0;
	int price;
	string name;
	string number;
	int total_price = 0;
	int temp1;
	int seats_to_reserve = 0;
	int l = 0;
	string temp_movie[10];
	int chk = 0;
	int temp_seat[10];
public:

	
	void setname(string name) {
		this->name = name;
	}
	void setnumber(string number) {
		this->number = number;
	}

	void viewmovie2() {
		ifstream in1;
		in1.open("moviedet.txt", ios::in);
		if (!in1) {
			cout << "not";
		}
		else {
			string m;
			int s;
			int p;
			int seats;
			int num_records = 0;

			// Count the number of records in the file
			while (in1.read((char*)&s, sizeof(s))) {
				in1.read((char*)&m, sizeof(m));
				in1.read((char*)&p, sizeof(p));
				in1.read((char*)&seats, sizeof(seats));

				num_records++;
			}

			in1.close();

			system("CLS");
			cout << "\t---Movie Booking System---";
			gotoxy(0, 1); cout << "NO." << endl; gotoxy(13, 1); cout << "MOVIE"; gotoxy(34, 1); cout << "PRICE"; gotoxy(43, 1); cout << "SEATS AVAILABLE";
			// Read the records again using a for loop
			in1.open("moviedet.txt", ios::in);
			for (int i = 0; i < num_records; i++) {
				in1.read((char*)&s, sizeof(s));
				in1.read((char*)&m, sizeof(m));
				in1.read((char*)&p, sizeof(p));
				in1.read((char*)&seats, sizeof(seats));
				


				gotoxy(0, i + 2); cout << s; gotoxy(13, i + 2); cout << m; gotoxy(34, i + 2); cout << p << " RS"; gotoxy(43, i + 2); cout << seats;

			}
			
			cout << "\n\n\tPRESS ANY KEY TO CONTINUE:" << endl;
			_getch();

			system("CLS");
			in1.close();
			menu();

		}
	}
	void storecustomerinfo() {
		ofstream out1;
		out1.open("info.txt", ios::app | ios::binary);
		if (!out1) {
			cout << "not exist";
		}
		else {
			out1.write((char*)&name, sizeof(name));
			out1.write((char*)&number, sizeof(number));
			out1.close();
		}
	}
	friend class admin;
	void seat_no() {
		for (int o = 0; o < temp; o++) {
			if (temp_movie[l - 1] == "SPIDERMAN" || temp_movie[l - 1] == "IRONMAN" || temp_movie[l - 1] == "DON") {
				if (temp_movie[l - 1] == "DON") {
					string filename = "seat1.txt";
					ifstream infile(filename);
					if (!infile) {
						cerr << "Error: could not open file " << filename << endl;

					}

					string seatToCheck;
					cout << "Enter a seat number to check availability: ";
					cin >> seatToCheck;

					string seat;
					bool found = false;
					ofstream outfile(filename + ".tmp");
					while (infile >> seat) {
						if (seat == seatToCheck) {
							found = true;
						}
						else {
							outfile << seat << endl;
						}
					}

					infile.close();
					outfile.close();

					if (!found) {
						cout << "Seat " << seatToCheck << " is not available" << endl;
						cout << "Press ant key to continue" << endl;
						_getch();
						remove((filename + ".tmp").c_str());
						temp = temp - count;
						seat_no();
					}
					else {
						if (remove(filename.c_str()) != 0) {
							cerr << "Error: could not delete file " << filename << endl;

						}
						if (rename((filename + ".tmp").c_str(), filename.c_str()) != 0) {
							cerr << "Error: could not rename file " << filename + ".tmp" << " to " << filename << endl;

						}
						
						count++;
					}
				}
				if (temp_movie[l - 1] == "IRONMAN") {
					string filename = "seat2.txt";
					ifstream infile(filename);
					if (!infile) {
						cerr << "Error: could not open file " << filename << endl;

					}

					string seatToCheck;
					cout << "Enter a seat number to check availability: ";
					cin >> seatToCheck;

					string seat;
					bool found = false;
					ofstream outfile(filename + ".tmp");
					while (infile >> seat) {
						if (seat == seatToCheck) {
							found = true;
						}
						else {
							outfile << seat << endl;
						}
					}

					infile.close();
					outfile.close();

					if (!found) {
						cout << "Seat " << seatToCheck << " is not available" << endl;
						cout << "Press ant key to continue" << endl;
						_getch();
						remove((filename + ".tmp").c_str());
						temp = temp - count;
						seat_no();
					}
					else {
						if (remove(filename.c_str()) != 0) {
							cerr << "Error: could not delete file " << filename << endl;
						}
						if (rename((filename + ".tmp").c_str(), filename.c_str()) != 0) {
							cerr << "Error: could not rename file " << filename + ".tmp" << " to " << filename << endl;

						}
					
						count++;
					}
				}
				if (temp_movie[l - 1] == "SPIDERMAN") {
					string filename = "seat3.txt";
					ifstream infile(filename);
					if (!infile) {
						cerr << "Error: could not open file " << filename << endl;

					}

					string seatToCheck;
					cout << "Enter a seat number to check availability: ";
					cin >> seatToCheck;

					string seat;
					bool found = false;
					ofstream outfile(filename + ".tmp");
					while (infile >> seat) {
						if (seat == seatToCheck) {
							found = true;
						}
						else {
							outfile << seat << endl;
						}
					}

					infile.close();
					outfile.close();

					if (!found) {
						cout << "Seat " << seatToCheck << " is not available" << endl;
						cout << "Press ant key to continue" << endl;
						_getch();
						remove((filename + ".tmp").c_str());
						temp = temp - count;
						seat_no();
					}
					else {
						if (remove(filename.c_str()) != 0) {
							cerr << "Error: could not delete file " << filename << endl;

						}
						if (rename((filename + ".tmp").c_str(), filename.c_str()) != 0) {
							cerr << "Error: could not rename file " << filename + ".tmp" << " to " << filename << endl;

						}
					
						count++;
					}
				}
			}
			else {
				int op;
				
				cout << "Enter a seat number to check availability: ";
				cin >> op;
				_getch();
			}
		}
	}

	void signup() {
		system("CLS");
		string name, number;
		cout << "\t\t----WELCOME CUSTOMER----\n\n";
		cout << "\tENTER YOUR NAME:";
		cin >> name;
		cout << endl;
		cout << "\tENTER YOUR PHONE NUMBER:";
		cin >> number;
		setname(name);
		setnumber(number);
		storecustomerinfo();
		menu();
	}
	void updateSeats() {
		system("CLS");
		ifstream in;
		string movie_name;
		cout << "ENTER MOVIE NAME: ";
		cin >> movie_name;
		in.open("moviedet.txt", ios::in | ios::binary);
		if (!in) {
			cout << "File not found!";
		}
		else {
			ofstream out;
			out.open("temp.txt", ios::out | ios::binary);

			string m;
			int s, p, seats;
			int num_records = 0;

			// Count the number of records in the file
			while (in.read((char*)&s, sizeof(s))) {
				in.read((char*)&m, sizeof(m));
				in.read((char*)&p, sizeof(p));
				in.read((char*)&seats, sizeof(seats));
				num_records++;
			}

			in.close();
			in.open("moviedet.txt", ios::in | ios::binary);

			// Read the records again using a for loop
			for (int i = 0; i < num_records; i++) {
				in.read((char*)&s, sizeof(s));
				in.read((char*)&m, sizeof(m));
				in.read((char*)&p, sizeof(p));
				in.read((char*)&seats, sizeof(seats));

				if (m == movie_name) {
					temp_movie[l] = movie_name;
					cout << "\nENTER NUMBER SEATS YOU WANT TO PURCHASE: ";
					cin >> seats_to_reserve;
					if (seats_to_reserve >= seats) {
						cout << "\nSeats are unavailable!";
						cout << "press any key to continue" << endl;
						_getch();
						chk = 1;
					}
					else {
						temp_seat[l] = seats_to_reserve;
						seats -= seats_to_reserve;
						l++;
						chk = 0;

					}
				}

				out.write((char*)&s, sizeof(s));
				out.write((char*)&m, sizeof(m));
				out.write((char*)&p, sizeof(p));
				out.write((char*)&seats, sizeof(seats));
			}
			in.close();
			out.close();

			remove("moviedet.txt");
			rename("temp.txt", "moviedet.txt");

			if (chk == 1) {
				updateSeats();
			}
			system("CLS");
			temp = seats_to_reserve;
			calculateTotalPrice(movie_name, seats_to_reserve);
			viewmovie2();
		}
	}

	void calculateTotalPrice(string movie_name, int num_seats) {
		ifstream in;
		in.open("moviedet.txt", ios::in | ios::binary);
		if (!in) {
			cout << "File not found!";

		}
		else {
			string m;
			int s, p, seats;
			int num_records = 0;

			// Count the number of records in the file
			while (in.read((char*)&s, sizeof(s))) {
				in.read((char*)&m, sizeof(m));
				in.read((char*)&p, sizeof(p));
				in.read((char*)&seats, sizeof(seats));
				num_records++;
			}

			in.close();
			in.open("moviedet.txt", ios::in | ios::binary);

			// Read the records again using a for loop
			for (int i = 0; i < num_records; i++) {
				in.read((char*)&s, sizeof(s));
				in.read((char*)&m, sizeof(m));
				in.read((char*)&p, sizeof(p));
				in.read((char*)&seats, sizeof(seats));

				if (m == movie_name) {
					total_price = total_price + (p * num_seats);

				}
			}

			in.close();
			cout << "SUCESSFULLY PURCHASED :D" << endl;
			cout << "\nPRESS ANY KEY TO CONTINUE:" << endl;
			_getch();
			system("CLS");
			seat_no();
			menu();
		}

	}

	virtual void checkout() {
		system("CLS");
		cout << "\t\t\tCHECKOUT" << endl;
		cout << "\t\t*************************" << endl;
		cout << "\n\t\tCUSTOMER NAME: " << name << endl;
		cout << "\t\tPHONE NUMBER: " << number << endl;
		cout << "\n\t\tMOVIES " << "\t\tSEATS" << endl;
		for (int j = 0; j < l; j++) {
			cout << "\t\t" << temp_movie[j] << "\t\t" << temp_seat[j] << endl;
		}
		cout << "\n\t\tTOTAL BILL: " << total_price << endl;
		cout << "\t\t*************************" << endl;
	}


	virtual	void menu() {
		int choice;

		system("CLS");
		cout << "\t\t------------------------------------------------\n";
		cout << "\t\t\tWELCOME TO USER INTERFACE\n";
		cout << "\t\t------------------------------------------------\n";
		cout << "1.VIEW MOVIE DETAILS:\n2.BUY TICKETS\n3.CHECKOUT \n0.TO EXIT" << "\nchoice:";
		cin >> choice;
		if (choice == 1) {
			cout << endl;

			viewmovie2();

		}
		if (choice == 2) {

			updateSeats();
		}
		if (choice == 3) {
			checkout();
		}
		if (choice == 0) {
			system("CLS");
			base();
		}

		else if (choice < 1 && choice>4) {
			cout << "YOU ENTERED WRONG CHOICE\nPLEASE TRY AGAIN\n\nPRESS ANY KEY TO CONTINUE";
			_getch();
			system("CLS");
			menu();
		}
	}

};
class Discount :public USER {
private:
	int temp_total;
	int temp_discount;
public:
	void checkVoucher() {
		string vouchercode;
		system("CLS");
		cout << "Enter PROMO CODE FOR DISCOUNT" << endl;
		cin >> vouchercode;
		ifstream file("voucher.txt");
		string code;

		if (file.is_open()) {
			while (getline(file, code)) {
				if (code == vouchercode) {
					if (code == "bili20") {
						file.close();
						temp_discount = 20;
						checkout(20);
						break;
					}
					if (code == "ash30") {
						file.close();
						temp_discount = 30;
						checkout(30);
						break;
					}
					if (code == "ashbil40") {
						file.close();
						temp_discount = 40;
						checkout(40);
						break;
					}

				}

			}
			file.close();
			if (code != vouchercode) {

				file.close();
				cout << "YOU HAVE ENTERED THE WRONG CODE\n\nWRITE CORRECT CODE AGAIN\n\tTHANKYOU!!";
				_getch();
				checkVoucher();
			}
		}

	}


	void checkout(int dis) {
		USER::checkout();
		cout << "\n\t\tDISCOUNT: " << temp_discount << "%";
		temp_total = total_price;
		temp_total = temp_total - ((float)temp_total * dis) / 100;
		cout << "\n\t\tBILL AFTER DISCOUNT:  " << temp_total << endl;
		cout << "\t\t*************************" << endl;
	}

	void menu() {
		int choice;
		system("CLS");
		cout << "\t\t------------------------------------------------\n";
		cout << "\t\t\tWELCOME TO USER MANUAL\n";
		cout << "\t\t------------------------------------------------\n";
		cout << "1.VIEW MOVIE DETAILS:\n2. BUY TICKETS\n3.CHECKOUT \n0.TO EXIT" << "\nchoice:";
		cin >> choice;
		if (choice == 1) {
			cout << endl;

			viewmovie2();

		}
		if (choice == 2) {
			updateSeats();
		}
		if (choice == 3) {
			checkVoucher();
		}
		if (choice == 0) {
			system("CLS");
			base();
		}
	}
};

class admin {
protected:
	int temp_price[10];
	int l = 0;
	int price;
public:
	
	int sno = 0;
	bool verify() {
		system("CLS");
		ifstream in2;
		in2.open("verify.txt", ios::in);
		if (!in2) {
			cout << "file not exist";
		}
		else {
			string password;
			string pass;
			cout << "\tENTER THE PASSWORD TO GET ACCESS\n\tPASSWORD:";
			cin >> password;
			while (!in2.eof()) {
				getline(in2, pass);
			}
			if (password == pass) {
				cout << "\tACCESS GRANTED\n";
				cout << "PRESS ANY KEY TO CONTINUE:";
				_getch();
				return true;
			}
			else {
				return false;
			}
		}
	}
	void addmovie() {
		ifstream in1;
		string m;
		int s;
		int p;
		int seats;
		int num_records = 0;
		in1.open("moviedet.txt", ios::in);
		if (!in1) {
			cout << "not";
		}
		else {


			// Count the number of records in the file
			while (in1.read((char*)&s, sizeof(s))) {
				in1.read((char*)&m, sizeof(m));
				in1.read((char*)&p, sizeof(p));
				in1.read((char*)&seats, sizeof(seats));
				num_records++;
			}

			in1.close();
		}
		ofstream out;
		out.open("moviedet.txt", ios::app | ios::binary);
		string movie;
		int no_seats;
		int price;
		cout << endl;
		cout << "ENTER MOVIE NAME:";
		cin >> movie;
		sno = num_records + 1;
		cout << "\nPRICE:";
		cin >> price;
		cout << "Enter no of seats" << endl;
		cin >> no_seats;
		if (!out) {
			cout << "not exist";
		}
		else {
			out.write((char*)&sno, sizeof(sno));
			out.write((char*)&movie, sizeof(movie));
			out.write((char*)&price, sizeof(price));
			out.write((char*)&no_seats, sizeof(no_seats));
			cout << endl;
			out.close();
		}

		cout << "press any key to continue" << endl;
		_getch();
		system("CLS");
		menu();

	}
	USER U;
	void viewmovie2() {

		ifstream in1;
		in1.open("moviedet.txt", ios::in);
		if (!in1) {
			cout << "not";
		}
		else {
			string m;
			int s;
			int p;
			int seats;
			int num_records = 0;

			// Count the number of records in the file
			while (in1.read((char*)&s, sizeof(s))) {
				in1.read((char*)&m, sizeof(m));
				in1.read((char*)&p, sizeof(p));
				in1.read((char*)&seats, sizeof(seats));

				num_records++;
			}

			in1.close();

			system("CLS");
			cout << "\t---Movie Booking System---";
			gotoxy(0, 1); cout << "NO." << endl; gotoxy(13, 1); cout << "MOVIE"; gotoxy(34, 1); cout << "PRICE"; gotoxy(43, 1); cout << "SEATS AVAILABLE";
			// Read the records again using a for loop
			in1.open("moviedet.txt", ios::in);
			for (int i = 0; i < num_records; i++) {
				in1.read((char*)&s, sizeof(s));
				in1.read((char*)&m, sizeof(m));
				in1.read((char*)&p, sizeof(p));
				in1.read((char*)&seats, sizeof(seats));
				//	cout << endl;
				//	cout << s << "\t\t" << m << "\t\t" << p;


				gotoxy(0, i + 2); cout << s; gotoxy(13, i + 2); cout << m; gotoxy(34, i + 2); cout << p << " RS"; gotoxy(43, i + 2); cout << seats;

			}
			cout << "\n\npress any key to continue" << endl;
			_getch();
			system("CLS");
			in1.close();
			menu();

		}
	}
	void update_price() {
		string temp_movie[10];
		ifstream in;
		string movie_name;
		cout << "enter the name of movie: ";
		cin >> movie_name;
		in.open("moviedet.txt", ios::in | ios::binary);
		if (!in) {
			cout << "File not found!";
		}
		else {
			ofstream out;
			out.open("temp.txt", ios::out | ios::binary);
			string m;
			int s, p, seats;
			int num_records = 0;
			// Count the number of records in the file
			while (in.read((char*)&s, sizeof(s))) {
				in.read((char*)&m, sizeof(m));
				in.read((char*)&p, sizeof(p));
				in.read((char*)&seats, sizeof(seats));
				num_records++;
			}
			in.close();
			in.open("moviedet.txt", ios::in | ios::binary);
			// Read the records again using a for loop
			for (int i = 0; i < num_records; i++) {
				in.read((char*)&s, sizeof(s));
				in.read((char*)&m, sizeof(m));
				in.read((char*)&p, sizeof(p));
				in.read((char*)&seats, sizeof(seats));
				if (m == movie_name) {
					temp_movie[l] = movie_name;
					cout << "enter new price: ";
					cin >> price;
					temp_price[l] = price;
					p = price;
					//cout << "price to be set " << p << endl;
					l++;
				}
				out.write((char*)&s, sizeof(s));
				out.write((char*)&m, sizeof(m));
				out.write((char*)&p, sizeof(p));
				out.write((char*)&seats, sizeof(seats));
			}
			in.close();
			out.close();
			remove("moviedet.txt");
			rename("temp.txt", "moviedet.txt");
			system("CLS");
			viewmovie2();
		}
	}

	void getcustomerinfo() {
		ifstream in3;
		in3.open("info.txt", ios::in);
		if (!in3) {
			cout << "not";
		}
		else {
			string na;
			string nu;
			int num_records = 0;

			// Count the number of records in the file
			while (in3.read((char*)&na, sizeof(na))) {
				in3.read((char*)&nu, sizeof(nu));
				num_records++;

			}
			in3.close();
			// Read the records again using a for loop
			in3.open("info.txt", ios::in);
			system("CLS");
			cout << "\t\tCUSTOMER INFO" << endl;
			cout << "NAME"; gotoxy(10, 1); cout << "CONTACT";
			for (int i = 0; i < num_records; i++) {
				in3.read((char*)&na, sizeof(na));
				in3.read((char*)&nu, sizeof(nu));
				gotoxy(0, i + 2); cout << na; gotoxy(10, i + 2); cout << nu << endl;
			}

			in3.close();
			cout << "\npress any key to continue" << endl;
			_getch();
			system("CLS");
			menu();
		}


	}
	void menu() {
		int choice;
		cout << "WELCOME TO ADMIN INTERFACE\n" << "1.ADD MOVIE\n2.VIEW MOVIE\n3.UPDATE PRICE\n4.CUSTOMER INFO\n0.TO EXIT" << "\nchoice:";
		cin >> choice;
		if (choice == 1) {
			system("CLS");
			addmovie();
		}
		if (choice == 2) {
			system("CLS");
			viewmovie2();
		}
		if (choice == 3) {
			system("CLS");
			update_price();
		}
		if (choice == 4) {
			system("CLS");

			getcustomerinfo();
		}
		if (choice == 0) {
			system("CLS");
			base();
		}
	}
	void signup() {
		system("CLS");
		bool access;
		int key = 0;
		cout << "\t\t----WELCOME ADMIN----\n\n";
		access = verify();
		if (access == true) {

			system("CLS");
			menu();

		}
		if (access == false) {
			for (int a = 0; a < 1; a++) {
				cout << "\nINCORRECT PASSWORD\n";
				cout << "PRESS ANY KEY TO RE-ENTER PASSWORD:";
				_getch();
				verify();

			}
		}
	}
};

void base() {
	int option;
	int choice;

	cout << "\t\t------------------------------------------------\n";
	cout << "\t\t\tWELCOME TO MOVIE BOOKING SYSTEM\n";
	cout << "\t\t------------------------------------------------\n";
	cout << "Select how you want to access:\n1:USER\n2:ADMIN\n0.EXIT\nEnter:";
	cin >> option;
	system("CLS");
	if (option == 1) {
		cout << "DEAR CUSTOMER ,\nDO YOU HAVE MEMBERSHIP ?\n\nPRESS 1 FOR YES\t\tPRESS 2 FOR NO\n\nCHOICE:";
		cin >> choice;
		if (choice == 1) {
			Discount d;
			d.signup();

		}
		if (choice == 2) {
			USER u;
			u.signup();
		}

	}
	if (option == 2) {
		admin a;
		a.signup();
	}
	if (option == 0) {
		exit;
	}
	else {
		cout << "YOU ENTERED WRONG CHOICE\nPLEASE TRY AGAIN\n\nPRESS ANY KEY TO REDIRECT ON THE MAIN PAGE:";
		_getch();
		system("CLS");
		base();
	}
}
int main() {
	system("color E1");
	base();
}
