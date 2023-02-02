#include "expression.hpp"

double Expression::evaluate() const { return 0.0; }
Expression::~Expression() {}

Number::Number(double value) : value(value) {}
double Number::getValue() { return this->value; }
double Number::evaluate() const { return this->value; }
void Number::visit(Visitor *visitor) { visitor->visitNumber(this); }

BinaryOperation::BinaryOperation(Expression *const left, char op,
                                 Expression *const right)
    : left(left), op(op), right(right) {}
BinaryOperation::~BinaryOperation() {
    delete this->left;
    this->left = 0;
    delete this->right;
    this->right = 0;
}
double BinaryOperation::evaluate() const {
    switch (this->op) {
    case '+':
        return this->left->evaluate() + this->right->evaluate();
        break;
    case '-':
        return this->left->evaluate() - this->right->evaluate();
        break;
    case '*':
        return this->left->evaluate() * this->right->evaluate();
        break;
    case '/':
        return this->left->evaluate() / this->right->evaluate();
        break;
    default:
        return 0.0;
        break;
    }
}
void BinaryOperation::visit(Visitor *visitor) {
    visitor->visitBinaryOperation(this);
}
Expression *const BinaryOperation::getLeft() { return this->left; }
Expression *const BinaryOperation::getRight() { return this->right; }
char BinaryOperation::getOp() { return this->op; }
