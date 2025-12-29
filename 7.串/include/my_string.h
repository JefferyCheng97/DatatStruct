#pragma once

#include <cstring>
#include <stdexcept>
#include <iostream>

class String    
{
private:
    char* str;
    size_t length;    

public:
    String();
    String(const char* s);
    String(const String& s);
    ~String();

    size_t getLength() const;

    char operator[](size_t index) const;
    String &operator=(const String& s);
    bool operator==(const String& s) const;
    bool operator!=(const String& s) const;
    String operator+(const String& s) const;

    String copy() const;

    friend std::ostream& operator<<(std::ostream& out, const String& s);
};
