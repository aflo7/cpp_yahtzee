#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>

class DiceTests {
 public:
  int rollDice() { return rand() % (6 - 1 + 1) + 1; }

  bool testSmallStraight(int dice[]) {
    int increases = 0;

    for (int i = 0; i < 6; i++) {
      if (dice[i] < dice[i + 1] && dice[i] == dice[i + 1] - 1) {
        increases += 1;
        if (increases == 3) {
          return true;
        }
      }
    }

    return false;
  }

  bool testLargeStraight(int dice[]) {
    int increases = 0;

    for (int i = 0; i < 6; i++) {
      if (dice[i] < dice[i + 1] && dice[i] == dice[i + 1] - 1) {
        increases += 1;
        if (increases == 4) {
          return true;
        }
      }
    }

    return false;
  }

  int displayFinalScore(int* param) {
    // int scores[13] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
    int totalScore = 0;
    for (int i = 0; i < 13; i++) {
      totalScore += param[i];
    }
    return totalScore;
  }
};


TEST(suite1, test1) {
  // Expect equality.
  DiceTests testDice;
  int test1 = testDice.rollDice();
  EXPECT_TRUE(test1 >= 0 && test1 <= 6);
}

TEST(suite1, test2) {
  DiceTests testDice;
  int test2 = testDice.rollDice();
  EXPECT_FALSE(test2 < 0 || test2 > 6);
}

TEST(suite1, test3) {
  int scores[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  DiceTests testDice;
  EXPECT_EQ(testDice.displayFinalScore(scores), 13);
}

TEST(suite1, test4) {
  int scores[13] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  DiceTests testDice;
  EXPECT_EQ(testDice.displayFinalScore(scores), 26);
}

// testing large straight function
TEST(suite1, test5) {
  int dice[6] = {5, 4, 3, 2, 1, 9};
  DiceTests testDice;
  std::sort(std::begin(dice), std::end(dice));
  EXPECT_TRUE(testDice.testLargeStraight(dice));
}

TEST(suite1, test6) {
  int dice2[6] = {6, 6, 6, 6, 6, 6};
  DiceTests testDice;

  std::sort(std::begin(dice2), std::end(dice2));
  EXPECT_FALSE(testDice.testLargeStraight(dice2));
}

TEST(suite1, test7) {
  int dice3[6] = {1, 2, 2, 3, 4, 5};
  DiceTests testDice;
  std::sort(std::begin(dice3), std::end(dice3));
  EXPECT_TRUE(testDice.testLargeStraight(dice3));
}

TEST(suite1, test8) {
  int dice4[6] = {1, 3, 4, 5, 5, 5};
  DiceTests testDice;
  std::sort(std::begin(dice4), std::end(dice4));
  EXPECT_FALSE(testDice.testLargeStraight(dice4));
}

// testing small straight function
TEST(smallStraight, test9) {
  int dice5[6] = {1,2,3,4,1,1};
  DiceTests testDice;
  EXPECT_TRUE(testDice.testSmallStraight(dice5));

}

TEST(smallStraight, test10) {
  int dice6[6] = {1,1,2,1,1,2};
  DiceTests testDice;
  EXPECT_FALSE(testDice.testSmallStraight(dice6));


}