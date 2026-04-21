class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // use a priority queue with a custom compare
        // compare on euclidean distance (less)
        // then return the first k elements

        // Using a custom function object to compare elements.
        struct {
            bool operator()(const std::vector<int> l, const std::vector<int> r) const {
                return (l[0] * l[0] + l[1] * l[1]) > (r[0] * r[0] + r[1] * r[1]);
            }
        } customLess;

        std::priority_queue q(points.begin(), points.end(), customLess);

        std::vector<std::vector<int>> res;

        while (q.size() != 0 && (k > 0)) {
            res.push_back(q.top());
            q.pop();
            k--;
        }

        return res;
    }
};
