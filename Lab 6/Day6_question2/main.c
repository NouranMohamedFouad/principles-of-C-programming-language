#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


#define SIZE 10
#define TERMINATOR '\0'

void setCursorType(int isInsertMode)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    if (isInsertMode)
    {
        cursorInfo.dwSize = 25;
    }
    else
    {
        cursorInfo.dwSize = 100;
    }
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    char input[SIZE]={0};
    int position=0,length=0,row=2,col=0,flag=1,insertMode=0;
    gotoxy(col,row);
    printf("please enter your input: "); //25 letters ,col+25
    col=25;
    gotoxy(col,row);

    while(flag)
    {
            char click=0;
            click=getch();
            if(click==-32) // extended keys
            {
                click=getch();

                if (click==71) //  home
                {
                    position=0;
                    gotoxy(25+position,row);
                }
                else if (click==79) //  end
                {
                    position=length;
                    gotoxy(25+position,row);
                }
                else if(click==75) // left
                {
                    if(position<=0){
                            position=0;
                            col=25;
                     }
                    else{
                         position--;
                         col=25+position;
                         gotoxy(col,row);
                    }
                }
                else if (click==77)  //right
                {
                    if(position<length)
                    {
                        position++;
                        col=25+position;
                        gotoxy(col,row);
                    }
                }
                else if (click==83) // Delete
                {

                        if(position<length){
                            for(int i=position; i<length-1; i++)
                            {
                                input[i]=input[i+1];
                            }
                            input[length-1]=TERMINATOR;
                            length--;
                            system("cls");
                            if(insertMode)
                            {
                                gotoxy(0,1);
                                printf("in insert mode: ");

                            }
                            gotoxy(0,row);
                            printf("please enter your input: ");
                            printf("%s",input);
                            gotoxy(25+position,row);

                    }
                }
            }
            else if(click==8) // Backspace
            {
                if(!insertMode)
                {
                    if(position>0)
                    {
                        for(int i=position-1;i<length-1;i++)
                        {
                            input[i]=input[i+1];
                        }
                        input[length-1]=TERMINATOR;
                        length--;
                        position--;
                        system("cls");
                        gotoxy(0,row);
                        printf("please enter your input: ");
                        printf("%s",input);
                        gotoxy(25+position,row);
                    }
                }
            }
            else if(click>=32 && click<=126) // normal keys
            {
                if(!insertMode)
                {
                    if(length<SIZE-1)
                    {
                        length++;
                        input[length-1]=TERMINATOR;
                        for(int i=length-1;i>position;i--)
                        {
                            input[i]=input[i-1];
                        }
                        input[position]=click;
                        position++;
                        system("cls");
                        gotoxy(0,row);
                        printf("please enter your input: ");
                        printf("%s",input);
                        gotoxy(25+position,row);
                    }
                }
                else if(insertMode)
                {
                     if(length<SIZE-1)
                    {
                        if(input[position]==0) //m4 bt overwrite al adeem
                        {
                            length++;
                            input[length-1]=TERMINATOR;
                        }
                        input[position]=click;
                        position++;
                        system("cls");
                        gotoxy(0,1);
                        printf("in insert mode: ");
                        gotoxy(0,row);
                        printf("please enter your input: ");
                        printf("%s",input);
                        gotoxy(25+position,row);
                    }
                }
            }
            if(click==9) //9 lel tab key
            {
                insertMode=!insertMode;
                if(insertMode){
                    gotoxy(0,1);
                    printf("in insert mode: ");
                    gotoxy(25+position,row);

                }
                else if(!insertMode)
                {
                    system("cls");
                    gotoxy(0,row);
                    printf("please enter your input: ");
                    printf("%s",input);
                    gotoxy(25+position,row);

                }


            }
            else if(click==13) //enter
            {
                gotoxy(0,row+1);
                printf("%s",input);
                flag=0;

            }
    }
    return 0;
}
