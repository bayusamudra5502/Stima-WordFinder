#include <lib/Util.hpp>
#include <gtest/gtest.h>

TEST(Utility_Test, Utility_Test_TrimWhitespace){
  ASSERT_EQ(Util::trimWhitespace("abcdefgh"),"abcdefgh");
  ASSERT_EQ(Util::trimWhitespace("a b c d e f g h"),"abcdefgh");
  ASSERT_EQ(Util::trimWhitespace("      abcdefgh"),"abcdefgh");
  ASSERT_EQ(Util::trimWhitespace("abcdefgh       "),"abcdefgh");
  ASSERT_EQ(Util::trimWhitespace("a   b c   d    e   f g   h     "),"abcdefgh");
  ASSERT_EQ(Util::trimWhitespace("   a  b c   d   e f   g h   "),"abcdefgh");
}

TEST(Utility_Test, Utility_Test_trimVectorString) {
  vector<string> problem;

  problem.push_back("abcdefghi");
  problem.push_back("a b c d e f g h i");
  problem.push_back("a   bc   de  f  g  h i");
  problem.push_back("a b c  de  f gh i  ");

  Util::trimVectorString(problem);
  
  for(string item: problem) {
    ASSERT_EQ(item,"abcdefghi");
  }
}