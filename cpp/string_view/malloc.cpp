#include <iostream>

using namespace std;

void* operator new(size_t t) {
    cout << "malloc:" << t << endl;
    return malloc(t);
}
 
void cpp_api(std::string& str) {
    // char temp[50]  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // assign只需要进行一次拷贝
    // str.assign(temp, 50);
    // 下面的写法需要进行两次拷贝
    // str = string(temp, 50);
    
    // string对std::move的构造函数没有特别的优化，依旧要进行一次拷贝
    // string temp = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    // string tempp(std::move(temp));
}
 
int main() {
    string s("hello, world.hello, world.hello, world.");
    cpp_api(s);
    return 0;
}