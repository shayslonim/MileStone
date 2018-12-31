#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Maps.h"
#include "Command/OpenDataServerCommand.h"
#include "Command/IfCommand.h"
#include <unordered_set>
#include <thread>
#include <fstream>

static void printVector(vector<string> array);

int main(int argc, char* argv[]) {
    Maps maps = Maps();
    Lexer lexer;
    Parser parser = Parser(&maps);
    //THIS IS A COMMENT I MADE SO I CAN PUSH THE FILE - HI SHIRA DID YOU GET IT? ;P
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
    //vector<string>::iterator iter = lines.begin();
    vector<vector<string>> lexerLines;
    for (int i = 0; i< lines.size(); i++) {
        lexerLines.push_back(*lexer.lexer(lines[i]));
    }
    parser.parse(lexerLines);
    //OpenDataServerCommand odsc = OpenDataServerCommand(5400, 10, new Maps());
    //ConditionCommand* command = new IfCommand(std::vector<std::string>());

}

static void printVector(vector<string> array) {
    for (string &s:array) {
        std::cout << s + " ";
    }
    cout << endl;
}