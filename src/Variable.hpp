//
// Created by Tobiasz Puslecki on 30/08/2021.
//

#pragma once

#include "LisaScript.hpp"

class Variable : public Expression
{
public:
    Variable(std::string n);
    virtual int eval(Memory& m);

private:
    std::string name;

};

class VariableNotFound { };