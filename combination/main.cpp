#include <iostream>
#include<vector>

using namespace std;


//index表示index已经push进了onecombination，所以循环时i从index+1开始，循环中递归时，index的值设为i而不是i+1!!!
//index和count各有各的作用，刚开始把两个混为了一个count，i的起始位置也利用count获得，这是不对的
void comb(vector<vector<int> >& res,vector<int> onecombination,int k,int n,int count,int index)
{
    if(count==k)
    {
        res.push_back(onecombination);
        return;
    }

    for(int i=index+1;i<=n;i++)
    {
        onecombination.push_back(i);
        comb(res,onecombination,k,n,count+1,i);
        onecombination.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
      vector<vector<int> > res;
      if(n<k)
        return res;

      vector<int> onecombination;
      comb(res,onecombination,k,n,0,0);

      return res;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
