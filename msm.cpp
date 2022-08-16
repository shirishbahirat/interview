#include <iostream>

using namespace std;

struct api {
	void (*dispatch) (int);
};


void send(int idx)
{
	cout << "send " << idx << endl;
}

int main(int argc, const char* argv[])
{

	api* arr[] = {nullptr, nullptr, nullptr, nullptr};

	return 0;
}