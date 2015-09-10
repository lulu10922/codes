#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int> > grid(m,vector<int>(n,0));

        for(int i=n-1;i>=0;i--)
        {
            if(obstacleGrid[m-1][i]!=1)
               grid[m-1][i]=1;
            else
                break;
        }
        for(int i=m-1;i>=0;i--)
        {
           if(obstacleGrid[i][n-1]!=1)
               grid[i][n-1]=1;
           else
               break;
        }


        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
                if(obstacleGrid[i][j]!=1)
                  grid[i][j]=grid[i+1][j]+grid[i][j+1];
        }

        return grid[0][0];
    }
};

int main()
{
    vector<vector<int> > obstacleGrid(3,vector<int>(3,0));
    obstacleGrid[1][1]=1;
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
