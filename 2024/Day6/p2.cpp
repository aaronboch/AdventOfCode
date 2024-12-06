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
  for (auto l : lines) {
    std::cout << l << std::endl;
  }
  for (int j = 0; j < (int)lines.size(); j++) {
    for (int i = 0; i < (int)lines[j].size(); i++) {
      std::cout << "j: " << j << " i: " << i << std::endl;

      if (lines[j][i] == '#' || lines[j][i] == '^') {
        continue;
      }
      lines[j][i] = 'O';
      /*
        for (auto l : lines) {
          std::cout << l << std::endl;
        }
      */

      int steps = 0;
      for (int y = 0; y < (int)lines.size(); y++) {
        int x = lines[y].find_first_of("^><j");

        if (x > 0 && steps < (int)lines.size() * (int)lines[0].size()) {
          // std::cout << lines[y][x] << " at y: " << y << "with: " << steps <<
          // " steps" << std::endl;
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
                lines[y][x] = '.';
                y = 0;
                steps++;
              }
            } else {
              steps = 0;
              break;
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
                lines[y][x] = '.';

                y = 0;
                steps++;
              }
            } else {
              steps = 0;
              break;
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
                lines[y][x] = '.';

                y = 0;
                steps++;
              }
            } else {
              steps = 0;
              break;
            }
          } else if (lines[y][x] == '<') {
            if (x - 1 >= 0) {
              if (lines[y][x - 1] == '#') {
                lines[y][x] = '^';
                y = 0;
              } else if (lines[y][x - 1] == 'O') {
                lines[y][x] = '^';
                y = 0;
              } else {
                lines[y][x - 1] = '<';
                lines[y][x] = '.';
                y = 0;
                steps++;
              }
            } else {
              steps = 0;
              break;
            }
          }
        } else if (steps >= (int)lines.size() * (int)lines[0].size()) {
          // std::cout << steps << ">=" << (int)lines.size() *
          // (int)lines[0].size()
          //          << " i: " << i << std::endl;
          result++;
          break;
        }
      }
      /*if (j == 6 && i == 3) {
        std::cout << std::endl;

        for (auto l : lines) {
          std::cout << l << std::endl;
        }
      }*/
      lines = linesCP;
    }
  }
  std::cout << result << std::endl;
  return 0;
}
