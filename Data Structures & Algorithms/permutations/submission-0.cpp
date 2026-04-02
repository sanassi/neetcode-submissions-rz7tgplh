class Solution {
public:
  using res_type = std::vector<std::vector<int>>;

  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    res_type res;

    aux(res, nums, 0);

    return res;
  }

private:
  void vec_swap(std::vector<int> &v, int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
  }

  void aux(res_type &res, std::vector<int> nums, size_t idx) {
    if (idx >= nums.size()) {
      res.push_back(nums);
      return;
    }

    for (size_t i = idx; i < nums.size(); i++) {
      vec_swap(nums, idx, i);
      aux(res, nums, idx + 1);
      vec_swap(nums, idx, i);
    }
  }
};
