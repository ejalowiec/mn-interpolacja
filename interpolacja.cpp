#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string imie, nazwisko;
int nr_tel;

int main() {

	fstream file;
	file.open("plik2.txt", ios::in);

	if (file.good() == false) {
		cerr << "File does not exist";
		exit(0);
	}

	int size;
	file >> size;

	int** arr = new int*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new int[2];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 2; j++)
			file >> arr[i][j];
	}
	
	file.close();

	cout << size << endl;
	cout << arr[0][0] << endl;
	cout << arr[1][0] << endl;
	cout << arr[2][0] << endl;
	cout << arr[3][0] << endl;
	cout << arr[4][0] << endl;
	cout << arr[0][1] << endl;
	cout << arr[1][1] << endl;
	cout << arr[2][1] << endl;
	cout << arr[3][1] << endl;
	cout << arr[4][1] << endl;


	return 0;
}