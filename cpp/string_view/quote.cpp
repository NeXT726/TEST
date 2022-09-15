// 将string &传到string没有问题
// 将string传到string &也没有问题

#include <iostream>

using namespace std;

void test(string a)
{
    cout << a << endl;
}

int main ()
{
    string x("abcdefg");
    string &xx = x;
    test(xx); 
}