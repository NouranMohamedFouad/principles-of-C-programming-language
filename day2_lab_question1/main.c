#include <stdio.h>
#include <stdlib.h>

int main()
{
    // constant for each row,col,and diagonal = n*(n^2 +1)/2
    // if n=3 ,so the matrix will contain numbers 1...9
    //rule: number 1 always stored in (n/2,n-1)
    // i moves anti-clock wise , while j moves clock wise
    printf("please enter the number of the Magic Square: ");
    int num=0;
    scanf("%d",&num);

    int magicSquare[num][num];

    int i=0,j=0;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            magicSquare[i][j]=0;
        }
    }

    ////////////////////////////////////////////////////

    //first value always to be (num/2,num-1)
    int row=num/2;
    int column=num-1;
    magicSquare[row][column]=1;

    //starting from al 2nd number
    int counter=2;
    i=1;
    while(i<num*num)
    {
        row-=1;
        column+=1;
        while(magicSquare[row][column]!= 0)
        {
            row+=1;
            column-=2;
            if(row== -1)
            {
                row=num-1;
            }
            if(column==num)
            {
                column=0;
            }
            if(row== -1 && column==num)
            {
                row=0;
                column=num-2;
            }
        }
        if(row== -1)
        {
            row=num-1;
        }
        if(column==num)
        {
            column=0;
        }
        if(row== -1 && column==num)
        {
            row=0;
            column=num-2;
        }
        if(magicSquare[row][column]== 0)
        {
            magicSquare[row][column]=counter++;
        }
        i++;
    }


    i=0,j=0;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("num %d %d  ",i,j);


            printf("%d \t",magicSquare[i][j]);
        }
        printf("\n");

    }

    return 0;
}
