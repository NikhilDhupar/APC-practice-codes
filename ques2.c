//calculating sum of digits using recursion
#include<stdio.h>
int calculatemethod1(int n)
{
    if(n<10)
    return n;
    else
    {
        return (n%10)+calculatemethod1(n/10);
    }
}
int calculatemethod2(int n,int s)
{
    if(n<10)
    return n+s;
    else
    {
        s=s+n%10;
        return calculatemethod2(n/10,s);
    }
}
int main()
{
    int num;
    printf("Enter number\n");
    scanf("%d",&num);
    //int sum=calculatemethod2(num);
    printf("Sum of all the digits of number %d using method1 is %d\n",num,calculatemethod1(num));
    printf("Sum of all the digits of number %d using method2 is %d\n",num,calculatemethod2(num,0));
    return 0;
}