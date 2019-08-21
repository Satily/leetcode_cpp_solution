#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> dict(128, 0);
        int q = 0;
        int maxLength = 0;
        for (int p = 0; p != s.length(); ++p) 
        {
            dict[s[p]]++;
            while (dict[s[p]] > 1)
            {
                dict[s[q++]]--;                
            }
            maxLength = max(maxLength, p - q + 1);
        }
        return maxLength;
    }
};

int main() 
{
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;    // 3
    cout << Solution().lengthOfLongestSubstring("bbbbb") << endl;       // 1
    cout << Solution().lengthOfLongestSubstring("pwwkew") << endl;      // 3
    return 0;
}