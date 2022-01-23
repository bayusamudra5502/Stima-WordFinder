#pragma once
#include "CharTable.hpp"

enum Color {
  NORMAL,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
};

class ColorTable: private CharTable
{
public:
  ColorTable(int rows, int cols);
  int getColumns();
  int getRows();
  int getAvailableSize();

  void setColor(int rows, int cols, Color t);

  iterator* tranverseAllColor();
};
