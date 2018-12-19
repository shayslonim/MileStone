cmake_minimum_required(VERSION 3.12)
project(MileStone)

set(CMAKE_CXX_STANDARD 14)

add_executable(MileStone main.cpp Lexer.cpp Lexer.h Command.cpp Command.h Parser.cpp Parser.h Expression/Expression.h Expression/NumExpression.cpp Expression/NumExpression.h Expression/Multiply.cpp Expression/Multiply.h Expression/Divide.cpp Expression/Divide.h Expression/BinaryExpression.cpp Expression/BinaryExpression.h Expression/Plus.cpp Expression/Plus.h Expression/Minus.cpp Expression/Minus.h Expression/ExpressionTest.cpp Expression/ExpressionTest.h)