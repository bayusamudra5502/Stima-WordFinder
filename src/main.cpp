#include <ctime>
#include <fstream>
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
  vector<vector<Color>> colorTable = matcher.getColorizedResult();

  Console::printTable(table, colorTable);

  cout << "Jumlah Perbandingan : " << matcher.getCharacterCheck() << endl;
  cout << "Waktu Eksekusi : "
       << (1000.0 * (timeStop - timeStart)) / CLOCKS_PER_SEC << " ms" << endl
       << endl;

  cout << "Apakah anda ingin menyimpan file hasil pemrosesan [Y/n] ? ";

  string ans;
  getline(cin, ans);

  if (tolower(ans[0]) == 'y') {
    cout << "Masukan path file : ";

    string path;
    getline(cin, path);
    ofstream filestream(path);

    filestream << "-- Hasil Pemrosesan --" << endl;

    writeTableToFile(filestream, table, colorTable);

    filestream << endl;
    filestream << "Jumlah Perbandingan : " << matcher.getCharacterCheck()
               << endl;
    filestream << "Waktu Eksekusi : "
               << (1000.0 * (timeStop - timeStart)) / CLOCKS_PER_SEC << " ms"
               << endl;

    filestream.close();

    cout << endl << "Berhasil menyimpan data" << endl;
    cout << endl;
  }

  return 0;
}