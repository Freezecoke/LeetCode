/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> container;
        for (char c : s)
        {
            if ((c == '(') || (c == '[') || (c == '{'))
            {
                container.push(c);
            }
            else
            {
                if (container.empty())
                {
                    return false;
                }
                if (c == ')' && container.top() != '(')
                {
                    return false;
                }
                if (c == ']' && container.top() != '[')
                {
                    return false;
                }
                if (c == '}' && container.top() != '{')
                {
                    return false;
                }

                container.pop();
            }
        }
        return container.empty();
    }
};
// @lc code=end

int main()
{
    Solution solution;
    {
        string s = "()[]{}";
        bool result = solution.isValid(s);
        cout << result << endl;
    }
    {
        string s = "([)]";
        bool result = solution.isValid(s);
        cout << result << endl;
    }
    {
        string s = "]";
        bool result = solution.isValid(s);
        cout << result << endl;
    }
    {
        string s = "(]";
        bool result = solution.isValid(s);
        cout << result << endl;
    }
}
