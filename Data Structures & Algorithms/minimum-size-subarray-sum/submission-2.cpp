class Solution {
public:
    // try the sliding window approach
    int minSubArrayLen(int target, vector<int>& nums) {
        // gist: keep a total sum, define a min to int_max advance in the array and
        // increment total.
        // if total > target, shrink the window and decrement total
        // until less than target, update the min subarray size
        // if min was not updated return 0

        int total = 0;
        int min = INT_MAX;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];

            while (total >= target) {
                total -= nums[l];
                min = std::min(min, r - l + 1);
                l++;
            }
        }

        return min == INT_MAX ? 0 : min;
    }
};