#include <iostream>
#include<vector>
#include<string>

using namespace std;
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

void NQueens(vector<vector<string> >& res,vector<string>& chess,int N,int row)
{
    if(row==N)
    {
        res.push_back(chess);
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(isNoDanger(chess,N,row,i))
        {
            chess[row][i]='Q';
            NQueens(res,chess,N,row+1);
            chess[row][i]='.';
        }
    }
}
vector<vector<string> > solveNQueens(int n)
{
    vector<vector<string> > res;
    vector<string> chess(n,string(n,'.'));
    NQueens(res,chess,n,0);
    return res;
}

int main()
{
    int N=1;
    vector<vector<string> > res;
    res=solveNQueens(N);
    for(int i=0;i<res.size();++i)
        for(int j=0;j<N;++j)
           cout<<res[i][j]<<endl;
    return 0;
}
