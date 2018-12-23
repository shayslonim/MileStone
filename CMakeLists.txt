cmake_minimum_required(VERSION 3.12)
project(MileStone)

set(CMAKE_CXX_STANDARD 14)

add_executable(MileStone main.cpp Lexer.cpp Lexer.h Command/Command.h Parser.cpp Parser.h Expression/Expression.h Expression/NumExpression.cpp Expression/NumExpression.h Expression/MultiplyExpression.cpp Expression/MultiplyExpression.h Expression/DivideExpression.cpp Expression/DivideExpression.h Expression/BinaryExpression.cpp Expression/BinaryExpression.h Expression/PlusExpression.cpp Expression/PlusExpression.h Expression/MinusExpression.cpp Expression/MinusExpression.h Expression/ExpressionTest.cpp Expression/ExpressionTest.h InfixHandler.h InfixHandler.cpp Command/Print.cpp Command/Print.h Maps.cpp Maps.h Command/Bind.cpp Command/Bind.h Command/VarCommand.cpp Command/VarCommand.h Command/Equals.cpp Command/Equals.h)