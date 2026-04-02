class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                for (int k = j; k < nums.size(); k++) {
                    if (i != j && i != k && j != k && (nums[i] + nums[j] + nums[k] == 0)) {
                        std::vector<int> p{nums[i], nums[j], nums[k]};
                        std::sort(p.begin(), p.end());
                        res.push_back(p);
                    }
                }
            }
        }

        set<vector<int>> s( res.begin(), res.end() );
        res.assign( s.begin(), s.end());

        return res;
    }
};
