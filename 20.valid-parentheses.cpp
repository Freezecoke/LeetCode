/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
#include <string>
#include <stack>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c : s){
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()){
                 return false;
                }
                
                char top = stack.top();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.empty();
    }
};
// @lc code=end

int main() {
    Solution solution;
    // Test1
    {
        std::cout << "Test1" << std::endl;
        string input = "()[]";
        bool result = solution.isValid(input);
        std::cout << result << std::endl;
    }
    // Test2
    {
        std::cout << "Test2" << std::endl;
        string input = "([])";
        bool result = solution.isValid(input);
        std::cout << result << std::endl;
    }

    // Test3
    {
        std::cout << "Test3" << std::endl;
        string input = "([)]";
        bool result = solution.isValid(input);
        std::cout << result << std::endl;
    }

    return 0;
}