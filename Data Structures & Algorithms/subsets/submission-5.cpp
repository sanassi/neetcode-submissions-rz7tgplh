class Solution {
public:
    using res_type = std::vector<std::vector<int>>;
    void aux(std::vector<int> &nums, int idx, std::vector<int> tmp, res_type& res) {
        if (idx >= nums.size()) {
            res.push_back(tmp);
            return;
        }

        tmp.push_back(nums[idx]);
        aux(nums, idx + 1, tmp, res);
        tmp.pop_back();
        aux(nums, idx + 1, tmp, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        res_type res;

        aux(nums, 0, {}, res);

        return res;
    }
};
