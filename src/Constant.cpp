//
// Created by Tobiasz Puslecki on 29/08/2021.
//

#include "Constant.hpp"

Constant::Constant(int v) : value(v) {}

int Constant::eval(Memory& m)
{
    return value;
}