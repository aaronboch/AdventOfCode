#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  std::ifstream file{"../Input/06"};
  std::string iLine;
  std::vector<std::string> lines;
  std::vector<std::string> linesCP;
  int result = 0;
  while (getline(file, iLine)) {
    lines.push_back(iLine);
  }
  linesCP = lines;

  for (int j = 0; j < (int)lines.size(); j++) {
    for (int i = 0; i < (int)lines[j].size(); i++) {
      bool running = true;
      bool up = true;
      bool right = false;
      bool down = false;

      // if (j == 6 && i == 3) {
      if (lines[j][i] == '#' || lines[j][i] == '^') {
        continue;
      }
      lines[j][i] = 'O';

      int steps = 0;
      int xPos = 0;
      int yPos = 0;
      for (int y = 0; y < (int)lines.size(); y++) {
        xPos = lines[y].find("^");
        yPos = y;
        if (xPos >= 0) {
          break;
        }
      }
      // for (auto l : lines) {
      //   std::cout << l << std::endl;
      // }
      std::cout << "J: " << j << " I: " << i << std::endl;
      // std::cout << "startpos y: " << yPos << " x: " << xPos << std::endl;

      while (running) {
        // std::cout << "y: " << yPos << " x: " << xPos << std::endl;
        if ((xPos > 0 && xPos < (int)lines[0].size()) &&
            (yPos > 0 && yPos < (int)lines.size() - 1) &&
            (steps < (int)lines.size() * (int)lines[0].size())) {
          if (up) {
            if (lines[yPos - 1][xPos] == '#' || lines[yPos - 1][xPos] == 'O') {
              up = false;
              right = true;
            } else {
              yPos--;
              steps++;
            }
          } else if (right) {
            if (lines[yPos][xPos + 1] == '#' || lines[yPos][xPos + 1] == 'O') {
              right = false;
              down = true;
            } else {
              xPos++;
              steps++;
            }
          } else if (down) {
            if (lines[yPos + 1][xPos] == '#' || lines[yPos + 1][xPos] == 'O') {
              down = false;
            } else {
              yPos++;
              steps++;
            }
          } else {
            if (lines[yPos][xPos - 1] == '#' || lines[yPos][xPos - 1] == 'O') {
              up = true;
            } else {
              xPos--;
              steps++;
            }
          }
        } else if (steps >= (int)lines.size() * (int)lines[0].size()) {
          result++;
          running = false;
        } else {
          running = false;
        }
      }

      // std::cout << "end y: " << yPos << " x: " << xPos << std::endl;

      lines = linesCP;
      //}
    }
  }
  std::cout << result << std::endl;
  return 0;
}
