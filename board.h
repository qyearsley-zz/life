#ifndef BOARD_H_
#define BOARD_H_

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
    int num_live_neighbors_(int row, int col);
    std::vector<bool> contents_;
    int nrows_;
    int ncols_;
};

#endif  // BOARD_H_
