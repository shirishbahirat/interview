#include <iostream>

using namespace std;

typedef void (*fcall)(int);


void call(int idx)
{

	cout << idx << endl;

}

int main(int argc, const char* argv[])
{

	fcall c;

	c = call;

	c(10);

	return 0;
}