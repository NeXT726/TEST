//https://www.runoob.com/cprogramming/c-function-strtok.html
//https://www.runoob.com/cprogramming/c-function-strstr.html
/**
 * 目的：想从http报文中提取报头，即第一个\r\n\r\n前的部分
 * 考虑：通过strstr找到那个位置，然后用strtok分割出前面的报头
 * 问题：
 *  1.strtok分割后，会把分隔符的第一个字符改为'\0'，分隔符的其他字符不变
 *  2.strstr找到的是分隔符的第一个字符的地址位置，我们要找到正文部分，需要往后移动分隔符的长度
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "hello\r\nworld!";
    char *world = strstr(str, "\r\n");
    char *hello = strtok(str, "\r\n");
    world = world + 2;
    printf("hello:%s\nworld:%s\n", hello, world);
}