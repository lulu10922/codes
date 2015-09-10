#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;

        int len=prices.size();
        vector<int> preprofit(len,0);
        vector<int> postprofit(len,0);

        int curMin=prices[0];
        int maxPro=0;
        for(int i=1;i<len;i++)
        {
            curMin=min(curMin,prices[i]);
            maxPro=max(maxPro,prices[i]-curMin);
            preprofit[i]=maxPro;
        }

        int curMax=prices[len-1];
        int maPro=0;
        for(int i=len-2;i>=0;i++)
        {
            curMax=max(curMax,prices[i]);
            maxPro=max(maxPro,curMax-prices[i]);
            postprofit[i]=maxPro;
        }

        int res=0;
        for(int i=0;i<len;i++)
        {
            res=max(res,preprofit[i]+postprofit[i]);
        }

        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
