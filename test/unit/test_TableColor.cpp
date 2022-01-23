#include <gtest/gtest.h>
#include <lib/ColorTable.hpp>

TEST(ColorTableTest, DISABLED_Creation){
  ColorTable* ctable = new ColorTable(5,5);

  ASSERT_EQ(ctable->getColumns(), 5);
  ASSERT_EQ(ctable->getRows(), 5);
  ASSERT_EQ(ctable->getAvailableSize(), 25);
}

TEST(ColorTableTest, DISABLED_SetColor){
  ColorTable* ctable = new ColorTable(5,5);
  ctable->setColor(2,2, BLUE);
  ctable->setColor(3,3, BLUE);

  ctable->setColor(0,0, RED);
  ctable->setColor(0,1, RED);
  ctable->setColor(0,2, RED);
  ctable->setColor(0,3, RED);

  ctable->setColor(4,2, GREEN);
  ctable->setColor(3,3, GREEN);
  ctable->setColor(2,4, GREEN);

  Color answer[25] = {
    RED,    RED,    RED,    RED,    NORMAL,
    NORMAL, NORMAL, NORMAL, NORMAL, NORMAL,
    NORMAL, NORMAL, BLUE,   NORMAL, GREEN,
    NORMAL, NORMAL, NORMAL, GREEN,  NORMAL,
    NORMAL, NORMAL, GREEN,  NORMAL, NORMAL
  };

  CharTable::iterator* it = ctable->tranverseAllColor();

  for(int i = 0; i < 25; i++){
    ASSERT_EQ(*it, answer[i]);
    it++;
  }
}
TEST(ColorTableTest, DISABLED_Iterator){}
