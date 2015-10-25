#ifndef LIFE_H_
#define LIFE_H_

#include <vector>

class Board {
  public:
    Board(int nrows, int ncols);
    Board(bool *contents, int nrows, int ncols);
    bool at(int row, int col);
    bool next_state(int row, int col);
    void tick();
    void print();
  private:
    std::vector<int> neighbors_(int row, int col);
    std::vector<bool> contents_;
    std::vector<bool> next_;
    int nrows_;
    int ncols_;
};

#endif  // LIFE_H_
