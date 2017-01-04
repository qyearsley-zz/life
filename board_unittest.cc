// Copyright 2017 Quinten Yearsley

#include "./board.h"
#include "gtest/gtest.h"

TEST(EmptyConstructor, BoardIsEmpty) {
  Board b(2, 1);
  EXPECT_FALSE(b.at(0, 0));
  EXPECT_FALSE(b.at(1, 0));
}

TEST(StringConstructor, SmallBoard) {
  Board b("##\n.#\n");
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_TRUE(b.at(0, 1));
  EXPECT_FALSE(b.at(1, 0));
  EXPECT_TRUE(b.at(1, 1));
}

TEST(StringConstructor, InvalidStringEmptyBoard) {
  Board b("######\n...\n");
  EXPECT_EQ("", b.to_string());
}

TEST(ToString, EmptyBoard) {
  Board b(2, 3);
  EXPECT_EQ("...\n...\n", b.to_string());
}

TEST(ToString, PopulatedBoard) {
  Board b("..#\n###\n");
  EXPECT_EQ("..#\n###\n", b.to_string());
}

TEST(At, OutsideBoardIsEmpty) {
  Board b(2, 3);
  EXPECT_FALSE(b.at(0, -1));
  EXPECT_FALSE(b.at(0, 3));
  EXPECT_FALSE(b.at(2, 0));
}

TEST(NextState, Starve0) {
  Board b("#.\n..\n");
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_FALSE(b.next_state(0, 0));
}

TEST(NextState, Starve1) {
  Board b("#.\n.#\n");
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_FALSE(b.next_state(0, 0));
}

TEST(NextState, Live2) {
  Board b("#.\n##\n");
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_TRUE(b.next_state(0, 0));
}

TEST(NextState, Live3) {
  Board b("##\n##\n");
  EXPECT_TRUE(b.at(0, 0));
  EXPECT_TRUE(b.next_state(0, 0));
}

TEST(NextState, NoBirth2) {
  Board b(".#\n#.\n");
  EXPECT_FALSE(b.at(0, 0));
  EXPECT_FALSE(b.next_state(0, 0));
}

TEST(NextState, Birth3) {
  Board b(".#\n##\n");
  EXPECT_FALSE(b.at(0, 0));
  EXPECT_TRUE(b.next_state(0, 0));
}

TEST(NextState, NoBirth4) {
  Board b(".##\n#.#\n");
  EXPECT_FALSE(b.at(1, 1));
  EXPECT_FALSE(b.next_state(1, 1));
}

TEST(NextState, Overcrowd4) {
  Board b(".##\n###\n");
  EXPECT_TRUE(b.at(1, 1));
  EXPECT_FALSE(b.next_state(1, 1));
}

TEST(NextState, Overcrowd8) {
  Board b("###\n###\n###\n");
  EXPECT_TRUE(b.at(1, 1));
  EXPECT_FALSE(b.next_state(1, 1));
}

TEST(Tick, Tick) {
  Board b(".#.\n#.#\n");
  b.tick();
  EXPECT_EQ(".#.\n.#.\n", b.to_string());
}
