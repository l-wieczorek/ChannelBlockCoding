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
#include <fstream>
#define PI 3.141592654

using namespace std;

int main()
{
	int nob; //number of bits
	float Es_N0_min, Es_N0_max, step;
	fstream fileInputBits, fileEncodedBits, fileAfterCanalBits, fileDecodedBits;

	// files where outputs are stored 
	fileInputBits.open("InputBits.txt", ios::out);
	fileEncodedBits.open("EncodedBits.txt", ios::out);
	fileAfterCanalBits.open("AfterCanalBits.txt", ios::out);
	fileDecodedBits.open("DecodedBits.txt", ios::out);

	try {
		cout << "Number of bits in one data frame delivered to encoder: ";
		cin >> nob;
		if (cin.fail())
			throw "Type integer value";
		cout << "Minimum value of Es/N0: ";
		cin >> Es_N0_min;
		if (cin.fail())
			throw "Type float value";
		cout << "Maximum value of Es/N0: ";
		cin >> Es_N0_max;
		if (cin.fail())
			throw "Type float value";
		if (Es_N0_min >= Es_N0_max)
			throw "Minimum value cannot be greater than maximum one!";
		cout << "Step change of parameter Es/N0: ";
		cin >> step;
		if (cin.fail())
			throw "Type float value";
		if (step > (Es_N0_max - Es_N0_min))
			throw "Type proper step value";
	}
	catch (const char* msg) {
		cerr << "Error! " << msg << endl;
		system("pause");
		exit(0);
	}

	// generator matrix
	int GM[3][6] = { {1, 0, 1, 1, 0, 0},{1, 1, 1, 0, 1, 0},{0, 1, 1 ,0, 0, 1} };

	// test matrix
	int TM[3][6] = { {1, 0, 0, 1, 1, 0},{0, 1, 0, 0, 1, 1},{0, 0, 1, 1, 1, 1} };

	// transposed test matrix
	int TM_t[6][3] = { {1, 0, 0},{0, 1, 0},{0, 0, 1},{1, 0, 1},{1, 1, 1},{0, 1, 1} };

	// dividing input into 3-bits blocks
	const int frameLength = 3;
	const int encodedBlockLength = 6;
	int *inputData = new int[nob];
	srand(time(NULL));
	for (int i = 0; i < nob; i++) {
		inputData[i] = rand() % 2;
	}
	int var = 0;
	int **inputDataBlocks = new int*[nob / frameLength];
	for (int i = 0; i < nob / frameLength; i++) {
		inputDataBlocks[i] = new int[frameLength];
		for (int j = 0; j < frameLength; j++) {
			inputDataBlocks[i][j] = inputData[var];
			var++;
		}
	}

	// saving input blocks of bit into a file
	for (int i = 0; i < nob / frameLength; i++) {
		for (int j = 0; j < frameLength; j++) {
			fileInputBits << inputDataBlocks[i][j] << " ";
		}
		fileInputBits << endl; // potem tu bez tego 
	}

	// multiplying matrices to get code words
	int **encodedBlocks = new int*[nob / frameLength];

	for (int i = 0; i < nob / frameLength; i++)
	{
		encodedBlocks[i] = new int[encodedBlockLength]();
		for (int j = 0; j < encodedBlockLength; j++)
		{
			for (int k = 0; k < frameLength; k++)
			{
				encodedBlocks[i][j] = encodedBlocks[i][j] ^ (inputDataBlocks[i][k] & GM[k][j]);
			}
		}
	}

	// saving encoded bits into a file
	for (int i = 0; i < nob / frameLength; i++)
	{
		for (int j = 0; j < encodedBlockLength; j++)
		{
			fileEncodedBits << encodedBlocks[i][j] << " ";
		}
		fileEncodedBits << endl;
	}

	float **encodedBlocksAfterCanal = new float*[nob / frameLength];
	int **encodedBlocksAfterDecision = new int*[nob / frameLength];
	int **syndroms = new int*[nob / frameLength];
	int **bitsRestored = new int*[nob / frameLength];

	// transmission in canal with increasing Es_N0 and then saving blocks after canal into a file
	while (Es_N0_min <= Es_N0_max) {
		fileAfterCanalBits << Es_N0_min << endl;
		for (int i = 0; i < nob / frameLength; i++)
		{
			encodedBlocksAfterCanal[i] = new float[encodedBlockLength]();
			for (int j = 0; j < encodedBlockLength; j++)
			{
				kanal(Es_N0_min, encodedBlockLength, encodedBlocks[i], encodedBlocksAfterCanal[i]);
				fileAfterCanalBits << encodedBlocksAfterCanal[i][j] << " ";
			}
			fileAfterCanalBits << endl;
		}

		// decision-making algorythm in a receiver on a data from canal
		for (int i = 0; i < nob / frameLength; i++)
		{
			encodedBlocksAfterDecision[i] = new int[encodedBlockLength]();
			for (int j = 0; j < encodedBlockLength; j++)
			{
				if (encodedBlocksAfterCanal[i][j] > 0)
					encodedBlocksAfterDecision[i][j] = 1;
				else
					encodedBlocksAfterDecision[i][j] = 0;
			}
		}
		// decoding part 
		// syndroms calculating
		for (int i = 0; i < nob / frameLength; i++)
		{
			syndroms[i] = new int[frameLength]();
			for (int j = 0; j < frameLength; j++)
			{
				for (int k = 0; k < encodedBlockLength; k++)
				{
					syndroms[i][j] = syndroms[i][j] ^ (encodedBlocksAfterDecision[i][k] & TM_t[k][j]);
				}
			}
		}

		// TU JEST CHUJNIA
		for (int i = 0; i < nob / frameLength; i++)
		{
			bitsRestored[i] = new int[encodedBlockLength]();
			for (int j = 0; j < encodedBlockLength; j++)
			{
				if (syndroms[i] == 0)
				{
					for (int k = 0; k < frameLength; k++)
					{
						bitsRestored[i][j] = bitsRestored[i][j] ^ (syndroms[i][k] & TM[k][j]);
					}
				}
				else bitsRestored[i][j] = encodedBlocksAfterDecision[i][j];
			}
		}

		for (int i = 0; i < nob / frameLength; i++)
		{
			for (int j = 0; j < frameLength; j++)
			{
				cout << syndroms[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < nob / frameLength; i++)
		{
			for (int j = 0; j < encodedBlockLength; j++)
			{
				cout << bitsRestored[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		Es_N0_min += step;

	}

	delete[] inputDataBlocks;
	delete[] inputData;
	delete[] encodedBlocks;
	delete[] syndroms;
	fileInputBits.close();
	fileEncodedBits.close();
	fileAfterCanalBits.close();
	fileDecodedBits.close();

	system("pause");
}
