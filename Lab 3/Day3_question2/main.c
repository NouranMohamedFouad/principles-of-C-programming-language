#include <stdio.h>
#include <stdlib.h>

//getting maximum and minimum values of an array


#define SIZE 5


int main()
{
    int array[SIZE];
    for(int i=0;i<SIZE;i++){
        printf(" please enter element %d: ",i+1);
        scanf("%d",&array[i]);
    }
    int max=array[0],min=array[0];
    for(int i=0;i<SIZE;i++)
    {
        if(min>array[i])
        {
            min=array[i];
        }
        if(max<array[i])
        {
            max=array[i];
        }
    }

    printf("maximum number is %d , and minimum number is %d",max,min);
    return 0;
}
