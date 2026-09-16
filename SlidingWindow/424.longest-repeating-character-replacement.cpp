/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int ans = 0;
        int left = 0;
        int maxFreq = 0;
        unordered_map<char, int> count;
        for (int right = 0; right < s.size(); right++)
        {
            count[s[right]]++;
            maxFreq = max(maxFreq, count[s[right]]);

            int windowSize = right - left + 1;
            while (windowSize - maxFreq > k)
            {
                count[s[left]]--;
                left++;
                windowSize = right - left + 1;
            }

            windowSize = right - left + 1;
            ans = max(ans, windowSize);
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution solution;
    {
        string s = "AABABBA";
        int k = 1;
        int result = solution.characterReplacement(s, k);
        cout << "Longest repeating character replacement: " << result << endl;
    }
    {
        string s = "ABAB";
        int k = 2;
        int result = solution.characterReplacement(s, k);
        cout << "Longest repeating character replacement: " << result << endl;
    }
    return 0;
}