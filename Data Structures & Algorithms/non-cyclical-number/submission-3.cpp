class Solution {
public:
    int digitSum(int n) {
        int res = 0;

        while (n != 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }

        return res;
    }

    bool isHappy(int n) {
        std::map<int, bool> met;

        int tmp = n;
        while (tmp != 1) {
            tmp = digitSum(tmp);
            if (met.find(tmp) != met.end())
                return false;
            met[tmp] = true;
        }

        return true;
    }
};
