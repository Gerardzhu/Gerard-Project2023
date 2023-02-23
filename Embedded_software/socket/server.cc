//tcp服务端的代码
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <unistd.h>

#define DATA_LEN 256
typedef struct
{
    uint8_t head1;  //0x55
    uint8_t head2;  //0xAA
    uint16_t dlen;  /**<  命令和数据字节数 */
    uint8_t cmd;
    uint8_t data[DATA_LEN]; /**<  实际数据内容 */
} tcp_mcu_cont __attribute__((aligned(4)));

int main()
{
    //1、创建socket套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("socket error");
        return -1;
    }
    struct sockaddr_in ser;
    ser.sin_family = AF_INET;
    ser.sin_port = htons(atoi("57012"));
    ser.sin_addr.s_addr = inet_addr("127.0.0.1");

    //2、绑定地址
    socklen_t len = sizeof(struct sockaddr_in);
    if(bind(sockfd, (struct sockaddr*)&ser, len) < 0)
    {
        perror("bind error");
        close(sockfd);
        return -1;
    }

    //3、监听
    if(listen(sockfd, 5) < 0)
    {
        perror("listen error");
        close(sockfd);
        return -1;
    }
    while(1)
    {
        int n_sockfd;
        struct sockaddr_in cli;
        //4、accept
        n_sockfd = accept(sockfd, (struct sockaddr*)&cli, &len);
        if(n_sockfd < 0)
        {
            perror("accept error");
            continue;
        }
        //5、recv
        while(1){
            //6、send
            tcp_mcu_cont buff;
            int ret=recv(n_sockfd, &buff, 256, 0);
            if(ret<0)
            {
                perror("recv error");
                continue;
            }
            printf("client %s[%d]say:%s", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port), (char *)&buff);
            
            memset(&buff, 0x00, 256);
            buff.head1 = 0x55;
            buff.head2 = 0xaa;
            buff.dlen = 2;
            buff.cmd = 1;
            buff.data[0] = 0x11;
            send(n_sockfd, (char *)&buff, sizeof(&buff)+1, 0);
            //7、close(sockfd)
        }
        close(n_sockfd);
    }
}

