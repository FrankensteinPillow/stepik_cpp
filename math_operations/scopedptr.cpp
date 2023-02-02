#include "scopedptr.hpp"

ScopedPtr::ScopedPtr(Expression *ptr) { this->_ptr = ptr; }

ScopedPtr::~ScopedPtr() {
    delete this->_ptr;
    this->_ptr = 0;
}

Expression *ScopedPtr::get() const { return this->_ptr; }

Expression *ScopedPtr::release() {
    Expression *tmpPtr = this->_ptr;
    this->_ptr = 0;
    return tmpPtr;
}

void ScopedPtr::reset(Expression *ptr) {
    delete this->_ptr;
    this->_ptr = ptr;
}

Expression &ScopedPtr::operator*() const { return *this->_ptr; }

Expression *ScopedPtr::operator->() const { return this->_ptr; }
