#include <iostream>
#include "Expression/ExpressionTest.h"
#include <unordered_set>

int main() {
    std::string line = "yay+divide/ love () wow + + ++";
    std::cout << "before: " << line << std::endl;
    //ExpressionTest::doTest();
    std::unordered_set<char> operators = {'+', '-', '/', '*', '(', ')', '='};
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

            if (inserted) {
                i++;
            }
            i++;

        }
    }
    std::cout << "after: " << line << std::endl;

    return 0;

}