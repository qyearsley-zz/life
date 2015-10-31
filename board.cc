#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "board.h"

const char kRowSeparator = '\n';
const char kAlive = '#';
const char kDead = '.';

Board::Board(int nrows, int ncols) :
    contents_(nrows * ncols), nrows_(nrows), ncols_(ncols) {}

Board::Board(std::string contents) {
  nrows_ = 0;
  for (size_t i = 0; i < contents.size(); i++) {
    if (contents.at(i) == kAlive) {
      contents_.push_back(true);
    } else if (contents.at(i) == kDead) {
      contents_.push_back(false);
    } else if (contents.at(i) == kRowSeparator) {
      nrows_++;
    }
  }
  ncols_ = contents.find(kRowSeparator);
  if (!is_valid()) {
    nrows_ = 0;
    ncols_ = 0;
    contents_.clear();
  }
}

bool Board::is_valid() {
  return (ncols_ * nrows_ <= (int)contents_.size());
}

std::string Board::to_string() {
  std::string result;
  for (int row = 0; row < nrows_; row++) {
    for (int col = 0; col < ncols_; col++) {
      result += at(row, col) ? kAlive : kDead;
    }
    result += kRowSeparator;
  }
  return result;
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

void Board::random_fill(){
  srand(time(NULL));
  for (int i = 0; i < nrows_ * ncols_; i++) {
    contents_.at(i) = rand() % 2 == 0;
  }
}
