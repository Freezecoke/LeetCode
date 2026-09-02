/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (minPrice > prices[i])
            {
                minPrice = prices[i];
            }
            else
            {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        int profit = solution.maxProfit(prices);
        cout << "Max Profit: " << profit << endl; // Output: Max Profit: 5
    }
    {
        vector<int> prices = {7, 6, 4, 3, 1};
        int profit = solution.maxProfit(prices);
        cout << "Max Profit: " << profit << endl; // Output: Max Profit: 5
    }
    return 0;
}
