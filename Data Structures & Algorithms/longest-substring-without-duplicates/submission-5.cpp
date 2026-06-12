class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> sub;
        int len = 0;

        int l = 0, r = 0;

        while (r < s.size()) {
            while (sub.find(s[r]) != sub.end()) {
               sub.erase(s[l]);
               l++; 
            }

            {
                sub.insert(s[r]);
                len = std::max(len, r - l + 1);
                r++;
            }
        }

        return len;
    }
};
