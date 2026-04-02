class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> v;

        for (auto value : nums) {
            auto tmp = v.insert(value);
            if (!tmp.second)
                return true;
        }
        return false;
    }
};
