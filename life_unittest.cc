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
