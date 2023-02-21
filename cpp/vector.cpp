#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    vector<int> num = {1,2,3,4,5};
    using NodePool = std::stack<int, std::vector<int>>;
    NodePool node;
    for (int i = 0; i < 64; i++)
        node.push(i);
    // cout << *(num.end()) << endl;
    cout << sizeof(NodePool) << endl;

    cout << 6 / 2 * 3 << endl;
}   