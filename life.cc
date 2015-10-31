#include <fstream>
#include <iostream>
#include <pthread.h>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "board.h"

void clear() {
  system("clear");
}

int main(int argc, char **argv) {
  Board board(30, 60);
  std::cout << argc << std::endl;
  if (argc < 2) {
    board.random_fill();
  } else {
    std::ifstream file(argv[1], std::ifstream::in);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string read_string = buffer.str();
    std::cout << "Read:" << std::endl << read_string << std::endl;
    Board b(read_string);
    board = b;
  }
  while (true) {
    clear();
    std::cout << board.to_string();
    sleep(1);
    board.tick();
  }
}
