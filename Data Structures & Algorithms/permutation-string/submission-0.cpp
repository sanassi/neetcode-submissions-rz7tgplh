class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::map<char, int> occ1;
        for (char c : s1) {
            occ1[c]++;
        }

        int target = occ1.size();

        for (int i = 0; i < s2.size(); i++) {
            //std::string tmp = "";
            std::map<char, int> occ2;
            int matches = 0;
            for (int j = i; i + s1.size() <= s2.size() && j < i + s1.size(); j++) {
                //tmp += s2[j];

                occ2[s2[j]]++;

                if (occ2.size() > occ1.size())
                    break;

                if (occ2[s2[j]] == occ1[s2[j]])
                    matches++;
                
                if (matches == target)
                    return true;
            }
            //std::cout << tmp << ": " << matches << " - " << target << std::endl;
        }

        return false;
    }
};
