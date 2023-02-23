#include <stdio.h>
#include <math.h>
typedef unsigned char uint8_t;
int main()
{
    uint8_t data[2];
    data[0] = 6;
    data[1] = 11;
    for(int i = 0; i < sizeof(data); i++)
        printf("data[%d] = %x\n", i, data[i]);
    return 0;
}