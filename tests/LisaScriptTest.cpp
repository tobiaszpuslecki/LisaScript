//
// Created by Tobiasz Puslecki on 30/08/2021.
//

#include <gtest/gtest.h>

#include "LisaScript.hpp"

TEST(ExpressionTree, shouldCalculateSimpleExpression)
{
    Memory m;
    Expression* f = new BinaryOperator('+', new Constant(2),
        new BinaryOperator('*',
       new BinaryOperator('+', new Constant(1), new Constant(7)),
      new BinaryOperator('*', new Constant(4), new Constant(5))));

    ASSERT_EQ(f->eval(m), 162);
}

TEST(ExpressionTree, shouldCalculateSimpleExpressionWithVariables)
{
    Memory m;
    m["x"] = 10;
    m["y"] = 5;
    Expression *e = new BinaryOperator('+',
                new BinaryOperator('*', new Constant(2), new Variable("x")),
                new Variable("y"));

    ASSERT_EQ(e->eval(m), 25);
}

TEST(Parser, shouldParseSimpleExpression)
{
    std::string input = "2 + (1 + 7) * (4 * 5)";

        Parser parser(input);
        Expression* e = parser.parseExpression();

        Memory m;

        ASSERT_EQ(e->eval(m), 162);
}

TEST(Parser, shouldParseSimpleExpressionWithVariables)
{
    Memory m;
    m["x"] = 10;
    m["y"] = 5;

    std::string input = "2 * x + y";

    Parser parser(input);
    Expression* e = parser.parseExpression();



    ASSERT_EQ(e->eval(m), 25);
}

TEST(Parser, shouldThrowVariableNotFound)
{
    Memory m;

    std::string input = "2 * x";

    Parser parser(input);
    Expression* e = parser.parseExpression();

    EXPECT_THROW(e->eval(m), VariableNotFound);
}

//TEST(Parser, shouldThrowNotParsed)
//{
//    Memory m;
//
//    std::string input = "2 @ x";
//
//    Parser parser(input);
//    Expression* e = parser.parseExpression();
//
//    EXPECT_THROW(e->eval(m), NotParsed);
//}