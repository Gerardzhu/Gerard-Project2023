#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
	//创建管道
	int pipefd[2] = {};	
	//打开无名官道
	if(pipe(pipefd))
	{
		perror("pipe");
		return -1;
	}
	//创建进程,父进程写关闭读
	if(fork())
	{
		close(pipefd[0]);
		printf("父进程:%u\n",getpid());
		while(1)
		{
			char buf[1024] = {};
			usleep(1000);
			printf(">");
			gets(buf);
			write(pipefd[1],buf,strlen(buf)+1);
			if(0 == strcmp(buf,"quit"))
			{
				printf("通信结束\n");
				close(pipefd[1]);
				return 0;
			}
		}
	}
	else//子进程读，关闭写
	{
		close(pipefd[1]);
		printf("子进程:%u\n",getpid());
		while(1)
		{
			char buf[1024] = {};
			read(pipefd[0],buf,sizeof(buf));
			if(0 == strcmp(buf,"quit"))
			{
				printf("通信结束\n");
				close(pipefd[0]);
				return 0;
			}
			printf("read:%s\n",buf);
		}
	}
	return 0;	
}

