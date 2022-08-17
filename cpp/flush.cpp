//直到flush()才真正把结果写入到文件中
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
using namespace std;

int main(void)
{
    fstream f("tmp.txt", ios::out);
    f.write("test", 4);
    cout << "wait write" << endl;  //此时'test'已写入缓冲区，但未写入文件，查看文件内容为空，见结果1
    sleep(20);
    f.flush();    //刷新缓冲区到文件
    cout << "wait flush" << endl;   //此时缓冲区内容已经刷新至文件，见结果2
    f.close();
    return 0;
}