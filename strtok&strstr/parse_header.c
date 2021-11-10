/**
 * 这个代码运行结果是错的。
 * 原因是因为strtok函数是以字符分割的，而不是字符串
 * 下面的思路是继续用strstr做分割。、
*/

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERVER_IP "10.0.0.1"

#define HTTP_VER "HTTP/1.0"

#define CHAR_GET "GET"
#define CHAR_POST "POST"

#define GET 1
#define POST 2

#define METHOD_SZ 4
#define URL_SZ 1024
#define VERSION_SZ 16

#define NAME_SZ 64
#define VALUE_SZ 1024

#define BUFFER_SZ 16*1024
#define R_NM 16


char buff[] ="GET /service/open/nick?users=&callback=jQuery17204034407522995025_1386320955034&_=1386320955173 HTTP/1.1\r\nHost: api.csdn.net.cn\r\nConnection: keep-alive\r\nAccept: */*\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36\r\nReferer: http://bbs.csdn.net/home\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-CN,zh;q=0.8\r\nCookie: 6320938.ovid\r\n\r\nHTTP/1.1 200 OK\r\nCache-Control: private\r\nContent-Length: 0";

typedef struct http_header_t {
    char method[METHOD_SZ];
    char url[URL_SZ];
    char version[VERSION_SZ];
} hheader;

typedef struct request_header_t {
    char name[NAME_SZ];
    char value[VALUE_SZ];
} rheader;

int get_method(char *method)
{
    if(!strcmp(CHAR_GET, method))
        return GET;
    else if(!strcmp(CHAR_POST, method))
        return POST;
    else return -1;
}

int parse_buffer(char *buf, hheader *h, rheader *r, char *data_buf)
{
    char *header;
    header = buf;
    char *tmp_ptr;
    char *out_ptr = NULL;
    char *in_ptr;
    int in = 0;

//将头部和数据部分分开，给data_buf赋值
    tmp_ptr = strtok_r(buff, "\r\n\r\n", &out_ptr);
    strcpy(data_buf, out_ptr);
    printf("data_buf:%s\n", out_ptr);
//将固定头部，也就是第一行解析
    /*out_ptr = NULL;
    tmp_ptr = strtok_r(header, "\r\n", &out_ptr);
    printf("header:%s\n", tmp_ptr);*/
/*
    tmp_ptr = strtok_r(header, " ", &in_ptr);
    strcpy(h->method, tmp_ptr);
    tmp_ptr = strtok_r(NULL, " ", &in_ptr);
    strcpy(h->url, tmp_ptr);
    tmp_ptr = strtok_r(NULL, " ", &in_ptr);
    strcpy(h->version, tmp_ptr);
//解析可变长头部
    while((tmp_ptr = strtok_r(NULL, "\r\n", &out_ptr)) != NULL){
        if(in > R_NM) {
            printf("可变长头部过多！\n");
            return -1;
        };

        in_ptr = NULL;
        strtok_r(tmp_ptr, ":", &in_ptr);
        strcpy(r[in].name, tmp_ptr);
        strcpy(r[in].value, in_ptr);
        in++;
    }
*/
}

int main(){
    hheader headerh;
    rheader headerr[R_NM];
    char *data_buffer = malloc(BUFFER_SZ);
    memset(data_buffer, 0, BUFFER_SZ);

    parse_buffer(buff, &headerh, headerr, data_buffer);
/*
    printf("method:%s\n", headerh.method);
    printf("url:%s\n", headerh.url);
    printf("version:%s\n", headerh.version);
*/
}