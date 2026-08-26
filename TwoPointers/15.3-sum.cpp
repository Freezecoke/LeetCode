/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            // Remove duplicate
            if ((i != 0) && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            // -4, -1, -1, 0, 1, 2
            // -4, -1, -1, 0, 5, 6
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)
                {
                    left++;
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
int main()
{
    Solution solution;
    {
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = solution.threeSum(nums);

        for (const vector<int> &triplet : result)
        {
            cout << "[";
            for (int i = 0; i < triplet.size(); i++)
            {
                cout << triplet[i];
                if (i < triplet.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }
    {
        vector<int> nums = {-1, -1, -1, 0, 1, 1, 1};
        vector<vector<int>> result = solution.threeSum(nums);

        for (const vector<int> &triplet : result)
        {
            cout << "[";
            for (int i = 0; i < triplet.size(); i++)
            {
                cout << triplet[i];
                if (i < triplet.size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
