#include <iostream>
#include <random>

using namespace std;

int mprint(int arr[4][5])
{

    int idx = 5;

    for (int i = 0; i < idx; ++i)
        cout << arr[0][i] << endl;

    return 0;
}

int main(int argc, const char* argv[])
{

    int arr[4][5] =  {{1,  2,  3,  4,  5},
                    {6,  7,  8,  9,  10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20}};

    mprint(arr);

    return 0;
}
