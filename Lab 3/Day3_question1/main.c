#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

//taking 1D array and printing it as 2D array
int main()
{
    int array[SIZE];
    for(int i=0;i<SIZE;i++){
        printf(" please enter element %d: ",i+1);
        scanf("%d",&array[i]);
    }

    int rows=0,cols=0;
    printf("please enter the number of rows you want: ");
    scanf("%d",&rows);

    while(SIZE%rows!=0)
    {
        printf("number of rows and columns must match the total size \nplease enter another number of rows: ");
        scanf("%d",&rows);
    }
    cols=SIZE/rows;

    printf("\nThe Result=\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int newIndex=i*cols+j;
            printf("%d \t",array[newIndex]);
        }
        printf("\n");
    }
    return 0;
}
