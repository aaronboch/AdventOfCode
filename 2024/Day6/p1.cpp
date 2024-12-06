#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
int main() {
  std::ifstream file{"../Input/06"};
  std::string iLine;
  std::vector<std::string> lines;

  while (getline(file, iLine)) {
    lines.push_back(iLine);
  }

  for (auto l : lines) {
    std::cout << l << std::endl;
  }

  for (int y = 0; y < (int)lines.size(); y++) {
    int x = lines[y].find_first_of("^><j");

    if (x > 0) {
      std::cout << "x:" << x << " y: " << y << std::endl;
      if (lines[y][x] == '^') {
        if (y - 1 >= 0) {
          if (lines[y - 1][x] == '#') {
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
          } else {
            lines[y][x - 1] = '<';
            lines[y][x] = 'X';
            y = 0;
          }
        }
      }
    }

    continue;
  }
  std::cout << std::endl;
  int result = 0;
  for (auto l : lines) {
    std::string::difference_type n = std::count(l.begin(), l.end(), 'X');
    result += n;
    std::cout << l << std::endl;
  }
  std::cout << result + 1 << std::endl;
  return 0;
}