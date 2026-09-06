/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double ans = 0;
        int sum = 0;
        int step = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        ans = (double)sum / k;
        step++;

        while (step + k <= nums.size())
        {
            sum = sum + nums[step + k - 1] - nums[step - 1];
            ans = max(ans, (double)sum / k);
            step++;
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    {
        vector<int> nums = {1, 12, -5, -6, 50, 3};
        int k = 4;
        double result = solution.findMaxAverage(nums, k);
        cout << "Maximum Average Subarray: " << result << endl;
    }
    {
        vector<int> nums = {5};
        int k = 1;
        double result = solution.findMaxAverage(nums, k);
        cout << "Maximum Average Subarray: " << result << endl;
    }
    return 0;
}