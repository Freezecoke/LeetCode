/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        // prefix Left -> Right
        int prefix = 1;
        for(int i=0; i<nums.size(); i++){
            answer[i] = prefix;
            prefix = prefix*nums[i];
        }
        // suffix Right -> Left
        int suffix = 1;
        for(int i=nums.size()-1; i>=0; i--){
            answer[i] = answer[i]*suffix;
            suffix = suffix*nums[i];
        }
        return answer;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}