class Solution {
public:
    // return max subarray of size k
    int slide(std::vector<int> &nums, int k) {
        int windowSum = 0;
        int maxSum = INT_MIN;

        // compute the first window sum

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        maxSum = std::max(maxSum, windowSum);

        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = std::max(maxSum, windowSum);
        }

        return maxSum;
    }

    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        for (int k = 1; k <= nums.size(); k++) {
            max = std::max(max, slide(nums, k));
        }

        return max;
    }
};
