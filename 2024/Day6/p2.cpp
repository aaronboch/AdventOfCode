#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
void moveGuard(std::vector<std::string> &lines, int &y);
int main() {
  std::ifstream file{"../Input/06t"};
  std::string iLine;
  std::vector<std::string> lines;
  std::vector<std::string> linesCP;
  while (getline(file, iLine)) {
    lines.push_back(iLine);
  }
  linesCP = lines;
  for (auto l : lines) {
    std::cout << l << std::endl;
  }
  for (int j = 0; j < (int)lines.size(); j++) {
    for (int i = 0; i < (int)lines[j].size(); i++) {
      if (lines[j][i] == '#' || lines[j][i] == '^') {
        continue;
      }
      lines[j][i] = 'O';
      for (int y = 0; y < (int)lines.size(); y++) {
        moveGuard(lines, y);
        // anderer ansatzt fuers loopen = wenn er mehr als die anzahl von
        // stellen der matrix beruehrt hat
      }
      std::cout << std::endl;
      int result = 0;
      for (auto l : lines) {
        std::cout << l << std::endl;
      }
      lines = linesCP;
      std::cout << "j: " << j << " i: " << i << std::endl;
    }
  }
  return 0;
}

void moveGuard(std::vector<std::string> &lines, int &y) {
  int x = lines[y].find_first_of("^><j");
  if (x > 0) {
    if (lines[y][x] == '^') {
      if (y - 1 >= 0) {
        if (lines[y - 1][x] == '#') {
          lines[y][x] = '>';
          y = 0;
        } else if (lines[y - 1][x] == 'O') {
          lines[y][x] = '>';
          y = 0;
        } else {
          lines[y - 1][x] = '^';
          lines[y][x] = 'X';
          y = 0;
        }
      }
    } else if (lines[y][x] == '>') {
      if (x + 1 < (int)lines[y].size()) {
        if (lines[y][x + 1] == '#') {
          lines[y][x] = 'j';
          y = 0;
        } else if (lines[y][x + 1] == 'O') {
          lines[y][x] = 'j';
          y = 0;
        } else {
          lines[y][x + 1] = '>';
          lines[y][x] = 'X';
          y = 0;
        }
      }
    } else if (lines[y][x] == 'j') {
      if (y + 1 < (int)lines.size()) {
        if (lines[y + 1][x] == '#') {
          lines[y][x] = '<';
          y = 0;
        } else if (lines[y + 1][x] == 'O') {
          lines[y][x] = '<';
          y = 0;
        } else {
          lines[y + 1][x] = 'j';
          lines[y][x] = 'X';
          y = 0;
        }
      }
    } else if (lines[y][x] == '<') {
      if (x - 1 >= 0) {
        if (lines[y][x - 1] == '#') {
          lines[y][x] = '^';
          y = 0;
        } else if (lines[y][x - 1] == '0') {
          lines[y][x] = '^';
          y = 0;
        } else {
          lines[y][x - 1] = '<';
          lines[y][x] = 'X';
          y = 0;
        }
      }
    }
  }
}