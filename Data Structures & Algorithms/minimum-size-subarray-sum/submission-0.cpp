class Solution {
public:
    // returns the min sum of subarrays of size k
    int slidingSum(int target, std::vector<int> &nums, int k) {
        int sum = 0;
        int max_sum = 0;

        for (int i = 0; i < k; i++)
            sum += nums[i];
        
        max_sum = sum;

        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, sum);
        }

        return max_sum;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        for (int k = 1; k <= nums.size(); k++) {
            if (slidingSum(target, nums, k) >= target)
                return k;
        }

        return 0;
    }
};