#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
int isNoDanger(vector<string>& chess,int N,int row,int n)
{
    int i,j;

    for(i=0;i<N;i++)
        if(chess[i][n]=='Q')
          return 0;

    for(i=row,j=n;i>=0&&j>=0;i--,j--)
        if(chess[i][j]=='Q')
          return 0;

    for(i=row,j=n;i<N&&j<N;i++,j++)
        if(chess[i][j]=='Q')
          return 0;

    for(i=row,j=n;i<N&&j>=0;i++,j--)
        if(chess[i][j]=='Q')
          return 0;

    for(i=row,j=n;i>=0&&j<N;i--,j++)
        if(chess[i][j]=='Q')
          return 0;

    return 1;
}

int NQueens(vector<string>& chess,int N,int row)
{
    if(row==N)
    {
        return 1;
    }
    int sum=0;
    for(int i=0;i<N;i++)
    {
        if(isNoDanger(chess,N,row,i))
        {
            chess[row][i]='Q';
            sum+=NQueens(chess,N,row+1);
            chess[row][i]='.';
        }
    }
    return sum;
}
int totalNQueens(int n)
{
    vector<string> chess(n,string(n,'.'));
    return NQueens(chess,n,0);
}
};

int main()
{
    Solution s;
    cout << s.totalNQueens(8)<< endl;
    return 0;
}
