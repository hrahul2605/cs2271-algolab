#ifndef _MODULE_GENERATE_UD
#define _MODULE_GENERATE_UD

const int MINIMUM_UD_RANGE = 11111111;
const int MAXIMUM_UD_RANGE = 99999999;
const int TOTAL_UD = int(1e6);

#include<iostream>
#include<random>
#include<fstream>

int generateRandomInteger(int minimum, int maximum){
	std::random_device						random_device;
	std::mt19937							generator(random_device());
	std::uniform_int_distribution<int>		distr(minimum, maximum);

	return distr(generator);	
}

void generateUDAndWriteToFile(const char * fileName, int minimum=MINIMUM_UD_RANGE, int maximum=MAXIMUM_UD_RANGE, int total=TOTAL_UD){
	std::ofstream FILE(fileName);
	
	if(FILE.is_open()){
		int i = total;
		while(i--){
			int integer = generateRandomInteger(minimum, maximum);
			FILE << integer << "\n";		
		}
		
		FILE.close();
	}
}

#endif