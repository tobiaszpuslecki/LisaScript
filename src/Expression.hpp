//
// Created by Tobiasz Puslecki on 29/08/2021.
//
#pragma once

#include "LisaScript.hpp"

typedef std::map<std::string, int> Memory;

class Expression
{
public:
    virtual ~Expression() {}
    virtual int eval(Memory& m) = 0;
};