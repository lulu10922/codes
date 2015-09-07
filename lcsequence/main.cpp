#include <iostream>
#include<string>
#include<vector>

using namespace std;
int lcs(const string& ,const string & );
int main()
{   string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    cout <<lcs(str1,str2)<< endl;
    return 0;
}
int lcs(const string& str1,const string & str2)
{
    size_t size1=str1.size();
    size_t size2=str2.size();
    vector<vector<int> > table(size1+1,vector<int>(size2+1,0));
    vector<vector<int> > flag(size1+1,vector<int>(size2+1,0));
    int i,j;
    for(i=1;i<size1+1;++i)
    {
        for(j=1;j<size2+1;++j)
        {
            if(str1[i-1]==str2[j-1])
                {table[i][j]=table[i-1][j-1]+1;
                 flag[i][j]=1;
                }
            else if(table[i][j-1]>table[i-1][j])
                {table[i][j]=table[i][j-1];
                 flag[i][j]=2;}
            else
            {
                table[i][j]=table[i-1][j];
                flag[i][j]=3;
            }
        }
    }

    i=size1,j=size2;
    while(i>0&&j>0)
    {
        if(flag[i][j]==1)
        {
            cout<<str1[i-1]<<" ";
            --i;
            --j;
        }
        else if(flag[i][j]==2)
            --j;
        else
            --i;
    }
    cout<<endl;


    return table[size1][size2];
}
