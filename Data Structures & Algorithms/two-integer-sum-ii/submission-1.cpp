class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;

        while (start != numbers.size() - 1) {
            for (int end = numbers.size() - 1; end > start; end--) {
                if (numbers[start] + numbers[end] == target) {
                    return {start + 1, end + 1};
                }
            }

            start += 1;
        }

        return {};
    }
};
