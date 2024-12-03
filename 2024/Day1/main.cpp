#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::ifstream input("../Input/01");
  std::string line;
  std::vector<int> left;
  std::vector<int> right;
  while (getline(input, line)) {
    std::istringstream lineStream{line};
    int num1, num2;
    lineStream >> num1 >> num2;

    left.push_back(num1);
    right.push_back(num2);
  }
  // Part 1
  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());
  int result1 = 0;
  for (int i = 0; i < (int)left.size(); i++) {
    result1 += abs(left.at(i) - right.at(i));
  }
  // Part 2
  int result2 = 0;
  for (auto l : left) {
    int count = 0;
    for (auto r : right) {
      if (r == l) {
        count++;
      }
    }
    result2 += l * count;
  }

  std::cout << result1 << std::endl;
  std::cout << result2 << std::endl;
  return 0;
}