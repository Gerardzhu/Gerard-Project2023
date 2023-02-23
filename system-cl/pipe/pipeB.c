#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    //1.创建管道文件,一般保存在/tmp目录下
    if(mkfifo("/tmp/fifo", 0644))
    {
        perror("mkfifo");
        return -1;
    }
    //2.打开管道
    int fd = open("/tmp/fifo", O_WRONLY);
    if(0 > fd)
    {
        perror("open");
        return -1;
    }
    //3.写数据
    char buf[1024] =  {};
    while(1)
    {
        printf(">");
        gets(buf);
        write(fd, buf, strlen(buf)+1);
        if(0 == strcmp(buf, "quit"))
        {
            printf("通信完成\n");
            break;
        }
    }
    //关闭管道文件
    close(fd);
    return 0;
}

