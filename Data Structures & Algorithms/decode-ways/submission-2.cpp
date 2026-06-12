class Solution {
public:

/*
    int aux(std::string s, size_t idx, std::vector<std::vector<std::string>>& res,
             std::vector<std::string> tmp) {
        if (idx >= s.size()) {
            tmp.push_back(s);
            res.push_back(tmp);
            return 1;
        }

        int r = 0;

        if (idx != 0)
            tmp.push_back(s.substr(0, idx));

        s = s.substr(idx);

        r += aux(s, idx + 1, res, tmp);
        r += aux(s, idx + 2, res, tmp);

        return r;
    }

    int numDecodings(string s) {
        // number of valid groupings of 1 or 2 characters

        std::vector<std::vector<std::string>> res;
        std::vector<std::string> tmp;

        std::cout << "count:" << aux(s, 0, res, tmp) << "\n";

        for (auto v : res) {
            std::cout << "[";
            for (auto str : v) {
                std::cout << "." << str << " ";
            }
            std::cout << "]\n";
        }

        return 0;
    }
*/

    std::unordered_map<char, int> mem;

    int aux(std::string s, int idx) {
        if (idx >= s.size()) {
            return 1;
        }

        // leading 0 not allowed!!!!!!
        if (s[idx] == '0') {
            return 0;
        }

        if (mem.find(idx) != mem.end())
            return mem[idx];

        int res = 0;

        res += aux(s, idx + 1);

        if (idx + 1 < s.size()) {
            if (s[idx] == '1' || (s[idx] == '2' && (s[idx + 1] <= '6')))
                res += aux(s, idx + 2);
        }

        mem[idx] = res;

        return res;
    }

    int numDecodings(string s) {
        return aux(s, 0);
    }
};
