#include<stdio.h>
int num(int p)
{
    int q=0;/*此数为2的q次方*/
    while(p!=1)
    {
       p=p/2;
       q++;
    }
    return q;
}
int add(int a)
{
    int num1=0;
    while((a&a-1)!=0)/*若为2的次方a&a-1应等于0*/
    {
        a=a+1;
        num1=num1+1;
    }
    return num1/*+个数*/
}
int reduce(int a)
{
    int num2=0;
    while((a&a-1)!=0)
    {
        a=a-1;
        num2=num2+1;
    }
    return num2;/*-个数*/
}
void dividenum(int n)
{
    int b=1;
    while(b<=n)
    {
        printf("^");
        b++;
    }
}
void addnum(int n,int a)
{
    int b=1;
    while(b<=add(a))
    {
        printf("+");
        b++;
    }
}
void reducenum(int n,int a)
{
    int b=1;
    while(b<=reduce(a))
    {
        printf("-");
        b++;
    }
}
int main()
{
    int a,n,b=1;
    printf("input\n");
    scanf("%d",&a);
    printf("output\n");
    if((a&a-1)==0)/*若为2的次方a&a-1应等于0*/
    {
        n=num(a);/*^个数*/
        printf("%d\n",n);
        dividenum(n);
    }
    else
    {
        if(add(a)<reduce(a))
        {
            n=num(a+add(a));/*^个数*/
            printf("%d\n",n+add(a));
            addnum(n,a);
            dividenum(n);
        }
        else
        {
            n=num(a-reduce(a));
            printf("%d\n",n+reduce(a));
            reducenum(n,a);
            dividenum(n);
        }
    }
   return 0;
}
