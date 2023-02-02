#include "sharedptr.hpp"

SharedPtr::SharedPtr(Expression *ptr) : _ptr(ptr) {
    if (ptr != 0) {
        this->_refCounter = new int(1);
    } else {
        this->_refCounter = 0;
    }
}

SharedPtr::SharedPtr(SharedPtr const &ptr) {
    if (ptr._ptr != 0) {
        this->_ptr = ptr._ptr;
        this->_refCounter = ptr._refCounter;
    }
    ++(*this->_refCounter);
}

SharedPtr::~SharedPtr() {
    if (this->_ptr != 0 && this->_refCounter != 0) {
        --(*this->_refCounter);
        if (*(this->_refCounter) <= 0) {
            delete this->_ptr;
            this->_ptr = 0;
            delete this->_refCounter;
            this->_refCounter = 0;
        }
    }
}

Expression *SharedPtr::get() const { return this->_ptr; }

SharedPtr &SharedPtr::operator=(SharedPtr const &ptr) {
    if (this != &ptr) {
        if (this->_ptr != 0) {
            --(*this->_refCounter);
        }
        if (ptr._ptr != 0) {
            ++(*ptr._refCounter);
        }
        this->_ptr = ptr._ptr;
        this->_refCounter = ptr._refCounter;
    }
    return *this;
}

void SharedPtr::reset(Expression *ptr) {
    if (this->_ptr != 0) {
        --(*this->_refCounter);
        if ((*this->_refCounter) <= 0) {
            delete this->_ptr;
            this->_ptr = 0;
            delete this->_refCounter;
            this->_refCounter = 0;
        }
        this->_refCounter = new int(1);
        this->_ptr = ptr;
    }
}

Expression *SharedPtr::operator->() const { return this->_ptr; }
Expression &SharedPtr::operator*() const { return *this->_ptr; }

