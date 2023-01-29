#include "classes.hpp"

size_t String::_countLength(const char *str) {
    size_t counter = 0;
    for (const char *s = str; *(s) != '\0'; ++s) {
        ++counter;
    }
    return counter;
}

char *String::_fillString(char s) {
    char *str = new char[this->size + 1];
    for (size_t i = 0; i < this->size; ++i) {
        str[i] = s;
    }
    str[this->size] = '\0';
    return str;
}

String::String(const char *str) {
    this->size = this->_countLength(str);
    this->str = new char[this->size + 1];
    for (size_t i = 0; i <= this->size; ++i) {
        this->str[i] = str[i];
    }
}

String::String(size_t count, char s) {
    this->size = count;
    this->str = this->_fillString(s);
}

size_t String::len() { return this->size; }

void String::append(String &rightStr) {
    size_t newSize = this->size + rightStr.size;
    char *newString = new char[newSize + 1];
    size_t counter = 0;
    for (; counter < this->size; counter++) {
        newString[counter] = this->str[counter];
    }
    for (size_t i = 0; i < rightStr.size; ++i, ++counter) {
        newString[counter] = rightStr.str[i];
    }
    newString[newSize] = '\0';
    delete[] this->str;
    this->str = newString;
    this->size = newSize;
}

void String::printStr() const {
    for (size_t i = 0; i <= this->size; ++i) {
        if (this->str[i] == '\0') {
            cout << "\\0";
            continue;
        }
        cout << this->str[i];
    }
    cout << endl;
}
String::~String() { delete this->str; }

String &String::operator=(String const &s) {
    if (this != &s) {
        delete[] this->str;
        this->size = s.size;
        this->str = new char[s.size + 1];
        strcpy(this->str, s.str);
    }
    return *this;
}

StringProxy String::operator[](size_t index) const {
    StringProxy str(this, index);
    return str;
}

StringProxy::StringProxy(String const *str, size_t startIndex) {
    this->str = new char[str->size - startIndex + 1];
    this->prevIndex = startIndex;
    size_t j = 0;
    for (size_t i = startIndex; i <= str->size; ++i) {
        this->str[j] = str->str[i];
        ++j;
    }
}
StringProxy::~StringProxy() { delete[] this->str; }

String StringProxy::operator[](size_t index) {
    size_t newStrSize = index - this->prevIndex;
    String tmpStr(newStrSize, ' ');
    for (size_t i = 0; i < newStrSize; ++i) {
        tmpStr.str[i] = this->str[i];
    }
    return tmpStr;
}

int main() {
    String *str = new String("some_long_string");
    str->printStr();
    String str3 = (*str)[6][15];
    str3.printStr();
    return 0;
}
