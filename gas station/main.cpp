#include <iostream>
#include<vector>

using namespace std;

//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int len=gas.size();
//        if(len<=1)
//            return 0;
//        int begin=0,end=0;
//        int count=0,i=0,gasInCar=0;
//
//        while(count<len)
//        {
//            gasInCar+=gas[i]-cost[i];
//            if(gasInCar>=0)
//            {
//                end++;
//                i=end;
//            }
//            else
//            {
//                --begin;
//                if(begin<0)
//                    begin=len-1;
//                i=begin;
//            }
//            count++;
//        }
//        if(gasInCar<0)
//            return -1;
//        else
//            return begin;
//    }
//};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int len=gas.size();
        int i,index=0;
        int sum=0,total=0;
        for(i=0;i<len;++i)
        {
            sum+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(sum<0)
            {
                index=i+1;
                sum=0;
            }
        }
        if(total<0)
            return -1;
        else
            return index;
    }
};

int main()
{
    int a[5]={5,0,9,4,3};
    int b[5]={6,7,5,9,5};
    vector<int> gas(a,a+5);
    vector<int> cost(b,b+5);
    Solution s;
    cout << s.canCompleteCircuit(gas,cost) << endl;
    return 0;
}
