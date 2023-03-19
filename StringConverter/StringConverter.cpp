#include <iostream>
#include <string>
#include <unordered_map>

std::string converted_string(const std::string& str)
{
  std::string convertedString;
  std::unordered_map<char, int> charMap;

  // lower all the characters and fill the char map
  for (const char ch : str) {
    convertedString.push_back(tolower(ch));
    charMap[convertedString.back()]++;
  }

  // replacing the characters
  for (int i{}; i < str.size(); ++i) {
    if (charMap.at(convertedString.at(i)) == 1) {
      convertedString[i] = '(';
    }
    else {
      convertedString[i] = ')';
    }
  }
  return convertedString;
}


int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " string1 [string2 ...]" << std::endl;
    return 1;
  }

  for (int i{ 1 }; i < argc; ++i) {
    std::cout << i << ") " << argv[i] << " => " << converted_string(argv[i]) << std::endl;
  }
  return 0;
}