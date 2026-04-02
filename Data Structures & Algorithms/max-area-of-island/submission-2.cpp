class Solution {
public:
    using grid_type = vector<vector<int>>;
    std::vector<std::pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void fill(grid_type& grid, int i, int j, int &max_area) {
        std::deque<std::pair<int, int>> q{{i, j}};
        int area = 1;

        while (!q.empty()) {
            auto e = q.front();
            q.pop_front();
            grid[e.first][e.second] = 0;

            int row = e.first;
            int col = e.second;

            std::cout << row << ", " << col << std::endl;

            /*
            if (row - 1 >= 0 && grid[row - 1][col] == 1)
                q.push_back({row - 1, col});
            if (row + 1 < grid.size() && grid[row + 1][col] == 1)
                q.push_back({row + 1, col});
            if (col - 1 >= 0 && grid[row][col - 1] == 1)
                q.push_back({row, col - 1});
            if (col + 1 >= 0 && grid[row][col + 1] == 1)
                q.push_back({row, col + 1});
            */

            for (auto direction : directions) {
                if (row + direction.first >= 0 && row + direction.first < grid.size() &&
                col + direction.second >= 0 && col + direction.second < grid[0].size())
                    if (grid[row + direction.first][col + direction.second] == 1) {
                        q.push_back({row + direction.first, col + direction.second});
                        grid[row + direction.first][col + direction.second] = 0;
                        area += 1;
                    }
            }
        }

        max_area = std::max(area, max_area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        int max_area = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                    std::cout << "poop" << std::endl;
                    fill(grid, i, j, max_area);
                }
            }
        }

        return max_area;
    }
};
