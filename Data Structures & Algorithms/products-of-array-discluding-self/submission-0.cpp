class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> output(nums);

        for (int i = 0; i < nums.size(); i++) {
            int mul = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    mul *= nums[j];
                }
            }
            output[i] = mul;
        }

        return output;
    }
};
