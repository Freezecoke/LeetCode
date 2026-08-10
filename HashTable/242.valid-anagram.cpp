/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        std::unordered_map<char, int> first;
        for (char c : s)
        {
            first[c]++;
        }
        std::unordered_map<char, int> second;
        for (char c : t)
        {
            second[c]++;
        }
        return first == second;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    {
        string s = "anagram";
        string t = "nagaram";
        bool result = solution.isAnagram(s, t);
        cout << (result ? "true" : "false") << endl;
    }
    {
        string s = "rat";
        string t = "car";
        bool result = solution.isAnagram(s, t);
        cout << (result ? "true" : "false") << endl;
    }
    return 0;
}