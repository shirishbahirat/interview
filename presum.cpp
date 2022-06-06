#include <iostream>

using namespace std;

int arr[] = {8,3,4,5,7,8,9,-1,3, -4, 5};


#define size 11

int psum[size];

void pre_sum(void)
{

	psum[0] = arr[0];

	for (int i = 1; i < size; ++i)
	{
		psum[i] = arr[i - 1] + arr[i];
		cout << psum[i] << endl;
	}

}


int main(int argc, const char* argv[])
{

	pre_sum();

	for (auto i: psum)
	{
		cout << i << " ";
	}

	cout << endl;

	return 0;
}