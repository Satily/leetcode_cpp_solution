#include<iostream>
#include<vector>
#include<string>
#include"helper.h"

using namespace std;

class Solution 
{
    const vector<vector<char>> CHARS = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.length() == 0) {
            return vector<string>();
        }
        vector<string> result{""};
        for (char digit: digits) {
            vector<string> currentResult;
            for (const string &resultItem: result) {
                for (char ch: CHARS[digit - 48]) {
                    currentResult.push_back(resultItem + ch);
                }
            }
            result = move(currentResult);
        }
        return result;
    }
};

int main() 
{
    cout << Solution().letterCombinations("23") << endl;
    return 0;
}

