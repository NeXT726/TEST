#include <iostream>

using namespace std;

int main()
{
    const char a[] = "12345678";
    // uint8_t * b = static_cast<uint8_t *>(a);  static_cast是不可以转换指针的，编译错误。
    const uint8_t *b = reinterpret_cast<const uint8_t *>(a); //reinterpret_cast用于转换指针，正确运行。
    cout << b << endl;
}