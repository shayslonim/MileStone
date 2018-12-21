#include <iostream>
#include "Expression/ExpressionTest.h"
#include "Lexer.h"
#include <unordered_set>
#include "InfixHandler.h"

static void printVector(vector<string> array);
int main() {
//    //var x = -3
//    string line = string() + "yay" + '"' + "+divide/ love" + '"' + "() wow + + 3+";
//    //string line = "3+";
//    cout << "before: " << line << std::endl;
//    //ExpressionTest::doTest();
//    cout << "after: " << Lexer::separateSpaces(line) << std::endl;


    InfixHandler converter;
    vector<string> result = converter.convertToPrefix({"5", "+", "5"});
    printVector(result);
    return 0;

}

static void printVector(vector<string> array) {
    for (string &s:array) {
        std::cout << s +" ";
    }
    cout << endl;
}