#include <gtest/gtest.h>
#include <lib/CharTable.hpp>
#include <lib/WordFinder.hpp>

TEST(WordFinderTest, DISABLE_Test){
  CharTable* charTable = new CharTable();

  char tableData[] = 
    "dbacas"
    "iubisf"
    "begasq"
    "esqlab"
    "sfqweb";

  for(char c: tableData){
    if(c != '\n'){
      charTable->insertChar(c);
    }
  }

  charTable -> setSize(5,6);
  
  WordFinder* finder = new WordFinder(charTable);
  finder->colorizeWord("baca");
  finder->colorizeWord("cial");
  finder->colorizeWord("web");
  finder->colorizeWord("lab");
  finder->colorizeWord("dug");
  finder->colorizeWord("dibeb");
  finder->colorizeWord("qas");
  finder->colorizeWord("sf");

  Color colorTable[5][6] = {
    {MAGENTA, RED,     RED,      GREEN,  RED,    NORMAL},
    {NORMAL,  MAGENTA, NORMAL,   GREEN,  WHITE,  WHITE},
    {NORMAL,  NORMAL,  MAGENTA,  CYAN,   NORMAL, NORMAL},
    {NORMAL,  NORMAL,  CYAN,     BLUE,   BLUE,   BLUE},
    {WHITE,   WHITE,   NORMAL,   YELLOW, YELLOW, YELLOW},
  };

  ColorTable* table = new ColorTable(5,6);

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
      table->setColor(i, j, colorTable[i][j]);
    }
  }

  CharTable::iterator *it = table->tranverseAllColor();
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 6; j++){
      ASSERT_EQ(colorTable[i][j], **it);
      it++;
    }
  }
}