#include<stdio.h>
#include<stdlib.h>
//count frequency of each word in a string
struct word
{
    struct word *next;
    int count;
    char c[20];
};
int compare(char *c,char *str,int start,int end)
{
    int i;
    for(i=0;c[i]!='\0';i++)
    {
        if(start+i<=end)
        {
            if(c[i]!=str[start+i])
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    if(start+i==end+1)
        return 1;
    else
        return 0;
}
struct word * createnode(char *str,int start,int end)
{   
        struct word *new;
        new=(struct word*)malloc(sizeof(struct word)*1);
        char *x=new->c;
        int ind=0;
        for(int i=start;i<=end;i++)
        {
            x[ind]=str[i];
            ind++;
        }
        x[ind]='\0';
        new->count=1;
        new->next=NULL;
        return new;
}
void findstring(struct word **hash,char *str,int start,int end)
{
    int x=str[start];
    if(str[start]>='a'&&str[start]<='z')
    {
        x=x-71;
    }
    else
    {
        x=x-65;
    }
    if(hash[x]==NULL)
    {
        hash[x]=createnode(str,start,end);
        if(hash[x]==NULL)
        {
            printf("Error\n");
        }
    }
    else
    {
        struct word *p=hash[x];
        for(;;p=p->next)
        {
            if(compare(p->c,str,start,end))
            {
                p->count=p->count+1;
                return;
            }
            if(p->next==NULL)
            break;
        }
        p->next=createnode(str,start,end);
    }   
}
int main()
{
    printf("Enter string\n");
    char str[200];
    scanf("%[^\n]s",str);
    struct word **hash;
    hash=(struct word**)malloc(sizeof(struct word*)*52);
    int i,startind=0,endindex=0;
    for(i=0;i<52;i++)
    {
        hash[i]=NULL;
    }
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
           findstring(hash,str,startind,endindex);
        }
        else if((!((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z')))&&((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')))
        {
            startind=i;
        }
    }
    if((str[i-1]>='a'&&str[i-1]<='z')||(str[i-1]>='A'&&str[i-1]<='Z'))
    {
        endindex=i-1;
        findstring(hash,str,startind,endindex);
    }
    //printing frequency
    for(i=0;i<52;i++)
    {
        if(hash[i]!=NULL)
        {
            struct word *p=hash[i];
            for(;;p=p->next)
            {
                printf("%s has a frequency of %d\n",p->c,p->count);
                if(p->next==NULL)
                break;
            }
        }
    }
    return 0;
}