#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
    //1.打开管道文件
    int fd = open("/tmp/fifo", O_RDONLY);
    if(0 > fd)
    {
        perror("open");
        return -1;
    }
    //2.读数据
    while(1)
    {
        char buf[1024] = {};
        read(fd, buf, sizeof(buf));
        if(0 == strcmp(buf, "quit"))
        {
            printf("退出\n");
            break;
        }
        printf("read:%s\n", buf);
    }
    //关闭管道文件
    close(fd);

    return 0;
}

