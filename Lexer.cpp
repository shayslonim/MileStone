//
// Created by shay on 12/16/18.
//

#include <iostream>
#include "Lexer.h"
#include <vector>
#include <string>
#include <list>
#include <set>
#include <unordered_set>

using namespace std;

std::vector<std::string>* Lexer::lexer(string line) {
    vector<string>* commands = new vector<string>();
    string command = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ' || line[i] == '\t') {
            commands->push_back(command);
            command = "";
        } else {
            command += line[i];
        }
    }
    return commands;
}
//This is a comment
string Lexer::separateSpaces(string line) {
    unordered_set<char> operators = {'+', '-', '/', '*', '(', ')', '='};
    int i = 0;
    bool inserted = false;
    while (i < line.length()) {
        if (operators.find(line[i]) != operators.end()) {
            if (i < line.length() - 1 && line[i + 1] != ' ') {
                line.insert(i + 1, " ");
            }

            if (i > 0 && line[i - 1] != ' ') {
                line.insert(i, " ");
                inserted = true;
            }

            i++;
            if (inserted) {
                i++;
            }
        }
    }
}
