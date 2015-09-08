#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int* candies=new int [ratings.size()];
        vector<int>::size_type i;
        for(i=0;i<ratings.size();++i)
           candies[i]=1;

        for(i=0;i<ratings.size()-1;++i)
            if(ratings[i+1]>ratings[i])
               candies[i+1]=candies[i]+1;

        for(i=ratings.size()-1;i>0;--i)
        {
            if(ratings[i-1]>ratings[i])
            {
                int tmp=candies[i]+1;
                if(candies[i-1]<tmp)
                    candies[i-1]=tmp;
            }
        }

        int sum=0;
        for(i=0;i<ratings.size();++i)
            sum+=candies[i];

        return sum;
    }
};

int main()
{
    vector<int> test(1);
    Solution s;
    cout << s.candy(test) << endl;
    return 0;
}
