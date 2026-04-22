class Solution {
public:
    int binSearch(std::vector<int> &nums, int l, int r, int target) {
        if (l > r)
            return -1;

        int mid = (r - l) / 2 + l;

        if (nums[mid] == target)
            return mid;
        
        if (nums[mid] > target) {
            return binSearch(nums, l, mid - 1, target);
        } else {
            return binSearch(nums, mid + 1, r, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size(), target);
    }
};
