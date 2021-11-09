//https://blog.csdn.net/xhu_eternalcc/article/details/19770467
/**
 * 这是另一个版本，目的和隔壁c文件一样，不过是使用strtok_r函数简化了过程。
 * 具体思路可以看上面那个引用链接，讲的挺好的。
*/


#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "hello world!";
    char *hello = str;
    char *world;
    char *tmp_ptr;
    strtok_r(str, " ", &tmp_ptr);
    world = tmp_ptr;
    printf("hello:%s\nworld:%s\n", hello, world);
}