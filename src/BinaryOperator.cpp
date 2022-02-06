//
// Created by Tobiasz Puslecki on 29/08/2021.
//

#include "BinaryOperator.hpp"

BinaryOperator::BinaryOperator(char s, Expression* l, Expression* r)
        : symbol(s), left(l), right(r) {}

int BinaryOperator::eval(Memory& m)
{
    switch (symbol)
    {
        case '*': return left->eval(m) * right->eval(m);
        case '+': return left->eval(m) + right->eval(m);
        case '-': return left->eval(m) - right->eval(m);
            // ... inne operatory
    }
}

BinaryOperator::~BinaryOperator()
{
    delete left;
    delete right;
}