#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int p = 0;
        int q = 0;
        int target = ((nums1.size() + nums2.size()) >> 1) + 1;
        int median = 0;
        int lastMedian = 0;
        while (p + q < target) 
        {
            lastMedian = median;
            if (q == nums2.size() || p != nums1.size() && nums1[p] < nums2[q])
            {
                median = nums1[p];
                p++;
            }
            else {
                median = nums2[q];
                q++;
            }
        }
        return ((nums1.size() + nums2.size()) & 1) == 0 ? (lastMedian + median) / 2.0 : (double)median;
    }
};

int main() 
{
    cout << Solution().findMedianSortedArrays(vector<int>{1, 3}, vector<int>{2}) << endl;
    cout << Solution().findMedianSortedArrays(vector<int>{1, 2}, vector<int>{3, 4}) << endl;
    return 0;
}