#include <iostream>

using namespace std;
//利用栈，左括号都压栈，右括号时判断栈顶是否是对应左括号，此时应注意先判断栈是否空！！！否则栈顶是没意义的，得到的答案也会是错的
//若栈为空或栈顶不匹配则返回false。当字符串进行完毕还没返回false，再看栈是否为空，不为空false，为空true。
class Solution {
public:
    bool isValid(string s) {
        stack<char> data;
        string::iterator ite=s.begin();
        while(ite!=s.end())
        {
            if(*ite=='('||*ite=='{'||*ite=='[')
              data.push(*ite);
            else if(*ite==')')
            {
                if(data.size()==0||data.top()!='(')
                  return 0;
                else
                  data.pop();
            }
            else if(*ite==']')
            {
                if(data.size()==0||data.top()!='[')
                  return 0;
                else
                  data.pop();
            }
            else if(*ite=='}')
            {
                if(data.size()==0||data.top()!='{')
                  return 0;
                else
                  data.pop();
            }
            ite++;
        }
        if(!data.empty())
          return 0;
        else
          return 1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
