class Solution {
public:
    using grid_type = vector<vector<char>>;

    void fill(grid_type& grid, int i, int j) {
        std::deque<std::pair<int, int>> q{{i, j}};

        while (!q.empty()) {
            auto e = q.front();
            q.pop_front();
            grid[e.first][e.second] = '0';

            std::cout << i << ", " << j << std::endl;

            int row = e.first;
            int col = e.second;

            if (row - 1 >= 0 && grid[row - 1][col] == '1')
                q.push_back({row - 1, col});
            if (row + 1 < grid.size() && grid[row + 1][col] == '1')
                q.push_back({row + 1, col});
            if (col - 1 >= 0 && grid[row][col - 1] == '1')
                q.push_back({row, col - 1});
            if (col + 1 >= 0 && grid[row][col + 1] == '1')
                q.push_back({row, col + 1});
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        //grid_type save = grid;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    //std::cout << i << ", " << j << std::endl;
                    fill(grid, i, j);
                }
            }
        }

        return count;
    }
};
