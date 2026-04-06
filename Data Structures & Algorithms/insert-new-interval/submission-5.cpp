class Solution {
public:
    using res_type = vector<vector<int>>;
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        res_type res;
        int n = intervals.size();
        int i = 0;

        while (i < n && newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            i++;
        }

        std::cout << i << "\n";

        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        for (; i < n; i++) {
            res.push_back(intervals[i]);
        }

        return res;
    }
};
