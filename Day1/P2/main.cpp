#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  std::string line;
  std::vector<std::string> left;
  std::vector<std::string> right;
  while (getline(input, line)) {
    std::string p1 = line.substr(0, 5);
    left.push_back(p1);
    std::string p2 = line.substr(8, 5);
    right.push_back(p2);
  }
  int result = 0;
  for (auto l : left) {
    int count = 0;
    for (auto r : right) {
      if (r == l) {
        count++;
      }
    }
    result += stoi(l) * count;
  }
  std::cout << result << std::endl;
  return 0;
}