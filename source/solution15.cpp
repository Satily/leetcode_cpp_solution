#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include"helper.h"
using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) 
        {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    do {                    
                        k--;
                    } while(j < k && nums[k] == nums[k + 1]);                    
                }
                else
                {
                    if (sum == 0) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    }
                    do {                    
                        j++;
                    } while(j < k && nums[j] == nums[j - 1]);
                }
            }
        }
        return result;
    }
};

int main() 
{
    // cout << Solution().threeSum(vector<int>{}) << endl;
    // cout << Solution().threeSum(vector<int>{-1, 0}) << endl;
    cout << Solution().threeSum(vector<int>{-1, 0, 1, 2, -1, -4}) << endl;
    return 0;
}