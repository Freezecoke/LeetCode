/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            if(map.find(target - nums[i]) != map.end()){
                answer.push_back(map[target - nums[i]]);
                answer.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return answer;
    }
};
// @lc code=end

int main(){
    Solution solution;
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> result = solution.twoSum(nums, target);
    for(int num : result){
        cout << num << " ";
    }
}