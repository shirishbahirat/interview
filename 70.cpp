#include <iostream>

using namespace std;

int round(int number)
{

	int sum = 0;

	while(number)
	{
		cout << number%10 << endl;

		sum += (number%10);

		number /= (10);
	}

	cout << "ans " << 10 - sum << endl;

	return 0;
}

int main(int argc, const char* argv[])
{

	round(8);
	round(35);
	round(64);

	return 0;
}