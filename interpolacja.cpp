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

	double** arr = new double*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new double[2];

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < 2; ++j)
			file >> arr[i][j];
	}
	
	file.close();

	// ---------------------- end of reading file ----------------------


	// ---------------------- calculating Lagrange interpolating polynomial for a specified node ----------------------
	
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

	// ---------------------- calculating Newton interpolating polynomial for a specified node ----------------------

	double wxNewton = 0.0;
	//double tempNewtonXi = 0.0;
	//double tempNewtonFi = 0.0;
	double tempNewton = 0.0;
	
	double** arrNewton = new double*[size];
	for (int i = 0; i < size; ++i)
		arrNewton[i] = new double[size];

	// first column is f(xi)

	for (int i = 0; i < size; ++i)	{
		arrNewton[i][0] = arr[i][1];
	}
	cout << arrNewton[0][0] << endl;
	int tempOne = 1;
	int tempZero = 0;
	
	for (int i = 0; i < size; ++i) {
		cout << "i - start: " << i << endl;
		for (int j = 0; j < size; ++j) {
			cout << "size: " << size << endl;
			cout << "j - start: " << j << endl;
			if (j < size - tempOne) {
				tempNewton = arrNewton[j + tempOne][i] - arrNewton[j + tempZero][i];
				cout << arrNewton[j + tempOne][i] << endl;
				cout << arrNewton[j + tempZero][i] << endl;
				cout << arr[j + tempOne][0] << endl;
				cout << arr[j][0] << endl;
				tempNewton /= arr[j + tempOne][0] - arr[j][0];
				cout << tempNewton << endl;
				arrNewton[j + tempOne][i + 1] = tempNewton;
				cout << arrNewton[j][i] << endl;
				cout << arrNewton[j + tempOne][i + 1] << endl;
				cout << "j: " << j << endl;
				cout << "i: " << i << endl;
			}
		}
		tempOne++;
		tempZero++;
	}


	//for (int i = 0; i < size; ++i) {
	//	if (i != size) {
	//		cout << i << endl;
	//		cout << arr[i + 1][1] << endl;
	//		cout << arr[i][1] << endl;
	//		cout << arr[i + 1][0] << endl;
	//		cout << arr[i + 1][0] << endl;
	//		tempNewton = arr[i + 1][1] - arr[i][1];
	//		tempNewton /= arr[i + 1][0] - arr[i][0];
	//		arrNewton[i] = tempNewton;
	//		cout << tempNewton << endl;
	//	}
	//}





	// displaying data from file

	//cout << size << endl;
	//cout << arr[0][0] << endl;
	//cout << arr[0][1] << endl;
	//cout << arr[0 + 1][0] << endl;
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
	cout << "Value of Lagrange polynomial for this node: " << wxLagrange << endl;
	// 6.
	cout << "Value of Netwon polynomial for this node: " << wxNewton << endl;
	// 7.
	cout << "Coefficients of Newton polynomial: " << endl;


	delete[] arr;

	return 0;
}