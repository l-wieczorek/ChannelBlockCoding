#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <limits>
#include <cstdlib>
#include "Kanal.hpp"
#define PI 3.141592654

using namespace std;

int main()
{
	int nob; //number of bits
	//float Eb_N0_min, Eb_N0_max, step;
	try{
	cout << "Number of bits in one data frame delivered to encoder: ";
	cin >> nob;
	//if (cin.fail())
	//	throw "Type integer value";
	//cout << "Minimum value of Eb/N0: ";
	//cin >> Eb_N0_min;
	//if (cin.fail())
	//	throw "Type float value";
	//cout << "Maximum value of Eb/N0: ";
	//cin >> Eb_N0_max;
	//if (cin.fail())
	//	throw "Type float value";
	//cout << "Step change of parameter Eb/N0: ";
	//cin >> step;
	//if (cin.fail())
	//	throw "Type float value";
	}
	catch (const char* msg) {
		cerr << "Error! "<<  msg << endl;
		system("pause");
		exit(0);	
	}
	//if (Eb_N0_max > Eb_N0_min) {
	//	
	//}
	//else
	//	cout << "You put wrong values, run program one more time!" << endl;

	//generowanie macierzy
	int data[3][6] = { { 1, 0, 0, 1, 0, 1 },{ 0, 1, 0, 1, 1, 0 },{ 0, 0, 1, 0, 1, 1 } };
	int data_wektor[3] = { 1,1,0 };
	int wynik[6] = { 0,0,0,0,0,0 };

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			wynik[i] = wynik[i] || (data_wektor[j] * data[j][i]);
		}
	}
	//
	//dzielenie na bloki po 3
	const int frameLength = 3;
	int *inputData = new int[nob];
	srand(time(NULL));
	for (int i = 0; i < nob; i++) {
		inputData[i] = rand()%2;
	}
	for (int i = 0; i < nob; i++) {
		cout << inputData[i] << " ";
	}
	cout << endl;
	int var = 0;
	int **inputDataBlocks = new int*[nob/frameLength];
	for (int i = 0; i < nob / frameLength; i++) {
		inputDataBlocks[i] = new int[frameLength];
		for (int j = 0; j < frameLength; j++) {
			inputDataBlocks[i][j] = inputData[var];
			var++;
		}
	}

	for (int i = 0; i < nob / frameLength; i++) {
		for (int j = 0; j < frameLength; j++) {
			cout << inputDataBlocks[i][j] <<" " ;
		}
		cout << endl;
	}
	delete[] inputDataBlocks;
	delete[] inputData;
	//
	system("pause");
}

