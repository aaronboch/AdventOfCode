#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
int main() {
  int result = 0;
  std::ifstream file{"../Input/04"};
  std::string input;
  std::string vert;

  std::regex pattern1{R"((XMAS))"};
  std::regex pattern2{R"((SAMX))"};

  std::vector<std::string> lines;

  while (getline(file, input)) {
    std::regex_iterator rit(input.begin(), input.end(), pattern1);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
      // std::string s = rit->str();
      // std::cout << s << std::endl;
      result++;
      rit++;
    }
    std::regex_iterator rit2(input.begin(), input.end(), pattern2);
    std::regex_iterator<std::string::iterator> rend2;
    while (rit2 != rend2) {
      // std::string s = rit2->str();
      // std::cout << s << std::endl;
      result++;
      rit2++;
    }

    lines.push_back(input);
  }
  std::cout << "Horizontal: " << result << std::endl;

  for (int x = 0; x < (int)lines[1].size(); x++) {
    for (int y = 0; y < (int)lines.size(); y++) {
      vert += lines[y][x];
    }

    std::regex_iterator rit(vert.begin(), vert.end(), pattern1);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
      // std::string s = rit->str();
      // std::cout << s << std::endl;

      result++;
      rit++;
    }
    std::regex_iterator rit2(vert.begin(), vert.end(), pattern2);
    std::regex_iterator<std::string::iterator> rend2;
    while (rit2 != rend2) {
      // std::string s = rit2->str();
      // std::cout << s << std::endl;
      result++;
      rit2++;
    }
    vert.clear();
  }
  std::cout << "Horizontal + Vertical: " << result << std::endl;

  std::string diag;
  for (int i = 0; i < ((int)lines.at(0).size() + (int)lines.size()) - 1; i++) {
    for (int j = 0; j < (int)lines.size(); j++) {
      int col = i - j;
      if (col >= 0 && col < (int)lines.at(j).size()) {
        diag += lines[j][col];
      }
    }
    // std::cout << diag << std::endl;

    std::regex_iterator rit(diag.begin(), diag.end(), pattern1);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
      // std::string s = rit->str();
      // std::cout << s << std::endl;
      result++;
      rit++;
    }
    std::regex_iterator rit2(diag.begin(), diag.end(), pattern2);
    std::regex_iterator<std::string::iterator> rend2;
    while (rit2 != rend2) {
      // std::string s = rit2->str();
      // std::cout << s << std::endl;
      result++;
      rit2++;
    }
    diag.clear();
  }
  std::cout << "Horizontal + Vertical + Diag1: " << result << std::endl;

  diag.clear();
  for (int i = 0; i < ((int)lines.at(0).size() + (int)lines.size()) - 1; i++) {
    for (int j = 0; j < (int)lines.size(); j++) {
      int col = (int)lines.at(0).size() - 1 - i + j;
      if (col >= 0 && col < (int)lines.at(j).size()) {
        diag += lines[j][col];
      }
    }

    // std::cout << diag << std::endl;

    std::regex_iterator diagRit(diag.begin(), diag.end(), pattern1);
    std::regex_iterator<std::string::iterator> diagRend;
    while (diagRit != diagRend) {
      // std::string s = diagRit->str();
      // std::cout << s << std::endl;
      result++;
      diagRit++;
    }
    std::regex_iterator diagRit2(diag.begin(), diag.end(), pattern2);
    std::regex_iterator<std::string::iterator> diagRend2;
    while (diagRit2 != diagRend2) {
      // std::string s = diagRit2->str();
      // std::cout << s << std::endl;
      result++;
      diagRit2++;
    }
    diag.clear();
  }
  std::cout << "Horizontal + Vertical + Diag1 + Diag2: " << result << std::endl;
}