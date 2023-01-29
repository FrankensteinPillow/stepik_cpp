#pragma once
#include <iostream>
using namespace std;

class StringProxy;

class String {
  public:
    size_t size;
    char *str;
    explicit String(const char *str = "");
    explicit String(size_t count, char s);
    ~String();
    size_t len();
    void append(String &rightStr);
    void printStr() const;
    String &operator=(String const &s);
    StringProxy operator[](size_t index) const;

  private:
    size_t _countLength(const char *str);
    char *_fillString(char s);
};

class StringProxy {
    public:
    char *str;
    size_t prevIndex;
    explicit StringProxy(String const *str, size_t startIndex);
    ~StringProxy();
    void printStr() const;
    String operator[](size_t index);
};
