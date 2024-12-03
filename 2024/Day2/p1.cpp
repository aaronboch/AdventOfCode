#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
int main() {
  int result = 0;
  std::ifstream input("../Input/02");
  std::string inputLine;

  while (getline(input, inputLine)) {
    std::vector<int> line;
    std::istringstream lineStream{inputLine};
    int test;
    while (lineStream >> test) {
      line.push_back(test);
    }
    if (!line.empty()) {
      int previous = line.at(0);
      bool safe = true;
      bool first = true;
      bool desc = true;

      for (int i = 1; i < (int)line.size(); i++) {
        int cur = line.at(i);
        int diff = previous - cur;
        if ((first || desc) && diff <= 3 && diff > 0) {
          if (first) {
            first = false;
          }
        } else if ((first || !desc) && diff >= -3 && diff < 0) {
          if (first) {
            first = false;
            desc = false;
          }
        } else {
          safe = false;
          break;
        }
        previous = cur;
      }
      if (safe) {
        result++;
      }
    } else {
      std::cerr << "Error: Parsed line is empty!" << std::endl;
    }
  }
  std::cout << result << std::endl;
}