#pragma once
#include "visitor.hpp"

class Expression {
  public:
    virtual double evaluate() const;
    virtual void visit(Visitor *visitor) = 0;
    virtual ~Expression();
};

class Number : public Expression {
  public:
    Number(double value);
    double getValue();
    double evaluate() const;
    void visit(Visitor *visitor);

  private:
    double value;
};

class BinaryOperation : public Expression {
  public:
    BinaryOperation(Expression *const left, char op, Expression *const right);
    ~BinaryOperation();
    double evaluate() const;
    void visit(Visitor *visitor);
    Expression *const getLeft();
    Expression *const getRight();
    char getOp();

  private:
    Expression *left;
    char op;
    Expression *right;
};
