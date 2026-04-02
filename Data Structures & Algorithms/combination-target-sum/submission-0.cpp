class Solution {
public:
  using res_type = std::vector<std::vector<int>>;
  res_type combinationSum(std::vector<int> &nums, int target) {
    res_type res;
    std::vector<int> sub;

    dfs(res, nums, sub, 0, 0, target);

    return res;
  }

private:
  void dfs(res_type &res, std::vector<int> &nums, std::vector<int> sub,
           int subTotal, size_t idx, int target) {
    if (idx >= nums.size()) {
      if (subTotal == target)
        res.push_back(sub);
      return;
    }

    if (subTotal > target)
      return;

    sub.push_back(nums[idx]);
    dfs(res, nums, sub, subTotal + nums[idx], idx, target);

    sub.pop_back();
    dfs(res, nums, sub, subTotal, idx + 1, target);
  }
};