#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string imie, nazwisko;
int nr_tel;

int main() {

	// ---------------------- reading file ----------------------

	fstream file;
	file.open("test.txt", ios::in);

	if (!file.good()) {
		cerr << "File does not exist";
		exit(0);
	}

	int size;
	file >> size;

	int** arr = new int*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new int[2];

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 2; ++j)
			file >> arr[i][j];
	}
	
	file.close();

	// displaying data from file

	cout << size << endl;
	cout << arr[0][0] << endl;
	cout << arr[0][1] << endl;
	cout << arr[1][0] << endl;
	cout << arr[1][1] << endl;
	cout << arr[2][0] << endl;
	cout << arr[2][1] << endl;
	cout << arr[3][0] << endl;
	cout << arr[3][1] << endl;
	cout << arr[4][0] << endl;
	cout << arr[4][1] << endl;

	// 1. Napisz program, który będzie obliczał wartość wielomianu interpolacyjnego Lagrange’a i Newtona w dowolnym punkcie (niekoniecznie w węźle interpolacji) oraz współczynniki wielomianu interpolacyjnego w postaci Newtona.
	// Założenia:
	// a) Węzły interpolacji i wartości funkcji w węzłach oraz liczba węzłów są zmiennymi pobieranymi z pliku tekstowego.
	// b) Punkt, w którym obliczamy wartość wielomianu jest parametrem podawanym z klawiatury przez użytkownika.
	// c) W wyniku działania program wypisuje wartość wielomianu interpolacyjnego w zadanym punkcie obliczoną wzorem interpolacyjnym Lagrange’a oraz wzorem Newtona oraz wielomian interpolacyjny Newtona.



	// ---------------------- displaying results ----------------------

	cout << "No of nodes: " << size << endl;
	cout << "Interpolation nodes: "; 
	for (int i = 0; i < size; ++i) {
		cout << arr[i][0];
		if (i != size-1) cout << ", ";
	}
	cout << endl;
	cout << "Node values: ";
	for (int j = 0; j < size; ++j) {
		cout << arr[j][1];
		if (j != size - 1) cout << ", ";
	}

	cout << endl;
	delete[] arr;

	return 0;
}