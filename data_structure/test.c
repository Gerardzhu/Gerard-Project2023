#include <stdio.h>

unsigned char testfunc(void)
{
    unsigned char ted = 2;
    return ted;
}

unsigned char main()
{
    unsigned char ret;
    ret = testfunc;
    printf("%d\n", ret);
    ret = testfunc();
    printf("%d\n", ret);
}