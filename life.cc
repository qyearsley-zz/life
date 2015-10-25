#include "life.h"

Board::Board(int nrows, int ncols) :
    contents_(nrows * ncols), nrows_(nrows), ncols_(ncols) {}

Board::Board(bool *contents, int nrows, int ncols) :
    contents_(nrows * ncols), nrows_(nrows), ncols_(ncols) {
  for (int i = 0; i < nrows; i++) {
    for (int j = 0; j < ncols; j++) {
      int pos = i * ncols + j;
      contents_.at(pos) = contents[pos] ? true : false;
    }
  }
}

bool Board::at(int row, int col) {
  if (row < 0 || col < 0 || row >= nrows_ || col > ncols_) {
    return false;
  }
  return contents_.at(row * ncols_ + col);
}
