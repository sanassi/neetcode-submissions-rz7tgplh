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

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx = -1;
        for (int i = 0; i < matrix.size(); i++) {
            if (target >= matrix[i][0] && target <= matrix[i].back()) {
                idx = i;
                break;
            }
        }

        if (idx == -1)
            return false;

        return search(matrix[idx], target) != -1;
    }
};
