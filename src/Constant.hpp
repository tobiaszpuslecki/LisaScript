#pragma once

#include "LisaScript.hpp"

class Constant : public Expression
{
public:
    Constant(int v);
    virtual int eval(Memory& m);

private:
    int value;
};