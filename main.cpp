#include <iostream>
#include "Expression/ExpressionTest.h"
#include "Lexer.h"
#include <unordered_set>

int main() {
    //var x = -3
    string line = string() + "yay" + '"' + "+divide/ love" + '"' + "() wow + + 3+";
    //string line = "3+";
    cout << "before: " << line << std::endl;
    //ExpressionTest::doTest();
    cout << "after: " << Lexer::separateSpaces(line) << std::endl;
    return 0;

}