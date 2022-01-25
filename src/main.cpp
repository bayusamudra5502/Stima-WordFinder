#include <ctime>
#include <iostream>

#include "lib/Matcher.hpp"
#include "lib/io/Console.hpp"
#include "lib/io/File.hpp"
using namespace std;
using namespace FileManagement;

int main(int argc, char* argv[]) {
  Console::printHeader();
  cout << endl;

  string filename;
  if (argc > 1) {
    filename = argv[1];
    cout << "Membaca file " << filename << endl << endl;
  } else {
    cout << "Insert file path : ";
    getline(cin, filename);
  }

  FileReader reader(filename);
  reader.parse();

  clock_t timeStart = clock();

  vector<string> table = reader.getTable();
  vector<string> patterns = reader.getPatterns();

  Matcher::StringMatcher matcher(table);

  for (string i : patterns) {
    matcher.match(i);
  }

  clock_t timeStop = clock();

  Console::printTable(table, matcher.getColorizedResult());

  cout << "Waktu Eksekusi : "
       << (1000.0 * (timeStop - timeStart)) / CLOCKS_PER_SEC << " ms" << endl
       << endl;

  return 0;
}