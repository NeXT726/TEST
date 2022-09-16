#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int ID;
    int score;
    //定义一个100字节的字节数组缓存
    char name[100];

    cout<<"Enter ID:"<<endl;
    //从标准输入读取的字节数据缓存到整形
    cin>>ID;  //-

    cout<<"Enter name:"<<endl;
    cin>>name;

    cout<<"Enter score:"<<endl;
    cin>>score;

    cout<<"You input data as follow..."<<endl;
    cout<<"ID:"<<ID<<endl;
    cout<<"Name:"<<name<<endl;
    cout<<"Score:"<<score<<endl;   
    return 0;
}