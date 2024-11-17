#include <stdio.h>
#include <stdlib.h>

int main()
{
    //question 3
    printf("Please choose from a or b or c \n\n");

    printf("**********************\n");
    printf("* a.Computer science *\n");
    printf("* b.Pharmacy         *\n");
    printf("* c.Business         *\n");
    printf("**********************\n\n");
    printf("Please enter your choice: ");

    char choice=0;
    scanf(" %c",&choice);
    switch(choice){
      case 'a':
        printf("your choice is a, Computer science");
      break;
      case 'b':
        printf("your choice is b, Pharmacy");
      break;
     case 'c':
        printf("your choice is c, Business");
      break;
      default:
        printf("Not A Valid Choice");
      break;
    }

    return 0;
}
