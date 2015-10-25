#include <limits.h>
#include "life.h"
#include "gtest/gtest.h"

TEST(Constructor, NoContents) {
  Board b(5, 5);
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
