// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "reader.cpp"


using namespace std;

int main(int argc, char** argv) {
	string path = " ";
	char choice = ' ';
	bool run = true;
	while (run) {
		cout << "Enter the path to your file to read (with the .txt attatched): ";
		cin >> path;
		Reader* r = new Reader();
		if (r->calculations(r->read(path)) == false) {
			cout << "Calculations not preformed correctly"<<endl;
		}
		else {
			cout << "Calculations performed correctly" << endl;
		}
		r->curve();
		


		while (true) {
			cout << "Do you want to contine? type 'y' for YES and 'n' for NO: ";
			cin >> choice;
			if (choice == 'n' || choice == 'N') {
				run = false;
				false;
			}
			else if (choice == 'y' || choice == 'Y') {
				r->reset();
				run = true;
				false;
			}
			else {
				cout << "You did not enter a valid responce."<<endl;
			}
		}
		
	}
	return 0;
}

/*
1.) Read class
	Needs to assign vars - create an object/string each time
2.) Math vars for st. dev ect.
3.) Probibility
4.) Writes strings following curve
5.) Exports a .out file
6.) Loop
*/