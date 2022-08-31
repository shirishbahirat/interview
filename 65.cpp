#include <iostream>
#include <random>

using namespace std;

int toss_biased(void)
{

    int data = rand();

    cout << (float)data/RAND_MAX << " " << data << endl;

    return 0;
}

int main(int argc, const char* argv[])
{

    int arr[4][] =  {{1,  2,  3,  4,  5},
                    {6,  7,  8,  9,  10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20}};

    toss_biased();

    return 0;
}
