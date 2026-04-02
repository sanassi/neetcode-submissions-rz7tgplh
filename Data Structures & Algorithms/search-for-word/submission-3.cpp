class Solution {
public:
  using board_type = std::vector<std::vector<char>>;

  void aux(board_type &board, std::string word, size_t wordIdx, size_t boardX,
           size_t boardY, bool &found, std::vector<std::vector<bool>> &mark) {
    static std::vector<std::pair<int, int>> coords = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    mark[boardX][boardY] = true;


    if (wordIdx == word.size()) {
      found = true;
      return;
    }

    for (const auto &c : coords) {
      int x = boardX + c.first;
      int y = boardY + c.second;

      if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
        if (board[x][y] == word[wordIdx] && !mark[x][y]) {
          aux(board, word, wordIdx + 1, x, y, found, mark);
          if (found)
            return;
        }
      }
    }

    mark[boardX][boardY] = false;
  }

  bool exist(board_type &board, std::string word) {
    bool found = false;
    std::vector<std::vector<bool>> mark;

    for (const auto &line : board) {
        mark.push_back({});
        for (const auto c : line) {
            mark.back().push_back(false);
        }
    }

    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[0].size(); j++) {
        char first = board[i][j];
        if (first == word[0]) {
          aux(board, word, 1, i, j, found, mark);
        }

        if (found)
          return found;
      }
    }

    return found;
  }
};