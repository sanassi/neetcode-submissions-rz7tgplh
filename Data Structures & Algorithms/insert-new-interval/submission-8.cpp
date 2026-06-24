class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> res;

        int i = 0;

        for (; i < intervals.size(); i++) {
            auto itv = intervals[i];
            if (itv[1] < newInterval[0]) {
                res.push_back(itv);
            }
            else
                break;
        }

        if (i >= intervals.size()) {
            res.push_back(newInterval);
            return res;
        }

        auto itv = intervals[i];
        std::cout << "stopped at: " << itv[0] << " " << itv[1] << std::endl;

        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {

            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);

            i++;
        }

        res.push_back(newInterval);

        for (; i < intervals.size(); i++) {
            res.push_back(intervals[i]);
        }

        return res;
    }
};
