#include <iostream>
#include<vector>
using namespace std;

void qsort(vector<int> &nums,int i,int j)
{
    if(i>=j)
        return;
    int l,r,mid=(i+j)/2;
    int tmp;
    tmp=nums[mid];
    nums[mid]=nums[i];
    nums[i]=tmp;

    for(l=i,r=i+1;r<=j;++r)
    {
        if(nums[r]<nums[i])
        {
            l++;
            tmp=nums[l];
            nums[l]=nums[r];
            nums[r]=tmp;

        }
    }
     tmp=nums[l];
    nums[l]=nums[i];
    nums[i]=tmp;
    qsort(nums,i,l-1);
    qsort(nums,l+1,j);
}

vector<vector<int> >threeSum(vector<int> &num)
{
    vector<vector<int> > result;
    vector<int> tmp(3,0);

    int i,j,k;
    int size=num.size();
    qsort(num,0,size-1);

    for(i=0;i<size-2;i++)
    {
        j=i+1,k=num.size()-1;
        while(j<k)
        {
            if(num[j]+num[k]==-num[i])
            {
                tmp[0]=num[i];
                tmp[1]=num[j];
                tmp[2]=num[k];

                result.push_back(tmp);
                while(j<k&&num[j]==num[j+1]) j++;
                while(j<k&&num[k]==num[k-1]) k--;
                j++;
                k--;
            }
            else if(num[j]+num[k]<-num[i])
                ++j;
            else
                --k;
        }
        while(i+1<size&&num[i]==num[i+1])
            ++i;

    }
    return result;
}


int main()
{
    int a[]={-1,0,1,2,-1,-4};
    vector<int> test(a,a+6);
    vector<vector<int> > result=threeSum(test);
    vector<vector<int> >::iterator ite;

    cout << "Hello world!" << endl;
    return 0;
}
