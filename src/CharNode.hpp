#pragma once
#include "types.hpp"

class CharNode
{
private:
  char c;
  CharNode* N[8];
public:
  CharNode(char c);

  void setAdjacentNode(Direction dir, CharNode* node);
  CharNode* getAdjacentNode(Direction dir);
  char getValue();
};
