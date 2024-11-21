#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main()
{
    int matrix[ROWS][COLS];
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++)
        {
            int intValidationChecker=1;
            char check;
             printf("enter matrix[%d][%d]:",i,j);
              int flag=1,num;
                while(flag){
                    if(scanf("%d", &num)){
                        matrix[i][j]=num;
                        flag=0;
                    }else{
                         printf("%d is a invalid number,please enter another : ",  matrix[i][j]);
                        while(getchar()!= '\n');
                    }
                }
        }
    }


    for(int i=0;i<ROWS;i++) {
        int sum=0;
        for(int j=0;j<COLS;j++)
        {
            sum+=matrix[i][j];
        }
        printf("sum of row %d: %d \n",i,sum);
        printf("\n");
    }

    for(int i=0;i<COLS;i++) {
        int sum=0;
        for(int j=0;j<ROWS;j++)
        {
            sum+=matrix[i][j];
        }
        printf("average of column %d: %d \n",i,sum/ROWS);
        printf("\n");
    }

    return 0;
}
