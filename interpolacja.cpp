#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


// 1. Napisz program, który będzie obliczał wartość wielomianu interpolacyjnego Lagrange’a i Newtona w dowolnym punkcie (niekoniecznie w węźle interpolacji) oraz współczynniki wielomianu interpolacyjnego w postaci Newtona.
// Założenia:
// a) Węzły interpolacji i wartości funkcji w węzłach oraz liczba węzłów są zmiennymi pobieranymi z pliku tekstowego.
// b) Punkt, w którym obliczamy wartość wielomianu jest parametrem podawanym z klawiatury przez użytkownika.
// c) W wyniku działania program wypisuje wartość wielomianu interpolacyjnego w zadanym punkcie obliczoną wzorem interpolacyjnym Lagrange’a oraz wzorem Newtona oraz wielomian interpolacyjny Newtona.

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

	if (size == 1) {
		cerr << "Number of nodes is too low";
		exit(0);
	}

	int** arr = new int*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new int[2];

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 2; ++j)
			file >> arr[i][j];
	}
	
	file.close();

	// ---------------------- end of reading file ----------------------

	// ---------------------- calculating  ----------------------


	float x; // entered number
	cout << "What node you want to calculate the value for: ";  cin >> x;

	double wx = 0.0;
	double temp = 0.0; 

	for (int i = 0; i < size; ++i) {
		temp = arr[i][1];
		for (int j = 0; j < size; j++) {
			if (i != j) {
				temp *= (x - arr[j][0]);
				temp /= (arr[i][0] - arr[j][0]);
			}
		}
		wx += temp;
	}

	

	// displaying data from file

	//cout << size << endl;
	cout << arr[0][0] << endl;
	cout << arr[0][1] << endl;
	cout << arr[0 + 1][0] << endl;
	//cout << arr[1][0] << endl;
	//cout << arr[1][1] << endl;
	//cout << arr[2][0] << endl;
	//cout << arr[2][1] << endl;
	//cout << arr[3][0] << endl;
	//cout << arr[3][1] << endl;
	//cout << arr[4][0] << endl;
	//cout << arr[4][1] << endl;


	// ---------------------- displaying results ----------------------

	// 1.
	cout << "No of nodes: " << size << endl;
	// 2.
	cout << "Interpolation nodes: "; 
	for (int i = 0; i < size; ++i) {
		cout << arr[i][0];
		if (i != size-1) cout << ", ";
	}
	cout << endl;
	// 3.
	cout << "Node values: ";
	for (int j = 0; j < size; ++j) {
		cout << arr[j][1];
		if (j != size - 1) cout << ", ";
	}
	cout << endl;
	// 4.
	cout << "Node you entered: " << x << endl;
	// 5.
	cout << "Value for this node: " << wx << endl;


	delete[] arr;

	return 0;
}