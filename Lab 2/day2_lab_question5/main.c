#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=10,j=1;
    int x=1;
    for(i=10;i>0;i--)
    {
        printf("\n\ntable number : %d's",i);
        for(j=1;j<=10;j++)
        {
            x=i*j;
            printf("\n\nresult of %d,%d = %d",i,j,x);
        }
        printf("\n\nend of table %d",i);
        printf("\n***************************************");
    }
    return 0;
}
