#pragma once

class Number;
class BinaryOperation;

class Visitor {
  public:
    virtual void visitNumber(Number *const num) = 0;
    virtual void visitBinaryOperation(BinaryOperation *const bop) = 0;
    virtual ~Visitor();
};

class PrintVisitor : public Visitor {
  public:
    virtual void visitNumber(Number *const num);
    virtual void visitBinaryOperation(BinaryOperation *const bop);
};
