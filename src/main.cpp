#include <iostream>

#include "lib/Matcher.hpp"
#include "lib/io/Console.hpp"
#include "lib/io/File.hpp"
using namespace std;
using namespace FileManagement;

int main() {
  Console::printHeader();
  cout << endl;

  string filename;
  cout << "Insert file path : ";
  getline(cin, filename);

  FileReader reader(filename);
  reader.parse();

  vector<string> table = reader.getTable();
  vector<string> patterns = reader.getPatterns();

  Matcher::StringMatcher matcher(table);

  for (string i : patterns) {
    matcher.match(i);
  }

  Console::printTable(table, matcher.getColorizedResult());

  return 0;
}