cmake_minimum_required(VERSION 3.12)
project(MileStone)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(MileStone main.cpp Lexer.cpp Lexer.h Command/Command.h Parser.cpp Parser.h  Expression/VarExpression.cpp
        Expression/VarExpression.h ExpressionFactory.cpp ExpressionFactory.h Expression/Expression.h
        Expression/NumExpression.cpp Expression/NumExpression.h Expression/MultiplyExpression.cpp
        Expression/MultiplyExpression.h Expression/DivideExpression.cpp
        Expression/DivideExpression.h Expression/BinaryExpression.cpp Expression/BinaryExpression.h
        Expression/PlusExpression.cpp Expression/PlusExpression.h Expression/MinusExpression.cpp
        Expression/MinusExpression.h Expression/ExpressionTest.cpp Expression/ExpressionTest.h InfixHandler.h
        InfixHandler.cpp Command/PrintCommand.cpp Command/PrintCommand.h Maps.cpp Maps.h Command/BindCommand.cpp
        Command/BindCommand.h Command/VarCommand.cpp Command/VarCommand.h Command/EqualsCommand.cpp
        Command/EqualsCommand.h Command/ConnectCommand.h Command/ConnectCommand.cpp Command/IfCommand.h
        Command/IfCommand.cpp Command/OpenDataServerCommand.h Command/OpenDataServerCommand.cpp Command/WhileCommand.h
        Command/WhileCommand.cpp Command/PrintCommand.cpp ServerReaderArguments.h ServerReaderArguments.cpp
        Expression/BiggerExpression.h Expression/BiggerExpression.cpp Expression/BiggerEqualsExpression.h
        Expression/BiggerEqualsExpression.cpp Expression/SmallerEqualsExpression.h Expression/SmallerEqualsExpression.cpp
        Expression/SmallerExpression.h Expression/SmallerExpression.cpp Expression/EqualsExpression.h
        Expression/EqualsExpression.cpp Command/ServerReader.h Command/ServerReader.cpp
        )