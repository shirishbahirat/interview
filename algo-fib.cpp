#include <iostream>
#include <vector>


using namespace std;

vector <int> fib_sequence(10, 0);

int fib(int n)
{

	if (n == 0) return 0;
	if (n == 1) return 1;

	if (fib_sequence[n]) return fib_sequence[n];

	fib_sequence[n] = fib(n - 1) + fib(n-2);

	return fib_sequence[n];
}

int main(int argc, const char* argv[])
{





	return 0;
}