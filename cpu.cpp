#include <iostream>
#include <thread>

using namespace std;

void data(int m)
{
	cout << "function pointer " << m << endl;
}

int main(int argc, const char* argv[])
{

 	unsigned num_cpus = thread::hardware_concurrency();

 	int arr[1] = {111};

 	typedef void (*results)(int);

 	results = &data;

 	results(1234);

 	cout << arr[0] << endl;

 	cout << "Launching " << num_cpus << " threads" << endl;

	return 0;
}