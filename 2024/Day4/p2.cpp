#include <fstream>
#include <iostream>
#include <regex>
#include <vector>

bool checkDiagMas(int diag, std::vector<std::string> lines, int pos1, int pos2);

int main() {
  int result = 0;
  std::ifstream file{"../Input/04"};
  std::string input;
  std::string vert;

  std::regex pattern1{R"((XMAS))"};
  std::regex pattern2{R"((SAMX))"};

  std::vector<std::string> lines;

  while (getline(file, input)) {
    lines.push_back(input);
  }
  int count = 0;
  for (int i = 1; i < (int)lines.size() - 1; i++) {
    for (int j = 1; j < (int)lines.at(0).size() - 1; j++) {
      if (lines[i][j] == 'A') {
        if (checkDiagMas(0, lines, i, j)) {
          if (checkDiagMas(1, lines, i, j)) {
            result++;
          }
        }
        count++;
      }
    }
  }
  std::cout << result << std::endl;
}

bool checkDiagMas(int diag, std::vector<std::string> lines, int i, int j) {
  if (diag == 0) {
    if (lines.at(i - 1).at(j - 1) == 'M') {
      if (lines.at(i + 1).at(j + 1) == 'S') {
        return true;
      }
    } else if (lines.at(i - 1).at(j - 1) == 'S') {
      if (lines.at(i + 1).at(j + 1) == 'M') {
        return true;
      }
    }
  } else if (diag == 1) {
    if (lines.at(i - 1).at(j + 1) == 'M') {
      if (lines.at(i + 1).at(j - 1) == 'S') {
        return true;
      }
    } else if (lines.at(i - 1).at(j + 1) == 'S') {
      if (lines.at(i + 1).at(j - 1) == 'M') {
        return true;
      }
    }
  }
  return false;
}