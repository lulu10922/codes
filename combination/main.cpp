#include <iostream>
#include<vector>

using namespace std;


//index��ʾindex�Ѿ�push����onecombination������ѭ��ʱi��index+1��ʼ��ѭ���еݹ�ʱ��index��ֵ��Ϊi������i+1!!!
//index��count���и������ã��տ�ʼ��������Ϊ��һ��count��i����ʼλ��Ҳ����count��ã����ǲ��Ե�
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
