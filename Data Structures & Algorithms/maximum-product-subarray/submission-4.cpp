class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPrd = INT_MIN;

        if (nums.size() == 1) {
            return nums[0];
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int prd = 1;
                for (int k = i; k <= j; k++) {
                    //std::cout << nums[k] << ",";
                    prd *= nums[k];
                }

                maxPrd = std::max(maxPrd, prd);
                //std::cout << "\n";
            }
        }

        return maxPrd;
    }
};
