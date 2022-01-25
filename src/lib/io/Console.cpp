#include "Console.hpp"

#include <iostream>
using namespace std;

string getColorANSI(Color color) {
  switch (color) {
    case RED:
      return "\x1B[31m";
    case GREEN:
      return "\x1B[32m";
    case YELLOW:
      return "\x1B[33m";
    case BLUE:
      return "\x1B[34m";
    case MAGENTA:
      return "\x1B[35m";
    case CYAN:
      return "\x1B[36m";
    case WHITE:
      return "\x1B[37m";
    case HIDDEN:
      return "\x1B[90m";
    case NORMAL:
    default:
      return "\x1B[0m";
  }
}

string Console::getColoredChar(Color color, char ch) {
  return getColorANSI(color) + ch + getColorANSI(NORMAL);
}

void Console::printTable(vector<string> charTable,
                         vector<vector<Color>> colorTable) {
  if (charTable.size() == 0) {
    cout << endl;
    return;
  }

  int rows = charTable.size();
  int cols = charTable[0].length();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (j > 0) {
        cout << " ";
      }

      cout << getColoredChar(colorTable[i][j], charTable[i][j]);
    }

    cout << endl;
  }

  cout << endl;
}

void Console::printHeader() {
  string headerTemplate =
      " __          __           _   _____               _      \n \\ \\       "
      " / /          | | |  __ \\             | |    \n  \\ \\  /\\  / /__  _ "
      "__ __| | | |__) |   _ _______| | ___ \n   \\ \\/  \\/ / _ \\| '__/ _` | "
      "|  ___/ | | |_  /_  / |/ _ \\\n    \\  /\\  / (_) | | | (_| | | |   | "
      "|_| |/ / / /| |  __/\n     \\/  \\/ \\___/|_|  \\__,_| |_|    "
      "\\__,_/___/___|_|\\___|\n";

  cout << getColorANSI(GREEN) << headerTemplate << getColorANSI(CYAN) << endl
       << "Versi 1.0.0" << getColorANSI(NORMAL) << endl;
}