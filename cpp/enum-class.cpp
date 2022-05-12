#include<iostream>

using namespace std;

enum class test{
    low,
    high,
};

int main()
{
    //int a = test::low;    ❌，枚举类需要强制类型转换，不能直接赋值
    test a = test::low;
    test b = test::high;
    cout << (a<b); // 但枚举类的对象之间可以进行相互的大小比较
}