#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int mid = (l & r) + ((l ^ r) >> 1);
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) {
            if (nums[l] <= target || nums[mid] <=nums[r]) r = mid - 1;
            else l = mid + 1;
        }
        else {
            if (nums[r] >=target || nums[mid] >= nums[l]) l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
