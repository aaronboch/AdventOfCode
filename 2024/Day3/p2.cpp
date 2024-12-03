#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int main() {
  std::ifstream input{"../Input/03"};
  int result = 0;
  bool enabled = true;
  std::string inputLine;
  while (getline(input, inputLine)) {
    std::regex pattern(R"((mul\(\d+,\d+\))|(don't\(\))|(do\(\)))");
    std::regex_iterator rit(inputLine.begin(), inputLine.end(), pattern);
    std::regex_iterator<std::string::iterator> rend;
    while (rit != rend) {
      std::string n1, n2;
      std::string s = rit->str();

      if (s == "do()") {
        enabled = true;
        rit++;
        continue;
      }
      if (s == "don't()") {
        enabled = false;
        rit++;
        continue;
      }
      if (enabled) {
        s = s.substr(4, s.length());
        int commaPos = s.find(',');
        n1 = s.substr(0, commaPos);
        s = s.substr(commaPos + 1, s.length());
        n2 = s.substr(0, s.find(')'));

        result += (stoi(n1) * stoi(n2));
      }
      rit++;
    }
  }
  std::cout << result << std::endl;
  return 0;
}