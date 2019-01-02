//
// Created by shira on 12/20/18.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand(vector<string> &line, Maps* maps) {
    this->line = line;
    this->maps = maps;
}

// The first string should be "print", and thr second one - what to print
void PrintCommand::execute(/*vector<string>::iterator*/) {
    // The second string is a quote: "print this"
    if (this->line[INDEX_PRINT][0] == '"' && this->line[INDEX_PRINT][this->line[INDEX_PRINT].length() - 1] == '"') {
        string printThis = string();
        for (int i = INDEX_PRINT; i < line.size(); i++) {
            printThis += line[i];
        }
        //cout << line[INDEX_PRINT].substr(START, line[INDEX_PRINT].length() - END) << endl;
        cout << printThis << endl;
    }
    // The second string represents a variable
    else {
        try {
            cout << this->maps->getValbyVar(this->line[INDEX_PRINT]) << endl;
        }
        catch (exception ex) {
            cout << this->maps->getValbyPath(this->line[INDEX_PRINT]) << endl;
        }
    }
}