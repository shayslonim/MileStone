//
// Created by shay on 12/18/18.
//

#include <iostream>
#include "ExpressionTest.h"

using namespace std;

void ExpressionTest::doTest() {
    Expression* one = new NumExpression(1);
    Expression* two = new NumExpression(2);
    Expression* five = new NumExpression(5);
    int successCount = 0;
    int testsCount = 0;
    //------------------ test 1 -----------------
    testsCount++;
    Expression* ex1 = new PlusExpression(one, two);
    if (ex1->calculate() != 3) {
        cout << "Test 1 failed!\n";
    } else {
        successCount++;
    }

    //------------------ test 2 -----------------
    testsCount++;
    Expression* ex2 = new DivideExpression(five, two);
    if (ex2->calculate() != 2.5) {
        cout << "Test 2 failed!\n";
    } else {
        successCount++;

    }
    //------------------ test 3 -----------------
    // * + 5 2 / 2 - 100 99
    //(5 + 2) * (2 / (100 - 99))
    testsCount++;
    Expression* ex3 = new MultiplyExpression(new PlusExpression(five, two), new DivideExpression(two, new MinusExpression(new NumExpression(100), new NumExpression(99))));
    if (ex3->calculate() != 14) {
        cout << "Test 3 failed!\n";
    } else {
        successCount++;
    }
    //------------------ end -----------------
    cout << "passed " << successCount << "/" << testsCount <<"\n";

}
