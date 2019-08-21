#include<iostream>
#include<stack>
#include<map>
using namespace std;

class Solution 
{
    const map<char, char> PAIRS = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'}
    };
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for (char ch: s) {
            const map<char, char>::const_iterator o = PAIRS.find(ch);
            if (o != PAIRS.cend()) {
                st.push(ch);
            } else if (st.empty() || PAIRS.at(st.top()) != ch) {
                return false;
            } else {
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() 
{
    cout << Solution().isValid("()") << endl;
    cout << Solution().isValid("()[]{}") << endl;
    cout << Solution().isValid("(]") << endl;
    cout << Solution().isValid("([)]") << endl;
    cout << Solution().isValid("{[]}") << endl;
    return 0;
}