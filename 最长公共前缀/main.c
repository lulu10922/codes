#include <stdio.h>
#include <stdlib.h>
//˵�����տ�ʼ���������ˣ����������ַ�������������������������������strsSizeΪ0��1������ҪС�Ĵ���
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0||strs==NULL)
      return "";
    if(strsSize==1)
      return *strs;

    int i,j=0;
    while(strs[0][j]!='\0')
    {
        int i=0;
        while(i<strsSize-1)
        {
            if (strs[i][j]==strs[i+1][j])
               i+=1;
            else
               break;
        }

        if(i==strsSize-1)
          j++;
        else
          break;
    }

//    char* res=malloc(sizeof(char)*(j+1));
//    for(i=0;i<j;i++)
//      res[i]=strs[0][i];
//    res[i]='\0';
    *(*strs+j)='\0';

    return *strs;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
