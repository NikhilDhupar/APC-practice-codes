#include<stdio.h>
//checking the longest word of the string
int main()
{
    printf("Enter string\n");
    char str[100];
    scanf("%[^\n]s",str);
    int startind=0,endindex=0,size=0,i;
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
            if(i-startind>size)
            {
                endindex=i-1;
                size=endindex-startind;
            }
        }
        else if((!((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z')))&&((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')))
        {
            startind=i;
        }
    }
    startind=endindex-size;
    for(i=startind;i<=endindex;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}