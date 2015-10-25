#ifndef LIFE_H_
#define LIFE_H_

#include <vector>

struct Coordinate {
  int row;
  int col;
};

class Board {
  public:
    Board(int nrows, int ncols);
    Board(bool **contents, int nrows, int ncols);
    bool at(Coordinate c);
    bool next_state(Coordinate c);
    std::vector<Coordinate> neighbors(Coordinate c);
    void tick();
    void print();
  private:
    std::vector<bool> contents;
};

#endif  // LIFE_H_
