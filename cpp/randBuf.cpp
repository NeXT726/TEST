#include <iostream>

using namespace std;

const int LEN = 62; // 26 + 26 + 10
char ArrCharElem[LEN];

bool RandChar(char * buf, size_t len)
{
    for(int i = 0; i < 10; i++){
        ArrCharElem[i] = '0' + i;
    }
    for(int i = 0; i < 26; i++){
        ArrCharElem[10+i] = 'a' + i;
    }
    for(int i = 0; i < 26; i++){
        ArrCharElem[36+i] = 'A' + i;
    }

	buf[len-1] = '\0';
	srand((unsigned)time(0));
	int iRand = 0;
	for (int i = 0; i < len; ++i)
	{
		iRand = rand() % LEN;
		buf[i] = ArrCharElem[iRand];
        // printf("%c", buf[i]);
	}
    return true;
}

int main()
{
    char buf[1024];
    RandChar(buf, 1024);
    string str(buf);

    printf("%s", str.c_str());
}