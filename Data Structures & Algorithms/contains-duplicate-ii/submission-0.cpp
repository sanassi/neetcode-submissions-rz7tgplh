class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int lb = std::max(0, i - k);
            int hb = std::min((int) nums.size() - 1,  i + k);

            std::cout << lb << ", " << hb << std::endl;

            for (int j = lb; j <= hb; j++)
                if (nums[i] == nums[j] && i != j) {
                    //std::cout << i << " . " << j << std::endl;
                    return true;
                }
        }

        return false;
    }
};