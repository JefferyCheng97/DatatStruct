#include "../include/my_string.h"

String::String()
{
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* s)
{
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

String::String(const String& s)
{
    length = s.length;
    str = new char[length + 1];
    std::strcpy(str, s.str);
}

String::~String()
{
    delete[] str;
}

size_t String::getLength() const
{
    return length;
}

char String::operator[](size_t index) const
{
    if (index >= length)
    {
        throw std::out_of_range("Index out of range");
    }

    return str[index];
}

/*
这里是连等操作, 比如 a = b = c;
所以才需要返回对象本身的引用, 如果只是 a = b, 那么返回 void 也可以。
如果只是返回了 String, 没有 &, 这意味着函数执行完，
会把当前对象（*this）克隆（Copy）一份临时产生的 String 对象返回出去。
这就好比 b 抄完了 c 的作业，准备把作业借给 a 抄:
    返回引用 (&)：s2 直接把自己的本子递给 s1。
    按值返回 (无 &)：s2 先找了一张新纸，把自己刚写好的作业重新抄一遍（克隆），
    然后把这张新纸递给 s1，s1 抄完后，这张新纸就被扔掉了。
显然，"按值返回" 多了一次无意义的内存申请和拷贝，效率变低了。
this 是一个指向自己的指针
*/
String& String::operator=(const String& s)
{
    if (this != &s)
    {
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    return *this;
}

bool String::operator==(const String& s) const
{
    if (length != s.length)
    {
        return false;
    }

    return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String& s) const
{
    return !(*this == s);
}

String String::operator+(const String& s) const
{
    String result;
    result.length = length + s.length;
    delete[] result.str;
    result.str = new char[result.length + 1];
    strcpy(result.str, str);
    strcat(result.str, s.str);

    return result;
}

String String::copy() const
{
    String s = *this;
    return s;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
    out << s.str;
    return out;
}
