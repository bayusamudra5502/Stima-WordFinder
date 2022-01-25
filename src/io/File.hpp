#pragma once
#include <string>

#include "../lib/types.hpp"
using namespace std;

namespace FileReader {
class FileReader {
 private:
  string filename;
  vector<vector<string>> charTable;
  vector<string> keywords;

  void fileParser();

 public:
  FileReader(string filename);
  vector<vector<string>> getTable();
  vector<string> getKeywords();
}
}  // namespace FileReader

namespace FileWritter {
void writeResToFile(string filename, vector<vector<string>> charTable,
                    vector<vector<Color>> colorTable);
}  // namespace FileWritter