#include <iostream>
#include <vector>

//Title: Exact or Min

using namespace std;

class Solution
{
public:
    int ExactOrMin(vector<int> &nums, int val)
    {

        if (nums.size() == 0) return -1;

        int answer = -1;
        int low = 0;
        int high = nums.size() - 1;
  
        while(low <= high) 
        {
        
            int mid = (low + high) / 2;

            if (nums[mid] == val) 
            { 
                return val; 
            } 
            else if (nums[mid] < val) 
            { 
                answer = nums[mid];
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
   
        }

        return answer;
    }


};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();

    vector<int> nums = {2,5,7,12,17,19,22};

    cout << obj->ExactOrMin(nums, 9) << endl;

    return 0;
}
