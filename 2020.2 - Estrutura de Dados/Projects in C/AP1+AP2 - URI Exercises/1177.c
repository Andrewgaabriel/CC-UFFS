#include <stdio.h>
int main()
{
    int n[1000], x, y, a;
    scanf ("%d", &x);
    for(y=0,a=0; y<1000; y++)
    {
        printf("N[%d] = %d\n",y,a);
        a++;
        if(a==x)
            a=0;
    }
    return 0;
}
