//calculate power of number
#include<stdio.h>
//method1 - using loops
/*
int main()
{
    printf("Enter number\n");
    int n,p;
    scanf("%d",&n);
    printf("Enter power");
    scanf("%d",&p);
    int res=n;
    while(p!=1)
    {
        if(p%2==0)
        {
            res=res*res;
            p=p/2;
        }
        else
        {
            {
                res=res*res*n;
                p=p/2;
            }
        }
    }
    printf("Result is %d\n",res);
    return 0;
}
*/
//method 2 - using recursion
int power(int n,int p)
{
    if(p==1)
    return n;
    else if(p%2==0)
    {
        int res=power(n,p/2);
        return res*res;
    }
    else
    {
        {
            int res=power(n,p/2);
        return n*res*res;
        }
    }
}
int main()
{
    int n,p;
    printf("Enter number\n");
    scanf("%d",&n);
    printf("Enter power");
    scanf("%d",&p);
    int res=power(n,p);
    printf("Result is %d\n",res);
    return 0;
}