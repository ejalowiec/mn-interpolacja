#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string imie, nazwisko;
int nr_tel;

int main() {
	cout << "Imie: "; cin >> imie;
	cout << "Nazwisko: "; cin >> nazwisko;
	cout << "Nr tel: "; cin >> nr_tel;

	fstream file;
	file.open("test.txt", ios::out);
	file << imie << endl;
	file << nazwisko << endl;
	file << nr_tel << endl;

	file.close();

	return 0;
}