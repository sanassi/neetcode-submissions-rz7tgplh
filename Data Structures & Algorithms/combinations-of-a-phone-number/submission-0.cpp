class Solution {
public:

    std::map<char, std::vector<std::string>> combs = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
    };

    void dfs(std::vector<std::string> &res, std::string digits, int i, std::string tmp) {
        if (i >= digits.size())
            return;

        std::vector<std::string> ds = combs[digits[i]];
        
        for (auto d : ds) {
            if ((tmp + d).size() == digits.size())
                res.push_back(tmp + d);
            dfs(res, digits, i + 1, tmp + d);
        }
    }

    vector<string> letterCombinations(string digits) {
        std::vector<std::string> res;

        dfs(res, digits, 0, "");

        return res;
    }
};
