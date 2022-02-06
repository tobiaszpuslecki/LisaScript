//
// Created by Tobiasz Puslecki on 30/08/2021.
//

#include "Parser.hpp"

const char EOS = '\0';

Parser::Parser(std::string input) : input(input), position(0)
{
    input.push_back(EOS);
}

void Parser::skipWhitespace()
{
    while (isspace(input[position]))
        position++;
}

char Parser::lookAhead()
{
    skipWhitespace();
    return input[position];
}

Expression* Parser::parseExpression()
{
    Expression* e = parseSum();
    if (lookAhead() == EOS)
        return e;
    else
    {
        delete e;
        throw NotParsed();
    }
}

Expression* Parser::parseSum()
{
    Expression* e = nullptr;

    try
    {
        e = parseMult();
        char c = lookAhead();

        while(c == '+' || c == '-')
        {
            position++;
            e = new BinaryOperator(c, e, parseMult());
            c = lookAhead();
        }
    }
    catch (NotParsed)
    {
        delete e;
        throw NotParsed();
    }

    return e;
}

Expression* Parser::parseMult()
{
    Expression* e = nullptr;

    try
    {
        e = parseTerm();
        char c = lookAhead();

        while(c == '*' || c == '/' || c == '%')
        {
            position++;
            e = new BinaryOperator(c, e, parseTerm());
            c = lookAhead();
        }
    }
    catch (NotParsed)
    {
        delete e;
        throw NotParsed();
    }

    return e;
}
Expression* Parser::parseTerm()
{
    char c = lookAhead();
    if (isdigit(c))
        return parseConstant();
    else if (isalpha(c))
        return parseVariable();
    else if (c == '(')
        return parseParen();
    else
        throw NotParsed();
}

Expression* Parser::parseConstant()
{
    int n = 0;
    while (isdigit(input[position]))
    {
        n *= 10;
        n += input[position] - '0';
        position++;
    }
    return new Constant(n);
}


Expression* Parser::parseVariable()
{
    std::string s;
    while (isalnum(input[position]))
    {
        s.push_back(input[position]);
        position++;
    }
    return new Variable(s);
}

Expression* Parser::parseParen()
{
    position++; // parse_term zapewnia, że wskaźnik
    // stoi na nawiasie otwierającym '('
    Expression* e = parseSum();
    if (lookAhead() == ')')
    {
        position++;
        return e;
    }
    else
    {
        delete e;
        throw NotParsed();
    }
}

