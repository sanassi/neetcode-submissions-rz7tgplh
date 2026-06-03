class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[0] < nums.back())
            return nums[0];
        
        int i = 0;
        while (i + 1 < nums.size() && nums[i + 1] > nums[i])
            i++;
        
        return (i + 1  <nums.size()) ?  nums[i + 1] : nums[i] ;
    }
};
