//
// Created by shira on 12/20/18.
//

#include "PrintCommand.h"

/**
 * Constructor
 * @param line vector<string> pointer
 * @param maps Mpas*
 */
PrintCommand::PrintCommand(vector<string> &line, Maps* maps) {
    this->line = line;
    this->maps = maps;
}

// The first string should be "print", and thr second one - what to print
/**
 * Do the printing
 */
void PrintCommand::execute(/*vector<string>::iterator*/) {
    // The string is a quote: "print this"
    ExpressionFactory factory = ExpressionFactory(this->maps);
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
            vector<string> expressionVector = vector<string>();
            while (i < this->line.size() && (!(this->line[i][0] == '"' &&
                     this->line[i][this->line[i].length() - END] == '"'))) {
                expressionVector.push_back(this->line[i]);
                i++;
            }
            i--;
            cout << factory.getExpressionFromUnorderedLine(expressionVector, 0, expressionVector.size() - 1)->calculate();
//            try {
//                cout << this->maps->getValbyVar(this->line[i]);
//            }
//            catch (exception ex) {
//                cout << this->maps->getValbyPath(this->line[i]);
//            }
        }
    }
    cout << endl;
}