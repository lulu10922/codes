#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char* addBinary(char* a, char* b) {
    int len1=strlen(a);
    int len2=strlen(b);
    int max;
    max=len1>len2?len1:len2;
    char* res=malloc(sizeof(char)*(max+1));

    int flag=0;
    int k=max-1;
    int i,j;
    for(i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
    {
        int sum;
        if(i>=0&&j>=0)
           sum=a[i]-'0'+b[j]-'0'+flag;
        if(i>=0&&j<0)
            sum=a[i]-'0'+flag;
        if(i<0&&j>=0)
            sum=b[j]-'0'+flag;

        if(sum>=2)
        {
            res[k--]=sum-2+'0';
            flag=1;
        }
        else
        {
            res[k--]=sum+'0';
            flag=0;
        }
    }

    res[max]='\0';

    if(flag==1)
    {
        res[0]='1';
        return res;
    }
    else
    {
        for(i=0;i<max;i++)
            res[i]=res[i+1];
        return res;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
