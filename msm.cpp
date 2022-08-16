#include <iostream>

using namespace std;

typedef void (*_dispatch) (int);


struct api {
    _dispatch dispatch;
    api(_dispatch d):dispatch(d){}
    api(){}
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
        arr[i] = new api();
        arr[i]->dispatch = send;
    }

    for (int i = 0; i < 4; ++i)
    {
        arr[i]->dispatch(i);
    }

    return 0;
}