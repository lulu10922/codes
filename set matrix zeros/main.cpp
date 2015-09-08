#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix)
    {
         int r=matrix.size();
         int c=matrix[0].size();
         if(r<=0||c<=0)
            return;

         int i,j,fr=0,fc=0;
         for(i=0;i<c;++i)
         {
             if(matrix[0][i]==0)
             {
                 fr=1;
                 break;
             }
         }
         for(i=0;i<r;++i)
         {
             if(matrix[i][0]==0)
             {
                 fc=1;
                 break;
             }
         }

         for(i=1;i<r;++i)
            for(j=1;j<c;++j)
               if(matrix[i][j]==0)
                {
                   matrix[i][0]=0;
                   matrix[0][j]=0;
                }
         for(i=1;i<r;++i)
            for(j=1;j<c;++j)
               if(matrix[i][0]==0||matrix[0][j]==0)
                  matrix[i][j]=0;

         if(fr)
         {
             for(i=0;i<c;++i)
                matrix[0][i]=0;
         }
         if(fc)
         {
             for(i=0;i<r;++i)
                matrix[i][0]=0;
         }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
