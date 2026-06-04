class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res;

        for (int i = 0; i < temperatures.size(); i++) {
            int j = i + 1;

            int curTemp = temperatures[i];

            for (; j < temperatures.size(); j++) {
                if (temperatures[j] > curTemp) {
                    break;
                }
            }

            if (j != temperatures.size()) {
                res.push_back(j - i);
            }
            else {
                res.push_back(0);
            }
        }

        return res;
    }
};
