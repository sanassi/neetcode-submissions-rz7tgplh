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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> res;

        for (auto str : strs) {
            bool found = false;
            for (auto& anags : res) {
                if (isAnagram(str, anags[0])) {
                    anags.push_back(str);
                    found = true;
                    break;
                }
            }

            if (!found) {
                res.push_back({str});
            }
        }

        return res;
    }
};
