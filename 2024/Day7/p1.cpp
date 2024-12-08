#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <tuple>
#include <vector>

bool checkLine(std::vector<long> nums, long target);

int main() {
  long result = 0;
  std::ifstream f{"../Input/07"};
  std::string l;
  while (getline(f, l)) {
    std::istringstream stream{l};
    std::string s;
    std::vector<long> nums;
    getline(stream, s, ':');
    long target = stol(s);

    getline(stream, s);
    std::istringstream numStream{s};
    long num;
    while (numStream >> num) {
      nums.push_back(num);
    }
    if (checkLine(nums, target)) {
      result += target;
    }
  }
  std::cout << "result: " << result << std::endl;

  return 0;
}

bool checkLine(std::vector<long> nums, long target) {
  std::queue<std::pair<long, long>> q;
  q.push({0, nums[0]});

  while (!q.empty()) {
    auto [index, curr] = q.front();
    q.pop();

    if (index == static_cast<long>(nums.size() - 1)) {
      if (curr == target) {
        return true;
      }
      continue;
    }

    long next = nums[index + 1];
    q.push({index + 1, curr + next});
    q.push({index + 1, curr * next});
  }
  return false;
}