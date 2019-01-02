#include <iostream>
#include "Expression/ExpressionTest.h"
#include "Lexer.h"
#include "Parser.h"
#include "Maps.h"
#include "Command/OpenDataServerCommand.h"
#include "Command/IfCommand.h"
#include <unordered_set>
#include <fstream>

int main(int argc, char* argv[]) {
    Maps maps = Maps();
    Lexer lexer;
    Parser parser = Parser(&maps);
    ifstream inFile;
    string buffer;

    if (argc < 2) {
        throw  "file name not entered";
    }
    inFile.open(argv[1]);
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
    vector<string> lines;
    while (getline(inFile, buffer)) {
        lines.push_back(buffer);
    }
    //vector<string>::iterator iter = lines.begin();
    vector<vector<string>> lexerLines;
    for (int i = 0; i < lines.size(); i++) {
        lexerLines.push_back(*lexer.lexer(lines[i]));
    }
    parser.parse(lexerLines);
    //OpenDataServerCommand odsc = OpenDataServerCommand(5400, 10, new Maps());
    //ConditionCommand* command = new IfCommand(std::vector<std::string>());
    return 0;
}