//在函数内改变引用的值是会改变原来变量的值，不像某个网站上讲的引用不会改变原值
#include<iostream>

using namespace std;

void addd(int &x)
{
    x++;
}

int main()
{
    int a = 1;
    cout << "自增前" << a;
    addd(a);
    cout << "自增后" << a;
}