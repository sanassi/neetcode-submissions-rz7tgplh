class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int k = 1;
        int maxSum = INT_MIN;
        for (; k <= nums.size(); k++) {
            for (int i = 0; i < nums.size(); i++) {
                int sum = 0;
                for (int j = i; j < i + k && j < nums.size(); j++) {
                    sum += nums[j];
                    //std::cout << nums[j] << " ";
                }
                //std::cout << "\n";

                maxSum = std::max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
