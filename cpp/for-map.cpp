#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,int> mapNum;
    mapNum.insert(pair<int, int>(2, 2));    //利用pair进行插入
    mapNum.insert(make_pair(3, 3));         //利用make_pair进行插入
    for (auto n : mapNum)
    {
        cout << n.first << n.second << endl;
    }
}
