//
// Created by shay on 12/16/18.
//

#include "Lexer.h"

Lexer::Lexer() {};

vector<string>* Lexer::lexer(string line) {
    line = separateSpaces(line);
    line = removeSpaces(line);
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

string Lexer::removeSpaces(string line) {
    string newLine = string();
    bool wasSpace = false;
    for (int i = 0; i < line.length(); i++) {
        if (!(line[i] == ' ' && wasSpace)) {
            newLine += line[i];
        }
        if (line[i] == ' ') {
            wasSpace = true;
        } else {
            wasSpace = false;
        }
    }
    return newLine;
}
//This is a comment
string Lexer::separateSpaces(string line) {
    unordered_set<char> operators = {'+', '-', '/', '*', '(', ')', '=',':'};
    int i = 0;
    bool inserted = false;
    bool isNum = false;
    bool isQuotation = false;
    while (i < line.length()) {
        if (line[i] == '"') {
            if (!isQuotation) {
                isQuotation = true;
                if (i > 0) {
                    line.insert(i, " ");
                    i++;
                }
            } else {
                isQuotation = false;
                if (i < line.length() - 1) {
                    line.insert(i + 1, " ");
                }
            }
        }
        if (!isQuotation) {
        if (line[i] >= '0' && line[i] <= '9') {
            isNum = true;
        } else {
            if (line[i] != ' ' && line[i] != '-') {
                isNum = false;
            }
        }
        if (operators.find(line[i]) != operators.end()) {
            if (i < line.length() - 1 && line[i + 1] != ' ') {
                if (!(line[i] == '-' && !isNum && (line[i + 1] >= '0' && line[i + 1] <= '9'))) {
                    line.insert(i + 1, " ");
                }
            }
            if (i > 0 && line[i - 1] != ' ') {
                line.insert(i, " ");
                inserted = true;
            }
        }
        if (inserted) {
            i++;
            inserted = false;
        }
    }
        i++;
    }
    return line;
}
