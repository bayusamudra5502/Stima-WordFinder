#include "Util.hpp"
#include <cctype>
using namespace std;

string Util::trimWhitespace(string input){
  string result = "";
  
  for(char i : input) {
    if(isalnum(i)){
      result += i;
    }
  }

  return result;
}

void Util::trimVectorString(vector<string> &input){
  for(int i = 0; i < (int) input.size(); i++) {
    input[i] = trimWhitespace(input[i]);
  }
}