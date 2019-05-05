//Eliminating extra spaces to convert given string into a proper sentence format
#include <stdio.h>
#include <string.h>
void compress(char *s,int start,int end)
{
    //int i;
    for(;s[end]!='\0';end++)
    {
        s[start]=s[end];
        start++;
    }
    s[start]='\0';
}
void makesentence(char *s)
{
    int i,start=-1,end=-1;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            start=i;
            break;
        }
    }
    if(start!=0)
    {
        compress(s,0,start);
    }
    for(;s[i]!='\0';i++)
    {
        if(s[i]==' '&&s[i-1]!=' ')
        start=i;
        else if(s[i]!=' '&&s[i-1]==' ')
        {
            end=i-1;
            if(end!=start)
            {
                compress(s,start,end);
                i=start+1;
            }
        }
    }
    if(s[i-1]==' ')
    {
        s[start]='\0';
    }
}
int main ()
{
    char str[200];
    printf("Enter string\n");
    scanf("%[^\n]s",str);
    makesentence(str);
    printf("%s",str);
}