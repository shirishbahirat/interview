#include <iostream>
#include <vector>

//Title: Square root

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        int left = 0, right = x;

        while (left < right)
        {

            int mid = left + (right - left)/2;

            if ((mid*mid) <= x)
                left = mid + 1;
            else
                right = mid;

        }

        return left - 1; 

    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();

    cout << obj->mySqrt(81) << endl;

    return 0;
}
