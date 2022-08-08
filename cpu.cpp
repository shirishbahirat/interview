#include <iostream>
#include <thread>

using namespace std;
using namespace thread;

int main(int argc, const char* argv[])
{

 	unsigned num_cpus = hardware_concurrency();

 	cout << "Launching " << num_cpus << " threads" << endl;

	return 0;
}