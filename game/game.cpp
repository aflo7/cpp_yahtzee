// commands to run this file:
// 1. g++ game.cpp -o game --std=c++17
// 2.  ./game

#include <algorithm>
#include <iostream>
#include <map>

class Die {
 public:
  int value;
  Die(int value) { this->value = value; }
};

class Dice {
 public:
  int rollDice() { return rand() % (6 - 1 + 1) + 1; }
};

class ScoreCard {
 public:
  int scores[13];
  ScoreCard() {
    for (int i = 0; i < 13; i++) {
      scores[i] = -1;  // this means that the index has not yet been scored
    }
  }

  void displayFinalScore() {
    int totalScore = 0;
    for (int i = 0; i < 13; i++) {
      totalScore += scores[i];
    }
    std::cout << "Your final score is: " << totalScore;
  }

  void displayScoreSheet() 
   std::string blankSpace = " __";
   std::string acesScore = scores[0] == -1 ? blankSpace : to_string(scores[0]);
   std::string twosScore = scores[1] == -1 ? blankSpace : to_string(scores[1]);
   std::string threesScore = scores[2] == -1 ? blankSpace : to_string(scores[2]);
   std::string foursScore = scores[3] == -1 ? blankSpace : to_string(scores[3]);
   std::string fivesScore = scores[4] == -1 ? blankSpace : to_string(scores[4);
   std::string sixesScore = scores[5] == -1 ? blankSpace : to_string(scores[5]);
   std::string threeOfAKindScore =
        (scores[6] == -1 ? blankSpace : to_string(scores[6]));
   std::string fourOfAKindScore =
        scores[7] == -1 ? blankSpace : to_string(scores[7]);
   std::string fullHouseScore = scores[8] == -1 ? blankSpace : to_string(scores[8]);
   std::string smallStraightScore =
        scores[9] == -1 ? blankSpace : to_string(scores[9]);
   std::string largeStraightScore =
        scores[10] == -1 ? blankSpace : to_string(scores[10]);
   std::string yahtzeeScore = scores[11] == -1 ? blankSpace : to_string(scores[11]);
   std::string chanceScore = scores[12] == -1 ? blankSpace : to_string(scores[12]);

    std::cout << "1: Aces: " << acesScore << std::endl;
    std::cout << "2: Twos: " << twosScore << std::endl;
    std::cout << "3: Threes: " << threesScore << std::endl;
    std::cout << "4: Fours: " << foursScore << std::endl;
    std::cout << "5: Fives: " << fivesScore << std::endl;
    std::cout << "6: Sixes: " << sixesScore << std::endl;
    std::cout << "7: 3 of a kind: " << threeOfAKindScore << std::endl;
    std::cout << "8: 4 of a kind: " << fourOfAKindScore << std::endl;
    std::cout << "9: Full House: " << fullHouseScore << std::endl;
    std::cout << "10: Small Straight: " << smallStraightScore << std::endl;
    std::cout << "11: Large Straight: " << largeStraightScore << std::endl;
    std::cout << "12: Yahztzee: " << yahtzeeScore << std::endl;
    std::cout << "13: Chance: " << chanceScore << std::endl;
  }

  void scoreCurrentDice(int choice, int dice) {
    // std::cout << "Inside score current dice" << std::endl;
    // std::cout << "choice: " << choice << std::endl;
    int sum = 0;
    switch (choice) {
      case 1:
        for (int i = 0; i < 6; i++) {
          if (dice[i] == 1) {
            sum += 1;
          }
        }
        break;
      case 2:
        for (int i = 0; i < 6; i++) {
          if (dice[i] == 2) {
            sum += 2;
          }
        }
        break;
      case 3:
        for (int i = 0; i < 6; i++) {
          if (dice[i] == 3) {
            sum += 3;
          }
        }
        break;
      case 4:
        for (int i = 0; i < 6; i++) {
          if (dice[i] == 4) {
            sum += 4;
          }
        }
        break;
      case 5:
        for (int i = 0; i < 6; i++) {
          if (dice[i] == 5) {
            sum += 5;
          }
        }
        break;
      case 6:
        for (int i = 0; i < 6; i++) {
          if (dice[i] == 6) {
            sum += 6;
          }
        }
        break;
      case 7: {
        map<int, int> counter;  // key= number, value= occurences of that number
        for (int i = 0; i < 6; i++) {
          counter[dice[i]]++;
        }
        for (auto pair : counter) {
          // std::cout << pair.first << ": " << pair.second << std::endl;
          if (pair.second >= 3) {
            sum += pair.first * 3;
            break;
          }
        }

        break;
      }
      case 8: {
        // score 4 of a kind
        map<int, int> counter;
        for (int i = 0; i < 6; i++) {
          counter[dice[i]]++;
        }
        for (auto pair : counter) {
          if (pair.second >= 4) {
            sum += pair.first * 4;
            break;
          }
        }
        break;
      }
      case 9:
        // score full house
        {
          // if both of the following conditions are true, give player 25 points
          bool twoOfAKind = false;
          bool threeOfAKind = false;
          map<int, int> counter;
          for (int i = 0; i < 6; i++) {
            counter[dice[i]]++;
          }

          for (auto pair : counter) {
            if (pair.second == 3) {
              threeOfAKind = true;
            } else if (pair.second == 2) {
              twoOfAKind = true;
            }
          }
          if (twoOfAKind && threeOfAKind) {
            sum += 25;
          }

          break;
        }
      case 10: {
        // small straight
        int increases =
            0;  // if there are 4 increases, we have a small straight
        for (int i = 0; i < 5; i++) {
          if (dice[i] < dice[i + 1]) {
            increases += 1;
          }
          if (increases == 4) {
            sum += 30;  // we have a small straight
          }
        }
        break;
      }
      case 11: {
        // large straight
        int increases =
            0;  // if there are 4 increases, we have a small straight
        for (int i = 0; i < 5; i++) {
          if (dice[i] < dice[i + 1]) {
            increases += 1;
          }
        }
        if (increases == 5) {
          sum += 40;  // we have a large straight
        }
        break;
      }
      case 12:

      {
        // yahtzee
        map<int, int> counter;
        for (int i = 0; i < 6; i++) {
          counter[dice[i]]++;
        }

        for (auto pair : counter) {
          if (pair.second == 5) {
            sum += 50;
          }
        }
        break;
      }
      case 13:
        // chance
        for (int i = 0; i < 6; i++) {
          sum += dice[i];
        }
        break;
      default:
        //
        std::cout << "default clause";
    }

    scores[choice - 1] = sum;
  }
};

class Game {
 public:
 std::string playerName;
  int roundsLeft;
  int dice[6];
  int totalScore;
  ScoreCard sc;
  Dice diceObj;

  Game(string playerName) {
    this->playerName = playerName;
    roundsLeft = 13;
    totalScore = 0;
    sc = new ScoreCard();
    diceObj = new Dice();
    gameLoop();
  }

  void rollSixDice() {
    for (int i = 0; i < 6; i++) {
      dice[i] = diceObj->rollDice();
    }
  }

  void gameLoop() {
    while (roundsLeft > 0) {
      int rerolls = 3;
     std::string choice = "";
      std::cout << "Current Round: " << roundsLeft << std::endl;

      while (rerolls > 0) {
        rollSixDice();
        std::cout << dice[0] << " " << dice[1] << " " << dice[2] << " ";
        std::cout << dice[3] << " " << dice[4] << " " << dice[5] << std::endl;
        std::cout << "Reroll? (" << rerolls << ") left. y/n/q" << std::endl;
        cin >> choice;

        if (choice == "n") {
          break;
        } else if (choice == "q") {
          endGame();
        } else if (choice == "y") {
          rerolls -= 1;
          continue;
        } else {
          std::cout << "Invalid input" << std::endl;
          exit(0);
        }
      }
      // choose the way you want to be scored
      int scoreChoice;
      std::cout << "Choose the way you want to be scored" << std::endl;
      sc->displayScoreSheet();
      cin >> scoreChoice;  // must be number between 1 and 13
      if (scoreChoice < 1 || scoreChoice > 13) {
        std::cout << "Invalid input" << std::endl;
        exit(0);
      }

      if (scoreChoice == 10 || scoreChoice == 11) {
        sort(begin(dice), end(dice));
      }
      sc->scoreCurrentDice(scoreChoice, dice);

      roundsLeft -= 1;
    }

    sc->displayFinalScore();
  }

  void endGame() { exit(0); }
};

int main() {
  Game game("Andres");

  std::cout << "Thanks for playing";
  return 0;
}
