class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;

        int maxLen = 1;

        for (int len = 1; len <= s.size(); len++) {
            for (int i = 0; i < s.size(); i++) {
                std::set<char> chars;
                for (int j = 0; j < len; j++) {
                    if (i + j < s.size())
                        chars.insert(s[i + j]);
                }

                if (chars.size() == len) {
                    maxLen = std::max(len, maxLen);
                }
            }
        }

        return maxLen;
    }
};
