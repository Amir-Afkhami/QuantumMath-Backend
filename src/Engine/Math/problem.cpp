#include "problem.h"

qm::Problem::Problem(const Problem &p)
{
  std::string* problem = new std::string(*p.problem);

}

qm::Problem::~Problem()
{
}
