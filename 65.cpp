#include <iostream>
#include <random>

using namespace std;

int mprint(int *arr, int m, int n)
{

    for (int i=0; i<m; i++)
     {
        for (int j=0; j<n; j++)
        {
           cout<<*((arr+i*n) + j)<<" ";
        }
        cout<<endl;
     }

    return 0;
}

int main(int argc, const char* argv[])
{

    int arr[4][5] =  {{1,  2,  3,  4,  5},
                    {6,  7,  8,  9,  10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20}};

    mprint((int *)arr, 5, 4);

    return 0;
}
