#pragma once

#include <string>
#include <vector>

#include "types.hpp"
using namespace std;

namespace Matcher {
class StringMatcher {
 private:
  vector<vector<Color>> colorTable;
  vector<string> charTable;
  pair<int, int> size;
  int characterCheck = 0;
  int colorNumber = 0;

  bool isPositionExist(pair<int, int> pos);
  int directionLength(pair<int, int> pos, Direction dir);
  bool isAdjecentIdxAvailable(pair<int, int> idx, Direction dir);
  pair<int, int> getAdjecentIdx(pair<int, int> idx, Direction dir);
  void matchDirection(pair<int, int> pos, Direction dir, string pattern,
                      bool heuristic);

 public:
  StringMatcher(vector<string> table);
  StringMatcher(vector<string> table, Color defaultColor);

  void match(string s);
  void match(string s, bool heuristic);
  pair<int, int> getSize();
  vector<vector<Color>> getColorizedResult();

  int getCharacterCheck();
};
}  // namespace Matcher