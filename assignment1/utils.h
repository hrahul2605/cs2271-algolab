#ifndef _MODULE_GENERAL
#define _MODULE_GENERAL

#include <cstdio>
#include <fstream>

template <typename T>
void readFromFileToArray(T arr[], int size, const char *fileName)
{

	std::ifstream FILE;
	FILE.open(fileName);

	if (FILE.is_open())
		for (int i = 0; i < size; i++)
			FILE >> arr[i];
	FILE.close();
}

template <typename T>
void writeFromArrayToFile(T arr[], int size, const char *fileName)
{
	std::ofstream FILE;
	FILE.open(fileName);

	if (FILE.is_open())
		for (int i = 0; i < size; i++)
			FILE << arr[i] << "\n";
	FILE.close();
}

template <typename T>
int checkForCorrectness(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		if (arr[i] > arr[i + 1])
			return 0;
	return 1;
}

#endif