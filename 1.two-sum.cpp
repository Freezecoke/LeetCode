/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> unordered_map;

        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if(unordered_map.find(remaining) != unordered_map.end()) {
                return {unordered_map[remaining], i};
            }
            unordered_map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

int main() {
    Solution solution;

    // Test 1
    {
        std::vector<int> nums = {2, 7, 11, 15};
        int target = 9;

        auto result = solution.twoSum(nums, target);

        std::cout << "Test 1: ";
        for (int index : result) {
            std::cout << index << " ";
        }
        std::cout << "\n";
    }

    // Test 2
    {
        std::vector<int> nums = {-3, 4, 3, 90};
        int target = 0;

        auto result = solution.twoSum(nums, target);

        std::cout << "Test 2: ";
        for (int index : result) {
            std::cout << index << " ";
        }
        std::cout << "\n";
    }

    // Test 3
    {
        std::vector<int> nums = {-1, -2, -3, -4, -5};
        int target = -8;

        auto result = solution.twoSum(nums, target);

        std::cout << "Test 3: ";
        for (int index : result) {
            std::cout << index << " ";
        }
        std::cout << "\n";
    }
    return 0;
}