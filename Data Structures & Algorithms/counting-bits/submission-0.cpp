class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            count += (n & 0x01);
            n = n >> 1;
        }

        return count;
    }

    vector<int> countBits(int n) {
        std::vector<int> res;

        for (int i = 0; i <= n; i++) {
            res.push_back(hammingWeight(i));
        }

        return res;  
    }
};
