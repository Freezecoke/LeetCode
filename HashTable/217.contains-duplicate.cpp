/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for(int num : nums){
            if(set.find(num) != set.end()){
                // Found a duplicate
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};
// @lc code=end
int main() {
    Solution solution;
    // Test1
    {
        std::cout << "Test1" << std::endl;
        vector<int> input = {1, 2, 3, 1};
        bool result = solution.containsDuplicate(input);
        std::cout << result << std::endl;
    }
    // Test2
    {
        std::cout << "Test2" << std::endl;
        vector<int> input = {1, 2, 3, 4};
        bool result = solution.containsDuplicate(input);
        std::cout << result << std::endl;
    }
    // Test3
    {
        std::cout << "Test3" << std::endl;
        vector<int> input = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        bool result = solution.containsDuplicate(input);
        std::cout << result << std::endl;
    }
}
