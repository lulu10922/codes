#include <iostream>

using namespace std;
//����ջ�������Ŷ�ѹջ��������ʱ�ж�ջ���Ƿ��Ƕ�Ӧ�����ţ���ʱӦע�����ж�ջ�Ƿ�գ���������ջ����û����ģ��õ��Ĵ�Ҳ���Ǵ��
//��ջΪ�ջ�ջ����ƥ���򷵻�false�����ַ���������ϻ�û����false���ٿ�ջ�Ƿ�Ϊ�գ���Ϊ��false��Ϊ��true��
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
