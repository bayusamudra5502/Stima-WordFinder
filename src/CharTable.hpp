#pragma once

#include <string>
#include "CharNode.hpp"
#include "types.hpp"
using namespace std;

class CharTable
{
private:
  CharNode* table;
  int size;
  int columns, rows;

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
  CharTable(int size = 10);

  class iterator
  {
    private:
      CharNode* node;
    public:
      iterator(Direction dir);

      iterator* next();
      iterator* prev();
      char getValue();
      
      bool isNextAvailable();
      bool isPrevAvailable();
  };

  int getColumns();
  int getRows();

  void setSize(int rows, int cols);

  int getSize();

  void insertChar(char t);

  string getString(int x, int y, Direction direction);
  iterator* getIterator(int x, int y, Direction dir);
};
