/**
 * 这个文件就是简单的测试一下在子函数中fclose文件会不会导致母函数的文件被关闭
 * 测试结果是 会的，我们在子函数中fclose的文件描述符不能再在母函数中使用
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int close_file(FILE * f)
{
    fclose(f);
    char *buff  = malloc(1024);
    memset(buff, 0, 1024);
    int n = fread(buff, 1, 1024, f);
    printf("buff:%s\tn:%d\n", buff, n);
}

int main()
{
    FILE *file = fopen("a", "r");
    //close_file(file);

    char *buff  = malloc(1024);
    memset(buff, 0, 1024);
    int n = fread(buff, 1, 1024, file);
    printf("buff:%s\tn:%d\n", buff, n);
}

