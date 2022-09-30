#include <iostream>
#include <cstdlib>
#include <string>

using std::string;
using std::cout;
using std::endl;

//重写string类的new操作符,添加一个可以识别malloc操作的输出
void* operator new(std::size_t n){
    cout<<"分配"<<n<<"字节"<<endl;
    return malloc(n);
}

void operator delete(void *p) throw(){
    free(p);
}

int main(int argc, char const *argv[])
{
    string s("HELLO++++++++++++++++++"); //直接初始化
    cout<<"初始化时的状态:"<<endl;
    cout<<"sizeof:"<<sizeof(s)<<endl;
    cout<<"size:"<<s.size()<<endl;
    cout<<"分配的内存尺寸(capacity):"<<s.capacity()<<endl;

    for(size_t i=25;i<64;++i){
        s.push_back('+');
        cout<<i<<":"<<s<<endl;
    }

    cout<<"push_back('+')之后的内存尺寸是"<<endl;
    cout<<"sizeof:"<<sizeof(s)<<endl;
    cout<<"size:"<<s.size()<<endl;
    cout<<"分配的内存尺寸(capacity):"<<s.capacity()<<endl;
}