#include <iostream>
#include <vector>

//Title: Search in Rotated Sorted Array

using namespace std;

class Solution {
public:

    int get_pivot(vector<int>& nums)
    {
        if (nums.empty())
        {
            return -1;
        }

        if (nums.size() < 2)
        {
            return 0;
        }

    }

    int search(vector<int>& nums, int target) {
        

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> arr = {4,5,6,7,0,1,2};


    Solution *obj = new Solution();

    int index = obj->search(arr, 7);

    return 0;
}
