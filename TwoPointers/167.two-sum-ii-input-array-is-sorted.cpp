/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] < target)
            {
                left++;
            }
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else
            {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
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
        vector<int> numbers = {2, 7, 11, 15};
        int target = 9;
        vector<int> result = solution.twoSum(numbers, target);
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    {
        vector<int> numbers = {2, 3, 4};
        int target = 6;
        vector<int> result = solution.twoSum(numbers, target);
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    {
        vector<int> numbers = {0, -1};
        int target = -1;
        vector<int> result = solution.twoSum(numbers, target);
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    return 0;
}