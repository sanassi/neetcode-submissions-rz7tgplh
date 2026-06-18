class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> charSet;
        
        int l = 0;
        int r = 0;

        int maxWindow = 0;

        while (r < s.size()) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }

            charSet.insert(s[r]);

            maxWindow = std::max(maxWindow, r - l + 1);

            r++;
        }

        return maxWindow;
    }
};
