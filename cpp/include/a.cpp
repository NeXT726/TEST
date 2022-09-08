#include "a.h"
#include "b.h"

void a()
{
    std::cout << "a" << std::endl;
}

int main()
{
    uint8_t * value = reinterpret_cast<uint8_t*>(const_cast<char*>("djl123$$$"));
    auto s = std::string(value, value+9);
    std::cout << "s:" << s << std::endl;
    b();
}