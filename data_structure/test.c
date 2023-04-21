#include <stdio.h>

#define RESULT 0 // 定义 RESULT 为 0
#ifndef PI 
#define PI 3.1416 
#endif

int main(void)
{
#if RESULT // 或者 0==RESULT
    printf("It's False!\n");
#else
    printf("It's True!, pi = %f\n", PI);
#endif // 标志结束#if
    return 0;
}