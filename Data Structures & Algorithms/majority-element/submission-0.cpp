class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> occ;

        for (auto n : nums) {
            occ[n]++;
        }

        for (const auto [k, v] : occ) {
            if (v > std::floor(nums.size() / 2))
                return k;
        }

        return -42;
    }
};