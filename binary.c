#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
    char a[40];
    int i;
    printf("\nEnter the no. in binary: ");
    scanf("%s",a);
    printf("\n");
    int n=strlen(a);
    int c=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!='.')
        {
            c=c+1;
        }
        else
        {
            break;
        }
    }

    float s=0.0,z;
    int f=0,m=0,b=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]=='.')
        {
            f=1;
            printf(".\n");
        }
        if(f==0)
        {
            if(a[i]=='1')
            {
                m=pow(2,c-1-i);
                s=s+m;
                printf("2^%d  x 1 = %d\n",c-1-i,m);
            }
            if(a[i]=='0')
            {
                printf("2^%d  x 0 = 0\n",c-1-i);
            }
        }
        else
        {
           if(a[i]=='1')
            {
                z=pow(2,b);
                s=s+z;
                printf("2^%d x 1 = %f\n",b,z);
                b=b-1;
                
            }
            if(a[i]=='0')
            {
                printf("2^%d x 0 = 0\n",b);
                b=b-1;
            } 
        }
    }
    printf("\nDecimal = %f\n",s);
}