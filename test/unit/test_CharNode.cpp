#include <gtest/gtest.h>
#include <lib/CharNode.hpp>

TEST(CharTableTest, DISABLED_Creation){
  CharNode* testObject = new CharNode('a');
  ASSERT_EQ(testObject->getValue(), 'a');
}

TEST(CharTableTest, DISABLED_SetAdjacent){
  CharNode* adjecentN = new CharNode('1');
  CharNode* adjecentNW = new CharNode('2');
  CharNode* adjecentW = new CharNode('3');
  CharNode* adjecentSW = new CharNode('4');
  CharNode* adjecentS = new CharNode('5');
  CharNode* adjecentSE = new CharNode('6');
  CharNode* adjecentE = new CharNode('7');
  CharNode* adjecentNE = new CharNode('8');
  CharNode* testObject = new CharNode('b');

  testObject->setAdjacentNode(NORTH, adjecentN);
  testObject->setAdjacentNode(NORTHEAST, adjecentNE);
  testObject->setAdjacentNode(EAST, adjecentE);
  testObject->setAdjacentNode(SOUTHEAST, adjecentSE);
  testObject->setAdjacentNode(SOUTH, adjecentS);
  testObject->setAdjacentNode(SOUTHWEST, adjecentSW);
  testObject->setAdjacentNode(WEST, adjecentW);
  testObject->setAdjacentNode(NORTHWEST, adjecentNW);

  ASSERT_EQ(testObject->getAdjacentNode(NORTH), adjecentN);
  ASSERT_EQ(testObject->getAdjacentNode(NORTHEAST), adjecentNE);
  ASSERT_EQ(testObject->getAdjacentNode(EAST), adjecentE);
  ASSERT_EQ(testObject->getAdjacentNode(SOUTHEAST), adjecentSE);
  ASSERT_EQ(testObject->getAdjacentNode(SOUTH), adjecentS);
  ASSERT_EQ(testObject->getAdjacentNode(SOUTHWEST), adjecentSW);
  ASSERT_EQ(testObject->getAdjacentNode(WEST), adjecentW);
  ASSERT_EQ(testObject->getAdjacentNode(NORTHWEST), adjecentNW);
}
