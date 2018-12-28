#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Command/OpenDataServerCommand.h"
#include "Command/IfCommand.h"
#include <unordered_set>
#include <thread>
#include <fstream>

static void printVector(vector<string> array);

int main(int argc, char* argv[]) {

//    ifstream inFile;
//    string buffer;
//    inFile.open(argv[0]);
//    if (!inFile) {
//        cerr << "Unable to open file datafile.txt";
//        exit(1);   // call system to stop
//    }
//    vector<string> lines;
//    while (getline(inFile, buffer)) {
//        lines.push_back(buffer);
//    }
//    vector<string>::iterator iter = lines.begin();
//
//    //todo: call parser with the iterator
    //OpenDataServerCommand odsc = OpenDataServerCommand(5400, 10, new Maps());o
    //ConditionCommand* command = new IfCommand(std::vector<std::string>());
    vector<vector<string>>* iterable = new vector<vector<string>>();

    for (vector<vector<string>>::iterator it = iterable->begin(); it != iterable->end(); ++it) {

    }

}

static void printVector(vector<string> array) {
    for (string &s:array) {
        std::cout << s + " ";
    }
    cout << endl;
}