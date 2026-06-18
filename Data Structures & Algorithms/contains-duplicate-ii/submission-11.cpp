class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, int> store;

        for (int i = 0; i < nums.size(); i++) {
            if (store.find(nums[i]) == store.end()) {
                store[nums[i]] = i;
            }
            else {
                if (std::abs(i - store[nums[i]]) <= k) {
                    //std::cout << store[nums[i]] << " " << i << std::endl;
                    return true;
                }
                store[nums[i]] = i;
            }
        }

        return false;
    }
};