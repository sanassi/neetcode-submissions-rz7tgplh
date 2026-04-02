class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> occs;
        std::vector<int> uniques;

        for (auto n : nums) {
            occs[n] += 1;

            if (occs[n] == 1) {
                uniques.push_back(n);
            }
        }

        struct customGreat {
            bool operator()(int a, int b) const { return occs.at(a) > occs.at(b); }
            customGreat(std::map<int, int> occs) {
                this->occs = occs;
            }

            std::map<int, int> occs;
        };

        std::sort(uniques.begin(), uniques.end(), customGreat(occs));

        std::vector<int> res(uniques.begin(), uniques.begin() + k);
        return res;
    }
};
