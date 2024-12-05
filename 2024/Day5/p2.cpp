#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int result = 0;
  std::ifstream file{"../Input/05"};
  std::string line;
  std::map<int, std::vector<int>> rules;

  // Rules
  while (getline(file, line)) {
    if (line == "") {
      break;
    }
    // std::cout << line << std::endl;

    int pos = line.find('|');

    int leftElem = std::stoi(line.substr(0, pos));
    int rightElem = std::stoi(line.substr(pos + 1, line.size() - 1));
    std::vector<int> right;

    if (rules.find(leftElem) != rules.end()) {
      right = rules[leftElem];
    }
    right.push_back(rightElem);
    rules[leftElem] = right;

    std::ostringstream oss;
    for (size_t i = 0; i < rules[leftElem].size(); ++i) {
      oss << rules[leftElem][i];
      if (i != rules[leftElem].size() - 1) {
        oss << ", ";  // Add a delimiter
      }
    }

    // std::cout << leftElem << " [" << oss.str() << ']' << std::endl;
  }

  // Data
  while (getline(file, line)) {
    std::vector<int> pages;
    // std::cout << "-----------" << std::endl;
    std::string num;
    std::istringstream lineStream{line};
    while (getline(lineStream, num, ',')) {
      pages.push_back(stoi(num));
    }
    bool accept = true;
    for (int i = 0; i < (int)pages.size(); i++) {
      // std::cout << "Page: " << pages[i] << " Checked: ";
      std::vector<int> rule;
      // std::cout << pages[i] << " contains: " << std::endl;

      if (rules.find(pages[i]) != rules.end()) {
        rule = rules[pages[i]];
      } else if (i == (int)pages.size() - 1) {
        continue;
      } else {
        accept = false;
        break;
      }

      int in = 0;
      int out = 0;
      for (int j = i + 1; j < (int)pages.size(); j++) {
        auto it = std::find(rule.begin(), rule.end(), pages[j]);
        if (it != rule.end()) {
          // std::cout << pages[j] << " ";
          in++;
        }
        out++;
      }
      // std::cout << "i: " << in << " a: " << out << std::endl;
      if (in != out) {
        accept = false;
        break;
      }
      // std::cout << std::endl;
    }
    if (!accept) {
      std::cout << std::endl;
      std::ostringstream oss;
      for (int page : pages) {
        oss << page << ' ';
      }
      std::cout << oss.str() << std::endl;
      for (int j = 0; j < (int)pages.size() - 1; j++) {
        auto rule = rules[pages[j]];
        std::cout << pages[j] << ": ";

        bool swapped = false;  // This flag will check if any swap happened

        for (int i = j + 1; i < (int)pages.size(); i++) {
          auto it = std::find(rule.begin(), rule.end(), pages[i]);
          if (it != rule.end()) {
            std::cout << pages[i] << " ";
          } else {
            std::cout << pages[i] << "! ";
            std::cout << "swap: " << pages[j] << " and " << pages[i] << " ";
            std::swap(pages[j], pages[i]);
            swapped = true;  // Mark that a swap happened
          }
        }

        if (swapped) {
          j--;  // Decrement j to check the current element again in the next
                // outer loop iteration
        }
        std::cout << std::endl;
      }

      result += pages[pages.size() / 2];

      std::ostringstream oss2;
      for (int page : pages) {
        oss2 << page << ' ';
      }
      std::cout << oss2.str() << std::endl;
    }
    // std::cout << std::endl;
  }
  std::cout << "result:" << result << std::endl;

  return 0;
}