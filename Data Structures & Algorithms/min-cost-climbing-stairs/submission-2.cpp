class Solution {
public:
    std::map<int, int> cache;
    
    int aux(std::vector<int> &cost, int i, int curCost) {
        if (i >= cost.size()) {
            //return std::min(minCost, curCost);
            return 0;
        }

        if (cache.find(i) != cache.end())
            return cache[i];

        int a = INT_MAX, b = INT_MAX;

        a = aux(cost, i + 1, curCost + cost[i]);
        b = aux(cost, i + 2, curCost + cost[i]);

        cache[i] = std::min(a, b) + cost[i];

        return cache[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // call the start function twice on 0 or 1 and take the min cost computed
        //int minCost = INT_MAX;
        return std::min(aux(cost, 0, 0), aux(cost, 1, 0));

        //return minCost;
    }
};
