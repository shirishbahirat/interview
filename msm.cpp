#include <iostream>

using namespace std;

typedef void (*_dispatch) (int);

struct api {
    _dispatch dispatch;
    api(_dispatch d):dispatch(d){}
};


void send(int idx)
{
    cout << "send " << idx << endl;
}

int main(int argc, const char* argv[])
{

    api* arr[] = {nullptr, nullptr, nullptr, nullptr};

    for (int i = 0; i < 4; ++i)
    {
        arr[i] = new api(send);
    }

    for (int i = 0; i < 4; ++i)
    {
        arr[i]->dispatch(i);
    }


    int msc[] = {14,6,11,2,3,1,7};
    int len = sizeof(msc)/sizeof(msc[0]);
    int msa[] = {4,3,1};

    int inversions = 0;

    for (int i = 0; i < 7; ++i)
    {
        for (int j = i; j < 7; ++j)
        {
            if (msc[i] > msc[j])
            {
                inversions++;
            }
        }
    }

    cout << inversions << endl;

    return 0;
}