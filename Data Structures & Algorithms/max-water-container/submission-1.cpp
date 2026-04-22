class Solution {
public:
    int maxArea(vector<int>& heights) {
        // greedy method, for each height, iterate on the the following ones
        // keep track of a max area

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                int area = (j - i) * (std::min(heights[i], heights[j]));
                maxArea = std::max(maxArea, area);
            }
        }

        return maxArea;
    }
};
