/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int ans = 0;
        unordered_map<char, int> last;
        for (int right = 0; right < s.size(); right++)
        {
            if (last.find(s[right]) != last.end())
            {
                left = max(left, last[s[right]] + 1);
            }
            last[s[right]] = right;

            int len = right - left + 1;
            ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    {
        string s = "abcabcbb";
        int length = solution.lengthOfLongestSubstring(s);
        cout << "Length of longest substring without repeating characters: " << length << endl;
    }
    {
        string s = "bbbbb";
        int length = solution.lengthOfLongestSubstring(s);
        cout << "Length of longest substring without repeating characters: " << length << endl;
    }
    {
        string s = "pwwkew";
        int length = solution.lengthOfLongestSubstring(s);
        cout << "Length of longest substring without repeating characters: " << length << endl;
    }
    return 0;
}