#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int right=left+1;
        int cur=0;

        while(right<prices.size())
        {
            while(prices[right]>=prices[right-1]&&right<prices.size())
                right++;
            int tmp=prices[right-1]-prices[left];
            if(tmp>cur)
                cur=tmp;
            if(prices[right]<prices[left])
                left=right;
        }
     return cur;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=0)
            return 0;
        int min=prices[0];
        int cur=0;

        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<min)
               min=prices[i];
            else
            {
                if(prices[i]-min>cur)
                    cur=prices[i]-min;
            }
        }

     return cur;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
