#include "expression.hpp"
#include <iostream>

using namespace std;

Visitor::~Visitor() {}

void PrintVisitor::visitNumber(Number *num) { cout << num->getValue(); }
void PrintVisitor::visitBinaryOperation(BinaryOperation *bop) {
    cout << "(";
    bop->getLeft()->visit(this);
    cout << " ";
    cout << bop->getOp();
    cout << " ";
    bop->getRight()->visit(this);
    cout << ")";
}

ostream &operator<<(ostream &os, Expression const &p) { return os; }
