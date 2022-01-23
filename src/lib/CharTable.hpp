#pragma once

#include <string>
#include "CharNode.hpp"
#include "types.hpp"
using namespace std;

class CharTable
{
private:
  CharNode* table;
  int availableSize;
  int columns, rows;
  int length;
  bool isSized = false;

  string getN(int x, int y);
  string getNE(int x, int y);
  string getE(int x, int y);
  string getSE(int x, int y);
  string getS(int x, int y);
  string get(int x, int y);
  string getS(int x, int y);
  string getSW(int x, int y);
  string getW(int x, int y);
  string getNW(int x, int y);
public:
  CharTable(int availableSize = 10);
  ~CharTable();

  class iterator
  {
    private:
      CharNode& node;
    public:
      iterator(Direction dir);

      iterator& operator++();
      char operator*();
      
      bool isNextAvailable();
  };

  int getColumns();
  int getRows();
  int getAvailableSize();

  void setSize(int rows, int cols);

  void insertChar(char t);

  string getString(int x, int y, Direction direction);
  iterator* getIterator(int x, int y, Direction dir);
  iterator* tranverseAllItem(int x, int y);
};
