#include <iostream>
#include <random>

using namespace std;

int toss_biased(void)
{

	int data = rand();
	cout << data << endl;
	return 0;
}

int main(int argc, const char* argv[])
{

	toss_biased();
	return 0;
}