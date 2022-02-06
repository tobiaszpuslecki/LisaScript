#pragma once

#include "LisaScript.hpp"

class BinaryOperator : public Expression
{
public:
    BinaryOperator(char s, Expression* l, Expression* r);
    virtual ~BinaryOperator();
    virtual int eval(Memory& m);

private:
    char symbol;
    Expression *left, *right;
};
