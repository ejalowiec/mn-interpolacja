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

	if (size <= 1) {
		cerr << "Number of nodes is too low";
		exit(0);
	}

	double** arr = new double*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new double[2];

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 2; ++j)
			file >> arr[i][j];
	}
	
	file.close();

	// ---------------------- Lagrange interpolating polynomial  ----------------------
	//  calculating Lagrange interpolating polynomial for a specified node 

	float x; // entered number
	cout << "What node you want to calculate the value for: ";  cin >> x;

	double wxLagrange = 0.0;
	double temp = 0.0; 

	for (int i = 0; i < size; ++i) {
		temp = arr[i][1];
		for (int j = 0; j < size; j++) {
			if (i != j) {
				temp *= (x - arr[j][0]);
				temp /= (arr[i][0] - arr[j][0]);
			}
		}
		wxLagrange += temp;
	}

	// ---------------------- Newton interpolating polynomial ----------------------
	// calculating differential quotients

	double** arrNewton = new double*[size];
	for (int i = 0; i < size; ++i)
		arrNewton[i] = new double[size];

	// first column is f(xi)

	for (int i = 0; i < size; ++i)	{
		arrNewton[i][0] = arr[i][1];
	}

	int tempOne = 1;
	int tempZero = 0;
	double tempNewton = 0.0;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (j < size - tempOne) {
				tempNewton = arrNewton[j + tempOne][i] - arrNewton[j + tempZero][i];
				tempNewton /= arr[j + tempOne][0] - arr[j][0];
				arrNewton[j + tempOne][i + 1] = tempNewton;
			}
		}
		tempOne++;
		tempZero++;
	}

	//  calculating Newton interpolating polynomial for a specified node 

	double wxNewton = 0.0;
	double tempNewton1 = 0.0;

	for (int i = 0; i < size; ++i) {
		if (i == 0)
			tempNewton1 = 1 * arrNewton[0][0];
		else {
			tempNewton1 = arrNewton[i][i];

			for (int j = 0; j < i; ++j) {
				tempNewton1 *= (x - arr[j][0]);
			}
		}
		wxNewton += tempNewton1;
	}

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
	cout << "Value of Lagrange polynomial for this node: " << wxLagrange << endl;
	// 6.
	cout << "Value of Netwon polynomial for this node: " << wxNewton << endl;
	// 7.
	cout << "Coefficients of Newton polynomial: ";
	for (int i = 0; i < size; ++i) {
		cout << arrNewton[i][i];
		if (i != size - 1) cout << ", ";
	}

	cout << endl;

	// ---------------------- clean up ----------------------

	delete[] arrNewton;
	delete[] arr;

	return 0;
}