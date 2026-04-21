class Solution {
public:
    using res_type = vector<vector<int>>;
    // combine the subsets question with sum tracking + backtracking

    void aux(std::vector<int> nums, std::vector<int> tmp, res_type& res, int i, int sum, int target) {
      if (i >= nums.size())
        return;
      
      if (sum == target) {
        res.push_back(tmp);
        return;
      }

      // since value can be reused, check to prevent infinite recursion
      if (sum >= target) {
        return;
      }

      std::cout << sum << "\n";

      tmp.push_back(nums[i]);
      // can retry the value so DONT increment i yet
      aux(nums, tmp, res, i, sum + nums[i], target);
      tmp.pop_back();
      aux(nums, tmp, res, i + 1, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res_type res;

        aux(nums, {}, res, 0, 0, target);

        return res;
    }
};
