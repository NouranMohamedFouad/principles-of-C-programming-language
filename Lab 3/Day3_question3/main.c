#include <stdio.h>
#include <stdlib.h>

//recursion function

int powerOperation(int num,int power)
{
    if(power==0){
        return 1;
    }
    else{
        // 3 3 -> 3   3 2 -> 3   3 1 -> 3   3 0 -> 1
        return num*powerOperation(num,power-1);
    }
}


int main()
{
    int num=0,power;
    printf("please enter the number: ");
    scanf(" %d",&num);

    if(num==0){
        printf("\n0 to the power anything is 0 \nplease enter another number: ");
        scanf(" %d",&num);
    }

    printf("\nplease enter the power: ");
    scanf(" %d",&power);

    printf("\n%d power %d is %d",num,power,powerOperation(num,power));
    return 0;
}
