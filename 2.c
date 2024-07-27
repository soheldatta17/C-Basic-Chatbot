#include<stdio.h>
int a(int b)
{
    if(b==0)
    {
        return b;
    }
    b--;
    a(b);
    printf("%d\n",b);
}
void main()
{
    int x=a(10);
    printf("%d",x);
}