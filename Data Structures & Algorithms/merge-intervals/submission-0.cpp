class Solution {
public:
    using res_type = std::vector<std::vector<int>>;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        res_type res;
        std::sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });

        int i = 0;
        int n = intervals.size();

        std::vector<int> in = intervals[0];

        while (i < n) {
            if (in[1] >= intervals[i][0]) {
                while (i < n && in[1] >= intervals[i][0]) {
                    in[0] = std::min(in[0], intervals[i][0]);
                    in[1] = std::max(in[1], intervals[i][1]);
                    i++;
                }
                res.push_back(in);
            }
            else {
                res.push_back(intervals[i]);
                i++;
            }

            if (i < n) {
                in = intervals[i];
            }
        }


        return res;
    }
};
