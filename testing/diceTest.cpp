

// commands to run this file:
// 1. g++ diceTest.cpp -o diceTest
// 2.  ./diceTest

#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;


class DiceTest {
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
};

int main() {
  DiceTest testDice;
  int test1 = testDice.rollDice();
  int test2 = testDice.rollDice();
  int test3 = testDice.rollDice();
  int test4 = testDice.rollDice();
  int test5 = testDice.rollDice();

  assert(test1 >= 1 && test1 <= 6);
  assert(test2 >= 1 && test2 <= 6);
  assert(test3 >= 1 && test3 <= 6);
  assert(test4 >= 1 && test4 <= 6);
  assert(test5 >= 1 && test5 <= 6);

  int dice[6] = {5, 4, 3, 2, 1, 9};
  int dice2[6] = {6, 6, 6, 6, 6, 6};
  int dice3[6] = {1, 2, 2, 3, 4, 5};
  int dice4[6] = {1, 3, 4, 5, 5, 5};

  sort(begin(dice), end(dice));
  sort(begin(dice2), end(dice2));
  sort(begin(dice3), end(dice3));
  sort(begin(dice4), end(dice4));

  assert(testDice.testLargeStraight(dice) == true);
  assert(testDice.testLargeStraight(dice2) == false);
  assert(testDice.testLargeStraight(dice3) == true);
  assert(testDice.testLargeStraight(dice4) == false);

  int dice5[6] = {1,2,3,4,1,1};
  int dice6[6] = {1,1,2,1,1,2};

  assert(testDice.testSmallStraight(dice5) == true);
  assert(testDice.testSmallStraight(dice6) == false);

  return 0;
}