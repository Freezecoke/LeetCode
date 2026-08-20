/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <string>
#include <cctype>
#include <locale>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while ((left < right) && !isalnum(s[left]))
            {
                left++;
            }
            while ((right > left) && !isalnum(s[right]))
            {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
int main()
{
    {
        Solution solution;
        string s = "A man, a plan, a canal: Panama";
        bool result = solution.isPalindrome(s);
        cout << result << endl;
    }
    {
        Solution solution;
        string s = "race a car";
        bool result = solution.isPalindrome(s);
        cout << result << endl;
    }
    {
        Solution solution;
        string s = " ";
        bool result = solution.isPalindrome(s);
        cout << result << endl;
    }
    {
        Solution solution;
        string s = ".,";
        bool result = solution.isPalindrome(s);
        cout << result << endl;
    }

    return 0;
}
