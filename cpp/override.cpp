#include <iostream>

using namespace std;

class father
{
public:
    void show1()
    {
        cout << "father::show1" << endl<< endl;
    }

    virtual void show2()
    {
        cout << "father::show2" << endl << endl;
    }
};

class son:public father
{
public:
    void show1()
    {
        cout << "son::show1" << endl<< endl;
    }

    virtual void show2()
    {
        cout << "son::show2" << endl << endl;
    }
};

int main()
{
	father f;
	son s;

	father *pf=&s;
	son *ps=&s;

	pf->show1();
	pf->show2();
	
	return 0;
}