#include<stdio.h>
//find reverse of a number
int reversemethod1(int n,int sum)
{
    if(n<10)
    return n+sum;
    else
    {
        sum+=n%10;
        return reversemethod1(n/10,sum*10);
    } 
}
int reversemethod2(int n,int *p)
{
    if(n<10)
    {
        *p=1;
        return n;
    }
    else
    {
        int sum=n%10;
        int rev=reversemethod2(n/10,p);
        *p=(*p)*10;
        sum=sum*(*p);
        return sum+rev;
    }
}
int main()
{
    int num,p=1;
    printf("Enter number\n");
    scanf("%d",&num);
    printf("Reverse of the given number is %d\n",reversemethod1(num,0));
    printf("Reverse of the given number is %d\n",reversemethod2(num,&p));
    return 0;
}