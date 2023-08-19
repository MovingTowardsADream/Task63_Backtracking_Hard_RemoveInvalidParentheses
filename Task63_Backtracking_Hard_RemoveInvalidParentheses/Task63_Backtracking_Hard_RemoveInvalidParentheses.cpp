#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::vector<std::string> res;
    std::unordered_map<std::string, int> mp;

    int getMinError(std::string s)
    {
        std::stack<char> st;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')')
            {
                if (st.size() > 0 && st.top() == '(')
                    st.pop();
                else
                    st.push(')');
            }
        }
        return st.size();
    }

    void backtracking(std::string s, int minError) {
        if (mp[s] != 0 || minError < 0)
            return;
        else
            mp[s]++;
        if (minError == 0)
        {
            if (!getMinError(s))
                res.push_back(s);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            std::string left = s.substr(0, i);
            std::string right = s.substr(i + 1);
            backtracking(left + right, minError - 1);
        }
    }

    std::vector<std::string> removeInvalidParentheses(std::string s)
    {
        backtracking(s, getMinError(s));
        return res;
    }
};