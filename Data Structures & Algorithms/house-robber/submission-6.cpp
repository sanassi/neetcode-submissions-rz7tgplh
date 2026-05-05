class Solution {
public:
    // cannot use previous idea, by going forward 2 by 2 we could miss a huge
    // house at some index, and return a lesser amount....
    std::map<int, int> cache;
    
    int aux(std::vector<int> &nums, int idx) {
        if (idx >= nums.size()) {
            //max = std::max(max, sum);
            return 0;
        }

        if (cache.find(idx) != cache.end())
            return cache[idx];

        // skip house (dont count the nums[idx] in the sum)
        int a = aux(nums, idx + 1);

        // steal from house (increment the sum)
        int b = aux(nums, idx + 2);

        int val = std::max(a, b + nums[idx]);
        cache[idx] = val;
        return val;
    }

    int rob(vector<int>& nums) {
        // if we're at index i, either visit i + 2 or i + 3 ? anything but i + 1.

        return aux(nums, 0);
    }
};
