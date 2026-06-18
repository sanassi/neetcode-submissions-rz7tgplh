class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string res = "";

        int i = 0;

        std::sort(strs.begin(), strs.end(), [] (auto &a, auto &b) {
            return a.size() < b.size();
        });

        while (true) {
            if (i >= strs[0].size())
                break;

            char c = strs[0][i];
            for (const auto &str : strs) {
                if (str[i] != c)
                    return res;
            }

            res += c;

            i++;
        }

        return res;   
    }
};