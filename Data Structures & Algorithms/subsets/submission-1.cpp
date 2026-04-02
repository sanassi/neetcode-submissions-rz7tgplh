class Solution {
  using res_type = std::vector<std::vector<int>>;

public:
  void aux(std::vector<int> &nums, res_type &res, size_t idx,
           std::vector<int> tmp) {
    if (idx == nums.size())
      return;

    tmp.push_back(nums[idx]);
    res.push_back(tmp);

    for (size_t i = idx + 1; i < nums.size(); i++) {
      aux(nums, res, i, tmp);
    }
  }
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    res_type res{{}};
    for (size_t i = 0; i < nums.size(); i++) {
      aux(nums, res, i, {});
    }

    return res;
  }
};