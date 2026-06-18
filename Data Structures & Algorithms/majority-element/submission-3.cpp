class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[std::floor(nums.size() / 2)];

        /*
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            int val = nums[i];

            while (i < nums.size() && nums[i] == val) {
                i++;
                cnt++;

                if (cnt > std::floor(nums.size() / 2))
                    return val;
            }

            i -= 1;

            //std::cout << val << " " << cnt << std::endl;
        }

        return -42;
        */
    }
};