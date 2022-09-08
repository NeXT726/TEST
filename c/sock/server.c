#include "http.h"

#define MAX_LISTEN 26

int main() {
        struct sockaddr_in serv_addr = {0};
        struct sockaddr_in clie_addr = {0};

        int socket_listen = socket(AF_INET, SOCK_STREAM, 0);

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
        //不知道可不可以直接用80端口
        serv_addr.sin_port = htons(80);
        if(bind(socket_listen, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) 
        {
                printf("Error when bind");
                close(socket_listen);
                return -1;
        }

        if(listen(socket_listen, MAX_LISTEN) == -1)
        {
                printf("Error when listen");
                close(socket_listen);
                return -1;
        }

        while (1) {
                int adr_size = sizeof(clie_addr);
                int socket_acc = accept(socket_listen, (struct sockaddr*)&clie_addr, &adr_size);
                char *str = "Hello World!\n";
                write(socket_acc, str, strlen(str));
                close(socket_acc);
        }

        close(socket_listen);
}
