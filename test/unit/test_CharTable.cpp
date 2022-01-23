#include <gtest/gtest.h>
#include <lib/CharTable.hpp>

TEST(CharTableTest, DISABLED_TestAvailableSize){
  CharTable *tableA, *tableB;
  tableA = new CharTable();
  tableB = new CharTable(20);

  ASSERT_EQ(tableA->getAvailableSize(), 10);
  ASSERT_EQ(tableA->getRows(), 1);

  ASSERT_EQ(tableB->getAvailableSize(), 20);
  ASSERT_EQ(tableB->getRows(), 1);
}

TEST(CharTableTest, DISABLED_TestInsertChar){
  CharTable* table = new CharTable();
  
  for(int i = 0; i < 20; i++){
    table->insertChar('a' + i);
  }

  ASSERT_EQ(table->getColumns(), 20);
  ASSERT_EQ(table->getRows(), 1);

  string result = table->getString(0,0,EAST);
  ASSERT_STREQ(result.c_str(), "abcdefghijklmnopqrst");
  ASSERT_EQ(result, new string("abcdefghijklmnopqrst"));
}

TEST(CharTableTest, DISABLED_TestSizing){
  CharTable* table = new CharTable();

  for(int i = 0; i < 25; i++){
    table->insertChar(i + 'a');
  }

  table->setSize(5,5);
  ASSERT_EQ(table->getColumns(), 5);
  ASSERT_EQ(table->getRows(), 5);

  table->setSize(25,1);
  ASSERT_EQ(table->getColumns(), 1);
  ASSERT_EQ(table->getRows(), 25);
}

void checkRoutines(char ans[], Direction dir){
  CharTable* table = new CharTable();

  for(int i = 0; i < 25; i++){
    table->insertChar(i + 'a');
  }

  table->setSize(5,5);

  CharTable::iterator* itN = table->getIterator(3,3, dir);
  int i = 0;

  while(itN->isNextAvailable()){
    ASSERT_EQ(ans[i], *itN);
    i++;
    itN++;
  }
}

TEST(CharTableTest, DISABLE_TestIterator) {
  checkRoutines("mhc", NORTH);
  checkRoutines("mie", NORTHEAST);
  checkRoutines("mno", EAST);
  checkRoutines("msy", SOUTHEAST);
  checkRoutines("mrw", SOUTH);
  checkRoutines("mqu", SOUTHWEST);
  checkRoutines("mlk", WEST);
  checkRoutines("mga", NORTHWEST);
}

TEST(CharTableTest, DISABLE_TestTranverse){
  CharTable* table = new CharTable();

  for(int i = 0; i < 25; i++){
    table->insertChar(i + 'a');
  }

  table->setSize(5,5);
  CharTable::iterator* hasil  = table->tranverseAllItem(0,0);

  for(int i = 0; i < 25; i++){
    ASSERT_EQ(*hasil, 'a'+i);
    hasil++;
  }

  hasil = table->tranverseAllItem(3,3);
  
  for(int i = 9; i < 25; i++){
    ASSERT_EQ(*hasil, 'a'+i);
    hasil++;
  }
}