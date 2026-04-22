class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // saw the solution... an O(n) one was not super obvious

        // intuition is to build a set from nums
        // find the start of a sequence (ie. element that does not have a previous one)
        // from there check if (possible) following ones exist. stop when it does not.
        // keep track of the max subsequence length


        std::unordered_set<int> s(nums.begin(), nums.end());

        int maxLength = 0;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int start = num;
                int length = 1;

                while (s.find(start + 1) != s.end()) {
                    start++;
                    length++;
                }

                maxLength = std::max(maxLength, length);
            }
        }

        return maxLength;
    }
};
