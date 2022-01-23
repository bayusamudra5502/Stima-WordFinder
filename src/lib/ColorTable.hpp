#pragma once
#include "CharTable.hpp"
#include "types.hpp"

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
