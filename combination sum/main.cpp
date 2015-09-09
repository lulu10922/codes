#include <iostream>
#include<vector>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

void comb(vector<vector<int> >& res,vector<int>& onecombination, vector<int>& candidates,int index,int target)
{
    if(target==0)
    {
        res.push_back(onecombination);
        return;
    }
    if(target<0)
        return;

    for(int i=index;i<candidates.size();++i)
    {
        int newtarget=target-candidates[i];
        onecombination.push_back(candidates[i]);
        comb(res,onecombination,candidates,i,newtarget);
        onecombination.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {

        vector<vector<int> > res;
        vector<int> onecombination;

        std::sort(candidates.begin(), candidates.end());

        comb(res,onecombination,candidates,0,target);

        return res;
}
