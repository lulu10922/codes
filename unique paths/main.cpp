#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1)
            return 1;

        vector<vector<int> > chess(m,vector<int>(n,0));

        for(int i=0;i<n;i++)
            chess[m-1][i]=1;
        for(int i=0;i<m;i++)
            chess[i][n-1]=1;

        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
               chess[i][j]=chess[i+1][j]+chess[i][j+1];
        }

        return chess[0][0];

    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3,3) << endl;
    return 0;
}
