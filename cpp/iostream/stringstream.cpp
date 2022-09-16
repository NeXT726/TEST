// stringstream 在<<输出的时候会以分隔符一个单词一个单词的输出（分隔符自己可以设置）
// 输入的时候，使用write和>>都会以append的方式输入stream中
// 通过stringstream.str()可以直接取出所有的数据内容。
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    stringstream data;
    char temp[] = "hello world";
    string str = "hello djl";
    data << str;
    data.write(temp, 12);
    string tmp;
    data >> tmp; 
    cout << data.str() << endl;
}