#pragma once
#include <string>
#include <vector>

#include "../types.hpp"
using namespace std;

namespace FileManagement {
class FileReader {
 private:
  string filename;
  vector<string> charTable;
  vector<string> patterns;

 public:
  void parse();
  FileReader(string filename);
  FileReader(ifstream* filestream);
  vector<string> getTable();
  vector<string> getPatterns();
};

void writeTableToFile(ofstream filestream, vector<string> charTable,
                      vector<vector<Color>> colorTable);
}  // namespace FileManagement
