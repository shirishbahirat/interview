#include <iostream>

using namespace std;

typedef void (*_dispatch) (int);

struct api {
    _dispatch dispatch;
    api(_dispatch d):dispatch(d){}
};

struct cdb{
    uint32_t cmd     : 8;
    uint32_t ecc     :16;
    uint32_t crc     : 8;
};


int indxc = 0;

void merge(int arr[], int lo, int mid, int hi)
{

    int idx = lo;
    int idy = mid + 1;
    int len = hi - lo + 1;
    int zrr[len];
    int idz = 0;

    while(idx <= mid && idy <=hi)
    {
        if (arr[idx] < arr[idy]) 
        {
            zrr[idz++] = arr[idx++];
        }
        else 
        {
            zrr[idz++] = arr[idy++];
            indxc++;
        }
    }

    while(idx <= mid) zrr[idz++] = arr[idx++];

    while(idy <=hi) zrr[idz++] = arr[idy++];

    for (int i = lo, j = 0; i <= hi; ++i, ++j)
    {
        arr[i] = zrr[j];
    }

}

void mergesort(int arr[], int lo, int hi)
{
    if (hi <= lo) return;

    int mid = lo + (hi - lo) / 2;

    mergesort(arr, lo, mid);

    mergesort(arr, mid+1, hi);

    merge(arr, lo, mid, hi);

}

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

    mergesort(msc, 0, len - 1);

    for (int i = 0; i < len; ++i)
    {
        cout << msc[i] << " ";
    }

    cout << endl;
    cout << indxc << endl;

    cdb scsi;

    scsi.cmd = 12;
    scsi.ecc = 56;
    scsi.crc = 16;

    cout << scsi.cmd << endl;

    return 0;
}