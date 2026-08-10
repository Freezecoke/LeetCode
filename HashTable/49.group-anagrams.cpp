/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for (const string& str : strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto& key : anagramMap) {
            result.push_back(key.second);
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for(const auto& group : result) {
        for(const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}