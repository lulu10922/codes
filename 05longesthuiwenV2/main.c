#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* longestPalindrome(char* s);
#define MIN(a,b) (a)<(b)?(a):(b)
int main()
{
    char s[10000];
    gets(s);
    printf("%s",longestPalindrome(s));
    return 0;
}
char* longestPalindrome(char* s)
{
    int len=strlen(s);
    int newslen=2*len+3;
    char newstr[newslen];

    newstr[0]='^';
    newstr[1]='#';
    int i=0,j=2;
    while(i<len)
    {
        newstr[j++]=s[i++];
        newstr[j++]='#';
    }
    newstr[j]='$';

    int mx=0;
    int id=0;
    int P[newslen];
    P[0]=0;
    for(i=1;i<newslen;++i)
    {
        if(i<mx)
        {
            P[i]=MIN(mx-i,P[2*id-i]);
        }
        else
            P[i]=0;
        while(newstr[i-P[i]-1]==newstr[i+P[i]+1])
            P[i]++;

        if(P[i]+i>mx)
        {
            mx=P[i]+i;
            id=i;
        }
    }

//    for(i=0;i<2*len;++i)
//    {
//        printf("%d ",P[i]);
//    }

    int max_index=0,max_len=0;
    for(i=0;i<2*len;i++)
    {
        if(P[i]>max_len)
        {
            max_len=P[i];
            max_index=i;
        }
    }

    int start,palinlen;
//    if(newstr[max_index-max_len]=='#')
//    {
//        start=(max_index-max_len+1-1)/2;
//        palinlen=max_len;
//    }
//    else
//    {
//        start=(max_index-max_len-1)/2;
//        palinlen=max_len+1;
//    }
    start=(max_index-max_len-1)/2;
    palinlen=max_len;

    char* ret=malloc(palinlen+1);
    for(i=0;i<palinlen;++i)
        ret[i]=s[start+i];
    ret[i]='\0';

    return ret;
}
