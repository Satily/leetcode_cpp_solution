#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if (s.length() <= 1) 
        {
            return s;
        }
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));
        for (int i = 0; i != s.length() + 1; ++i) 
        {
            dp[i][0] = dp[i][1] = 1;
        }
        dp[s.length()][1] = 0;
        int resultIndex = 0;
        int resultLength = 1;
        for (int i = 2; i < s.length() + 1; i++) 
        {
            for (int j = 0; j < s.length() + 1 - i; j++) 
            {
                if (dp[j + 1][i - 2] == 1 && s[j] == s[j + i - 1]) {
                    dp[j][i] = 1;
                    resultIndex = j;
                    resultLength = i;
                }
            }
        }
        return s.substr(resultIndex, resultLength);
    }
};

int main() 
{
    cout << Solution().longestPalindrome("ac") << endl;
    // cout << Solution().longestPalindrome("babad") << endl;
    // cout << Solution().longestPalindrome("cbbd") << endl;
    return 0;
}