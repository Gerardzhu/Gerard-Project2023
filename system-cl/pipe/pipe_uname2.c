# include<stdio.h>
# include<string.h>
# include<unistd.h>
# include<assert.h>
# include<fcntl.h>
# include<sys/wait.h>

int main(int argc,char const *argv[])
{
	//创建一无名管道
	int fd[2];
	pipe(fd);
	//创建子进程
    //父进程发，子进程收
	pid_t pid = fork();
    assert(pid!=-1);
	if (pid == 0)//子进程
	{
		close(fd[1]);//关闭写端
        while(1)
        {
            char buff[128]={0};
            int accept=read(fd[0],buff,127);
            if(accept<=0)
            {
                break;
            }
            printf("son:%d success read %s\n",getpid(),buff);  
        }
          //通信结束，关闭读端   
        close (fd[0]);     
	}
	else //父进程
	{
		//父进程读端无意义(可以关闭)
        close(fd[0]);
        //写端写入数据
        while(1)
        {
        char buff[128]={0};
       printf("father:%d write data:",getpid());
         fgets(buff,127,stdin);
            write(fd[1],buff,strlen(buff)-1);
             if(strncmp(buff,"over",4)==0)
            {
                break;
             }
        }
            //通信结束，关闭写端
            close (fd[1]); 
            //等待子进程退出
            wait(NULL);
	}
	return 0;
}