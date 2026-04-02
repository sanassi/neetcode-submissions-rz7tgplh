#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  void aux(int n, std::string tmp, std::vector<std::string> &res, size_t size,
           size_t open, size_t close) {
    if (open > size)
      return;

    if (close > open)
      return;

    if (tmp.size() == 2 * size) {
      res.push_back(tmp);
      return;
    }

    aux(n, tmp + "(", res, size, open + 1, close);
    aux(n, tmp + ")", res, size, open, close + 1);
  }

  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    aux(n, "", res, n, 0, 0);

    return res;
  }
};