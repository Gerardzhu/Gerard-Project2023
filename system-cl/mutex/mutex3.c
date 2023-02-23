#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

/**
 * https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html
 *
 */

static pthread_mutex_t mutex;

void* calls(void *ptr) {
	pthread_mutex_lock(&mutex);
	printf("thread1: 1\n");
	//sleep(2);
	pthread_mutex_unlock(&mutex);
	sleep(1);
	printf("thread1: 3\n");
	pthread_mutex_lock(&mutex);
	printf("thread1: 5\n");
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void* calls2(void *ptr) {
	pthread_mutex_lock(&mutex);
	printf("thread2:2\n");
	//sleep(2);
	printf("thread2:4\n");
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main() {
	pthread_mutex_init(&mutex, NULL);
	pthread_t thread;
	pthread_t thread2;
	pthread_create(&thread, NULL, calls, NULL);
	//sleep(2);
	pthread_create(&thread2, NULL, calls2, NULL);
	pthread_join(thread, NULL);
	pthread_join(thread2, NULL);
	if (0 != pthread_mutex_destroy(&mutex)) {
		perror("pthread_mutex_destroy");
	}
	printf("main exit\n");
	return EXIT_SUCCESS;
}

