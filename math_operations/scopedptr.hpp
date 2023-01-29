#pragma once
#include "expression.hpp"

class ScopedPtr {
  public:
    explicit ScopedPtr(Expression *ptr = 0);
    ~ScopedPtr();
    Expression *get() const;
    Expression *release();
    void reset(Expression *ptr = 0);
    Expression &operator*() const;
    Expression *operator->() const;

  private:
    ScopedPtr(ScopedPtr const &);
    ScopedPtr &operator=(ScopedPtr const &);
    Expression *_ptr;
};
