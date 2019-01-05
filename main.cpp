#include <iostream>
#include "Expression/ExpressionTest.h"
#include "Lexer.h"
#include "Parser.h"
#include "Maps.h"
#include "Command/OpenDataServerCommand.h"
#include "Command/IfCommand.h"
#include <unordered_set>
#include <algorithm>
#include <fstream>

int main(int argc, char* argv[]) {
    Maps maps = Maps();
    Lexer lexer;
    Parser parser = Parser(&maps);
    ifstream inFile;
    string buffer;

    if (argc < 2) {
        cerr << "file name not entered";

    }
    inFile.open(argv[1]);
    if (!inFile) {
        cerr << "Unable to open file: " << argv[1];
        exit(1);   // call system to stop
    }
    vector<string> lines;
    while (getline(inFile, buffer)) {
        lines.push_back(buffer);
    }
    //vector<string>::iterator iter = lines.begin();
    vector<vector<string>> lexerLines;
    for (int i = 0; i < lines.size(); i++) {
        auto line = *lexer.lexer(lines[i]);
        vector<string> result;
        std::copy_if(line.begin(), line.end(), back_inserter(result), [](string s) { return !s.empty(); });
        lexerLines.push_back(result);
    }
//    //~~~~~~~~~~~~~~~~~~~~``
//    //print lexed lines
//    for (int j = 0; j < lexerLines.size(); j++) {
//        for (int i = 0; i < lexerLines[j].size(); ++i) {
//            cout << lexerLines[j][i] << " ";
//        }
//        cout << endl;
//    }
//    //~~~~~~~~~~~~~~~~~~~
    parser.parse(lexerLines);
    //OpenDataServerCommand odsc = OpenDataServerCommand(5400, 10, new Maps());
    //ConditionCommand* command = new IfCommand(std::vector<std::string>());
    return 0;
}