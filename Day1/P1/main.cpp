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
  std::sort(left.begin(), left.end());
  std::sort(right.begin(), right.end());
  int result = 0;
  for (int i = 0; i < (int)left.size(); i++) {
    result += abs(stoi(left.at(i)) - stoi(right.at(i)));
  }
  std::cout << result << std::endl;
  return 0;
}