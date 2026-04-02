class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<int, int> occ_s;
        std::map<int, int> occ_t;

        for (auto c : s) {
            occ_s[c] += 1;
        }

        for (auto c : t) {
            occ_t[c] += 1;
        }

        if (occ_t.size() != occ_s.size())
            return false;

        for (auto p_s : occ_s) {
            if (occ_t.find(p_s.first) == occ_t.end()) {
                return false;
            }

            if (occ_t[p_s.first] != p_s.second)
                return false;
        }

        return true;
    }
};
