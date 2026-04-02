class Solution {
public:
    using res_type = vector<vector<int>>;

    // Naive solution: start with a full nums vector
    // Remove one element and recurse
    // Add res vector if 0 duplicates

    void aux(vector<int> nums, int removeIdx, res_type& res) {
        std::vector<int> r;
        for (int val : nums) {
            r.push_back(val);
        }
        if (std::find(res.begin(), res.end(), r) == res.end())
            res.push_back(r);

        nums.erase(nums.begin() + removeIdx);

        for (int i = 0; i < nums.size(); i++) {
            aux(nums, i, res);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        res_type subs;
        subs.push_back({});

        for (int i = 0; i < nums.size(); i++) {
            aux(nums, i, subs);
        }

        return subs;
    }
};
