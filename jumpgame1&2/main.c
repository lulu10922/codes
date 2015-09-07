bool canJump(int* nums, int numsSize)
{
    if(numsSize<=1)
      return true;
    int maxstep=nums[0];
    for(int i=1;i<numsSize;++i)
    {
       if(maxstep>0)
       {
         --maxstep;
         if(maxstep+i>=numsSize-1)
           return true;
         maxstep=maxstep>nums[i]?maxstep:nums[i];
       }
       else
         return false;
    }
    return true;
}

int jump(int* nums, int numsSize) {
        int ret = 0;
        int curMax = 0;
        int curRch = 0;
        int index=0;
        int index1=0;
        for(int i = 0; i < numsSize; i ++)
        {
            if(curRch < i)
            {
                ret ++;
                curRch = curMax;
            }
            if(curMax < nums[i]+i)
            {
               curMax=nums[i]+i;
            }
        }
        return ret;
}

int jump(int* nums, int numsSize) {
        if(numsSize<=1)
          return 0;
        int ret = 0;
        int curMax = 0;
        int curRch = 0;
        int index=0;
        int index1=0;
        for(int i = 0; i < numsSize; i ++)
        {
            if(curRch < i)
            {
                index=index1;
                ret ++;
                curRch = curMax;
            }
            if(curMax < nums[i]+i)
            {  index1=i;
               curMax=nums[i]+i;
            }
        }
        return index;
}
