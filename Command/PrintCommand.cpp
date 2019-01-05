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
    // The string is a quote: "print this"
    for (int i = INDEX_PRINT; i < this->line.size(); i++) {
        if (this->line[i][0] == '"' &&
            this->line[i][this->line[i].length() - END] == '"') {
            string printThis = string();
            for (int j = START; j < line[i].length() - END; j++) {
                printThis += line[i][j];
            }
            //cout << line[INDEX_PRINT].substr(START, line[INDEX_PRINT].length() - END) << endl;
            cout << printThis;
        }
        // The string represents a variable
        else {
            try {
                cout << this->maps->getValbyVar(this->line[i]);
            }
            catch (exception ex) {
                cout << this->maps->getValbyPath(this->line[i]);
            }
        }
    }
    cout << endl;
}