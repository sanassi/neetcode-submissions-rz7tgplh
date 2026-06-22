class Solution {
public:
    using res_type = std::vector<std::vector<int>>;

    void swap(std::vector<int> &v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    void aux(std::vector<int> &nums, res_type &res, int idx) {
        if (idx >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums, idx, i);
            aux(nums, res, idx + 1);
            swap(nums, idx, i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        res_type res;

        aux(nums, res, 0);

        return res;
    }
};
