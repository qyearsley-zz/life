// Copyright 2017 Quinten Yearsley

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <string>

class Board {
 public:
  Board(int nrows, int ncols);
  explicit Board(std::string contents);

  bool is_valid();
  bool at(int row, int col);
  bool next_state(int row, int col);
  void tick();
  std::string to_string();
  void random_fill();

 private:
  int num_live_neighbors_(int row, int col);
  std::vector<bool> contents_;
  int nrows_;
  int ncols_;
};

#endif  // BOARD_H_
