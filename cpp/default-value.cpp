//函数的参数默认值可以在声明时指定，在定义时不指定，就像下面这样
#include <iostream>

void printBool(bool in = true);

void printBool(bool in){
    std::cout << in;
}

int main()
{
    printBool();
}