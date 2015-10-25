#include <limits.h>
#include "life.h"
#include "gtest/gtest.h"

TEST(EmptyConstructor, BoardIsEmpty) {
  Board b(2, 3);
  EXPECT_FALSE(b.at(0, 0));
  EXPECT_FALSE(b.at(0, 1));
  EXPECT_FALSE(b.at(0, 2));
  EXPECT_FALSE(b.at(1, 0));
  EXPECT_FALSE(b.at(1, 1));
  EXPECT_FALSE(b.at(1, 2));
}

TEST(EmptyConstructor, OutsideBoardIsEmpty) {
  Board b(2, 3);
  EXPECT_FALSE(b.at(0, -1));
  EXPECT_FALSE(b.at(0, 3));
  EXPECT_FALSE(b.at(2, 0));
}

TEST(ContentsConstructor, BoardIsFilledOut) {
  bool example[] = {
    0, 0, 1,
    1, 1, 1
  };
  Board b(example, 2, 3);
  EXPECT_FALSE(b.at(0, 0));
  EXPECT_FALSE(b.at(0, 1));
  EXPECT_TRUE(b.at(0, 2));
  EXPECT_TRUE(b.at(1, 0));
  EXPECT_TRUE(b.at(1, 1));
  EXPECT_TRUE(b.at(1, 2));
}

TEST(At, OutsideBoardIsEmpty) {
  Board b(2, 3);
  EXPECT_FALSE(b.at(0, -1));
  EXPECT_FALSE(b.at(0, 3));
  EXPECT_FALSE(b.at(2, 0));
}

TEST(NextState, Starve0) {
  bool example[] = {
    1, 0,
    0, 0
  };
  Board b(example, 2, 2);
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_FALSE(b.next_state(0, 0));
}

TEST(NextState, Starve1) {
  bool example[] = {
    1, 0,
    0, 1
  };
  Board b(example, 2, 2);
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_FALSE(b.next_state(0, 0));
}

TEST(NextState, Live2) {
  bool example[] = {
    1, 0,
    1, 1
  };
  Board b(example, 2, 2);
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_TRUE(b.next_state(0, 0));
}

TEST(NextState, Live3) {
  bool example[] = {
    1, 1,
    1, 1
  };
  Board b(example, 2, 2);
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_TRUE(b.next_state(0, 0));
}

TEST(NextState, NoBirth2) {
  bool example[] = {
    0, 1,
    1, 0
  };
  Board b(example, 2, 2);
  EXPECT_FALSE(b.at(0, 0));
  EXPECT_FALSE(b.next_state(0, 0));
}

TEST(NextState, Birth3) {
  bool example[] = {
    0, 1,
    1, 1
  };
  Board b(example, 2, 2);
  EXPECT_FALSE(b.at(0, 0));
  EXPECT_TRUE(b.next_state(0, 0));
}

TEST(NextState, NoBirth4) {
  bool example[] = {
    0, 1, 1,
    1, 0, 1
  };
  Board b(example, 2, 3);
  EXPECT_FALSE(b.at(1, 1));
  EXPECT_FALSE(b.next_state(1, 1));
}

TEST(NextState, Overcrowd4) {
  bool example[] = {
    0, 1, 1,
    1, 1, 1
  };
  Board b(example, 2, 3);
  EXPECT_TRUE(b.at(1, 1));
  EXPECT_FALSE(b.next_state(1, 1));
}

TEST(NextState, Overcrowd8) {
  bool example[] = {
    1, 1, 1,
    1, 1, 1,
    1, 1, 1
  };
  Board b(example, 3, 3);
  EXPECT_TRUE(b.at(1, 1));
  EXPECT_FALSE(b.next_state(1, 1));
}
