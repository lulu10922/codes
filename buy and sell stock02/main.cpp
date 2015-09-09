#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int profit=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]<prices[i+1])
            {
                profit+=prices[i]-prices[buy];
                buy=i+1;
            }
        }
        return profit;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
