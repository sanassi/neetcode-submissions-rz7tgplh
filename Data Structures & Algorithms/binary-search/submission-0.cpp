class Solution {
public:
    int rec(std::vector<int> &v, int target, int left, int right) {
        if (left > right)
            return -1;

        int mid = (right - left) / 2 + left;

        if (target > v[mid]) {
            return rec(v, target, mid + 1, right);
        }
        else if (target < v[mid]) {
            return rec(v, target, left, mid - 1);
        }
        else
            return mid;
    }

    int search(vector<int>& nums, int target) {
        return rec(nums, target, 0, nums.size() - 1);
    }
};
