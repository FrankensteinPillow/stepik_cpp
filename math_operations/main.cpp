#include "expression.hpp"
#include "scopedptr.hpp"
#include "sharedptr.hpp"
#include "visitor.hpp"
#include <iostream>

using namespace std;

int main() {
    Number *n1 = new Number(2.4);
    Number *n2 = new Number(5.3);
    Number *n3 = new Number(9.2);
    PrintVisitor *visitor = new PrintVisitor();

    Expression *exp = new BinaryOperation(n1, '+', n2);
    cout << exp->evaluate() << endl;

    Expression *exp1 = new BinaryOperation(n3, '*', exp);
    cout << exp1->evaluate() << endl;

    Expression *exp2 = new BinaryOperation(exp1, '-', new Number(10));
    cout << exp2->evaluate() << endl;

    // using simple smart pointer here that bound with stack
    ScopedPtr sptr(new BinaryOperation(new Number(123.114), '/', exp2));
    sptr->visit(visitor);
    cout << " = " << sptr->evaluate() << endl;
    Number *n11 = new Number(666.98);
    Number *n12 = new Number(88.7);
    // try to using shared smart pointer here
    SharedPtr e1(new BinaryOperation(n11, '/', n12));
    e1->visit(visitor);
    cout << " = " << e1->evaluate() << endl;
    SharedPtr e3 = e1;
    SharedPtr e5(exp);
    return 0;
}
