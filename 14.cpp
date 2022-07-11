#include <iostream>
#include <random>
#include <ctime>

using namespace std;


int main(int argc, const char* argv[])
{
   
    srand (time(NULL));

    int circle = 0;
    int square = 0;


   for (int i = 0; i < 100000; ++i)
   {
   		double x = (double)rand() / (RAND_MAX + 1.0);
   		double y = (double)rand() / (RAND_MAX + 1.0);

   		double rs = (x*x) + (y*y);

   		if (rs > 1)
   		  square++;
   		else
   		  circle++;

	}

	cout << square << " " << circle << " " << (double)circle/(double)square << endl;


	return 0;
}