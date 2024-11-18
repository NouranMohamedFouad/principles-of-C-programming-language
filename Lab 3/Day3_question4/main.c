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


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(void)
{

    int flag = 1, row =1,col =1;

    gotoxy(col*55,row*10);
    setTextColor(stdout,6); // Light BROWN color as a default
    printf("New");
    gotoxy(col*55,(row*10)+5);
    printf("Display");
    gotoxy(col*55,(row*10)+10);
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
                    row=1;
                }
                else {
                    row-=5;  // Move up
                }

            }
            else if(click==80) // down
            {
                if(row==11)
                {
                    row=11;
                }
                else
                {
                    row+=5;
                }

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
                setTextColor(stdout,14);
                gotoxy(55,20);
                printf("Exit");
            }
        }
        else if (click==13) // enter
        {
            system("cls");
            setTextColor(stdout,6);
            gotoxy(col*55,10);
            if (row==1)
            {
                printf("New");
            }
            else if(row==6)
            {
                printf("Display");
            }
            else
            {
                printf("Exit");
            }
            char click = getch();
            if (click == 27)
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

    }
    return EXIT_SUCCESS;
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


















































