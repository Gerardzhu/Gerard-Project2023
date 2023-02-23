//多线程同步--条件锁(相当与windows的事件)测试
//要先让pthread_cond_wait进入等待信号状态,才能调用pthread_cond_signal发送信号,才有效.
//不能让pthread_cond_signal在pthread_cond_wait前面执行
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> //多线程所用头文件 
#include <semaphore.h> //信号量使用头文件 
pthread_cond_t g_cond /*=PTHREAD_MUTEX_INITIALIZER*/; //申明条锁,并用宏进行初始化
pthread_mutex_t g_mutex ;
//线程执行函数

void threadFun1(void)
{
    int i;
    pthread_mutex_lock(&g_mutex); //1
    pthread_cond_wait(&g_cond, &g_mutex); //如g_cond无信号,则阻塞
    for( i = 0; i < 2; i++ ) {
        printf("thread threadFun1.\n");
        sleep(1);
    }
    pthread_cond_signal(&g_cond);
    pthread_mutex_unlock(&g_mutex);
}

int main(void)
{
    pthread_t id1; //线程的标识符
    pthread_t id2;
    pthread_cond_init(&g_cond, NULL); //也可以程序里面初始化
    pthread_mutex_init(&g_mutex, NULL); //互斥变量初始化

    int i, ret;
    ret = pthread_create(&id1, NULL, (void *)threadFun1, NULL);
    if (ret != 0) { //不为0说明线程创建失败
        printf ("Create pthread1 error!\n");
        exit (1);
    }
    sleep(5); //等待子线程先开始

    pthread_mutex_lock(&g_mutex); //2
    pthread_cond_signal(&g_cond); //给个开始信号,注意这里要先等子线程进入等待状态在发信号,否则无效
    pthread_mutex_unlock(&g_mutex);
    pthread_join(id1,NULL);
    pthread_cond_destroy(&g_cond); //释放
    pthread_mutex_destroy(&g_mutex); //释放
    return 0;
}