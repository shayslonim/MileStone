#include <iostream>
//<<<<<<< HEAD
#include "Expression/ExpressionTest.h"
//=======
#include "Lexer.h"
#include "Parser.h"
#include "Maps.h"
#include "Command/OpenDataServerCommand.h"
#include "Command/IfCommand.h"
//>>>>>>> origin/master
#include <unordered_set>
#include <fstream>

//
//
//int main() {
//    std::string line = "yay+divide/ love () wow + + ++";
//    std::cout << "before: " << line << std::endl;
//    //ExpressionTest::doTest();
//    std::unordered_set<char> operators = {'+', '-', '/', '*', '(', ')', '='};
//    int i = 0;
//    bool inserted = false;
//    while (i < line.length()) {
//        if (operators.find(line[i]) != operators.end()) {
//            if (i < line.length() - 1 && line[i + 1] != ' ') {
//                line.insert(i + 1, " ");
//            }
//            if (i > 0 && line[i - 1] != ' ') {
//                line.insert(i, " ");
//                inserted = true;
//            }
//
//<<<<<<< HEAD
//            if (inserted) {
//                i++;
//            }
//            i++;
//
//        }
//    }
//    std::cout << "after: " << line << std::endl;
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