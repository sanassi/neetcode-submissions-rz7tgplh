class Solution {
public:
    /*
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());

        int nb = 0;

        for (int i = coins.size() - 1; i >= 0; i--) {
            int count = amount / coins[i];
            //std::cout << 
            if (count > 0) {
                nb += count;
                amount -= count * coins[i];
            }
        }

        if (amount > 0)
            return -1;

        return nb;
    }
    */

    void aux(std::vector<int> &coins, int amount, int idx, int nb, int &minNb) {
        if (idx >= coins.size() || amount < 0)
            return;
        
        if (amount == 0) {
            minNb = std::min(minNb, nb);
            return;
        }

        aux(coins, amount - coins[idx], idx, nb + 1, minNb);
        aux(coins, amount, idx + 1, nb, minNb);
    }

    int coinChange(vector<int>& coins, int amount) {
        int minNb = INT_MAX;
        aux(coins, amount, 0, 0, minNb);

        return minNb == INT_MAX ? -1 : minNb;
    }
};
