#include <stdio.h>
#include <stdlib.h>
//说明：刚开始理解错题意了，是找所有字符串的最长公共，而不是两个。另外对于strsSize为0或1的情形要小心处理。
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
