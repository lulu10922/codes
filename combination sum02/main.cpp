#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


void comb(vector<vector<int> >& res,vector<int>& onecombination, vector<int>& candidates,int index,int target)
{
    if(target==0)
    {
        res.push_back(onecombination);
        return;
    }
    if(target<0)
        return;

    for(int i=index;i!=candidates.size();++i)
    {
      if(i==index||candidates[i]!=candidates[i-1])
      {
        int newtarget=target-candidates[i];
        onecombination.push_back(candidates[i]);
        comb(res,onecombination,candidates,i+1,newtarget);
        onecombination.pop_back();
      }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int> > res;
        vector<int> onecombination;

        sort(candidates.begin(), candidates.end());

        comb(res,onecombination,candidates,0,target);

        return res;
}


int main()
{
    int a[]={1};
    vector<int> candidates(a,a+1);
    vector<vector<int> > res=combinationSum2(candidates,2);
    int r;
    r=res.size();
    for (int i=0;i<r;i++)
    {for(int j=0;j<res[i].size();j++)
        cout<<res[i][j]<<" ";
      cout<<endl;
    }

    return 0;
}
