/*
* 下面给出一个小的测试程序进一步了解互斥，
* mutex互斥信号量锁住的不是一个变量，而是阻塞住一段程序。
* 如果对一个mutex变量testlock执行了第一次pthread_mutex_lock(testlock)之后，
* 在unlock(testlock)之前的这段时间内，如果有其它线程也执行到了pthread_mutex_lock（testlock）,
* 这个线程就会被阻塞住，直到之前的线程unlock之后才能执行，
* 由此，实现同步，也就达到了保护临界区域资源的作用。
*/

#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

static pthread_mutex_t testlock;
pthread_t test_thread;

void *test()
{
    pthread_mutex_lock(&testlock);
    printf("thread Test() \n");
    pthread_mutex_unlock(&testlock);
}

int main()
{
    pthread_mutex_init(&testlock, NULL);
    pthread_mutex_lock(&testlock);

    printf("Main lock \n");

    pthread_create(&test_thread, NULL, test, NULL);
    sleep(1); //更加明显的观察到是否执行了创建线程的互斥锁
    printf("Main unlock \n");
    pthread_mutex_unlock(&testlock);

    sleep(1);

    pthread_join(test_thread,NULL);
    pthread_mutex_destroy(&testlock);
    return 0;
}