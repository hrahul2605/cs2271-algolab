#ifndef _MODULE_GENERATE_ND
#define _MODULE_GENERATE_ND

const double MEAN = 7000.0;
const double STANDARD_DEVIATION = 2000.0;
const int TOTAL_ND = int(1e6);
const double MAX_ND_VAL = 10000.00;
const double MIN_ND_VAL = 0.00;

#include <iostream>
#include <random>
#include <fstream>

double generateRandomNumberND(double mean, double stddev)
{
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::normal_distribution<double> distr(mean, stddev);

    return distr(generator);
}

void generateNDAndWriteToFile(const char *fileName, double mean = MEAN, double stddev = STANDARD_DEVIATION, int total = TOTAL_ND)
{
    std::ofstream FILE(fileName);

    if (FILE.is_open())
    {
        int i = total;
        while (i--)
        {
            double dd = generateRandomNumberND(mean, stddev);
            FILE << dd << "\n";
        }

        FILE.close();
    }
}

void generateNDBetweenZeroAndOne(const char *fileName, double mean = MEAN, double stddev = STANDARD_DEVIATION, int total = TOTAL_ND)
{
    std::ofstream FILE(fileName);

    if (FILE.is_open())
    {
        int i = total;
        while (i--)
        {
            double dd;
            bool key = true;
            while (key)
            {
                dd = generateRandomNumberND(mean, stddev);

                if (dd >= MIN_ND_VAL && dd <= MAX_ND_VAL)
                    key = false;
            }

            FILE << dd / MAX_ND_VAL << "\n";
        }

        FILE.close();
    }
}

#endif