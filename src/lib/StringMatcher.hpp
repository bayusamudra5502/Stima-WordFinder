#pragma once

#include <string>
using namespace std;

class StringMatcher
{
  private:
    string pattern;
    
  public:
    StringMatcher(string pattern);
    bool isMatch(string text);
};
