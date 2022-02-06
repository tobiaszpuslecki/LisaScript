//
// Created by Tobiasz Puslecki on 29/08/2021.
//

#include "Variable.hpp"

Variable::Variable(std::string n) : name(n) { }

int Variable::eval(Memory& m)
{
     Memory::iterator it = m.find(name);
        if (it == m.end()) // Nie ma zmiennej w pamięci
            throw VariableNotFound();
        return it->second;

}

