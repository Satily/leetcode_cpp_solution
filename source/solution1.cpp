#include<iostream>
#include<vector>
#include<algorithm>
#include"helper.h"
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<pair<int, int>> numsWithIndex;
        vector<int> result;
        for (int i = 0; i != nums.size(); ++i) 
        {
            numsWithIndex.push_back(make_pair(nums.at(i), i));
        }
        sort(numsWithIndex.begin(), numsWithIndex.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool { return a.first < b.first; });
        int i = 0;
        int j = numsWithIndex.size() - 1;
        while (i < j) 
        {
            int sum = numsWithIndex[i].first + numsWithIndex[j].first - target;
            if (sum > 0) 
            {
                j--;
            }
            else if (sum < 0) 
            {
                i++;
            }
            else 
            {                
                result.push_back(numsWithIndex[i].second);
                result.push_back(numsWithIndex[j].second);
                break;
            }
        }
        return result;
    }
};

int main() 
{    
    cout << Solution().twoSum(vector<int>{3, 2, 4}, 6) << endl;
    cout << Solution().twoSum(vector<int>{2, 7, 11, 15}, 9) << endl;
    return 0;
}