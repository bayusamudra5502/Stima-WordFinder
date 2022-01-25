#include "Matcher.hpp"

#include <string>
using namespace std;
using namespace Matcher;

/* Private Method */
int StringMatcher::directionLength(pair<int, int> pos, Direction dir) {
  if (!this->isPositionExist(pos)) {
    return -1;
  }

  switch (dir) {
    case NORTH:
      return pos.first + 1;
    case NORTHWEST:
      return min(this->directionLength(pos, NORTH),
                 this->directionLength(pos, WEST));
    case WEST:
      return pos.second + 1;
    case SOUTHWEST:
      return min(this->directionLength(pos, SOUTH),
                 this->directionLength(pos, WEST));
    case SOUTH:
      return this->size.first - pos.first;
    case SOUTHEAST:
      return min(this->directionLength(pos, SOUTH),
                 this->directionLength(pos, EAST));
    case EAST:
      return this->size.second - pos.second;
    case NORTHEAST:
      return min(this->directionLength(pos, NORTH),
                 this->directionLength(pos, EAST));
  }

  return -1;
}

bool StringMatcher::isPositionExist(pair<int, int> pos) {
  return pos.first >= 0 && pos.second >= 0 && pos.first < size.first &&
         pos.second < size.second;
}

bool StringMatcher::isAdjecentIdxAvailable(pair<int, int> idx, Direction dir) {
  switch (dir) {
    case NORTH:
      return this->isPositionExist(pair<int, int>(idx.first - 1, idx.second));
    case EAST:
      return this->isPositionExist(pair<int, int>(idx.first, idx.second + 1));
    case SOUTH:
      return this->isPositionExist(pair<int, int>(idx.first + 1, idx.second));
    case WEST:
      return this->isPositionExist(pair<int, int>(idx.first, idx.second - 1));
    case NORTHEAST:
      return this->isAdjecentIdxAvailable(idx, NORTH) &&
             this->isAdjecentIdxAvailable(idx, EAST);
    case NORTHWEST:
      return this->isAdjecentIdxAvailable(idx, NORTH) &&
             this->isAdjecentIdxAvailable(idx, WEST);
    case SOUTHEAST:
      return this->isAdjecentIdxAvailable(idx, SOUTH) &&
             this->isAdjecentIdxAvailable(idx, EAST);
    case SOUTHWEST:
      return this->isAdjecentIdxAvailable(idx, SOUTH) &&
             this->isAdjecentIdxAvailable(idx, WEST);
  }

  return false;
}

pair<int, int> StringMatcher::getAdjecentIdx(pair<int, int> idx,
                                             Direction dir) {
  if (!this->isAdjecentIdxAvailable(idx, dir)) {
    return pair<int, int>(-1, -1);
  }

  switch (dir) {
    case NORTH:
      return pair<int, int>(idx.first - 1, idx.second);
    case NORTHEAST:
      return pair<int, int>(idx.first - 1, idx.second + 1);
    case EAST:
      return pair<int, int>(idx.first, idx.second + 1);
    case SOUTHEAST:
      return pair<int, int>(idx.first + 1, idx.second + 1);
    case SOUTH:
      return pair<int, int>(idx.first + 1, idx.second);
    case SOUTHWEST:
      return pair<int, int>(idx.first + 1, idx.second - 1);
    case WEST:
      return pair<int, int>(idx.first, idx.second - 1);
    case NORTHWEST:
      return pair<int, int>(idx.first - 1, idx.second - 1);
  }

  return pair<int, int>(-1, -1);
}

/* Match Direction */
void StringMatcher::matchDirection(pair<int, int> pos, Direction dir,
                                   string pattern, bool heuristic) {
  pair<int, int> currentPos = pos;
  while (this->directionLength(currentPos, dir) >= (int)pattern.length() ||
         (!heuristic && this->directionLength(currentPos, dir) >= 0)) {
    int match = 0;
    pair<int, int> posIndex = currentPos;

    for (int i = 0; i < (int)pattern.length(); i++) {
      if (!this->isPositionExist(posIndex) ||
          this->charTable[posIndex.first][posIndex.second] != pattern[match]) {
        break;
      }

      match++;
      posIndex = this->getAdjecentIdx(posIndex, dir);
    }

    if (match == (int)pattern.length()) {
      // Colorize
      pair<int, int> posIndex = currentPos;
      for (int i = 0; i < (int)pattern.length(); i++) {
        this->colorTable[posIndex.first][posIndex.second] =
            (Color)(this->colorNumber % 7 + 2);
        posIndex = this->getAdjecentIdx(posIndex, dir);
      }

      this->colorNumber++;
    }

    currentPos = this->getAdjecentIdx(currentPos, dir);
  }
}

/* Constructor */
StringMatcher::StringMatcher(vector<string> table)
    : StringMatcher(table, HIDDEN) {}

StringMatcher::StringMatcher(vector<string> table, Color defaultColor) {
  this->charTable = table;
  this->size.first = table.size();

  if (this->size.first > 0) {
    this->size.second = table[0].length();
  } else {
    this->size.second = 0;
  }

  for (int i = 0; i < this->size.first; i++) {
    vector<Color> row;
    for (int j = 0; j < this->size.second; j++) {
      row.push_back(defaultColor);
    }
    this->colorTable.push_back(row);
  }
}

/* Public Methods */
vector<vector<Color>> StringMatcher::getColorizedResult() {
  return this->colorTable;
}

void StringMatcher::match(string pattern, bool heuristic) {
  for (int i = 0; i < this->size.first; i++) {
    for (int j = 0; j < this->size.second; j++) {
      this->matchDirection(pair<int, int>(i, j), NORTH, pattern, heuristic);
      this->matchDirection(pair<int, int>(i, j), NORTHWEST, pattern, heuristic);
      this->matchDirection(pair<int, int>(i, j), WEST, pattern, heuristic);
      this->matchDirection(pair<int, int>(i, j), SOUTHWEST, pattern, heuristic);
      this->matchDirection(pair<int, int>(i, j), SOUTH, pattern, heuristic);
      this->matchDirection(pair<int, int>(i, j), SOUTHEAST, pattern, heuristic);
      this->matchDirection(pair<int, int>(i, j), EAST, pattern, heuristic);
      this->matchDirection(pair<int, int>(i, j), NORTHEAST, pattern, heuristic);
    }
  }
}

void StringMatcher::match(string pattern) { this->match(pattern, false); }

pair<int, int> StringMatcher::getSize() { return this->size; }
