
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x,int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

int main()
{
    int num=0;
    printf("enter the size of the matrix(size must be odd):");

    scanf("%d",&num);
    while(num%2==0){
        printf("this number is not an odd number,please enter odd number: ");
        scanf("%d",&num);
    }
     printf("\n");
    int row=1,col=(num+1)/2;
    for(int i=1;i<=num*num;i++){
        gotoxy(col*4,row);
        Sleep(1500);
        printf("%d \t",i);
        if(i%num==0){
            row++;
        }
        else{
            row --;
            col --;
            if(row<1)
                row=num;
            if(col<1)
                col=num;
        }
    }
    return 0;

}
