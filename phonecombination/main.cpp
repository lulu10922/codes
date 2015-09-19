#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

//还是用回溯法，注意输入大小为0时的情况
class Solution {
public:
void dfs(vector <string> & res,string & tmp,string digits,int cur,int size,unordered_map<char,string> map)
{
    if(cur==size)
    {
        res.push_back(tmp);
        return;
    }

    string s=map[digits[cur]];
    for(int i=0;i<s.size();i++)
    {
        tmp.push_back(s[i]);
        dfs(res,tmp,digits,cur+1,size,map);
        tmp.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    unordered_map<char,string> map;
    map['2']="abc",map['3']="def",map['4']="ghi",map['5']="jkl",map['6']="mno",map['7']="pqrs",map['8']="tuv",map['9']="wxyz";
    vector<string> res;
    string tmp;

    if(digits.size()==0)
      return res;

    dfs(res,tmp,digits,0,digits.size(),map);

    return res;
}

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
