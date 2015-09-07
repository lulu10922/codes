#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
int reverse(int x) {
    int rx,sign;
    if (x<0)
    {
        sign=-1;
        x=-x;
    }
    else sign=1;
    rx=0;
    do {rx=rx*10+x%10;}
        while(x/=10);
        rx=rx*sign;
    return rx;
}
