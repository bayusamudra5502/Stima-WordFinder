#include "File.hpp"

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "../Util.hpp"
using namespace std;

FileManagement::FileReader::FileReader(string filename) {
  this->filename = filename;
  this->parse();
}

bool isStringSpaceOnly(string str) {
  for (char c : str) {
    if (!isspace(c)) {
      return false;
    }
  }

  return true;
}

void FileManagement::FileReader::parse() {
  ifstream fileStream(this->filename);
  vector<string> tables;
  string line;

  while (getline(fileStream, line) && !isStringSpaceOnly(line)) {
    tables.push_back(line);
  }

  Util::trimVectorString(tables);
  this->charTable = tables;

  while (getline(fileStream, line)) {
    if (!isStringSpaceOnly(line)) this->patterns.push_back(line);
  }

  fileStream.close();
}

vector<string> FileManagement::FileReader::getTable() {
  return this->charTable;
}

vector<string> FileManagement::FileReader::getPatterns() {
  return this->patterns;
}

void FileManagement::writeTableToFile(ofstream filestream,
                                      vector<string> charTable,
                                      vector<vector<Color>> colorTable) {
  filestream << "# Tabel Hasil Pemrosesan" << endl << endl;

  if (charTable.size() == 0) {
    filestream << "--- Tabel Kosong ---" << endl;
    return;
  } else {
    filestream << "" << endl;
  }

  for (int i = 0; i < (int)charTable.size(); i++) {
    for (int j = 0; j < (int)charTable[0].length(); j++) {
      if (j > 0) {
        filestream << " ";
      }

      if (colorTable[i][j] == HIDDEN) {
        filestream << "-";
      } else {
        filestream << charTable[i][j];
      }
    }

    filestream << endl;
  }
}