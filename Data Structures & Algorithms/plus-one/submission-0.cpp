class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size() - 1;

        int carry = 1;
        while (end >= 0 && carry != 0) {
            int val = digits[end] + carry;
            digits[end] = val % 10;
            carry = val / 10;
            end--;
        }

        if (end < 0 && carry != 0) {
            //std::cout << carry << "\n";
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
