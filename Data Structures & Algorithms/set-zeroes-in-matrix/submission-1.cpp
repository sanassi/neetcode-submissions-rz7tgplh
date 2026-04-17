class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();


        std::set<std::pair<int, int>> zeroes;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    zeroes.insert({i, j});
            }
        }

        for (const auto &zero : zeroes) {
            int x = zero.first;
            int y = zero.second;

            for (int i = 0; i < n; i++) {
                matrix[x][i] = 0;
            }

            for (int i = 0; i < m; i++) {
                matrix[i][y] = 0;
            }
        }
    }
};
