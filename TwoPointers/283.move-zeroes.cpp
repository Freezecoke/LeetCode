/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // i for finding non-zero
        // j for putting non-zero
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }

        // the rest set to zeros
        while (j < nums.size())
        {
            nums[j] = 0;
            j++;
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums{0, 1, 0, 3, 12};
    solution.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}