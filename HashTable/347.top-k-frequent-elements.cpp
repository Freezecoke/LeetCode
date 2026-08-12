/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        // Step 1: Count frequency
        // 1 → 3
        // 2 → 2
        // 3 → 1
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        // frequency : num
        // bucket[1] = [3]
        // bucket[2] = [2]
        // bucket[3] = [1]
        for (auto &[num, count] : freq)
        {
            bucket[count].push_back(num);
        }

        vector<int> result;
        for (int i = nums.size(); i >= 1 && result.size() < k; i--)
        {
            for (int num : bucket[i]){
                result.push_back(num);
            }
        }

        return result;
    }

    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> freqMap;
    //     for(int num : nums){
    //         freqMap[num]++;
    //     }

    //     // Convert freqMap to freqVec
    //     vector<pair<int, int>> freqVec;
    //     for(auto& [num, count] : freqMap){
    //         freqVec.push_back({num, count});
    //     }

    //     // Sort by frequency
    //     sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b){
    //         return a.second > b.second;
    //     });

    //     vector<int> out;
    //     for(int i=0; i<k; i++){
    //         out.push_back(freqVec[i].first);
    //     }
    //     return out;
    // }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = solution.topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}