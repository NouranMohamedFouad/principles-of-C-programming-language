#include <stdio.h>
#include <stdlib.h>



void swap1(int * x,int * y){
    printf("before swap: x=%d , y=%d \n",*x,*y);

    *x=abs(*x)+abs(*y);
    *y=abs(*y)-abs(*x);
    *x=abs(*x)-abs(*y);
    *x=abs(*x);
    *y=abs(*y);
    printf("after swap: x=%d , y=%d",*x,*y);
}
///////////////////////////////////////////////////////
void swap2(int * x,int * y){
    printf("before swap: x=%d , y=%d \n",*x,*y);

    *x = *x * *y;
    *y = *x / *y;
    *x = *x / *y;

    printf("after swap: x=%d , y=%d",*x,*y);
}
///////////////////////////////////////////////////////
void swap3(int * x,int * y){
    printf("before swap: x=%d , y=%d \n",*x,*y);
    *y=abs(*y)+abs(*x);
    *x=abs(*x)-abs(*y);
    *y=abs(*x)-abs(*y);
    *x=abs(*x);
    *y=abs(*y);


    printf("after swap: x=%d , y=%d",*x,*y);
}
///////////////////////////////////////////////////////
void swap4(int * x,int * y){
    printf("before swap: x=%d , y=%d \n",*x,*y);

    *y = *y * *x;
    *x = *y / *x;
    *y = *y / *x;

    printf("after swap: x=%d , y=%d",*x,*y);
}

int main()
{

    int x=5,y=6;
    swap4(&x,&y);

    return 0;
}
