class Solution {
public:
    // Naive solution:
    // iterate from left to right
    // to get the biggest diff
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;

        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > maxProf) {
                    maxProf = prices[j] - prices[i];
                }
            }
        }

        return maxProf;
    }
};
