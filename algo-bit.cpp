#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char* argv[])
{

	// total bit set
	int data = 17;
	int count = 0;

	while(data)
	{
		data = data & (data - 1);
		count++;
	}

	cout << count << endl;

	// rightmost bit

	data = 63;

	data = data & ~(data - 1);

	cout << log2(data) << endl;

	// leftmost bit

	data = 16;

	cout << (int)log2(data) << endl;


	// signed shift

	data = -8;

	cout << INT_MAX - ((unsigned)data >> 1) << endl;

	return 0;
}