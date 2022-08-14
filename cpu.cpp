#include <iostream>
#include <thread>

using namespace std;

void data(int m)
{
	cout << "function pointer " << m << endl;
}


dpush() {
    git add .
    if [ "$1" != "" ]
    then
        git commit -m "$1"
    else
        git commit --file comment.txt
    fi
    git push
}


int main(int argc, const char* argv[])
{

 	unsigned num_cpus = thread::hardware_concurrency();

 	int arr[1] = {111};

 	void (*results)(int);

 	results = data;

 	results(1234);

 	cout << arr[0] << endl;

 	cout << "Launching " << num_cpus << " threads" << endl;

	return 0;
}