class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = -1;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i; j < heights.size(); j++) {
                int h = std::min(heights[i], heights[j]);
                int area = (j - i) * h;
                if (area > maxArea)
                    maxArea = area;
            }
        }

        return maxArea;
    }
};
