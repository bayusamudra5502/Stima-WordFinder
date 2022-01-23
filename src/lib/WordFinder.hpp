#include "CharTable.hpp"
#include "ColorTable.hpp"

class WordFinder
{
private:
  /* data */
public:
  WordFinder(CharTable* wordTable);
  void colorizeWord(string word);
  ColorTable getColorTable();
  ~WordFinder();
};
