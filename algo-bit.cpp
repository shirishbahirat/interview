#include <iostream>

using namespace std;





int main(int argc, const char* argv[])
{

	int data = 16;
	int count = 0;

	while(data)
	{
		data = data & (data - 1);
		count++;
	}

	cout << count << endl;


	return 0;
}