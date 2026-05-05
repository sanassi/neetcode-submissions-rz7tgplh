class Solution {
public:

    bool rec(std::vector<int> &nums, int index) {
        if (index >= nums.size() - 1) {
            return true;
        }

        std::cout << nums.size() << ", " << index << "\n";

        for (int jump = 1; jump <= nums[index]; jump++) {
            bool res = rec(nums, index + jump);
            if (res) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return rec(nums, 0);
    }
};
