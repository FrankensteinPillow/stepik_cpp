#include <iostream>
using namespace std;

struct Expression {};
struct Number {};
struct BinaryOperation {};

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
    if (this->_refCounter != 0) {
        --(*this->_refCounter);
    }
    if (this->_refCounter != 0 && *(this->_refCounter) <= 0) {
        delete this->_ptr;
        delete this->_refCounter;
    }
}

SharedPtr &SharedPtr::operator=(SharedPtr const &ptr) {
    if (this != &ptr) {
        if (this->_refCounter != 0) {
            --(*this->_refCounter);
        }
        if (ptr._refCounter != 0) {
            ++(*ptr._refCounter);
        }
        this->_ptr = ptr._ptr;
        this->_refCounter = ptr._refCounter;
    }
    return *this;
}

void SharedPtr::reset(Expression *ptr) {
    if (this->_refCounter != 0) {
        --(*this->_refCounter);
        if (*this->_refCounter <= 0) {
            delete this->_ptr;
            delete this->_refCounter;
        }
    }
    this->_ptr = ptr;
    if (ptr == 0) {
        this->_refCounter = 0;
    } else {
        this->_refCounter = new int(1);
    }
}

Expression *SharedPtr::operator->() const { return this->_ptr; }
Expression &SharedPtr::operator*() const { return *this->_ptr; }

int main() {
    SharedPtr p1;
    {
        SharedPtr p2(new Expression());
        SharedPtr p3(new Expression());
        SharedPtr p4(p2);
        SharedPtr p5;
        p5 = p2;
        p5 = p4;
        p1 = p5;
        p3.reset(0);
        p3 = p5;
        p5.reset(0);
        SharedPtr p6;
        SharedPtr p7;
        p7 = p7;
        p7.reset(0);
        p7.reset(new Expression());
        SharedPtr p8(new Expression());
        p8.reset(0);
    }
    p1 = p1;
    return 0;
}
