#include <iostream>

using namespace std;

int round(int number)
{

	while(number)
	{
		cout << number%10 << endl;
		number /= (10);
	}

	return 0;
}

int main(int argc, const char* argv[])
{

	round(8);
	round(35);
	round(64);

	return 0;
}