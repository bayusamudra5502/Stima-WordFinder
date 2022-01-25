#pragma once

#include <string>
#include <vector>

#include "../types.hpp"

using namespace std;

namespace Console {
void printTable(vector<string> charTable, vector<vector<Color>> colorTable);
string getColoredChar(Color color, char ch);
void printHeader();
}  // namespace Console