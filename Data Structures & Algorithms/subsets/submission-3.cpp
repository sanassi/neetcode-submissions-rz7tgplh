class Solution {
public:
    using res_type = std::vector<std::vector<int>>;
    void aux(res_type &res, std::vector<int> &nums, std::vector<int> tmp, int i) {
      //if (i >= nums.size()) {
      //  res.push_back(tmp);
      //  return;
      //}
      res.push_back(tmp);
      // explore paths with the element
      for (int j = i; j < nums.size(); j++) {
      tmp.push_back(nums[j]);
      aux(res, nums, tmp, j + 1);
      // explore paths without
      tmp.pop_back();
      //aux(res, nums, tmp, i + 1);
      }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;

        aux(res, nums, tmp , 0);

        return res;
    }
};
