#include <stdio.h>
#include <stdlib.h>
int maxSubArray(int* nums, int numsSize);
int status=0;
int main()
{
    printf("Hello world!\n");
    return 0;
}
int maxSubArray(int* nums, int numsSize)
{
    if(nums==NULL||numsSize==0)
    {
        status=1;
        return 0;
    }

    int max=nums[0];
    int cur=0;
    int i;
    for(i=0;i<numsSize;++i)
    {
        cur+=nums[i];
        if(cur>max)
            max=cur;
        if(cur<0)
            cur=0;
    }
    return max;
}
