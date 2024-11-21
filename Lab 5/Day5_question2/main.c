#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#endif
#include <unistd.h>     // for isatty()
#endif

#include <stdlib.h>
#include <stdio.h>

#define NAMESIZE 50
#define EMPLOYEESIZE 50


// use an enum for platform-independent interface:
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;

// set output color on the given stream:
void setTextColor(FILE *stream, TextColor color);
void gotoxy(int,int);

typedef struct Employee{
	char name[NAMESIZE];
	int code;
	int salary;
}Employee;

int main(void)
{
    Employee employees[EMPLOYEESIZE]={0};
    int employeesCreated=0;
    int flag=1,row=1,col=1;
    gotoxy(col*55,row*10);
    setTextColor(stdout,14); // Light BROWN color as a default
    printf("New");
    gotoxy(col*55,(row*10)+5);
    setTextColor(stdout,6); // Light BROWN color as a default
    printf("Display");
    gotoxy(col*55,(row*10)+10);
    printf("Modify");
    gotoxy(col*55,(row*10)+15);
    printf("Exit");
    row=1;
    gotoxy(col*55,row*10);


    while(flag){
        char click = 0;
        click = getch();
        if(click==-32) // extended keys
        {
            click=getch();
            if(click==72) // up
            {
                if(row==1) //first row
                {
                    row=16;
                }
                else {
                    row-=5;  // Move up
                }

            }
            else if(click==80) // down
            {
                if(row==16)
                {
                    row=1;
                }
                else
                {
                    row+=5;
                }

            }
            else if(click==71) // home button
            {
                row=1;  //will go to new
            }
            else if(click==79) // end button
            {
                row=16;  //will go to exit
            }

            //going to the place i chose (up 2w down)
            if(row==1)
            {
                setTextColor(stdout,14);
                system("cls");
                gotoxy(55,10);
                printf("New");
                setTextColor(stdout,6);
                gotoxy(55,15);
                printf("Display");
                gotoxy(55,20);
                printf("Modify");
                gotoxy(55,25);
                printf("Exit");
            }
            else if(row==6)
            {
                system("cls");
                setTextColor(stdout,6);
                gotoxy(55,10);
                printf("New");
                setTextColor(stdout,14);
                gotoxy(55,15);
                printf("Display");
                setTextColor(stdout,6);
                gotoxy(55,20);
                printf("Modify");
                gotoxy(55,25);
                printf("Exit");
            }
            else if(row==11)
            {
                setTextColor(stdout,6);
                system("cls");
                gotoxy(55,10);
                printf("New");
                setTextColor(stdout,6);
                gotoxy(55,15);
                printf("Display");
                setTextColor(stdout,14);
                gotoxy(55,20);
                printf("Modify");
                setTextColor(stdout,6);
                gotoxy(55,25);
                printf("Exit");
            }
            else
            {
                setTextColor(stdout,6);
                system("cls");
                gotoxy(55,10);
                printf("New");
                setTextColor(stdout,6);
                gotoxy(55,15);
                printf("Display");
                setTextColor(stdout,6);
                gotoxy(55,20);
                printf("Modify");
                setTextColor(stdout,14);
                gotoxy(55,25);
                printf("Exit");
            }
        }
        else if (click==13) // enter button
        {
            system("cls");
            setTextColor(stdout,6);
            if (row==1)
            {
                gotoxy(col*55,1);

                int sizee=0;
                printf("\nplease enter the number of employees you want to insert:");
                scanf("%d",&sizee);
                employeesCreated=intEnterEmployee(employees,sizee,employeesCreated);
            }
            else if(row==6)
            {
                gotoxy(col*45,1);
                if(employeesCreated==0){
                    setTextColor(stdout,4);
                    printf("\nThere is no employees right now!\n");
                    setTextColor(stdout,6);
                }
                for(int j=0;j<employeesCreated;j++)
                {
                    printf("\nnumber %d) Employee's name:%s \n",j+1,employees[j].name);
                    printf("number %d) Employee's code:%d \n",j+1,employees[j].code);
                    printf("number %d) Employee's salary:%d \n",j+1,employees[j].salary);
                }
            }
            else if(row==11)
            {
                 gotoxy(col*45,1);
                if(employeesCreated==0){
                    setTextColor(stdout,4);
                    printf("\nCannot Modify Cause there is no employees right now!\n");
                    setTextColor(stdout,6);
                }
                for(int j=0;j<employeesCreated;j++)
                {
                    printf("\nnumber %d) Employee's name:%s \n",j+1,employees[j].name);
                    printf("number %d) Employee's code:%d \n",j+1,employees[j].code);
                    printf("number %d) Employee's salary:%d \n",j+1,employees[j].salary);
                }
                voidModifyEmployee(employees);

            }
            else
            {
                gotoxy(col*45,10);
                setTextColor(stdout,11);
                printf("THANKS FOR TRYING MY PROGRAM!");
                setTextColor(stdout,6);
                Sleep(1500);
                exit(0);
            }
            char click=getch();
            if (click==83) //delete button
            {
                system("cls");
                row =1,col =1;
                gotoxy(col*55,row*10);
                setTextColor(stdout,6);
                printf("New");
                gotoxy(col*55,(row*10)+5);
                printf("Display");
                gotoxy(col*55,(row*10)+10);
                printf("Exit");
                row=1;
                gotoxy(col*55,row*10);
            }
        }
        else if(click==8) //backspace button
        {
            flag=0;
        }
    }
    return EXIT_SUCCESS;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int intEnterEmployee(Employee e[],int sizee,int currentIndex)
{
    int flag=1;
    char choice=0,counter=0,check;
    int i=currentIndex;
    while(i<sizee && flag)
    {
        int intSalaryChecker=1,intCodeChecker=1;
        printf("\nplease enter Employee's code: ");
        while(intCodeChecker)
         {
            int num=0;
            if((scanf("%d%c", &num,&check)==2 && check=='\n'))
            {
                if(num<=0){
                    printf("\nplease enter a positive number of code: ");
                    fflush(stdin);
                }
                else
                {
                    int isUnique=1;
                    for(int j=0;j<EMPLOYEESIZE && isUnique ;j++){
                        if(e[j].code==num){
                            isUnique=0;
                            printf("\nThis code is already taken,please enter another one: ");
                        }
                    }
                    if(isUnique)
                    {
                        e[i].code=num;
                        intCodeChecker=0;
                    }
                    else
                    {
                        fflush(stdin);
                    }

                }
            }
            else
            {
                printf("\nplease enter only numbers for code: ");
                fflush(stdin);
            }
        }
        printf("please enter Employee's name: ");
        scanf(" %s",e[i].name);

        printf("please enter Employee's salary: ");
         while(intSalaryChecker)
        {
                if((scanf("%d%c", &e[i].salary, &check)==2 && check=='\n')){
                    if(e[i].salary<=0){
                        printf("\nplease enter a positive number of salary: ");
                         fflush(stdin);
                    }
                    else{
                        intSalaryChecker=0;
                    }
                }
                else{
                    printf("\nplease enter only numbers for salary: ");
                    fflush(stdin);
                }
        }


        printf("press y to continue or n to exit: ");
        scanf(" %c", &choice);
        while(choice!='y' && choice!='Y' && choice!='n' && choice!='N')
        {
            setTextColor(stdout,4);
            printf("\nplease press only  y or n: ");
            scanf(" %c", &choice);
        }
        setTextColor(stdout,6);

        if( choice=='N' || choice=='n'){
            setTextColor(stdout,2);
            printf("\nyou inserted %d Employees successfully ",counter+1);
            flag=0;
            setTextColor(stdout,6);
        }
        i++;
        counter++;
        if( choice=='Y' || choice=='y' && i==sizee){
            printf("\nyou already inserted all the employees you wanted");
            flag=0;
        }
    }
    return i;
}
//////////////////////////////////////////////////////////
void voidModifyEmployee(Employee e[])
{
    int flag=1;
    char counter=0,check;
    while(flag)
    {
        int intSalaryChecker=1,intCodeChecker=1;
        char choice=0;

        int id=0;
        printf("\nplease enter the code of the Employee you want to modify: ");
        while(intCodeChecker)
        {
            int num=0;
            if((scanf("%d%c", &num,&check)==2 && check=='\n'))
            {
                if(num<=0){
                        printf("\nplease enter a positive number of code: ");
                         fflush(stdin);
                }
                else{
                    int isFound=0;
                    for(int j=0;j<EMPLOYEESIZE && !isFound ;j++){
                        if(e[j].code==num){
                            isFound=1;
                            id=j;
                        }
                    }
                    if(isFound)
                    {
                        intCodeChecker=0;
                    }
                    else{
                        printf("\ncode is not present please enter a valid code: ");
                        fflush(stdin);
                    }

                }


            }
            else
            {
                printf("\nplease enter only numbers for code: ");
                fflush(stdin);
            }
        }

        char c=0;
        printf("\nplease choose 1 to modify name ,and 2 to modify salary: ");
        scanf(" %c",&c);
        while(c!='1' && c!='2')
        {
            setTextColor(stdout,4);
            printf("\nplease press only  1 or 2: ");
            scanf(" %c", &c);
        }
        setTextColor(stdout,6);
        if(c=='1'){
            printf("\nplease enter the name to be modified: ");
            scanf(" %s",e[id].name);
        }
        else if(c=='2'){
            printf("\nplease enter the salary to be modified: ");
            while(intSalaryChecker)
             {
                if((scanf("%d%c", &e[id].salary, &check)==2 && check=='\n')){
                    if(e[id].salary<=0){
                        printf("\nplease enter a positive number of salary: ");
                         fflush(stdin);
                    }
                    else{
                        intSalaryChecker=0;
                    }
                }
                else{
                    printf("\nplease enter only numbers for salary: ");
                    fflush(stdin);
                }
            }
        }
        printf("\npress y to continue or n to exit: ");
        scanf(" %c", &choice);
        while(choice!='y' && choice!='Y' && choice!='n' && choice!='N')
        {
            setTextColor(stdout,4);
            printf("\nplease press only  y or n: ");
            scanf(" %c", &choice);
        }
        setTextColor(stdout,6);

        if( choice=='N' || choice=='n'){
            setTextColor(stdout,2);
            printf("\nyou made %d modifications successfully ",counter+1);
            flag=0;
            setTextColor(stdout,6);
        }
        counter++;
    }
}


#ifdef _WIN32

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}

#else

static const char *ansiColorSequences[] =
{
    "\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m"
};

static const char *ansiColorTerms[] =
{
    "xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0
    // there are probably missing a few others
};

// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{
    char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        // we're directly outputting to a terminal supporting ANSI colors,
        // so send the appropriate sequence:
        fputs(ansiColorSequences[color], stream);
    }
}

#endif

