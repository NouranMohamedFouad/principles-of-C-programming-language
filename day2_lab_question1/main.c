#include <stdio.h>
#include <stdlib.h>

int main()
{
    // constant for each row,col,and diagonal = n*(n^2 +1)/2
    // if n=3 ,so the matrix will contain numbers 1...9
    // i moves anti-clock wise , while j moves clock wise
    printf("please enter the number of the Magic Square(must be odd number): ");
    int num=0;
    scanf("%d",&num);
    if(num%2==0){
        printf("sorry this is not an odd number!");
        return;
    }

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

    int row=0;
    int column=num/2;
    magicSquare[row][column]=1;

    //starting from al 2nd number

    i=2;
    while(i<=num*num)
    {
        row-=1;
        column+=1;

        if(row<= -1 && column>=num)
        {
            row+=2;
            column--;
        }
        else if(column>=num)
        {
            column=0;
        }
        else if(row<= -1)
        {
            row=num-1;
        }
        if(magicSquare[row][column]!= 0)
        {
            row+=2;
            column-=1;
        }
        magicSquare[row][column]=i;

        i++;
    }

    i=0,j=0;
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            printf("%d \t",magicSquare[i][j]);
        }
        printf("\n");
    }
    return 0;
}
