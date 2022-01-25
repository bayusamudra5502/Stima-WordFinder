#include <gtest/gtest.h>

#include <lib/Matcher.hpp>
using namespace std;
using namespace Matcher;

TEST(Matcher_Test, Matcher_Size_Test) {
  StringMatcher* emptyTable = new StringMatcher(vector<string>());
  ASSERT_EQ(emptyTable->getSize(), (pair<int, int>(0, 0)));

  StringMatcher* notEmptyTable;
  vector<string> data;
  data.push_back("abcde");
  data.push_back("abcde");
  data.push_back("abcde");
  data.push_back("abcde");

  notEmptyTable = new StringMatcher(data);
  ASSERT_EQ(notEmptyTable->getSize(), (pair<int, int>(4, 5)));
}

TEST(Matcher_Test, Matcher_Match_Test_E_NonHeuristic) {
  vector<string> table;
  table.push_back("bacacuk");
  table.push_back("makansa");
  table.push_back("nasdrwm");

  vector<string> words;
  words.push_back("baca");
  words.push_back("makansayur");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {RED, RED, RED, RED, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_E_Heuristic) {
  vector<string> table;
  table.push_back("bacacuk");
  table.push_back("makansa");
  table.push_back("nasdrwm");

  vector<string> words;
  words.push_back("baca");
  words.push_back("makansayur");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {RED, RED, RED, RED, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_NE_NonHeuristic) {
  vector<string> table;
  table.push_back("asjdcuk");
  table.push_back("iaaania");
  table.push_back("nnsdtwm");

  vector<string> words;
  words.push_back("dan");
  words.push_back("kita");
  words.push_back("si");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, GREEN, HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN},
      {GREEN, HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_NE_Heuristic) {
  vector<string> table;
  table.push_back("asjdcuk");
  table.push_back("iaaania");
  table.push_back("nnsdtwm");

  vector<string> words;
  words.push_back("dan");
  words.push_back("kita");
  words.push_back("si");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, GREEN, HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN},
      {GREEN, HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_N_NonHeuristic) {
  vector<string> table;
  table.push_back("hshdcuk");
  table.push_back("aiiania");
  table.push_back("hnsdtwm");

  vector<string> words;
  words.push_back("kamar");
  words.push_back("hah");
  words.push_back("hist");
  words.push_back("kam");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {GREEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, YELLOW},
      {GREEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, YELLOW},
      {GREEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, YELLOW},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_N_Heuristic) {
  vector<string> table;
  table.push_back("hshdcuk");
  table.push_back("aiiania");
  table.push_back("hnsdtwm");

  vector<string> words;
  words.push_back("kamar");
  words.push_back("hah");
  words.push_back("hist");
  words.push_back("kam");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {GREEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, YELLOW},
      {GREEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, YELLOW},
      {GREEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, HIDDEN, YELLOW},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_NW_NonHeuristic) {
  vector<string> table;
  table.push_back("lshncuk");
  table.push_back("aiiaaia");
  table.push_back("hnndtdm");

  vector<string> words;
  words.push_back("kamar");
  words.push_back("nil");
  words.push_back("dan");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {RED, HIDDEN, HIDDEN, YELLOW, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, RED, HIDDEN, GREEN, YELLOW, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, RED, GREEN, HIDDEN, YELLOW, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_NW_Heuristic) {
  vector<string> table;
  table.push_back("lshncuk");
  table.push_back("aiiaaia");
  table.push_back("hnndtdm");

  vector<string> words;
  words.push_back("kamar");
  words.push_back("nil");
  words.push_back("dan");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {RED, HIDDEN, HIDDEN, YELLOW, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, RED, HIDDEN, GREEN, YELLOW, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, RED, GREEN, HIDDEN, YELLOW, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_W_NonHeuristic) {
  vector<string> table;
  table.push_back("libsink");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("kamar");
  words.push_back("nisbi");
  words.push_back("dan");
  words.push_back("bill");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, GREEN, GREEN, GREEN, GREEN, BLUE, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, HIDDEN, BLUE, HIDDEN, HIDDEN},
      {HIDDEN, WHITE, WHITE, WHITE, HIDDEN, HIDDEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_W_Heuristic) {
  vector<string> table;
  table.push_back("libsink");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("kamar");
  words.push_back("nisbi");
  words.push_back("dan");
  words.push_back("bill");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, GREEN, GREEN, GREEN, GREEN, BLUE, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, HIDDEN, BLUE, HIDDEN, HIDDEN},
      {HIDDEN, WHITE, WHITE, WHITE, HIDDEN, HIDDEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_SE_NonHeuristic) {
  vector<string> table;
  table.push_back("libsink");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("liana");
  words.push_back("sad");
  words.push_back("bat");
  words.push_back("sat");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, HIDDEN, YELLOW, GREEN, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, YELLOW, GREEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, RED, YELLOW, GREEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_SE_Heuristic) {
  vector<string> table;
  table.push_back("libsink");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("liana");
  words.push_back("sad");
  words.push_back("bat");
  words.push_back("sat");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, HIDDEN, YELLOW, GREEN, HIDDEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, YELLOW, GREEN, HIDDEN, HIDDEN},
      {HIDDEN, HIDDEN, HIDDEN, RED, YELLOW, GREEN, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_S_NonHeuristic) {
  vector<string> table;
  table.push_back("aswsskd");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("sins");
  words.push_back("sad");
  words.push_back("dam");
  words.push_back("sinsin");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, HIDDEN, HIDDEN, GREEN, HIDDEN, HIDDEN, YELLOW},
      {HIDDEN, HIDDEN, HIDDEN, RED, GREEN, HIDDEN, YELLOW},
      {HIDDEN, HIDDEN, HIDDEN, RED, HIDDEN, GREEN, YELLOW},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_S_Heuristic) {
  vector<string> table;
  table.push_back("aswsskd");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("sins");
  words.push_back("sad");
  words.push_back("dam");
  words.push_back("sinsin");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, HIDDEN, HIDDEN, GREEN, HIDDEN, HIDDEN, YELLOW},
      {HIDDEN, HIDDEN, HIDDEN, RED, GREEN, HIDDEN, YELLOW},
      {HIDDEN, HIDDEN, HIDDEN, RED, HIDDEN, GREEN, YELLOW},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_SW_NonHeuristic) {
  vector<string> table;
  table.push_back("aswsskd");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("sis");
  words.push_back("wih");
  words.push_back("di");
  words.push_back("kads");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN, GREEN},
      {HIDDEN, RED, YELLOW, HIDDEN, HIDDEN, BLUE, HIDDEN},
      {RED, HIDDEN, HIDDEN, YELLOW, HIDDEN, BLUE, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}

TEST(Matcher_Test, Matcher_Match_Test_SW_Heuristic) {
  vector<string> table;
  table.push_back("aswsskd");
  table.push_back("aiiaaia");
  table.push_back("hnadtdm");

  vector<string> words;
  words.push_back("sis");
  words.push_back("wih");
  words.push_back("di");
  words.push_back("kads");

  StringMatcher* matcher = new StringMatcher(table);
  for (string str : words) {
    matcher->match(str, true);
  }

  vector<vector<Color>> colorResult = matcher->getColorizedResult();
  Color resultMatrix[3][7] = {
      {HIDDEN, HIDDEN, RED, HIDDEN, HIDDEN, HIDDEN, GREEN},
      {HIDDEN, RED, YELLOW, HIDDEN, HIDDEN, BLUE, HIDDEN},
      {RED, HIDDEN, HIDDEN, YELLOW, HIDDEN, BLUE, HIDDEN},
  };

  vector<vector<Color>> resultMap;
  for (int i = 0; i < 3; i++) {
    resultMap.push_back(vector<Color>());

    for (int j = 0; j < 7; j++) {
      resultMap[i].push_back(resultMatrix[i][j]);
    }
  }

  ASSERT_EQ(resultMap, colorResult);
}
