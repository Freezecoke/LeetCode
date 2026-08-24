/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            char buffer = s[left];
            s[left] = s[right];
            s[right] = buffer;
            left++;
            right--;
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    {
        vector<char> s = {'h', 'e', 'l', 'l', 'o'};
        solution.reverseString(s);
        for (char c : s)
        {
            cout << c;
        }
        cout << endl;
    }
    {
        vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
        solution.reverseString(s);
        for (char c : s)
        {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}