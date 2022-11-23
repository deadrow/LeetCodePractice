class Solution {
public:
    set<int> square_nums;
public:
    bool is_divided_by(int n, int count) {
      if (count == 1) {
        return square_nums.count(n);
      }

      for (auto square : square_nums) {
        if (is_divided_by(n - square, count - 1)) {
          return true;
        }
      }
      return false;
    }

    int numSquares(int n) {
      square_nums.clear();

      for (int i = 1; i * i <= n; ++i) {
        square_nums.insert(i * i);
      }

      int count = 1;
      for (; count <= n; ++count) {
        if (is_divided_by(n, count))
          return count;
      }
      return count;
    }
};