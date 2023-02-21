#include <stdio.h>
#include <iostream>

class Main
{
public:
    constexpr static auto func1 =
        [](int a, int b) -> int
    {
        return a + b;
    };

    template <typename func>
    int test(int a, int b)
    {
        const func add;
        return add(a, b);
    };

    int exec(int a, int b)
    {
        return test<decltype(func1)>(a, b);
    };
};

int main()
{
    std::cout << Main().exec(1, 2) << std::endl;
    return 0;
}
