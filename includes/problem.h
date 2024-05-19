#pragma once
#include <expression.h>
#include <unordered_map>

namespace qm
{
  enum class ProblemType
  {
    Arithmetic,
    Area,
    Volume,
    Sum,
    Factor,
  };

  class Problem
  {
    std::string *m_problem;
    Expression *m_expression;

    ProblemType m_type;

    std::unordered_map<std::string, std::string> *m_known_vars;

  public:
    Problem(std::string *prob, Expression *exp, ProblemType t,
            std::unordered_map<std::string, std::string> *vars)
        : m_problem(prob), m_expression(exp), m_type(t), m_known_vars(vars) {}

    Problem(std::string *prob, Expression *exp, ProblemType t)
        : m_problem(prob), m_expression(exp), m_type(t)
    {
      m_known_vars = nullptr;
    }

    Problem(const Problem &p);

    ~Problem();
  };
} // namespace qm
