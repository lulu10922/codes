#include <stdio.h>
#include <stdlib.h>

int findMin(int* nums, int numsSize)
{
    if(nums[0]<nums[numsSize-1])
       return nums[0];

    int left=0,right=numsSize-1;
    while(left+1<right)
    {
        while(left<right&&nums[left]==nums[left+1]) left++;
        while(left<right&&nums[right]==nums[right-1]) right--;
        int mid=(left+right)/2;
        if(nums[mid]>nums[left])
            left=mid;
        else if(nums[mid]<nums[right])
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
