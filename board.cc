#include "assert.h"
#include <string>
#include <vector>

#include "board.h"

const char kRowSeparator = '\n';
const char kAlive = '#';
const char kDead = '.';

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

Board::Board(std::string contents) {
  contents_;
  int ncols = contents.find(kRowSeparator);
  int nrows = 0;
  for (int i = 0; i < contents.size(); i++) {
    if (contents.at(i) == kAlive) {
    }
  }
  assert(ncols
  int row = 0;
  for (int i = 0; i < contents.size(); i++) {
  }
}

bool Board::at(int row, int col) {
  if (row < 0 || col < 0 || row >= nrows_ || col >= ncols_) {
    return false;
  }
  return contents_.at(row * ncols_ + col);
}

bool Board::next_state(int row, int col) {
  int count = num_live_neighbors_(row, col);
  return count == 3 || (at(row, col) && count == 2);
}

int Board::num_live_neighbors_(int row, int col) {
  int count = 0;
  for (int i = row - 1; i <= row + 1; i++) {
    for (int j = col - 1; j <= col + 1; j++) {
      if (i == row && j == col) {
	continue;
      }
      if (at(i, j)) {
	++count;
      }
    }
  }
  return count;
}

void Board::tick() {
  std::vector<bool> next;
  for (int i = 0; i < nrows_; i++) {
    for (int j = 0; j < ncols_; j++) {
      next.push_back(next_state(i, j));
    }
  }
  contents_ = next;
}
