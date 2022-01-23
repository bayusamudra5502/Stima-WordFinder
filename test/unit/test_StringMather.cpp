#include <gtest/gtest.h>
#include <lib/StringMatcher.hpp>

TEST(StringMatcher, DISABLED_Found){
  StringMatcher* matcher = new StringMatcher("WEST");

  ASSERT_TRUE(matcher->isMatch("WESTERN"));
  ASSERT_TRUE(matcher->isMatch("TOTHEWEST"));
  ASSERT_TRUE(matcher->isMatch("INTHEWESTJAVA"));
  ASSERT_TRUE(matcher->isMatch("IN THE WEST JAVA"));
  ASSERT_TRUE(matcher->isMatch("    WEST  "));
}

TEST(StringMatcher, DISABLED_NotFound){
  StringMatcher* matcher = new StringMatcher("WEST");

  ASSERT_FALSE(matcher->isMatch("W"));
  ASSERT_FALSE(matcher->isMatch("WE"));
  ASSERT_FALSE(matcher->isMatch("WES"));
  ASSERT_FALSE(matcher->isMatch("SOUTH"));
  ASSERT_FALSE(matcher->isMatch("WESAT"));
  ASSERT_FALSE(matcher->isMatch("SOUTHWES"));
}
