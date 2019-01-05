//
// Created by shay on 12/16/18.
//

#include "Lexer.h"

Lexer::Lexer() {};

vector<string>* Lexer::lexer(string line) {
    bool isQuotation = false;
    line = separateSpaces(line);
    line = removeRepeatingSpaces(line);
    vector<string>* commands = new vector<string>();
    string command = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '"') {
            isQuotation ? isQuotation = false : isQuotation = true;
        }
        if (line[i] == ' ' || line[i] == '\t') {
            if (!isQuotation) {
                commands->push_back(command);
                command = "";
            }
            else {
                command += line[i];
            }
        } else {
            command += line[i];
        }
    }
    commands->push_back(command);
    command = "";
    return commands;
}

string Lexer::removeRepeatingSpaces(string line) {
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

string Lexer::separateSpaces(string line) {
    unordered_set<char> operators = {'+', '-', '/', '*', '(', ')', '=', ':', ',', '>','<'};
    int i = 0;
    bool inserted = false;
    bool isNumOrVal = false;
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
        if (isDigitOrLetter(line[i])) {
            isNumOrVal = true;
        } else {
            if (line[i] != ' ' && line[i] != '-') {
                isNumOrVal = false;
            }
        }
        if (operators.find(line[i]) != operators.end()) {
            if (i < line.length() - 1 && line[i + 1] != ' ') {
                if (!(line[i] == '-' && !isNumOrVal && isDigitOrLetter(line[i + 1]))) {
                    if (!(((line[i] == '<' || line[i] == '>') && line[i + 1] == '=') || (line[i] == '=' && line[i + 1] == '='))) {
                        line.insert(i + 1, " ");
                    }
                }
            }
            if (i > 0 && line[i - 1] != ' ') {
                if (!(((line[i - 1] == '<' || line[i - 1] == '>') && line[i] == '=') || (line[i - 1] == '=' && line[i] == '='))) {
                line.insert(i, " ");
                inserted = true;
            }
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

bool Lexer::isDigitOrLetter(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
