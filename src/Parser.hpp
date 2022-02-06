//
// Created by Tobiasz Puslecki on 30/08/2021.
//

#pragma once

#include <iostream>

#include "LisaScript.hpp"

class Parser
{
    std::string input;    // analizowany tekst
    size_t position; // wskaźnik na aktualnie "oglądany" znak

public:

    explicit Parser(std::string input);

    // Pomija wszystkie białe znaki i przesuwa wskaźnik
    // na pierwszy znak, który nie jest biały.
    void skipWhitespace();

    // Pomija białe znaki i informuje jaki znak "oglądamy".
    char lookAhead();

    Expression* parseExpression(); // Parsuje wyrażanie.
    Expression* parseSum();        // Parsuje "sumę".
    Expression* parseMult();       // Parsuje składnik.
    Expression* parseTerm();       // Parsuje czynnik.
    Expression* parseConstant();   // Parsuje liczbę.
    Expression* parseVariable();   // Parsuje nazwę zmiennej.
    Expression* parseParen();      // Parsuje "sumę" w nawiasie.
};

class NotParsed : public std::exception { };
