#include <expression.h>

namespace qm
{
  Expression::Expression(const std::string &l, const std::string &r, Expression *p, Operator op)
  {
    leftText = l;
    rightText = r;
    parent = p;
    operation = op;
  }
  Expression::Expression(Expression *l, const std::string &r, Expression *p, Operator op)
  {
    left = l;
    rightText = r;
    parent = p;
    operation = op;
  }
  Expression::Expression(const std::string &l, Expression *r, Expression *p, Operator op)
  {
    leftText = l;
    right = r;
    parent = p;
    operation = op;
  }
  Expression::Expression(const std::string &l, const std::string &r, Operator op)
  {
    leftText = l;
    rightText = r;
    parent = nullptr;
    operation = op;
  }
  Expression::Expression(Expression *l, const std::string &r, Operator op)
  {
    left = l;
    rightText = r;
    parent = nullptr;
    operation = op;
  }
  Expression::Expression(const std::string &l, Expression *r, Operator op)
  {
    leftText = l;
    right = r;
    parent = nullptr;
    operation = op;
  }
  Expression::Expression(Expression *exp)
  {
    // leftText = exp.leftText ? new std::string(*exp.leftText) : nullptr;
    // rightText = exp.rightText ? new std::string(*exp.rightText) : nullptr;

    Expression *temp = exp;
    Expression *root = new Expression(nullptr, nullptr, exp->operation);

    while (temp != nullptr)
    {
      if (temp->left != nullptr && root->left == nullptr)
      {
        root->left = new Expression(temp->left->leftText, temp->left->rightText,
                                    root, temp->left->operation);
        temp = temp->left;
        root = root->left;
      }
      else if (temp->right != nullptr && root->right == nullptr)
      {
        root->right = new Expression(temp->right->leftText, temp->right->rightText,
                                    root, temp->right->operation);
        temp = temp->right;
        root = root->right;
      }
      else
      {
        temp = temp->parent;
        root = root->parent ? root->parent : root;
      }

    }
    
    leftText = root->leftText;
    rightText = root->rightText;
    left = root->left;
    right = root->right;
    parent = nullptr;
    operation = root->operation;

    root->left = nullptr;
    root->right = nullptr;

    delete root;
  }
  Expression::~Expression()
  {
    delete left;
    delete right;
  }
} // namespace qm