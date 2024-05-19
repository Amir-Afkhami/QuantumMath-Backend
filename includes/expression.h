#pragma once

#include <operator.h>
#include <string>

namespace qm
{
    struct Expression
    {
        std::string leftText;
        std::string rightText;

        Expression *left;
        Expression *right;
        Expression *parent;
        Operator operation;

        Expression(Expression *l, Expression *r, Expression *p, Operator op) : left(left), right(right), parent(p), operation(op) {}

        Expression(const std::string &l, const std::string &r, Expression *p, Operator op);

        Expression(Expression *l, const std::string &r, Expression *p, Operator op);

        Expression(const std::string &l, Expression *r, Expression *p, Operator op);

        Expression(Expression *l, Expression *r, Operator op) : left(left), right(right), operation(op) {}

        Expression(const std::string &l, const std::string &r, Operator op);

        Expression(Expression *l, const std::string &r, Operator op);

        Expression(const std::string &l, Expression *r, Operator op);

        Expression(Expression *exp);

        ~Expression();
    };
} // namespace qm
