#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string imie, nazwisko;
int nr_tel;

int main() {

	fstream file;
	file.open("test.txt", ios::in);

	if (file.good() == false) {
		cout << "File does not exist";
		exit(0);
	}

	string line;
	int noofline = 1;

	while (getline(file, line)) {
		switch (noofline) {
		case 1: imie = line; break;
		case 2: nazwisko = line; break;
		case 3: nr_tel = atoi(line.c_str()); break;
		}
		noofline++;
	}

	file.close();

	cout << imie << endl;
	cout << nazwisko << endl;
	cout << nr_tel << endl;

	return 0;
}