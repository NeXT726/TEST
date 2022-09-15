#include <iostream>

using namespace std;

void* operator new(size_t t) {
    cout << "malloc:" << t << endl;
    return malloc(t);
}
 
void cpp_api(const std::string&) {}
 
int main() {
    string s{"hello, world"};
    cpp_api(s.substr(0, 5));
    return 0;
}