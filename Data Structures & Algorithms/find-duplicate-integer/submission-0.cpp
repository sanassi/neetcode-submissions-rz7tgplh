class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size()) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
                return nums[i];
            i += 1;
        }

        return i;
    }
};
