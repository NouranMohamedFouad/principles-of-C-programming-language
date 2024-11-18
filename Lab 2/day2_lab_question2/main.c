#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Question 2
    int sum=0;
    int num=0;
    do{
        num=0;
        printf("\n please enter number :");
        scanf("%d",&num);
        sum+=num;

    }while(sum<=100);
    printf("\n you exceeded 100");
    printf("\n total sum = %d",sum);
    return 0;
}
