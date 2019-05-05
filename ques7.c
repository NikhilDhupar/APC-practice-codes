#include<stdio.h>
//reversing each word in the given string
void reversestring(char *str,int startindex,int endindex)
{
    if(endindex-startindex<=0)
    {
        return;
    }
    else
    {
        char c;
        c=str[endindex];
        str[endindex]=str[startindex];
        str[startindex]=c;
        reversestring(str,startindex+1,endindex-1);
    }
}
int main()
{
    printf("Enter string\n");
    char str[100];
    scanf("%[^\n]s",str);
    int startind=0,endindex=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
        {
            startind=i;
            i++;
            break;
        }
    }
    for(;str[i]!='\0';i++)
    {
        if((!((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')))&&((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z')))
        {
           endindex=i-1;
           reversestring(str,startind,endindex);
        }
        else if((!((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z')))&&((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')))
        {
            startind=i;
        }
    }
    printf("%s",str);
    return 0;
}