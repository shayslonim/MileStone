#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include <unordered_set>
#include <thread>
#include <fstream>

static void printVector(vector<string> array);

int main(int argc, char* argv[]) {
    ifstream inFile;
    string buffer;
    inFile.open(argv[0]);
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    vector<string> lines;
    while (getline(inFile, buffer)) {
        lines.push_back(buffer);
    }
    vector<string>::iterator iter = lines.begin();

    //todo: call parser with the iterator
    return 0;

}

static void printVector(vector<string> array) {
    for (string &s:array) {
        std::cout << s + " ";
    }
    cout << endl;
}