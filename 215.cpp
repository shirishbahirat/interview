#include <iostream>
#include <vector>
#include <queue>

//Title: Kth Largest Element in an Array

using namespace std;

class Solution {
public:
    priority_queue<int> data;

    int findKthLargest(vector<int>& nums, int k) {
        
        for (int i = 0; i < nums.size(); ++i)
        {
            data.push(nums[i]);
        }

        int i = 0;
        int results = -1;

        while (!data.empty() && (i < k))
        {
            ++i;
            data.pop();
            results = data.front();
        }

        return results;
    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();
    return 0;
}
