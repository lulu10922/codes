#include <iostream>
#include<vector>
using namespace std;


int maxArea(vector<int>& height) {
       int size=height.size();
       int left=0,right=size-1;
       int cur=0;

       while(left<right)
       {
           if(height[left]<height[right])
           {
               int tmp=height[left]*(right-left);
               if(cur<tmp)
                cur=tmp;
               left++;
           }
           else
           {
               int tmp=height[right]*(right-left);
               if(cur<tmp)
                cur=tmp;
               right--;
           }
       }

       return cur;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
