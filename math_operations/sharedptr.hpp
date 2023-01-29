#pragma once
#include "expression.hpp"

class SharedPtr {
  public:
    explicit SharedPtr(Expression *ptr = 0);
    ~SharedPtr();
    SharedPtr(const SharedPtr &);
    SharedPtr &operator=(const SharedPtr &);
    Expression *get() const;
    void reset(Expression *ptr = 0);
    Expression &operator*() const;
    Expression *operator->() const;

  private:
    Expression *_ptr;
    int *_refCounter;
};
