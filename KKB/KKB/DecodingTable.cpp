#include "pch.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

using namespace std;

bool IfEqual(int a[], int b[], unsigned int size)
{
	return equal(a, a + size, b);
}

void DecodingTable(int *data) 
{
	int errorVector[7][6] = { {1,0,1,0,0,1}, {0,1,1,0,1,0}, {1,1,0,0,1,1}, {1,1,0,1,0,0}, {0,1,1,1,0,1}, {1,0,1,1,1,0}, {0,0,0,1,1,1} };
	int wrongVectors1[7][6] = { {1,0,1,0,0,0},{1,0,1,0,1,1},{1,0,1,1,0,1},{1,0,0,0,0,1},{1,1,1,0,0,1},{0,0,1,0,0,1},{0,0,1,0,0,0} };
	int wrongVectors2[7][6] = { {0,1,1,0,1,1},{0,1,1,0,0,0},{0,1,1,1,1,0},{0,1,0,0,1,0},{0,0,1,0,1,0},{1,1,1,0,1,0},{1,1,1,0,1,1} };
	int wrongVectors3[7][6] = { {1,1,0,0,1,0},{1,1,0,0,0,1},{1,1,0,1,1,1},{1,1,1,0,1,1},{1,0,0,0,1,1},{0,1,0,0,1,1},{0,1,0,0,1,0} };
	int wrongVectors4[7][6] = { {1,1,0,1,0,1},{1,1,0,1,1,0},{1,1,0,0,0,0},{1,1,1,1,0,0},{1,0,0,1,0,0},{0,1,0,1,0,0},{0,1,0,1,0,1} };
	int wrongVectors5[7][6] = { {0,1,1,1,0,0},{0,1,1,1,1,1},{0,1,1,0,0,1},{0,1,0,1,0,1},{0,0,1,1,0,1},{1,1,1,1,0,1},{1,1,1,1,0,0} };
	int wrongVectors6[7][6] = { {1,0,1,1,1,1},{1,0,1,1,0,0},{1,0,1,0,1,0},{1,0,0,1,1,0},{1,1,1,1,1,0},{0,0,1,1,1,0},{0,0,1,1,1,1} };
	int wrongVectors7[7][6] = { {0,0,0,1,1,0},{0,0,0,1,0,1},{0,0,0,0,1,1},{0,0,1,1,1,1},{0,1,0,1,1,1},{1,0,0,1,1,1},{1,0,0,1,1,0} };

	if (IfEqual(wrongVectors1[0], data, sizeof(wrongVectors1[0]) / sizeof(*wrongVectors1[0])) || IfEqual(wrongVectors1[1], data, sizeof(wrongVectors1[1]) / sizeof(*wrongVectors1[1])) || IfEqual(wrongVectors1[2], data, sizeof(wrongVectors1[2]) / sizeof(*wrongVectors1[2])) || IfEqual(wrongVectors1[3], data, sizeof(wrongVectors1[3]) / sizeof(*wrongVectors1[3])) || IfEqual(wrongVectors1[4], data, sizeof(wrongVectors1[4]) / sizeof(*wrongVectors1[4])) || IfEqual(wrongVectors1[5], data, sizeof(wrongVectors1[5]) / sizeof(*wrongVectors1[5])) || IfEqual(wrongVectors1[6], data, sizeof(wrongVectors1[6]) / sizeof(*wrongVectors1[6])))
	{
		for (int i = 0; i<sizeof(errorVector[0])/sizeof(*errorVector[0]); i++)
			data[i] = errorVector[0][i];
	}
	else if (IfEqual(wrongVectors2[0], data, sizeof(wrongVectors2[0]) / sizeof(*wrongVectors2[0])) || IfEqual(wrongVectors2[1], data, sizeof(wrongVectors2[1]) / sizeof(*wrongVectors2[1])) || IfEqual(wrongVectors2[2], data, sizeof(wrongVectors2[2]) / sizeof(*wrongVectors2[2])) || IfEqual(wrongVectors2[3], data, sizeof(wrongVectors2[3]) / sizeof(*wrongVectors2[3])) || IfEqual(wrongVectors2[4], data, sizeof(wrongVectors2[4]) / sizeof(*wrongVectors2[4])) || IfEqual(wrongVectors2[5], data, sizeof(wrongVectors2[5]) / sizeof(*wrongVectors2[5])) || IfEqual(wrongVectors2[6], data, sizeof(wrongVectors2[6]) / sizeof(*wrongVectors2[6])))
	{
		for (int i = 0; i<sizeof(errorVector[1]) / sizeof(*errorVector[1]); i++)
			data[i] = errorVector[1][i];
	}
	else if (IfEqual(wrongVectors3[0], data, sizeof(wrongVectors3[0]) / sizeof(*wrongVectors3[0])) || IfEqual(wrongVectors3[1], data, sizeof(wrongVectors3[1]) / sizeof(*wrongVectors3[1])) || IfEqual(wrongVectors3[2], data, sizeof(wrongVectors3[2]) / sizeof(*wrongVectors3[2])) || IfEqual(wrongVectors3[3], data, sizeof(wrongVectors3[3]) / sizeof(*wrongVectors3[3])) || IfEqual(wrongVectors3[4], data, sizeof(wrongVectors3[4]) / sizeof(*wrongVectors3[4])) || IfEqual(wrongVectors3[5], data, sizeof(wrongVectors3[5]) / sizeof(*wrongVectors3[5])) || IfEqual(wrongVectors3[6], data, sizeof(wrongVectors3[6]) / sizeof(*wrongVectors3[6])))
	{
		for (int i = 0; i<sizeof(errorVector[2]) / sizeof(*errorVector[2]); i++)
			data[i] = errorVector[2][i];
	}
	else if (IfEqual(wrongVectors4[0], data, sizeof(wrongVectors4[0]) / sizeof(*wrongVectors4[0])) || IfEqual(wrongVectors4[1], data, sizeof(wrongVectors4[1]) / sizeof(*wrongVectors4[1])) || IfEqual(wrongVectors4[2], data, sizeof(wrongVectors4[2]) / sizeof(*wrongVectors4[2])) || IfEqual(wrongVectors4[3], data, sizeof(wrongVectors4[3]) / sizeof(*wrongVectors4[3])) || IfEqual(wrongVectors4[4], data, sizeof(wrongVectors4[4]) / sizeof(*wrongVectors4[4])) || IfEqual(wrongVectors4[5], data, sizeof(wrongVectors4[5]) / sizeof(*wrongVectors4[5])) || IfEqual(wrongVectors4[6], data, sizeof(wrongVectors4[6]) / sizeof(*wrongVectors4[6])))
	{
		for (int i = 0; i<sizeof(errorVector[3]) / sizeof(*errorVector[3]); i++)
			data[i] = errorVector[3][i];
	}
	else if (IfEqual(wrongVectors5[0], data, sizeof(wrongVectors5[0]) / sizeof(*wrongVectors5[0])) || IfEqual(wrongVectors5[1], data, sizeof(wrongVectors5[1]) / sizeof(*wrongVectors5[1])) || IfEqual(wrongVectors5[2], data, sizeof(wrongVectors5[2]) / sizeof(*wrongVectors5[2])) || IfEqual(wrongVectors5[3], data, sizeof(wrongVectors5[3]) / sizeof(*wrongVectors5[3])) || IfEqual(wrongVectors5[4], data, sizeof(wrongVectors5[4]) / sizeof(*wrongVectors5[4])) || IfEqual(wrongVectors5[5], data, sizeof(wrongVectors5[5]) / sizeof(*wrongVectors5[5])) || IfEqual(wrongVectors5[6], data, sizeof(wrongVectors5[6]) / sizeof(*wrongVectors5[6])))
	{
		for (int i = 0; i<sizeof(errorVector[4]) / sizeof(*errorVector[4]); i++)
			data[i] = errorVector[4][i];
	}
	else if (IfEqual(wrongVectors6[0], data, sizeof(wrongVectors6[0]) / sizeof(*wrongVectors6[0])) || IfEqual(wrongVectors6[1], data, sizeof(wrongVectors6[1]) / sizeof(*wrongVectors6[1])) || IfEqual(wrongVectors6[2], data, sizeof(wrongVectors6[2]) / sizeof(*wrongVectors6[2])) || IfEqual(wrongVectors6[3], data, sizeof(wrongVectors6[3]) / sizeof(*wrongVectors6[3])) || IfEqual(wrongVectors6[4], data, sizeof(wrongVectors6[4]) / sizeof(*wrongVectors6[4])) || IfEqual(wrongVectors6[5], data, sizeof(wrongVectors6[5]) / sizeof(*wrongVectors6[5])) || IfEqual(wrongVectors6[6], data, sizeof(wrongVectors6[6]) / sizeof(*wrongVectors6[6])))
	{
		for (int i = 0; i<sizeof(errorVector[5]) / sizeof(*errorVector[5]); i++)
			data[i] = errorVector[5][i];
	}
	else if (IfEqual(wrongVectors7[0], data, sizeof(wrongVectors7[0]) / sizeof(*wrongVectors7[0])) || IfEqual(wrongVectors7[1], data, sizeof(wrongVectors7[1]) / sizeof(*wrongVectors7[1])) || IfEqual(wrongVectors7[2], data, sizeof(wrongVectors7[2]) / sizeof(*wrongVectors7[2])) || IfEqual(wrongVectors7[3], data, sizeof(wrongVectors7[3]) / sizeof(*wrongVectors7[3])) || IfEqual(wrongVectors7[4], data, sizeof(wrongVectors7[4]) / sizeof(*wrongVectors7[4])) || IfEqual(wrongVectors7[5], data, sizeof(wrongVectors7[5]) / sizeof(*wrongVectors7[5])) || IfEqual(wrongVectors7[6], data, sizeof(wrongVectors7[6]) / sizeof(*wrongVectors7[6])))
	{
		for (int i = 0; i<sizeof(errorVector[6]) / sizeof(*errorVector[6]); i++)
			data[i] = errorVector[6][i];
	}
}