#include <iostream>
#include <vector>

//Title: First bad version

using namespace std;

class Solution {
public:

    int bad_version = 4;

    int arr[] = {1,2,3,4,5,6,7};

    bool isBadVersion(int version)
    {
        if (version == bad_version) return true;

        return false;
    }

    int firstBadVersion(int n) {
        
        int left = 0, right = n;

        while (left < right)
        {
            int mid = left + (left - right)/2;

            if (isBadVersion(mid)) return true;

            left = mid + 1;

        }

        return left;
    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();
    return 0;
}
