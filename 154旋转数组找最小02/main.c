#include <stdio.h>
#include <stdlib.h>

int mininorder(int *nums,int left,int right)
{
    int tmp=nums[left];
    int i;
    for(i=left+1;i<=right;++i)
    {
        if(nums[i]<tmp)
            tmp=nums[i];
    }
    return tmp;
}

int findMin(int* nums, int numsSize)
{
    if(nums[0]<nums[numsSize-1])
       return nums[0];
    int left=0,right=numsSize-1;
    while(left+1<right)
    {
        int mid=(left+right)/2;
        //当中间值和左右同时相等时，只能用遍历的方法。
        if(nums[mid]==nums[left]&&nums[mid]==nums[right])
            return mininorder(nums,left,right);

        if(nums[mid]>=nums[left])
            left=mid;
        else if(nums[mid]<=nums[right])
            right=mid;
    }

    return nums[right];
}

int main()
{
    int a[]={1,1,1,0,1};
    printf("%d\n",findMin(a,5));
    return 0;
}
