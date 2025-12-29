#include "../include/my_string.h"

using namespace std;

int main()
{
    String s("12345d");
    cout << s << endl;
    cout << s + "445" << endl;
    cout << s[5] << endl;
    cout << (s == "12345d") << endl;
    cout << (s != "12345d") << endl;

    s = s + "asd";
    String a, b, c;
    a = b = c = s;
    cout << s << endl;
    cout << a << b << c << s << endl;

    String x = s.copy();
    cout << x << endl;

    return 0;
}