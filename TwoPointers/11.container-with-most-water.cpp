/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int water = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            water = max(water, min(height[left], height[right]) * (right - left));

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return water;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    {
        vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result = solution.maxArea(height);
        cout << "Max area: " << result << endl; // Expected output: 49
    }
    {
        vector<int> height = {1, 1};
        int result = solution.maxArea(height);
        cout << "Max area: " << result << endl; // Expected output: 1
    }

    return 0;
}