#include <iostream>
#include <thread>

using namespace std;

int main(int argc, const char* argv[])
{

 	unsigned num_cpus = thread::hardware_concurrency();

 	cout << "Launching " << num_cpus << " threads" << endl;

	return 0;
}