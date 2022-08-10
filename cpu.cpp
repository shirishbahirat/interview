#include <iostream>
#include <thread>

using namespace std;

int main(int argc, const char* argv[])
{

 	unsigned num_cpus = thread::hardware_concurrency();

 	int arr[1] = {111};

 	typedef void (*results)(int);

 	cout << arr[0] << endl;

 	cout << "Launching " << num_cpus << " threads" << endl;

	return 0;
}