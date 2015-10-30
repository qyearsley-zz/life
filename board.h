#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <string>

class Board {
  public:
    Board(int nrows, int ncols);
    Board(bool *contents, int nrows, int ncols);
    Board(std::string contents);
    bool at(int row, int col);
    bool next_state(int row, int col);
    void tick();
    std::string to_string();
  private:
    int num_live_neighbors_(int row, int col);
    std::vector<bool> contents_;
    int nrows_;
    int ncols_;
};

#endif  // BOARD_H_
